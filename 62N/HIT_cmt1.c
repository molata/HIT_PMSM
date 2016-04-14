#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
extern unsigned char ucRec_Success;
extern ST_SERIAL_DECODE stSerial_decode;
extern uint uiRec_bytes_num;
extern unsigned char ucSerial_rec_bytes[16];
void Cmt1IntFunc()
{
	if(ucRec_Success == 1)
	{
		serial_decode(ucSerial_rec_bytes, &stSerial_decode, uiRec_bytes_num, 0);
		ucRec_Success = 0;
	}
	
}