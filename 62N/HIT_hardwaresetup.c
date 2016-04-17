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
	R_PG_SCI_Set_C5();
	R_PG_SCI_Set_C6();   
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
}

#endif