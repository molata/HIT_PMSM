/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_RSPI_C0.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 23.05.2016 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_spi.h"
#include "r_pdl_spi_RX62Nxx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_RSPI_Set_C0(void);
bool R_PG_RSPI_SetCommand_C0(void);
bool R_PG_RSPI_TransferAllData_C0(uint32_t * tx_start, uint32_t * rx_start, uint16_t sequence_loop_count);
bool R_PG_RSPI_GetStatus_C0(bool * idle, bool * receive_full, bool * transmit_empty);
bool R_PG_RSPI_GetError_C0(bool * over_run, bool * mode_falt, bool * parity_error);
bool R_PG_RSPI_GetCommandStatus_C0(uint8_t * current_command, uint8_t * error_command);
bool R_PG_RSPI_StopModule_C0(void);



