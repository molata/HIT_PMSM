#include "iodefine.h"
void spi_Setup()
{
//////////////////////////////////////////////////////////////spi set/////////////////////////////////////////////
	SYSTEM.MSTPCRA.BIT.MSTPA28 = 1;//STOP DTC
	SYSTEM.MSTPCRB.BIT.MSTPB17 = 0;//ENABLE SPI
	RSPI0.SPCR.BIT.SPMS = 1;//3 XIAN MOSHI
	
	RSPI0.SPCR.BIT.MSTR = 1;//PDL_SCI_MODE_SYNC_MASTER   Masterģʽ�£������SPI_DI�����
	
	RSPI0.SPCR.BIT.TXMD = 0;//PDL_SPI_TRANSMIT_ONLY
	
	IOPORT.PFGSPI.BIT.RSPIS = 0;//PDL_SPI_PIN_A   
	IOPORT.PFGSPI.BIT.RSPCKE = 1;//PDL_SPI_PIN_RSPCK_ENABLE
	IOPORT.PFGSPI.BIT.MISOE = 1;
	IOPORT.PFGSPI.BIT.MOSIE = 1;
	
	RSPI0.SPPCR.BIT.MOIFV = 1; // ����ʱ���ź�����Ϊ�ߵ�ƽ
	RSPI0.SPPCR.BIT.MOIFE = 1;//PDL_SPI_PIN_MOSI_IDLE_LAST
	
	RSPI0.SPDCR.BIT.SPLW = 0;//PDL_SPI_BUFFER_128    20160403Ӧ�����ó��ֽڶ�ȡ������������
	
	RSPI0.SPSCR.BIT.SPSLN = 0;//PDL_SPI_FRAME_1_1
	
	RSPI0.SPCKD.BIT.SCKDL = 0;//1 ��RSPCK
	
	RSPI0.SSLND.BIT.SLNDL = 0;//PDL_SPI_SSL_DELAY_1
	
	RSPI0.SPND.BIT.SPNDL = 0;//PDL_SPI_NEXT_DELAY_1
	
	RSPI0.SPCMD0.BIT.BRDV = 0;//
	RSPI0.SPBR.BYTE = 0X13;//1M
	
	
	
	//////////////////////////////////
	RSPI0.SPSCR.BIT.SPSLN = 0;
	
	RSPI0.SPCMD0.BIT.CPHA = 1;//PDL_SPI_CLOCK_MODE_0
	RSPI0.SPCMD0.BIT.CPOL = 1;   // 20160403����ʱ���óɸߵ�ƽ��Ч CPOLΪ1
	
	RSPI0.SPCMD0.BIT.BRDV = 0;//PDL_SPI_DIV_1
	
	RSPI0.SPCMD0.BIT.SPB = 0X0F;//4;//PDL_SPI_LENGTH_16�� 20160403���ֽڳ������ó�8λ
	RSPI0.SPCMD0.BIT.LSBF = 0;//PDL_SPI_MSB_FIRST
	
	RSPI0.SPCR.BIT.SPE = 1;
//////////////////////////////////////////////////////////////spi set end//////////////////////////////////////////	

}
void spi1_Setup()
{
	//////////////////////////////////////////////////////////////spi set/////////////////////////////////////////////
	SYSTEM.MSTPCRA.BIT.MSTPA28 = 1;//STOP DTC
	SYSTEM.MSTPCRB.BIT.MSTPB16 = 0;//ENABLE SPI
	RSPI1.SPCR.BIT.SPMS = 1;//3 XIAN MOSHI
	
	RSPI1.SPCR.BIT.MSTR = 1;//PDL_SCI_MODE_SYNC_MASTER   Masterģʽ�£������SPI_DI�����
	
	RSPI1.SPCR.BIT.TXMD = 0;//PDL_SPI_TRANSMIT_ONLY
	
	//IOPORT.PFHSPI.BIT.RSPIS = 0;//PDL_SPI_PIN_A
	IOPORT.PFHSPI.BIT.RSPIS = 1;
	IOPORT.PFHSPI.BIT.RSPCKE = 1;//PDL_SPI_PIN_RSPCK_ENABLE
	IOPORT.PFHSPI.BIT.MISOE = 1;
	IOPORT.PFHSPI.BIT.MOSIE = 1;
	
	RSPI1.SPPCR.BIT.MOIFV = 1; // ����ʱ���ź�����Ϊ�ߵ�ƽ
	RSPI1.SPPCR.BIT.MOIFE = 1;//PDL_SPI_PIN_MOSI_IDLE_LAST
	
	RSPI1.SPDCR.BIT.SPLW = 0;//PDL_SPI_BUFFER_128    20160403Ӧ�����ó��ֽڶ�ȡ������������
	
	RSPI1.SPSCR.BIT.SPSLN = 0;//PDL_SPI_FRAME_1_1
	
	RSPI1.SPCKD.BIT.SCKDL = 0;//1 ��RSPCK
	
	RSPI1.SSLND.BIT.SLNDL = 0;//PDL_SPI_SSL_DELAY_1
	
	RSPI1.SPND.BIT.SPNDL = 0;//PDL_SPI_NEXT_DELAY_1
	
	RSPI1.SPCMD0.BIT.BRDV = 0;//
	RSPI1.SPBR.BYTE = 0X13;//1M
	
	
	
	//////////////////////////////////
	RSPI1.SPSCR.BIT.SPSLN = 0;
	
	RSPI1.SPCMD0.BIT.CPHA = 1;//PDL_SPI_CLOCK_MODE_0
	RSPI1.SPCMD0.BIT.CPOL = 1;   // 20160403����ʱ���óɸߵ�ƽ��Ч CPOLΪ1
	
	RSPI1.SPCMD0.BIT.BRDV = 0;//PDL_SPI_DIV_1
	
	RSPI1.SPCMD0.BIT.SPB = 0X0F;//4;//PDL_SPI_LENGTH_16�� 20160403���ֽڳ������ó�8λ
	RSPI1.SPCMD0.BIT.LSBF = 0;//PDL_SPI_MSB_FIRST
	
	RSPI1.SPCR.BIT.SPE = 1;
//////////////////////////////////////////////////////////////spi set end//////////////////////////////////////////	
}

void TAloop()
{
	
}