/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-29     Tobby       the first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_spi.h"
#include <string.h>
#include "pin_config.h"
#include "cmt2310a_Reg.h"
#include "base_types.h"
#include "cmt2310a_def.h"
#include "radio_drv.h"

#define DBG_TAG "CMTTX"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

rt_sem_t IRQ1_Sem = RT_NULL;
rt_thread_t rf_433_task = RT_NULL;

uint32_t Self_Id = 87654321;
uint32_t Self_Default_Id = 10000000;


struct cmt2310 rf_433;

void rf_433_sem_init(void)
{
    IRQ1_Sem = rt_sem_create("IRQ1_Sem", 0, RT_IPC_FLAG_FIFO);
}

void IRQ1_ISR(void *parameter)
{
    rt_sem_release(IRQ1_Sem);
}

void IRQ1_Bounding(void)
{
    rt_pin_mode(Radio_IRQ, PIN_MODE_INPUT_PULLUP);
    rt_pin_attach_irq(Radio_IRQ, PIN_IRQ_MODE_RISING, IRQ1_ISR, RT_NULL);
    rt_pin_irq_enable(Radio_IRQ, PIN_IRQ_ENABLE);
}

int32_t CMTTX_REC_Test(void)
{
    rf_433_start();
}

void RadioSend(uint32_t Taget_Id, uint8_t counter, uint8_t Command, uint8_t Data)
{
    char *buf = rt_malloc(64);
    uint8_t check = 0;
    if (counter < 255)
        counter++;
    else
        counter = 0;

    sprintf(buf, "!{%08ld,%08ld,%03d,%02d,%d}", Taget_Id, Self_Id, counter, Command, Data);

    for (uint8_t i = 1; i < 29; i++)
    {
        check += buf[i];
    }
    buf[29] = ((check >> 4) < 10) ? (check >> 4) + '0' : (check >> 4) - 10 + 'A';
    buf[30] = ((check & 0xf) < 10) ? (check & 0xf) + '0' : (check & 0xf) - 10 + 'A';
    buf[31] = '\r';
    buf[32] = '\n';
    Normal_send(buf, 33);
    rt_free(buf);
}

void GatewayDataSend(uint32_t target_id, uint32_t device_id, uint8_t rssi, uint8_t control, uint8_t value)
{
    char *buf = rt_malloc(64);
    sprintf(buf, "*G{%08ld,%08ld,%08ld,%03d,%03d,%02d}G", target_id, Self_Id, device_id, rssi, control, value);
    Normal_send(buf, 42);
    rt_free(buf);
}

void rf_433_task_callback(void *parameter)
{
    static rt_err_t result;
    uint8_t g_radio_rx_buf[47];            //高频接收缓存
    uint16_t calc_crc = 0;
    uint16_t src_crc = 0;
    uint8_t dest_payload[50] = { 0 };
    uint8_t dis_payload[50] = { 0 };
    int8_t Rssi_dbm;

    vRadioGoRxInit();
    while (1)
    {
        result = rt_sem_take(IRQ1_Sem, RT_WAITING_FOREVER);
        if (result == RT_EOK)
        {
            vRadioReadFifo(g_radio_rx_buf, 47);

            if (g_radio_rx_buf[0] == 0x21) //
            {
                memcpy(dest_payload, g_radio_rx_buf, 35);
                memcpy(dis_payload, g_radio_rx_buf, 33);
                calc_crc = crc16_test(33, dest_payload);
                src_crc = two_char_to_int(g_radio_rx_buf[33], g_radio_rx_buf[34]);
                Rssi_dbm = bRadioReadReg(CMT2310A_RSSI_REG); //-128;   //  CMT2310A_RSSI_REG
                if (calc_crc == src_crc)
                {
                    rf433_rx_callback(Rssi_dbm,dis_payload,32);
                }
                else
                {
                    LOG_D("EURev ERRER= %s\r\n", dis_payload);
                }
            }
            else if (g_radio_rx_buf[0] == 0x2D)
            {
                memcpy(dest_payload, g_radio_rx_buf, 47);
                memcpy(dis_payload, g_radio_rx_buf, 45);
                calc_crc = crc16_test(45, dest_payload);
                src_crc = two_char_to_int(g_radio_rx_buf[45], g_radio_rx_buf[46]);
                Rssi_dbm = bRadioReadReg(CMT2310A_RSSI_REG); //-128;   //  CMT2310A_RSSI_REG
                if (calc_crc == src_crc)
                {
                    rf433_rx_callback(Rssi_dbm,dis_payload,44);
                }
                else
                {
                    LOG_D("MURev ERRER= %s\r\n", dis_payload);
                }
            }
            else if (g_radio_rx_buf[0] == 0x2A)
            {
                memcpy(dest_payload, g_radio_rx_buf, 44);
                memcpy(dis_payload, g_radio_rx_buf, 42);
                calc_crc = crc16_test(42, dest_payload);
                src_crc = two_char_to_int(g_radio_rx_buf[42], g_radio_rx_buf[43]);
                Rssi_dbm = bRadioReadReg(CMT2310A_RSSI_REG); //-128;   //  CMT2310A_RSSI_REG
                if (calc_crc == src_crc)
                {
                    LOG_D("GURev  = %s,RSSI = %d\r\n", dis_payload, Rssi_dbm);
                }
                else
                {
                    LOG_D("GURev ERRER= %s\r\n", dis_payload);
                }
            }

            vRadioClearRxFifo();
            vRadioClearInterrupt();
            memset(g_radio_rx_buf, 0, 47);
            memset(dest_payload, 0, 50);
            memset(dis_payload, 0, 50);
            bRadioGoRx();
        }
    }
}

void rf_433_start(void)
{
    vSpiMasterInit();
    rf_433_task = rt_thread_create("rf_433_task", rf_433_task_callback, RT_NULL, 2048, 5, 10);
    rt_thread_startup(rf_433_task);
    rf_433_sem_init();
    IRQ1_Bounding();
}


void rf433_rx_callback(int rssi,uint8_t *buffer,uint8_t len)
{
    switch(buffer[1])
    {
    case '{':
//        NormalSolve(rssi,buffer,len);
        LOG_D("EURev is %s,RSSI is %d,Len is %d\r\n",buffer,rssi,len);
        break;
    case 'A':
        LOG_D("MURevA is %s,RSSI is %d,Len is %d\r\n",buffer,rssi,len);
//        GatewaySyncSolve(rssi,buffer,len);
        break;
    case 'B':
        LOG_D("MURevB is %s,RSSI is %d,Len is %d\r\n",buffer,rssi,len);
//        GatewayWarningSolve(rssi,buffer,len);
        break;
    case 'C':
        LOG_D("MURevC is %s,RSSI is %d,Len is %d\r\n",buffer,rssi,len);
//        GatewayControlSolve(rssi,buffer,len);
        break;
    }
}


void EUTest(void)
{
    RadioSend(12345678, 0, 0, 0);
}
MSH_CMD_EXPORT(EUTest, EUTest);

void GUTest(void)
{
    RadioSend(12345678, 0, 0, 0);
    GatewayDataSend(12345678, 12345678, 0, 0, 0);
}
MSH_CMD_EXPORT(GUTest, GUTest);

