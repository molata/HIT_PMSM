/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_RSPI_C1.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 19.04.2016 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_spi.h"
#include "r_pdl_spi_RX62Nxx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_RSPI_Set_C1(void);
bool R_PG_RSPI_SetCommand_C1(void);
bool R_PG_RSPI_TransferAllData_C1(uint32_t * tx_start, uint32_t * rx_start, uint16_t sequence_loop_count);
bool R_PG_RSPI_GetStatus_C1(bool * idle, bool * receive_full, bool * transmit_empty);
bool R_PG_RSPI_GetError_C1(bool * over_run, bool * mode_falt, bool * parity_error);
bool R_PG_RSPI_GetCommandStatus_C1(uint8_t * current_command, uint8_t * error_command);
bool R_PG_RSPI_StopModule_C1(void);



