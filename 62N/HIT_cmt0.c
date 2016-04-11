#include "iodefine.h"
//unsigned short HIT_oucnt = 0;
unsigned char ucTestSerial[2] = {0x55, 0xaa};
unsigned char ucRecSerial[2] = {0};
unsigned char ucRecLaser[2] = {0};
short HIT_SPIRX = 0;
void Cmt0IntFunc()
{
/*******    SCIÖÐ¶Ï    **************/
	//R_PG_SCI_StartSending_C6(ucTestSerial, 2);    /***  test for serial  ***/
	//serial_loop();	
	//laser_loop();
	shoucaoqi_loop();
	PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
	R_PG_SCI_StartSending_C6(ucTestSerial, 2);	
	R_PG_SCI_StartSending_C0(ucTestSerial, 2);
	R_PG_RSPI_TransferAllData_C0(ucTestSerial, ucRecSerial, 1);	
	R_PG_RSPI_TransferAllData_C1(ucTestSerial, ucRecLaser, 1);
}