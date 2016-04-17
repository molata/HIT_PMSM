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
	spi_Setup();     // SPI����
	spi1_Setup();
}

void SCI_setup()    //��ʼ��SCI
{
	R_PG_SCI_Set_C0();
	R_PG_SCI_Set_C5();
	R_PG_SCI_Set_C6();   
}
void Clock_setup()   //��ʼ��ʱ��
{
	R_PG_Clock_Set();
	
}
void CMT_setup()    // ��ʼ��CMT0
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