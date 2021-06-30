/*******************************************************************************
* @file  rsi_ble_config.h
* @brief 
*******************************************************************************
* # License
* <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
*******************************************************************************
*
* The licensor of this software is Silicon Laboratories Inc. Your use of this
* software is governed by the terms of Silicon Labs Master Software License
* Agreement (MSLA) available at
* www.silabs.com/about-us/legal/master-software-license-agreement. This
* software is distributed to you in Source Code format and is governed by the
* sections of the MSLA applicable to Source Code.
*
******************************************************************************/

#ifndef RSI_BLE_CONFIG_H
#define RSI_BLE_CONFIG_H

#include <rsi_data_types.h>

/****************************************************************
 * *                      Application configuration Macros
 * ***************************************************************/
#define RSI_BLE_LOCAL_NAME "SILABS_DEVICE"

//! Address type of the device to connect
#define RSI_BLE_DEV_ADDR_TYPE LE_PUBLIC_ADDRESS

//! Address of the device to connect
#define RSI_BLE_DEV_ADDR "11:11:11:11:11:11"

//! Remote Device Name to connect
#define RSI_REMOTE_DEVICE_NAME "SLAVE"

#define SLAVE_MODE  0
#define MASTER_MODE 1
#define DUAL_MODE   2
#define BLE_ROLE    SLAVE_MODE

/*=======================================================================*/
//! Application supported events list
/*=======================================================================*/
#define RSI_APP_EVENT_ADV_REPORT   0
#define RSI_APP_EVENT_CONNECTED    1
#define RSI_APP_EVENT_DISCONNECTED 2

/******************************************************
 * *                      Macros
 * ******************************************************/
//! Power Save Profile Mode
#define PSP_MODE RSI_SLEEP_MODE_2

//! Power Save Profile type
#define PSP_TYPE RSI_MAX_PSP

#define RSI_BLE_SET_RAND_ADDR "00:23:A7:12:34:56"

#define CLEAR_WHITELIST              0x00
#define ADD_DEVICE_TO_WHITELIST      0x01
#define DELETE_DEVICE_FROM_WHITELIST 0x02

#define ALL_PHYS 0x00

#define RSI_BLE_DEV_ADDR_RESOLUTION_ENABLE 0

#define RSI_OPERMODE_WLAN_BLE 13

#define RSI_BLE_MAX_NBR_ATT_REC  80
#define RSI_BLE_MAX_NBR_ATT_SERV 10

#define RSI_BLE_MAX_NBR_SLAVES    1
#define RSI_BLE_MAX_NBR_MASTERS   1
#define RSI_BLE_GATT_ASYNC_ENABLE 0
#define RSI_BLE_GATT_INIT         0

/* Number of BLE notifications */
#define RSI_BLE_NUM_CONN_EVENTS 20

/* Number of BLE GATT RECORD SIZE IN (n*16 BYTES), eg:(0x40*16)=1024 bytes */
#define RSI_BLE_NUM_REC_BYTES 0x40

#define RSI_BLE_INDICATE_CONFIRMATION_FROM_HOST 0

/*=======================================================================*/
//! Advertising command parameters
/*=======================================================================*/

#define RSI_BLE_ADV_TYPE          UNDIR_CONN
#define RSI_BLE_ADV_FILTER_TYPE   ALLOW_SCAN_REQ_ANY_CONN_REQ_ANY
#define RSI_BLE_ADV_DIR_ADDR_TYPE LE_PUBLIC_ADDRESS
#define RSI_BLE_ADV_DIR_ADDR      "00:15:83:6A:64:17"

#define RSI_BLE_ADV_INT_MIN     0x100
#define RSI_BLE_ADV_INT_MAX     0x200
#define RSI_BLE_ADV_CHANNEL_MAP 0x07

/*=======================================================================*/
//! Connection parameters
/*=======================================================================*/
#define LE_SCAN_INTERVAL 0x0100
#define LE_SCAN_WINDOW   0x0050

#define CONNECTION_INTERVAL_MIN 0x00A0
#define CONNECTION_INTERVAL_MAX 0x00A0

#define CONNECTION_LATENCY  0x0000
#define SUPERVISION_TIMEOUT 0x07D0 //2000

#include <rsi_ble_common_config.h>

#endif
