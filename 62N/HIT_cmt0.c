#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
/********* SPI������ص����ݽṹ ***************/
uchar ucSPI_sendTA = 0;        // �Ƿ����SPI���͵ı�־λ
uchar ucSPI_sendTA_startCount = 0; // ��ʼ����SPI��������
uchar ucSPI_sendTA_count = 0;    // SPI���͵ļ�����
uchar ucSPI_sendTB = 0;        // �Ƿ����SPI���͵ı�־λ
uchar ucSPI_sendTB_startCount = 0; // ��ʼ����SPI��������
uchar ucSPI_sendTB_count = 0;    // SPI���͵ļ�����
/********** ��IOʹ�ܼ����ص����ݽṹ **************/
uchar uc62TA_fresh = 0;       // IO�Ƿ����˸���
uchar uc62TA_IO_history = 0;  // IO����ʷ��¼�������Ƚ����µļ��ֵ��û�и���
uchar uc62TA_IO_Value = 0;    // ת�ӼĴ����е�����
uchar uc62TB_fresh = 0;       
uchar uc62TB_IO_history = 0;
uchar uc62TB_IO_Value = 0;
/************** ���ڷ���������ص����ݽṹ *********/
uchar ucLaser_send_time_count = 0;    // ����巢�͵�ʱ�Ӽ�����������50us����һ��
uchar ucSerial_send_time_count = 0;   // ���ڷ��͵�ʱ�Ӽ�����Ŀ�������50us����һ��

unsigned int ucCmtCount = 0;
unsigned char ucSend_byte = 0;
unsigned char ucSerial_send_data[16] = {0x55, 0XAA, 0x16, 0X01, 0x00, 0X00, 0x02, 0X03, 0x00, 0X01, 0X01, 0X02, 0x12, 0X13, 0x00, 0Xff};
unsigned int uiSerial_send_len = 16;
unsigned int uiSerial_send_count = 0;
unsigned int uiByte_count = 0;
unsigned char ucSend_flag = 0;

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

void Cmt0IntFunc()   // 5us
{
	//serial_receive_loop();
	//if(ucSerial_send_time_count >= 9)  // 50us����һ��BITE����ͬ�Ĳ�������Ҫʵ��ȥ����
	{
		//serial_send_loop();	
		//ucSerial_send_time_count = 0;
	}
	//ucSerial_send_time_count++;
	
	//laser_receive_loop();

	if(ucLaser_send_time_count >= 9)     // 50us
	{
		//laser_send_loop();
		ucSend_flag = 1;
		ucLaser_send_time_count = 0;
	}
	ucLaser_send_time_count++;

	/********************** 62TA����ָ�� **************************/
/***
	uc62TA_IO_Value = PORT5.PORT.BIT.B4;   // ֱ�ӴӼĴ����ж�ȡʹ���ź�
	if(ucSPI_sendTA_startCount == 1)
	{
		ucSPI_sendTA_count++;         // ��4us����Ϊʱ�ӽ��м���
		if(ucSPI_sendTA_count >= 6)  //�����жϺ�20us,����
		{
			ucSPI_sendTA = 1;	      // ��SPI�Ĵ����е���ͨ��ͬ��ģʽ���ͳ�ȥ
			ucSPI_sendTA_count = 0;   // ������һ����������
			ucSPI_sendTA_startCount = 0;
		}	
	}
	if(uc62TA_IO_Value != uc62TA_IO_history)  // ��history��¼�Ƿ�IO�źŷ����˱仯
	{
		uc62TA_IO_history = uc62TA_IO_Value;    
		uc62TA_fresh = 1;                     // IO�źŸ����ˣ������µ��źŷ�����ʷ��
	}
	else 
	{
		uc62TA_fresh = 0;	
	}
	if(uc62TA_fresh == 1 && uc62TA_IO_Value == 1)   // ������ǰ�źŷ����仯�������������źţ����м���
	{
		ucSPI_sendTA_startCount = 1;	
	}
***/
	/********************** 62TB����ָ�� **************************/
/****
	uc62TB_IO_Value = PORTA.PORT.BIT.B0;              // ��Ϊȫ�ֱ�����ԭ�򣬺�������д��һ�飬����ע��ͨ��ָ�����ʽ�����⺯����copy
	if(ucSPI_sendTB_startCount == 1)
	{
		ucSPI_sendTB_count++;
		if(ucSPI_sendTB_count >= 8)  //�����жϺ�20us,����
		{
			ucSPI_sendTB = 1;	
			ucSPI_sendTB_count = 0;
			ucSPI_sendTB_startCount = 0;
		}	
	}
	if(uc62TB_IO_Value != uc62TB_IO_history)
	{
		uc62TB_IO_history = uc62TB_IO_Value;
		uc62TB_fresh = 1;
	}
	else 
	{
		uc62TB_fresh = 0;	
	}
	if(uc62TB_fresh == 1 && uc62TB_IO_Value == 1)
	{
		ucSPI_sendTB_startCount = 1;	
	}
***/


/*************** for test ********************/
	if(ucSend_flag == 1)
	{
		//R_PG_SCI_StartSending_C6(ucSerial_send_data, 3);
		ucSend_byte = ucSerial_send_data[uiSerial_send_count];
		SCI6.TDR  = ucSend_byte;
		SCI6.SCR.BIT.TE = 0X01;        // ����ط���Ҫ�Ѷ����Ž�ȥ
		SCI6.SCR.BIT.TIE = 0X01;
		uiSerial_send_count++;
		if(uiSerial_send_count >= uiSerial_send_len)
		{
			uiSerial_send_count = 0;
			ucSend_flag = 0;	
		}
		ucSend_flag = 0;
	}
}