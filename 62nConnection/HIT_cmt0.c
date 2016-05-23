#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
uchar ucSPI_sendTA = 0;        // �Ƿ����SPI���͵ı�־λ
uchar ucSPI_sendTA_startCount = 0; // ��ʼ����SPI��������
uchar ucSPI_sendTA_count = 0;    // SPI���͵ļ�����
uchar ucSPI_sendTB = 0;        // �Ƿ����SPI���͵ı�־λ
uchar ucSPI_sendTB_startCount = 0; // ��ʼ����SPI��������
uchar ucSPI_sendTB_count = 0;    // SPI���͵ļ�����

uchar uc62TA_fresh = 0;
uchar uc62TA_IO_history = 0;
uchar uc62TA_IO_Value = 0;
uchar uc62TB_fresh = 0;
uchar uc62TB_IO_history = 0;
uchar uc62TB_IO_Value = 0;
/***************** ���ڷ������ ********************/
uchar ucLaser_send_time = 0;
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
void Cmt0IntFunc()   // 10us
{
	
	/********************** 62TA����ָ�� **************************/
	uc62TA_IO_Value = PORT5.PORT.BIT.B4;              // ����ⲿ����
	if(uc62TA_IO_Value != uc62TA_IO_history && uc62TA_IO_Value == 0x01)
	{
		ucSPI_sendTA = 1;
		
	}
	if(uc62TA_IO_Value != uc62TA_IO_history)
	{
		uc62TA_IO_history = uc62TA_IO_Value;	
	}

	/********************** 62TB����ָ�� **************************/
	uc62TB_IO_Value = PORTA.PORT.BIT.B0;
	if(uc62TB_IO_Value != uc62TB_IO_history && uc62TB_IO_Value == 0x01)
	{
		ucSPI_sendTB = 1;
		
	}
	if(uc62TB_IO_Value != uc62TB_IO_history)
	{
		uc62TB_IO_history = uc62TB_IO_Value;	
	}

}