#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
extern uchar ucSPI_sendTA;  
extern uchar ucSPI_sendTB;  
void Cmt1IntFunc()   // 50us
{
	serial_loop();                // ��Ӧ��λ���ĳ��򣬴�����ַ���ָ��
	laser_loop();                 // ��Ӧ�����ĳ��򣬴�����ַ���ָ��
	SCI0CheckError();             // SCI0�������
	SCI6CheckError();             // SCI6�������
/***** SPI���պͷ��� ********/

	if(ucSPI_sendTA == 1)         // SPI����ָ��յ�1��ʱ�򣬷���SPI����
	{
		SPI_62TA_loop();          
		ucSPI_sendTA = 0;	      // reset
	}
/***** SPI���պͷ��� ********/

	if(ucSPI_sendTB == 1)
	{
		SPI_62TB_loop();
		ucSPI_sendTB = 0;	
	}

}