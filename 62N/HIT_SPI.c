#ifndef HITSPIC
#define HITSPIC
#include "iodefine.h"
#include "typedefine.h"
#include "HIT_common.h"
#include "HIT_SPI.h"
extern ST_SERIAL_DATA stSerial_data;     // 内部状态结构体
extern ST_PC_CMD st_pc_cmd;              //计算器指令结构体，用于缓冲上位机的指令
ushort us62TA_send_data = 0;     // 向62TA发送命令
ushort us62TA_rec_data = 0;      // 接收62TA的角度数据
ushort us62TA_rec_history = 0;      // 接收62TA的角度数据
ushort us62TB_send_data = 0;     // 向62TB发送命令
ushort us62TB_rec_data = 0;      // 接收62TB的角度数据
ushort us62TB_rec_history = 0;      // 接收62Tb的角度数据
ushort usTemp_PCA_cmd = 0;
ushort usTemp_PCB_cmd = 0;
unsigned char ucTestSerial[2] = {0x55, 0xaa};

uchar ucSPI_62TA_cmd = 0;             // SPI查询状态
uchar ucSPI_62TB_cmd = 0;  
uchar ucSPI_Check_count = 0;           
void SPI_62TA_loop()
{
	if(ucSPI_62TA_cmd == SPI_CHECK_62T)  // 向62T发送查询指令
	{
		us62TA_send_data = 0x55AA;
		//if(ucSPI_Check_count > 10)
		//{
			//us62TA_send_data = usTemp_PCA_cmd;   // 仅仅用来测试
			R_PG_RSPI_TransferAllData_C0(&us62TA_send_data, &us62TA_rec_data, 1);    // 发送上位机指令
			if(us62TA_rec_history != us62TA_rec_data)
			{
					
			}
			usTemp_PCA_cmd++;
			us62TA_rec_history = us62TA_rec_data;
			stSerial_data.elevation_deg = ((float)(us62TA_rec_data) - 1800)/ 100;     // 更新角度值
		//}
		
	}
	else if (ucSPI_62TA_cmd == SPI_SEND_CMD)
	{
		us62TA_send_data = (short)(st_pc_cmd.fpPitchDeg * 100 + 1800);   // 按照协议的方式发送
		R_PG_RSPI_TransferAllData_C0(&us62TA_send_data, &us62TA_rec_data, 1);    // 发送上位机指令
		ucSPI_62TA_cmd = SPI_CHECK_62T;
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
	if(ucSPI_62TB_cmd == SPI_CHECK_62T)  // 向62T发送查询指令
	{
			//us62TB_send_data = usTemp_PCB_cmd;   // 仅仅用来测试
			us62TB_send_data = 0x55AA;
			//PORTE.DR.BIT.B3 = !PORTE.DR.BIT.B3;
			R_PG_RSPI_TransferAllData_C1(&us62TB_send_data, &us62TB_rec_data, 1);    // 发送上位机指令
			if(us62TB_rec_history != us62TB_rec_data)
			{
					
			}
			usTemp_PCB_cmd++;
			us62TB_rec_history = us62TB_rec_data;
			stSerial_data.elevation_deg = ((float)(us62TB_rec_data) - 1800)/ 100;     // 更新角度值
	}
	else if (ucSPI_62TB_cmd == SPI_SEND_CMD)
	{
		us62TB_send_data = (short)(st_pc_cmd.fpSailDeg * 100 + 1800);   // 按照协议的方式发送
		R_PG_RSPI_TransferAllData_C1(&us62TB_send_data, &us62TB_rec_data, 1);    // 发送上位机指令
		ucSPI_62TB_cmd = SPI_CHECK_62T;
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
}

#endif