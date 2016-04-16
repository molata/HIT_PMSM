#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
void Cmt1IntFunc()   // 50us
{
	serial_loop();
	laser_loop();
	SPI_62TA_loop();
	SPI_62TB_loop();
	PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
}