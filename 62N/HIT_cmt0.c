#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
/********* SPI发送相关的数据结构 ***************/
uchar ucSPI_sendTA = 0;        // 是否进行SPI发送的标志位
uchar ucSPI_sendTA_startCount = 0; // 开始进行SPI发数计数
uchar ucSPI_sendTA_count = 0;    // SPI发送的计数器
uchar ucSPI_sendTB = 0;        // 是否进行SPI发送的标志位
uchar ucSPI_sendTB_startCount = 0; // 开始进行SPI发数计数
uchar ucSPI_sendTB_count = 0;    // SPI发送的计数器
/********** 和IO使能检测相关的数据结构 **************/
uchar uc62TA_fresh = 0;       // IO是否发生了更新
uchar uc62TA_IO_history = 0;  // IO的历史记录，用来比较最新的检测值有没有更新
uchar uc62TA_IO_Value = 0;    // 转接寄存器中的数据
uchar uc62TB_fresh = 0;       
uchar uc62TB_IO_history = 0;
uchar uc62TB_IO_Value = 0;
/************** 串口发送周期相关的数据结构 *********/
uchar ucLaser_send_time_count = 0;    // 激光板发送的时钟计数，控制在50us发送一次
uchar ucSerial_send_time_count = 0;   // 串口发送的时钟计数，目标控制在50us发送一次

unsigned int ucCmtCount = 0;
unsigned char ucSend_byte = 0;
unsigned char ucSerial_send_data[16] = {0x55, 0XAA, 0x16, 0X01, 0x00, 0X00, 0x02, 0X03, 0x00, 0X01, 0X01, 0X02, 0x12, 0X13, 0x00, 0Xff};
unsigned int uiSerial_send_len = 16;
unsigned int uiSerial_send_count = 0;
unsigned int uiByte_count = 0;
unsigned char ucSend_flag = 0;

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

void Cmt0IntFunc()   // 5us
{
	//serial_receive_loop();
	//if(ucSerial_send_time_count >= 9)  // 50us发送一个BITE，不同的波特率需要实际去测量
	{
		//serial_send_loop();	
		//ucSerial_send_time_count = 0;
	}
	//ucSerial_send_time_count++;
	
	//laser_receive_loop();

	if(ucLaser_send_time_count >= 9)     // 50us
	{
		//laser_send_loop();
		ucSend_flag = 1;
		ucLaser_send_time_count = 0;
	}
	ucLaser_send_time_count++;

	/********************** 62TA发送指令 **************************/
/***
	uc62TA_IO_Value = PORT5.PORT.BIT.B4;   // 直接从寄存器中读取使能信号
	if(ucSPI_sendTA_startCount == 1)
	{
		ucSPI_sendTA_count++;         // 将4us，作为时钟进行计数
		if(ucSPI_sendTA_count >= 6)  //接收中断后20us,发数
		{
			ucSPI_sendTA = 1;	      // 将SPI寄存器中的数通过同步模式发送出去
			ucSPI_sendTA_count = 0;   // 进入下一个发送周期
			ucSPI_sendTA_startCount = 0;
		}	
	}
	if(uc62TA_IO_Value != uc62TA_IO_history)  // 从history记录是否IO信号发生了变化
	{
		uc62TA_IO_history = uc62TA_IO_Value;    
		uc62TA_fresh = 1;                     // IO信号更新了，将更新的信号放入历史中
	}
	else 
	{
		uc62TA_fresh = 0;	
	}
	if(uc62TA_fresh == 1 && uc62TA_IO_Value == 1)   // 仅当当前信号发生变化，且是上升沿信号，进行计数
	{
		ucSPI_sendTA_startCount = 1;	
	}
***/
	/********************** 62TB发送指令 **************************/
/****
	uc62TB_IO_Value = PORTA.PORT.BIT.B0;              // 因为全局变量的原因，函数重新写了一遍，后期注意通过指针的形式，避免函数的copy
	if(ucSPI_sendTB_startCount == 1)
	{
		ucSPI_sendTB_count++;
		if(ucSPI_sendTB_count >= 8)  //接收中断后20us,发数
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
***/


/*************** for test ********************/
	if(ucSend_flag == 1)
	{
		//R_PG_SCI_StartSending_C6(ucSerial_send_data, 3);
		ucSend_byte = ucSerial_send_data[uiSerial_send_count];
		SCI6.TDR  = ucSend_byte;
		SCI6.SCR.BIT.TE = 0X01;        // 这个地方需要把东西放进去
		SCI6.SCR.BIT.TIE = 0X01;
		uiSerial_send_count++;
		if(uiSerial_send_count >= uiSerial_send_len)
		{
			uiSerial_send_count = 0;
			ucSend_flag = 0;	
		}
		ucSend_flag = 0;
	}
}