/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-11-26     Tobby       the first version
 */

#include "CMT2310A_reg.h"
#include "CMT2310A_def.h"
#define  uint8_t unsigned char


#ifndef __CMT2310A_PARAMS_H
#define __CMT2310A_PARAMS_H

#define CMT2310A_PAGE0_SIZE         (0x77-0x28+1)
#define CMT2310A_PAGE1_SIZE         (0xef-0x80+1)
#define CMT2310A_PAGE2_SIZE         (0x3f-0x00+1)



/****************************************************************************
;---------------------------------------
;  CMT2310A Configuration File
;  Generated by CMOSTEK RFPDK 1.53_Update3
;  2022.11.26 09:32
;---------------------------------------
; Mode                       = Advanced
; Part Number                = CMT2310A
; Frequency                  = 434.700 MHz
; DC-DC                      = Off
; Demodulation               = GFSK
; Xtal Cap Load              = 2
; Data Rate                  = 4.800 kbps
; Deviation                  = 1.600 kHz
; Tx Xtal Tol.               = 10 ppm
; Rx Xtal Tol.               = 10 ppm
; TRx Matching Network Type  = 20 dBm
; Tx Power                   = +10 dBm
; Gaussian BT                = 0.5
; PA Ramp                    = On
; PA Ramp Step               = 25
; RF Performance             = NA
; Output Drive Capability    = 0.5mA
; Rx Duty-Cycle              = Off
; Tx Duty-Cycle              = Off
; Sleep Timer                = Off
; Sleep Time                 = NA
; Rx Timer                   = Off
; Rx Time T1                 = NA
; Rx Time T2                 = NA
; Rx Exit State              = STBY
; Tx Exit State              = STBY
; TX Duty Cycle Persist      = Off
; Packet Done Exit           = Off
; TX Duty-Cycle Times        = 0
; SLP Mode                   = Mode 0
; RSSI Valid Source          = RSSI Compare
; PJD Window                 = NA
; RSSI Compare TH            = -107 dBm
; CDR Type                   = Counting
; AFC                        = disable
; FSK2 Data Map              = 0:F-low 1:F-high
; FSK4 Data Map              = NA
; FSK4 RX Data Map           = NA
; CDR Type                   = Counting
; CDR Range Sel FSK          = NA
; Channel BW                 = autosel
; Baseband BW FSK            = autosel
; Data Mode                  = Packet
; Packet Mode                = Normal
; PiggyBacking               = Disable
; Manchester                 = Disable
; Manchester Type            = NA
; Whitening                  = Disable
; Whiten Type                = NA
; Whiten Seed Type           = NA
; Whiten Seed                = NA
; FEC                        = Disable
; FEC Type                   = NA
; FEC Padding Code           = NA
; crc err clear fifo         = Not Clear
; Tx Packet Gap              = 32 symbol(s)
; Tx Packet Number           = 1 packet(s)
; Tx Prefix Type             = 0
; Packet Type                = Fixed Length
; Address-Length Position    = NA
; Length Size                = 1-byte
; Payload Bit Order          = Start from lsb
; Address Field              = Disable
; Preamble Rx Size           = 4
; Preamble Tx Size           = 4
; Preamble Value             = 170
; Preamble Unit              = 8-bit
; Sync Size                  = 4-byte
; Sync Format                = S2LP
; Sync Value                 = 861221717
; Sync Manchester            = Disable
; Sync Value Selection       = Sync Value
; Sync FEC Value             = 861221717
; Sync Tolerance             = None
; Address Detect Mode        = None
; Address Split Mode         = NA
; Address Size               = NA
; Address Err Mask           = NA
; Address Free               = NA
; Dest Addr Value            = NA
; Src Addr Value             = NA
; Dest Addr Bit Mask         = NA
; Src Addr Bit Mask          = NA
; Sequence Num               = None
; Sequence Num Match         = off
; Sequence Num Mode          = NA
; Sequence Num Value         = NA
; FCS2                       = None
; FCS2 Value                 = NA
; Payload Length             = 47
; CRC Options                = None
; CRC Swap                   = NA
; CRC Seed                   = NA
; CRC Bit Invert             = NA
; CRC Range                  = NA
; CRC Polynomial             = NA
; CRC Bit Order              = NA
; CRC Refin                  = NA
; CRC_Refout                 = NA
; Frequency Hopping Mode     = Mode 2
; Freq Hopping Space         = 10 kHz
; Hopping Channels           = 10
; CSMA Mode                  = Disable
; CSMA RSSI Detection        = NA
; Hopping Persist            = Disable
; Hopping Intermediate State = TRFS
; CSMA Sleep Timer Random    = NA
; CSMA Rx Time               = NA
; CSMA Sleep Time M          = NA
; CSMA Sleep Time R          = NA
; CSMA Persist               = NA
; CSMA Detect Times          = NA
; Tx Auto Hopping            = Disable
; Rx Auto Hopping            = Disable
; Auto Acknowledge           = off
; Auto Resend                = off
; Maximum Resend Times       = 1
; RSSI Detect Mode           = always
; LFOSC LFXO Sel             = LFOSC(32kHz)
; LF Clock Out               = off
; Dout Mute                  = disable
; Dout Mute Sel              = NA
; dout adjust mode           = disable
; Dout Adjust Percentage     = NA
; LBD Threshold              = 2.4 v
; Antenna Diversity          = off
; Antenna Switch Mode        = NA
; Collision Detect           = off
; Collision Step             = NA
; RSSI Offset dB             = NA
; RSSI Offset Sel            = autosel

;---------------------------------------
;  The following are the Register contents
;---------------------------------------

*****************************************************************************/

