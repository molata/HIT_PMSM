#include "iodefine.h"
//unsigned short HIT_oucnt = 0;
unsigned char ucTestSerial[2] = {0xAA, 0x99};// 从波形上来看第一个字节是数组的最后一个数
unsigned char ucRecSerial[2] = {0};
unsigned char ucRecLaser[2] = {0};
short HIT_SPIRX = 0;
unsigned char over_run, mode_falt, parity_error;
void Spi1IntFunc()
{
/****
	R_PG_RSPI_GetError_C1 ( &over_run, &mode_falt, &parity_error ); //Get error flags
	if( over_run || mode_falt)
	{
		RSPI1.SPSR.BIT.OVRF = 0X00;
		RSPI1.SPSR.BIT.MODF = 0X00;
		RSPI1.SPCR.BIT.SPE = 1;
	}
***/
	if(RSPI1.SPSR.BIT.OVRF)
	{
		RSPI1.SPSR.BIT.OVRF = 0X00;
	}
	if(RSPI1.SPSR.BIT.MODF)
	{
		RSPI1.SPSR.BIT.MODF = 0X00;
	}
		
}
void Cmt0IntFunc()
{
/*******    SCI中断    **************/
	//R_PG_SCI_StartSending_C6(ucTestSerial, 2);    /***  test for serial  ***/
	serial_loop();	
	//laser_loop();
/***
	R_PG_RSPI_TransferAllData_C0(ucTestSerial, ucRecSerial, 1);	
	R_PG_RSPI_StartTransfer_C1(ucTestSerial, ucRecLaser, 1);
	if(ucRecLaser[0] == 0x55)
	{
		shoucaoqi_loop();
		PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
		R_PG_SCI_StartSending_C6(ucTestSerial, 2);	
		R_PG_SCI_StartSending_C0(ucTestSerial, 2);
		HIT_SPIRX = 1;
	}
	else if(ucRecLaser[1] == 0x55)
	{
		shoucaoqi_loop();
		PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
		R_PG_SCI_StartSending_C6(ucTestSerial, 2);	
		R_PG_SCI_StartSending_C0(ucTestSerial, 2);
		HIT_SPIRX = 1;
	}
***/	
}