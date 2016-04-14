#include "iodefine.h"
#include "typedefine.h"
#include "Serial.h"
//unsigned short HIT_oucnt = 0;
unsigned char ucTestSerial[2] = {0xAA, 0x99};// 从波形上来看第一个字节是数组的最后一个数
unsigned char ucRecSerial[2] = {0};
unsigned char ucRecLaser[2] = {0};
short HIT_SPIRX = 0;
unsigned char over_run, mode_falt, parity_error;
/**** 用以测试的状态量 ****/
extern uchar ucShake_success;          // 握手是否成功的标志量
extern uint uiRec_bytes_num;
extern uchar ucSerial_rec_bytes[16];
extern ST_SERIAL_DECODE stSerial_decode;
unsigned char serial_Rec_Data;
extern unsigned char ucSerial_rec_bytes[16];
unsigned char ucBuffer_rec_bytes[16];
unsigned int serial_Rec_Count = 0;
unsigned char ucRec_Success = 0;
void Spi1IntFunc()
{
/****
	R_PG_RSPI_GetError_C1 ( &over_run, &mode_falt, &parity_error ); //Get error flags
	if( over_run || mode_falt)
	{
		RSPI1.SPSR.BIT.OVRF = 0X00;
		RSPI1.SPSR.BIT.MODF = 0X00;
		RSPI1.SPCR.BIT.SPE = 1;
	}
***/
	if(RSPI1.SPSR.BIT.OVRF)
	{
		RSPI1.SPSR.BIT.OVRF = 0X00;
	}
	if(RSPI1.SPSR.BIT.MODF)
	{
		RSPI1.SPSR.BIT.MODF = 0X00;
	}
		
}
void Sci6ReFunc()
{
	if(SCI6.SSR.BIT.FER)
	{
		SCI6.SSR.BIT.FER = 0;
	}
	if (SCI6.SSR.BIT.ORER)
	{
		SCI6.SSR.BIT.ORER = 0;
	}
}
void Sci6TrFunc()
{
}
void Sci6ErFunc()
{
	if(SCI6.SSR.BIT.FER)
	{
		SCI6.SSR.BIT.FER = 0;
	}
	if (SCI6.SSR.BIT.ORER)
	{
		SCI6.SSR.BIT.ORER = 0;
	}
} 
void Cmt0IntFunc()
{
	int iswape = 0;
	if(SCI6.SSR.BIT.RDRF == 1)
	{
		serial_Rec_Data = SCI6.RDR;
		SCI6.SSR.BIT.RDRF = 0;
		ucBuffer_rec_bytes[serial_Rec_Count] = serial_Rec_Data;
		serial_Rec_Count++;
		if (ucShake_success == 0)
		{
			if(serial_Rec_Count == 5)
			{
				for(iswape = 0; iswape < 5; iswape++)
				{
					ucSerial_rec_bytes[iswape] = ucBuffer_rec_bytes[iswape];
					ucRec_Success = 1;
				}
				serial_Rec_Count = 0;
				uiRec_bytes_num = 5;
			}
			
		}   // 握手未成功，只接收5个字节
		if (ucShake_success == 1)
		{
			if(serial_Rec_Count == 16)
			{
				for(iswape = 0; iswape < 16; iswape++)
				{
					ucSerial_rec_bytes[iswape] = ucBuffer_rec_bytes[iswape];
					ucRec_Success = 1;
				}
				serial_Rec_Count = 0;	
				uiRec_bytes_num = 16;
			}	
		}
	}
	{
	SCI6.SSR.BIT.ORER = 0;
	}
	SCI6.SCR.BIT.RE = 0X01;
	SCI6.SCR.BIT.RIE = 0X01;
}