/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_SCI_C6.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 23.05.2016 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_sci.h"
#include "r_pdl_sci_RX62Nxx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_SCI_Set_C6(void);
bool R_PG_SCI_StartSending_C6(uint8_t * data, uint16_t count);
bool R_PG_SCI_GetSentDataCount_C6(uint16_t * count);
bool R_PG_SCI_StartReceiving_C6(uint8_t * data, uint16_t count);
bool R_PG_SCI_StopCommunication_C6(void);
bool R_PG_SCI_GetReceivedDataCount_C6(uint16_t * count);
bool R_PG_SCI_GetReceptionErrorFlag_C6(bool * parity, bool * framing, bool * overrun);
bool R_PG_SCI_GetTransmitStatus_C6(bool * complete);
bool R_PG_SCI_StopModule_C6(void);



