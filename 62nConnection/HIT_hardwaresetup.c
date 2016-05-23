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
	SCI0.SCR.BYTE = SCI0.SCR.BYTE & 0XCF;               // ͬʱ�ر�TE��RE
	SCI0.SCR.BYTE = SCI0.SCR.BYTE | 0X30;               // ͬʱ��TE��RE
	SCI0.SCR.BIT.RIE = 0X01;   
	ICU.IER[0x1A].BIT.IEN7 = 1;                         // allow ICU0 rxi interrupt              
	ICU.IER[0x1B].BIT.IEN0 = 1;                         // allow ICU0 rxi interrupt 
	ICU.IER[0x1B].BIT.IEN1 = 1;                         // allow ICU0 rxi interrupt 
	
	R_PG_SCI_Set_C5();
	
	R_PG_SCI_Set_C6();   
	SCI6.SCR.BYTE = SCI6.SCR.BYTE & 0XCF;              // ͬʱ�ر�TE��RE
	SCI6.SCR.BYTE = SCI6.SCR.BYTE | 0X30;              // ͬʱ��TE��RE
	SCI6.SCR.BIT.RIE = 0X01; 
	ICU.IER[0x1D].BIT.IEN7 = 1;                         // allow ICU0 rxi interrupt  
	ICU.IER[0x1E].BIT.IEN0 = 1;                         // allow TXI rxi interrupt  
	ICU.IER[0x1E].BIT.IEN1 = 1;                         // allow TEIE rxi interrupt  
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
/**** Port54 for 62TA ʹ���źŶ� *****/
	PORT5.DDR.BIT.B4 = 0x00;   // ����ģʽ
	PORT5.ICR.BIT.B4 = 0X01;   // �����ʹ�� 
/**** PortA0 for 62TB ʹ���źŶ� *****/
	PORTA.DDR.BIT.B0 = 0x00;   // ����ģʽ
	PORTA.ICR.BIT.B0 = 0X01;   // �����ʹ�� 
}

#endif