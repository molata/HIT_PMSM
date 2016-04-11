#include "iodefine.h"
unsigned short HIT_ceshi = 0;
void Cmt0IntFunc()
{
/*******    SCIÖÐ¶Ï    **************/
	serial_loop();	
//	HIT_ceshi++;
	PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
}