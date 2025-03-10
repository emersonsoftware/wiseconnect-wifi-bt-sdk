/*******************************************************************************
* @file  rsi_ram_dump.c
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

/**
 * Include files
 * */
//! include file to refer data types
#include "rsi_data_types.h"

//! COMMON include file to refer wlan APIs
#include "rsi_common_apis.h"

//! WLAN include file to refer wlan APIs
#include "rsi_wlan_apis.h"
#include "rsi_wlan_non_rom.h"

//! socket include file to refer socket APIs
#include "rsi_socket.h"

#include "rsi_bootup_config.h"
//! Error include files
#include "rsi_error.h"

//! OS include file to refer OS specific functionality
#include "rsi_os.h"

#define ENABLE 1

#define DISABLE 0

//! Memory length for driver
#define GLOBAL_BUFF_LEN 15000

//! Read content length
#define RAM_CONENT_LEN (64 * 1024)

//! Address in RS9116
#define READ_ADDRESS 0x0

//! chunk length to read from RS9116
#define CHUNK_LENGTH 4096

#ifdef LINUX_PLATFORM
#include <stdio.h>
#endif

//! Memory to initialize driver
uint8_t global_buf[GLOBAL_BUFF_LEN];

uint8_t ram_content[RAM_CONENT_LEN];

int32_t rsi_ram_dump_app()
{
  int32_t status = RSI_SUCCESS;
  int32_t offset = 0, chunk_len;
#ifdef LINUX_PLATFORM
  FILE *fp = NULL;
#endif
  //! WC initialization
  status = rsi_wireless_init(0, 0);
  if (status != RSI_SUCCESS) {
    return status;
  }

  while (offset < RAM_CONENT_LEN) {
    chunk_len = ((RAM_CONENT_LEN - offset) >= CHUNK_LENGTH) ? CHUNK_LENGTH : (RAM_CONENT_LEN - offset);
    status    = rsi_get_ram_dump(READ_ADDRESS + offset, chunk_len, &ram_content[offset]);
    if (status != RSI_SUCCESS) {
      return status;
    }
    offset += chunk_len;
  }
#ifdef LINUX_PLATFORM
  fp = fopen("dump.txt", "w");
  if (fp == NULL) {
    return -1;
  }
  fwrite(ram_content, RAM_CONENT_LEN, 4, fp);
  fclose(fp);
#endif
  return status;
}

int main()
{
  int32_t status;
#ifdef RSI_WITH_OS
  rsi_task_handle_t wlan_task_handle = NULL;

  rsi_task_handle_t driver_task_handle = NULL;
#endif
  //! Driver initialization
  status = rsi_driver_init(global_buf, GLOBAL_BUFF_LEN);
  if ((status < 0) || (status > GLOBAL_BUFF_LEN)) {
    return status;
  }

  //! Redpine module intialisation
  status = rsi_device_init(LOAD_NWP_FW);
  if (status != RSI_SUCCESS) {
    return status;
  }
  status = rsi_ram_dump_app();

  return status;
}
