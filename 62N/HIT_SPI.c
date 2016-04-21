#ifndef HITSPIC
#define HITSPIC
#include "iodefine.h"
#include "typedefine.h"
#include "HIT_common.h"
#include "HIT_SPI.h"
extern ST_SERIAL_DATA stSerial_data;     // �ڲ�״̬�ṹ��
extern ST_PC_CMD st_pc_cmd;              //������ָ��ṹ�壬���ڻ�����λ����ָ��
ushort us62TA_send_data = 0;     // ��62TA��������
ushort us62TA_rec_data = 0;      // ����62TA�ĽǶ�����
ushort us62TA_rec_history = 0;      // ����62TA�ĽǶ�����
ushort us62TB_send_data = 0;     // ��62TB��������
ushort us62TB_rec_data = 0;      // ����62TB�ĽǶ�����
ushort us62TB_rec_history = 0;      // ����62Tb�ĽǶ�����
ushort usTemp_PCA_cmd = 0;
ushort usTemp_PCB_cmd = 0;
unsigned char ucTestSerial[2] = {0x55, 0xaa};

uchar ucSPI_62TA_cmd = 0;             // SPI��ѯ״̬
uchar ucSPI_62TB_cmd = 0;  
uchar ucSPI_Check_count = 0;           
void SPI_62TA_loop()
{
	if(ucSPI_62TA_cmd == SPI_CHECK_62T)  // ��62T���Ͳ�ѯָ��
	{
		us62TA_send_data = 0xFFFF;
		//if(ucSPI_Check_count > 10)
		//{
			R_PG_RSPI_TransferAllData_C0(&us62TA_send_data, &us62TA_rec_history, 1);    // ������λ��ָ��
			if((us62TA_rec_history >> 14) == (0x000F >> 2))
			{
				us62TA_rec_data = us62TA_rec_history - (0x000F << 14);   // �����ݽ�����
				stSerial_data.elevation_deg = ((float)us62TA_rec_data - 1800) / 100;
			}
			else if((us62TA_rec_history >> 14) == 0X0000)
			{
				us62TA_rec_data = us62TA_rec_history;
				stSerial_data.elevation_view_deg_speed = ((float)us62TA_rec_data - 6000) / 1000;
			}
			
			us62TA_rec_history = us62TA_rec_data;
			//stSerial_data.elevation_deg = ((float)(us62TA_rec_data) - 1800)/ 100;     // ���½Ƕ�ֵ
		//}
	}
	else if (ucSPI_62TA_cmd == SPI_SEND_CMD)
	{
		
		us62TA_send_data = (short)(st_pc_cmd.fpPitchDeg * 100 + 1800);   // ����Э��ķ�ʽ����
		R_PG_RSPI_TransferAllData_C0(&us62TA_send_data, &us62TA_rec_data, 1);    // ������λ��ָ��
		usTemp_PCA_cmd++;
		if(usTemp_PCA_cmd == 5)
		{
			ucSPI_62TA_cmd = SPI_SEND_CMD;
			usTemp_PCA_cmd = 0;	
		}
	}


	if(RSPI0.SPSR.BIT.OVRF == 1)
	{
		RSPI0.SPSR.BIT.OVRF = 0;
	 }
	if(RSPI0.SPSR.BIT.MODF == 1)
	{
		RSPI0.SPSR.BIT.MODF = 0;
	 }
}

void SPI_62TB_loop()
{
	if(ucSPI_62TB_cmd == SPI_CHECK_62T)  // ��62T���Ͳ�ѯָ��
	{
			//us62TB_send_data = usTemp_PCB_cmd;   // ������������
			us62TB_send_data = 0xFFFF;
			//PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
			R_PG_RSPI_TransferAllData_C1(&us62TB_send_data, &us62TB_rec_history, 1);    // ������λ��ָ��
			if((us62TB_rec_history >> 14) == (0x000F >> 2))
			{
				us62TB_rec_data = us62TB_rec_history - (0x000F << 14);   // �����ݽ�����
				stSerial_data.elevation_deg = ((float)us62TB_rec_data - 1800) / 100;
			}
			else if((us62TB_rec_history >> 14) == 0X0000)
			{
				us62TB_rec_data = us62TB_rec_history;
				stSerial_data.elevation_view_deg_speed = ((float)us62TA_rec_data - 6000) / 1000;
			}
			us62TB_rec_history = us62TB_rec_data;
	}
	else if (ucSPI_62TB_cmd == SPI_SEND_CMD)
	{
		us62TB_send_data = (short)(st_pc_cmd.fpSailDeg * 100 + 1800);   // ����Э��ķ�ʽ����
		R_PG_RSPI_TransferAllData_C1(&us62TB_send_data, &us62TB_rec_data, 1);    // ������λ��ָ��
		usTemp_PCB_cmd++;
		if(usTemp_PCB_cmd == 5)
		{
			ucSPI_62TB_cmd = SPI_SEND_CMD;
			usTemp_PCB_cmd = 0;	
		}
	}


	if(RSPI1.SPSR.BIT.OVRF == 1)
	{
		RSPI1.SPSR.BIT.OVRF = 0;
	 }
	if(RSPI1.SPSR.BIT.MODF == 1)
	{
		RSPI1.SPSR.BIT.MODF = 0;
	 }
}

void spi_Setup()
{
	R_PG_RSPI_Set_C0();
	R_PG_RSPI_SetCommand_C0();
	RSPI0.SPCR.BIT.SPE = 1;
}

void spi1_Setup()
{
	IOPORT.PFHSPI.BIT.RSPIS = 1;
	R_PG_RSPI_Set_C1();
	IOPORT.PFHSPI.BIT.RSPIS = 1;
	R_PG_RSPI_SetCommand_C1();
	IOPORT.PFHSPI.BIT.RSPIS = 1;
	RSPI1.SPCR.BIT.SPE = 1;
	PORTE.ICR.BIT.B7 = 0X01;
	PORTE.ICR.BIT.B6 = 0X01;
	PORTE.ICR.BIT.B5 = 0X01;
}

#endif