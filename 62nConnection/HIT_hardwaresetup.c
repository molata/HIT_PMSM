#ifndef HITHARDWARESETUPC
#define HITHARDWARESETUPC
#include "iodefine.h"
#include "HIT_hardwaresetup.h"
//#include "HIT_SPI.h"
void HIT_hardwaresetup()
{
	System_setup();
	Clock_setup();
	SCI_setup();
	CMT_setup(); 
	spi_Setup();     // SPI启动
	spi1_Setup();
}

void SCI_setup()    //初始化SCI
{
	R_PG_SCI_Set_C0();
	SCI0.SCR.BYTE = SCI0.SCR.BYTE & 0XCF;
	SCI0.SCR.BYTE = SCI0.SCR.BYTE | 0X30;
	
	R_PG_SCI_Set_C5();
	
	R_PG_SCI_Set_C6();   
	SCI6.SCR.BYTE = SCI6.SCR.BYTE & 0XCF;
	SCI6.SCR.BYTE = SCI6.SCR.BYTE | 0X30;
}
void Clock_setup()   //初始化时钟
{
	R_PG_Clock_Set();
	
}
void CMT_setup()    // 初始化CMT0
{
	R_PG_Timer_Start_CMT_U0_C0();  
	R_PG_Timer_Start_CMT_U0_C1();
}
void System_setup()
{
	PORTE.DDR.BIT.B3 = 0X01;
	PORTE.DR.BIT.B3 = 0X01;
/**** Port54 for 62TA 使能信号端 *****/
	PORT5.DDR.BIT.B4 = 0x00;   // 输入模式
	PORT5.ICR.BIT.B4 = 0X01;   // 输入口使能 
/**** PortA0 for 62TB 使能信号端 *****/
	PORTA.DDR.BIT.B0 = 0x00;   // 输入模式
	PORTA.ICR.BIT.B0 = 0X01;   // 输入口使能 
}

#endif