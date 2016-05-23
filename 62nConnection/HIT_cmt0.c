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
/***************** 串口发送相关 ********************/
uchar ucLaser_send_time = 0;
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
void Cmt0IntFunc()   // 10us
{
	
	/********************** 62TA发送指令 **************************/
	uc62TA_IO_Value = PORT5.PORT.BIT.B4;              // 检测外部触发
	if(uc62TA_IO_Value != uc62TA_IO_history && uc62TA_IO_Value == 0x01)
	{
		ucSPI_sendTA = 1;
		
	}
	if(uc62TA_IO_Value != uc62TA_IO_history)
	{
		uc62TA_IO_history = uc62TA_IO_Value;	
	}

	/********************** 62TB发送指令 **************************/
	uc62TB_IO_Value = PORTA.PORT.BIT.B0;
	if(uc62TB_IO_Value != uc62TB_IO_history && uc62TB_IO_Value == 0x01)
	{
		ucSPI_sendTB = 1;
		
	}
	if(uc62TB_IO_Value != uc62TB_IO_history)
	{
		uc62TB_IO_history = uc62TB_IO_Value;	
	}

}