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

/******************************************************
 * *                      Macros
 * ******************************************************/

#define RSI_BLE_SET_RAND_ADDR "00:23:A7:12:34:56"

//! local device IO capability
#define RSI_BLE_SMP_IO_CAPABILITY    0x01
#define CLEAR_WHITELIST              0x00
#define ADD_DEVICE_TO_WHITELIST      0x01
#define DELETE_DEVICE_FROM_WHITELIST 0x02

#define ALL_PHYS 0x00

#define RSI_BLE_DEV_ADDR_RESOLUTION_ENABLE 0

#define RSI_OPERMODE_WLAN_BLE 13

#define RSI_BLE_MAX_NBR_ATT_REC  80
#define RSI_BLE_MAX_NBR_ATT_SERV 10

#define RSI_BLE_MAX_NBR_SLAVES    3
#define RSI_BLE_MAX_NBR_MASTERS   1
#define RSI_BLE_GATT_ASYNC_ENABLE 0
#define RSI_BLE_GATT_INIT         0

/* Number of BLE notifications */
#define RSI_BLE_NUM_CONN_EVENTS 20

/* Number of BLE GATT RECORD SIZE IN (n*16 BYTES), eg:(0x40*16)=1024 bytes */
#define RSI_BLE_NUM_REC_BYTES 0x40

#define RSI_BLE_INDICATE_CONFIRMATION_FROM_HOST 0
#define SET_SMP_CONFIGURATION                   0x01
#if SET_SMP_CONFIGURATION
#define LOCAL_OOB_DATA_FLAG_NOT_PRESENT (0x00)

// BLUETOOTH SPECIFICATION Version 5.0 | Vol 3, Part H 3.6.1 Key Distribution and Generation
#define ENC_KEY_DIST  (1 << 0)
#define ID_KEY_DIST   (1 << 1)
#define SIGN_KEY_DIST (1 << 2)
#define LINK_KEY_DIST (1 << 3)
#if RESOLVE_ENABLE
#define RESPONDER_KEYS_TO_DIST (ENC_KEY_DIST | SIGN_KEY_DIST | ID_KEY_DIST)
#else
#define RESPONDER_KEYS_TO_DIST (ENC_KEY_DIST | SIGN_KEY_DIST)
#endif
#if RESOLVE_ENABLE
#define INITIATOR_KEYS_TO_DIST (ID_KEY_DIST | ENC_KEY_DIST | SIGN_KEY_DIST)
#else
#define INITIATOR_KEYS_TO_DIST (ENC_KEY_DIST | SIGN_KEY_DIST)
#endif
#endif
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

//!Advertise status
//! Start the advertising process
#define RSI_BLE_START_ADV 0x01
//! Stop the advertising process
#define RSI_BLE_STOP_ADV 0x00

//! BLE Tx Power Index On Air
#define RSI_BLE_PWR_INX 30

//! BLE Active H/w Pwr Features
#define BLE_DISABLE_DUTY_CYCLING 0
#define BLE_DUTY_CYCLING         1
#define BLR_DUTY_CYCLING         2
#define BLE_4X_PWR_SAVE_MODE     4
#define RSI_BLE_PWR_SAVE_OPTIONS BLE_DISABLE_DUTY_CYCLING

//!Advertise types

/* Advertising will be visible(discoverable) to all the devices.
 * Scanning/Connection is also accepted from all devices
 * */
#define UNDIR_CONN 0x80

/* Advertising will be visible(discoverable) to the particular device 
 * mentioned in RSI_BLE_ADV_DIR_ADDR only. 
 * Scanning and Connection will be accepted from that device only.
 * */
#define DIR_CONN 0x81

/* Advertising will be visible(discoverable) to all the devices.
 * Scanning will be accepted from all the devices.
 * Connection will be not be accepted from any device.
 * */
#define UNDIR_SCAN 0x82

/* Advertising will be visible(discoverable) to all the devices.
 * Scanning and Connection will not be accepted from any device
 * */
#define UNDIR_NON_CONN 0x83

