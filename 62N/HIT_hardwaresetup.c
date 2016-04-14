#ifndef HITHARDWARESETUPC
#define HITHARDWARESETUPC
#include "iodefine.h"
#include "HIT_hardwaresetup.h"
#include "HIT_SPI.h"
void HIT_hardwaresetup()
{
	System_setup();
	Clock_setup();
	SCI_setup();
	CMT0_setup(); 
	//spi_Setup();     // SPI����
	//spi1_Setup();
	//Exinterrupt_setup();  //  �ⲿ�жϴ�����ʼ��
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
void CMT0_setup()    // ��ʼ��CMT0
{
	R_PG_Timer_Start_CMT_U0_C0();  
}
void System_setup()
{
	PORTE.DDR.BIT.B3 = 0X01;
	PORTE.DR.BIT.B3 = 0X01;
}

void Exinterrupt_setup()
{
	//R_PG_ExtInterrupt_Set_IRQ5();	
}
void GPT_setup()
{
	
}

#endif