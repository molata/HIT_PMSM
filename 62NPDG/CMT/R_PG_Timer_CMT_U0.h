/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_Timer_CMT_U0.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 20.04.2016 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_cmt.h"
#include "r_pdl_cmt_RX62Nxx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_Timer_Start_CMT_U0_C0(void);
bool R_PG_Timer_HaltCount_CMT_U0_C0(void);
bool R_PG_Timer_ResumeCount_CMT_U0_C0(void);
bool R_PG_Timer_GetCounterValue_CMT_U0_C0(uint16_t * counter_val);
bool R_PG_Timer_SetCounterValue_CMT_U0_C0(uint16_t counter_val);
bool R_PG_Timer_Start_CMT_U0_C1(void);
bool R_PG_Timer_HaltCount_CMT_U0_C1(void);
bool R_PG_Timer_ResumeCount_CMT_U0_C1(void);
bool R_PG_Timer_GetCounterValue_CMT_U0_C1(uint16_t * counter_val);
bool R_PG_Timer_SetCounterValue_CMT_U0_C1(uint16_t counter_val);
bool R_PG_Timer_StopModule_CMT_U0(void);



