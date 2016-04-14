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
* File Name    : R_PG_RSPI_C1.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 14.04.2016 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "R_PG_RSPI_C1.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_RSPI_Set_C1(void)
*
* Function Name: R_PG_RSPI_Set_C1
*
* Description  : Set up the RSPI
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SPI_Create
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_RSPI_Set_C1(void)
{
	return R_SPI_Create(
		1,
		PDL_SCI_MODE_SYNC_MASTER | PDL_SPI_FULL_DUPLEX | PDL_SPI_PIN_CMOS | PDL_SPI_PIN_A | PDL_SPI_PIN_RSPCK_ENABLE | PDL_SPI_PIN_MOSI_ENABLE | PDL_SPI_PIN_MISO_ENABLE | PDL_SPI_PIN_SSL0_DISABLE | PDL_SPI_PIN_SSL1_DISABLE | PDL_SPI_PIN_SSL2_DISABLE | PDL_SPI_PIN_SSL3_DISABLE | PDL_SPI_PIN_MOSI_IDLE_HIGH,
		PDL_SPI_BUFFER_64 | PDL_SPI_FRAME_1_1 | PDL_SPI_PARITY_NONE,
		PDL_SPI_CLOCK_DELAY_1 | PDL_SPI_SSL_DELAY_1 | PDL_SPI_NEXT_DELAY_1,
		0x17 | 0x80000000
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_RSPI_SetCommand_C1(void)
*
* Function Name: R_PG_RSPI_SetCommand_C1
*
* Description  : Set up the command
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SPI_Command
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_RSPI_SetCommand_C1(void)
{
	bool res;

	res = R_SPI_Command(
		1,
		0,
		PDL_SPI_CLOCK_MODE_3 | PDL_SPI_DIV_1 | PDL_SPI_ASSERT_SSL0 | PDL_SPI_SSL_NEGATE | PDL_SPI_LENGTH_16 | PDL_SPI_LSB_FIRST,
		PDL_SPI_CLOCK_DELAY_MINIMUM | PDL_SPI_SSL_DELAY_MINIMUM | PDL_SPI_NEXT_DELAY_MINIMUM
	);

	if( !res ){
		return res;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_RSPI_TransferAllData_C1(uint32_t * tx_start, uint32_t * rx_start, uint16_t sequence_loop_count)
*
* Function Name: R_PG_RSPI_TransferAllData_C1
*
* Description  : Transmit all data
*
* Arguments    : uint32_t * tx_start : The start address of the data to be sent.
*              : uint32_t * rx_start : The start address of the received data.
*              : uint16_t sequence_loop_count : Repeat count of command sequence
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SPI_Transfer
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_RSPI_TransferAllData_C1(uint32_t * tx_start, uint32_t * rx_start, uint16_t sequence_loop_count)
{
	if( (tx_start == 0) || \
		(rx_start == 0) )
	{
		return false;
	}

	return R_SPI_Transfer(
		1,
		PDL_SPI_DMAC_DTC_TRIGGER_DISABLE,
		tx_start,
		rx_start,
		sequence_loop_count,
		PDL_NO_FUNC,
		0
	);
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_RSPI_GetStatus_C1(bool * idle, bool * receive_full, bool * transmit_empty)
*
* Function Name: R_PG_RSPI_GetStatus_C1
*
* Description  : Acquire the RSPI status flag
*
* Arguments    : bool * idle : The address of storage area for the idle flag
*              :             : (0:  RSPI is in the idle state 1: RSPI is in the transfer state)
*              : bool * receive_full : The address of storage area for the receive buffer full flag
*              :                     : (0: Data has been received 1: No data has been received)
*              : bool * transmit_empty : The address of storage area for the transmit buffer empty flag
*              :                       : (0: Transmit buffer is not empty 1: Transmit buffer is empty)
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SPI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_RSPI_GetStatus_C1(bool * idle, bool * receive_full, bool * transmit_empty)
{
	uint16_t status;
	bool res;

	res = R_SPI_GetStatus(
		1,
		&status,
		PDL_NO_PTR
	);

	if( idle ){
		*idle = (status >> 1) & 0x01;
	}
	if( receive_full ){
		*receive_full = (status >> 7) & 0x01;
	}
	if( transmit_empty ){
		*transmit_empty = (status >> 5) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_RSPI_GetError_C1(bool * over_run, bool * mode_falt, bool * parity_error)
*
* Function Name: R_PG_RSPI_GetError_C1
*
* Description  : Acquire the RSPI error flag
*
* Arguments    : bool * over_run : The address of storage area for the overrun error flag.
*              : bool * mode_falt : The address of storage area for the mode fault error flag
*              : bool * parity_error : The address of storage area for the parity error flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SPI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_RSPI_GetError_C1(bool * over_run, bool * mode_falt, bool * parity_error)
{
	uint16_t status;
	bool res;

	res = R_SPI_GetStatus(
		1,
		&status,
		PDL_NO_PTR
	);

	if( over_run ){
		*over_run = status & 0x01;
	}
	if( mode_falt ){
		*mode_falt = (status >> 2) & 0x01;
	}
	if( parity_error ){
		*parity_error = (status >> 3) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_RSPI_GetCommandStatus_C1(uint8_t * current_command, uint8_t * error_command)
*
* Function Name: R_PG_RSPI_GetCommandStatus_C1
*
* Description  : Acquire the command status flag
*
* Arguments    : uint8_t * current_command : The address of storage area for the current command pointer (0 to 7)
*              : uint8_t * error_command : The address of storage area for the command pointer when an error is detected (0 to 7)
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SPI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_RSPI_GetCommandStatus_C1(uint8_t * current_command, uint8_t * error_command)
{
	uint16_t status;
	bool res;

	res = R_SPI_GetStatus(
		1,
		&status,
		PDL_NO_PTR
	);

	if( current_command ){	
		*current_command = (status >> 8) & 0x07;
	}
	if( error_command ){
		*error_command = (status >> 12) & 0x07;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_RSPI_StopModule_C1(void)
*
* Function Name: R_PG_RSPI_StopModule_C1
*
* Description  : Shut down the RSPI
*
* Arguments    : None
*
* Return Value : true  : Shutting down succeeded.
*              : false : Shutting down failed.
*
* Calling Functions : R_SPI_Destroy
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_RSPI_StopModule_C1(void)
{
	return R_SPI_Destroy( 1 );
}



