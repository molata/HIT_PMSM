/******************************************************************************
* DISCLAIMER

* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized.

* This software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.

* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY 
* DISCLAIMED.

* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES 
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS 
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

* Renesas reserves the right, without notice, to make changes to this 
* software and to discontinue the availability of this software.  
* By using this software, you agree to the additional terms and 
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_SCI_C6.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 11.04.2016 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "R_PG_SCI_C6.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_Set_C6(void)
*
* Function Name: R_PG_SCI_Set_C6
*
* Description  : Set up the serial I/O
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SCI_Create
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_Set_C6(void)
{
	return R_SCI_Create(
		6,
		PDL_SCI_ASYNC | PDL_SCI_TX_CONNECTED | PDL_SCI_RX_CONNECTED | PDL_SCI_CLK_INT_IO | PDL_SCI_8_BIT_LENGTH | PDL_SCI_PARITY_NONE | PDL_SCI_STOP_1,
		BIT_31 | PDL_SCI_PCLK_DIV_1 | PDL_SCI_CYCLE_BIT_8 | 0xc | (230769 & 0x00FFFF00ul),
		15
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StartSending_C6(uint8_t * data, uint16_t count)
*
* Function Name: R_PG_SCI_StartSending_C6
*
* Description  : Start transmission of serial data
*
* Arguments    : uint8_t * data : The start address of the data to be sent.
*              : uint16_t count : The number of the data to be sent.
*              :                : Set this to 0 if the transmit data is a character string
*              :                : (ending with a null character).
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SCI_Send
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_StartSending_C6(uint8_t * data, uint16_t count)
{
	if( data == 0 ){ return false; }

	return R_SCI_Send(
		6,
		PDL_SCI_DMAC_DTC_TRIGGER_DISABLE,
		data,
		count,
		Sci6TrFunc
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetSentDataCount_C6(uint16_t * count)
*
* Function Name: R_PG_SCI_GetSentDataCount_C6
*
* Description  : Acquires the count of transmitted serial data
*
* Arguments    : uint16_t * count : The storage location for the number of bytes
*              :                  : that have been transmitted in the current transmission.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_GetSentDataCount_C6(uint16_t * count)
{
	uint8_t status;

	if( count == 0 ){ return false; }

	return R_SCI_GetStatus(
		6,
		&status,
		PDL_NO_PTR,
		count,
		PDL_NO_PTR
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StartReceiving_C6(uint8_t * data, uint16_t count)
*
* Function Name: R_PG_SCI_StartReceiving_C6
*
* Description  : Start reception of serial data
*
* Arguments    : uint8_t * data : The start address of the storage area for the expected data.
*              : uint16_t count : The number of the data to be received.
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SCI_Receive
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_StartReceiving_C6(uint8_t * data, uint16_t count)
{
	if( data == 0 ){ return false; }

	return R_SCI_Receive(
		6,
		PDL_SCI_DMAC_DTC_TRIGGER_DISABLE,
		data,
		count,
		Sci6ReFunc,
		PDL_NO_FUNC
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StopCommunication_C6(void)
*
* Function Name: R_PG_SCI_StopCommunication_C6
*
* Description  : Stop transmission and reception of serial data
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SCI_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_StopCommunication_C6(void)
{
	return R_SCI_Control(
		6,
		PDL_SCI_STOP_TX_AND_RX
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetReceivedDataCount_C6(uint16_t * count)
*
* Function Name: R_PG_SCI_GetReceivedDataCount_C6
*
* Description  : Acquires the count of received serial data
*
* Arguments    : uint16_t * count : The storage location for the number of bytes
*              :                  : that have been received in the current reception process.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_GetReceivedDataCount_C6(uint16_t * count)
{
	uint8_t status;

	if( count == 0 ){ return false; }

	return R_SCI_GetStatus(
		6,
		&status,
		PDL_NO_PTR,
		PDL_NO_PTR,
		count
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetReceptionErrorFlag_C6(bool * parity, bool * framing, bool * overrun)
*
* Function Name: R_PG_SCI_GetReceptionErrorFlag_C6
*
* Description  : Get the serial reception error flag
*
* Arguments    : bool * parity : The address of storage area for the parity error flag.
*              : bool * framing : The address of storage area for the framing error flag.
*              : bool * overrun : The address of storage area for the overrun error flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_GetReceptionErrorFlag_C6(bool * parity, bool * framing, bool * overrun)
{
	uint8_t status;
	bool res;

	res = R_SCI_GetStatus(
		6,
		&status,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( parity ){
		*parity = (status >> 3) & 0x01;
	}
	if( framing ){
		*framing = (status >> 4) & 0x01;
	}
	if( overrun ){
		*overrun = (status >> 5) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetTransmitStatus_C6(bool * complete)
*
* Function Name: R_PG_SCI_GetTransmitStatus_C6
*
* Description  : Get the serial data transmission status
*
* Arguments    : bool * complete : The address of storage area for the transmission completion flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_GetTransmitStatus_C6(bool * complete)
{
	uint8_t status;
	bool res;

	res = R_SCI_GetStatus(
		6,
		&status,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( complete ){ *complete = (status >> 2) & 0x01; }

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StopModule_C6(void)
*
* Function Name: R_PG_SCI_StopModule_C6
*
* Description  : Shut down the serial I/O channel
*
* Arguments    : None
*
* Return Value : true  : Shutting down succeeded.
*              : false : Shutting down failed.
*
* Calling Functions : R_SCI_Destroy
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_StopModule_C6(void)
{
	return R_SCI_Destroy( 6 );
}



