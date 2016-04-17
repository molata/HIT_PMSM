#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"

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
void Cmt0IntFunc()   // 4us
{
	//serial_receive_loop();
	//laser_receive_loop();
}