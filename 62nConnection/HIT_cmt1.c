#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
extern uchar ucSPI_sendTA;  
extern uchar ucSPI_sendTB;  
void Cmt1IntFunc()   // 50us
{
	serial_loop();                // 响应上位机的程序，处理各种发送指令
	laser_loop();                 // 响应激光板的程序，处理各种发送指令
	SCI0CheckError();             // SCI0清除错误
	SCI6CheckError();             // SCI6清除错误
/***** SPI接收和发送 ********/

	if(ucSPI_sendTA == 1)         // SPI发送指令，收到1的时候，发送SPI数据
	{
		SPI_62TA_loop();          
		ucSPI_sendTA = 0;	      // reset
	}
/***** SPI接收和发送 ********/

	if(ucSPI_sendTB == 1)
	{
		SPI_62TB_loop();
		ucSPI_sendTB = 0;	
	}

}