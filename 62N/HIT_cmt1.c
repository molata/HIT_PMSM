#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
extern uchar ucSPI_sendTA;  
void Cmt1IntFunc()   // 50us
{
	serial_loop();
	laser_loop();
	//SPI_62TB_loop();
	PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
	if(ucSPI_sendTA == 1)
	{
		SPI_62TA_loop();
		ucSPI_sendTA = 0;	
	}

}