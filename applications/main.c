/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-07-13     RT-Thread    first version
 */

#include <rtthread.h>
#include "flashwork.h"
#include "device.h"
#include "key.h"
#include "led.h"
#include "wifi-uart.h"
#include "heart.h"
#include "dog.h"
#include "board.h"
#include "protocol.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

int main(void)
{
    LOG_I("System Version is %s\r\n",MCU_VER);
    flash_Init();
    led_Init();
    LoadDevice2Memory();
    Key_Reponse_Init();
    button_Init();
    CMTTX_REC_Test();
//    Sync_Init();
//    rf_433_start();
//    RadioDequeueTaskInit();
//    Heart_Init();
//    WiFi_Init();
    while (1)
    {
        rt_thread_mdelay(1000);
    }
}