/* Advertising will be visible(discoverable) to the particular device 
 * mentioned in RSI_BLE_ADV_DIR_ADDR only. 
 * Scanning and Connection will be accepted from that device only.
 * */
#define DIR_CONN_LOW_DUTY_CYCLE 0x84

//!Advertising flags
#define LE_LIMITED_DISCOVERABLE 0x01
#define LE_GENERAL_DISCOVERABLE 0x02
#define LE_BR_EDR_NOT_SUPPORTED 0x04

//!Advertise filters
#define ALLOW_SCAN_REQ_ANY_CONN_REQ_ANY               0x00
#define ALLOW_SCAN_REQ_WHITE_LIST_CONN_REQ_ANY        0x01
#define ALLOW_SCAN_REQ_ANY_CONN_REQ_WHITE_LIST        0x02
#define ALLOW_SCAN_REQ_WHITE_LIST_CONN_REQ_WHITE_LIST 0x03

//! Address types
#define LE_PUBLIC_ADDRESS            0x00
#define LE_RANDOM_ADDRESS            0x01
#define LE_RESOLVABLE_PUBLIC_ADDRESS 0x02
#define LE_RESOLVABLE_RANDOM_ADDRESS 0x03

/*=======================================================================*/

/*=======================================================================*/
//! Connection parameters
/*=======================================================================*/
#define LE_SCAN_INTERVAL 0x0100
#define LE_SCAN_WINDOW   0x0050

#define CONNECTION_INTERVAL_MIN 0x00A0
#define CONNECTION_INTERVAL_MAX 0x00A0

#define CONNECTION_LATENCY  0x0000
#define SUPERVISION_TIMEOUT 0x07D0 //2000

/*=======================================================================*/

/*=======================================================================*/
//! Scan command parameters
/*=======================================================================*/

#define RSI_BLE_SCAN_TYPE        SCAN_TYPE_ACTIVE
#define RSI_BLE_SCAN_FILTER_TYPE SCAN_FILTER_TYPE_ALL

//!Scan status
#define RSI_BLE_START_SCAN 0x01
#define RSI_BLE_STOP_SCAN  0x00

//!Scan types
#define SCAN_TYPE_ACTIVE  0x01
#define SCAN_TYPE_PASSIVE 0x00

//!Scan filters
#define SCAN_FILTER_TYPE_ALL             0x00
#define SCAN_FILTER_TYPE_ONLY_WHITE_LIST 0x01

#define RSI_SEL_INTERNAL_ANTENNA 0x00
#define RSI_SEL_EXTERNAL_ANTENNA 0x01

#define LOCAL_OOB_DATA_FLAG_NOT_PRESENT (0x00)
#define AUTH_REQ_BONDING_BITS           ((1 << 0))
#define AUTH_REQ_MITM_BIT               (1 << 2)
#define AUTH_REQ_SC_BIT                 (1 << 3)
#define AUTH_REQ_BITS                   (AUTH_REQ_BONDING_BITS | AUTH_REQ_MITM_BIT) // | AUTH_REQ_SC_BIT)
#define MAXIMUM_ENC_KEY_SIZE_16         (16)
#define ENC_KEY_DIST                    (1 << 0)
#define ID_KEY_DIST                     (1 << 1)
#define SIGN_KEY_DIST                   (1 << 2)
#define LINK_KEY_DIST                   (1 << 3)
#if RESOLVE_ENABLE
#define RESPONDER_KEYS_TO_DIST (ENC_KEY_DIST | SIGN_KEY_DIST | ID_KEY_DIST)
#else
#define RESPONDER_KEYS_TO_DIST (ENC_KEY_DIST | SIGN_KEY_DIST)
#endif
#if RESOLVE_ENABLE
#define INITIATOR_KEYS_TO_DIST (ID_KEY_DIST | ENC_KEY_DIST | SIGN_KEY_DIST)
#else
#define INITIATOR_KEYS_TO_DIST (ENC_KEY_DIST | SIGN_KEY_DIST)
#endif

#endif