const uint8_t g_cmt2310a_rx_page0[CMT2310A_PAGE0_SIZE] = {
    0x22,
    0x04,
    0x00,
    0xAA,
    0x06,
    0x00,
    0x00,
    0x00,
    0x00,
    0x55,
    0x33,
    0x55,
    0x33,
    0x00,
    0x00,
    0x00,
    0x00,
    0x55,
    0x33,
    0x55,
    0x33,
    0x2E,
    0x00,
    0x02,
    0x00,
    0x00,
    0x00,
    0x00,
    0x2D,
    0x00,
    0x00,
    0x00,
    0x2D,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x45,
    0x1F,
    0x00,
    0x00,
    0x00,
    0x00,
    0x08,
    0x00,
    0x00,
    0x00,
    0x00,
    0x1F,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xE4,
    0x20,
    0x20,
    0x20,
    0x01,
    0x00,
    0xD0,
    0xE0,
    0xE2,
    0x84,
    0x30,
    0x04,
    0xD0,
    0xE0,
    0x80,
    0x00,
    0x41,
    0x00,
    0x01,
    0x00,
    0x02,
    0x00,
    0x00,
    0x03,
    0x04,
};   

/* [CMT page1] */
const uint8_t g_cmt2310a_rx_page1[CMT2310A_PAGE1_SIZE] = {
    0x10,
    0x06,
    0x00,
    0xFF,
    0x00,
    0xCD,
    0x02,
    0x28,
    0x50,
    0x87,
    0x31,
    0x5B,
    0x08,
    0x00,
    0xFF,
    0x00,
    0x6C,
    0xCC,
    0xCC,
    0x0A,
    0xB4,
    0xD5,
    0x09,
    0xE0,
    0x20,
    0x08,
    0x05,
    0x2F,
    0x02,
    0x00,
    0x39,
    0x3F,
    0x00,
    0x19,
    0x00,
    0x00,
    0x06,
    0xE4,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xCA,
    0x6C,
    0xCC,
    0x4C,
    0xDB,
    0x6B,
    0x00,
    0x80,
    0x0F,
    0x64,
    0x06,
    0x02,
    0xD5,
    0x09,
    0x00,
    0x36,
    0x01,
    0x20,
    0xC8,
    0x63,
    0xA1,
    0x0B,
    0x1A,
    0x58,
    0x40,
    0x71,
    0x74,
    0xA5,
    0x0F,
    0x01,
    0x13,
    0xE6,
    0x54,
    0x0C,
    0x09,
    0xE2,
    0x1A,
    0x08,
    0x00,
    0xB4,
    0x09,
    0x0F,
    0x09,
    0x4C,
    0x00,
    0x00,
    0xF6,
    0x00,
    0x00,
    0x00,
    0x10,
    0x95,
    0x00,
    0x00,
    0x47,
    0x12,
    0x25,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
};   

//#define CMT2310A_AUTO_HOP_ENABLE
#ifdef  CMT2310A_AUTO_HOP_ENABLE
#define freq_space_val           0x0A
#define freq_times_val           0x0A
#define freq_switch_state_val    0x01
#define freq_hop_persist_val     0x00

/* [CMT page2] */
const uint8_t g_cmt2310a_page2[CMT2310A_PAGE2_SIZE] = {
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
     0x00,
};   
#endif

#endif


