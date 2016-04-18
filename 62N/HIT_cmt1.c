#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
uchar uc62TA_fresh = 0;
uchar uc62TA_IO_history = 0;
uchar uc62TA_IO_Value = 0;
uchar uc62TB_fresh = 0;
uchar uc62TB_IO_history = 0;
uchar uc62TB_IO_Value = 0;
void Cmt1IntFunc()   // 50us
{
	serial_loop();
	laser_loop();

	//SPI_62TB_loop();
	PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
	
	/********************** 62TA发送指令 **************************/
	//if(uc62TA_IO != PORT5.DR.BIT.B4)
	uc62TA_IO_Value = PORT5.PORT.BIT.B4;
	if(uc62TA_IO_Value != uc62TA_IO_history)
	{
		uc62TA_IO_history = uc62TA_IO_Value;
		uc62TA_fresh = 1;
	}
	else 
	{
		uc62TA_fresh = 0;	
	}
	if(uc62TA_fresh == 1 && uc62TA_IO_Value == 1)
	{
		SPI_62TA_loop();	
	}
/********************** 62TB发送指令 **************************/
/***
	if(uc62TB_IO != PORTA.PORT.BIT.B0)
	{
		uc62TB_IO = PORTA.PORT.BIT.B0;
		uc62TB_fresh = 1;
	}
	else 
	{
		uc62TB_fresh = 0;	
	}
	if(uc62TB_fresh == 1 && uc62TB_IO == 1)
	{
		SPI_62TB_loop();	
	}
**/
}