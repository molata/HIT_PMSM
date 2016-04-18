#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
uchar ucSPI_sendTA = 0;        // 是否进行SPI发送的标志位
uchar ucSPI_sendTA_startCount = 0; // 开始进行SPI发数计数
uchar ucSPI_sendTA_count = 0;    // SPI发送的计数器
uchar ucSPI_sendTB = 0;        // 是否进行SPI发送的标志位
uchar ucSPI_sendTB_startCount = 0; // 开始进行SPI发数计数
uchar ucSPI_sendTB_count = 0;    // SPI发送的计数器

uchar uc62TA_fresh = 0;
uchar uc62TA_IO_history = 0;
uchar uc62TA_IO_Value = 0;
uchar uc62TB_fresh = 0;
uchar uc62TB_IO_history = 0;
uchar uc62TB_IO_Value = 0;
void Spi1IntFunc()
{
	if(RSPI1.SPSR.BIT.OVRF)
	{
		RSPI1.SPSR.BIT.OVRF = 0X00;
	}
	if(RSPI1.SPSR.BIT.MODF)
	{
		RSPI1.SPSR.BIT.MODF = 0X00;
	}	
}
void Cmt0IntFunc()   // 4us
{
	//serial_receive_loop();
	laser_receive_loop();
	/********************** 62TA发送指令 **************************/

	//if(uc62TA_IO != PORT5.DR.BIT.B4)
	uc62TA_IO_Value = PORT5.PORT.BIT.B4;
	if(ucSPI_sendTA_startCount == 1)
	{
		ucSPI_sendTA_count++;
		if(ucSPI_sendTA_count >= 8)  //接收中断后20us,发数
		{
			ucSPI_sendTA = 1;	
			ucSPI_sendTA_count = 0;
			ucSPI_sendTA_startCount = 0;
		}	
	}
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
		ucSPI_sendTA_startCount = 1;	
	}

	/********************** 62TB发送指令 **************************/
	uc62TB_IO_Value = PORTA.PORT.BIT.B0;
	if(ucSPI_sendTB_startCount == 1)
	{
		ucSPI_sendTB_count++;
		if(ucSPI_sendTB_count >= 12)  //接收中断后20us,发数
		{
			ucSPI_sendTB = 1;	
			ucSPI_sendTB_count = 0;
			ucSPI_sendTB_startCount = 0;
		}	
	}
	if(uc62TB_IO_Value != uc62TB_IO_history)
	{
		uc62TB_IO_history = uc62TB_IO_Value;
		uc62TB_fresh = 1;
	}
	else 
	{
		uc62TB_fresh = 0;	
	}
	if(uc62TB_fresh == 1 && uc62TB_IO_Value == 1)
	{
		ucSPI_sendTB_startCount = 1;	
	}
}