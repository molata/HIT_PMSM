#include "Serial.h"
#include "iodefine.h"
#include "HIT_common.h"
#include <string.h>
#include "HIT_SPI.h"
/****************** 207程序通信相关 ********************************/
extern UNSENSOR_STATES unAllsensor_states;   // 内部所有传感器的状态
extern uchar ucSPI_62TB_cmd;                 // 决定是否要发命令给62TA
extern uchar ucSPI_62TA_cmd;                // 决定是否要发送命令62TB

/**************** 上位机接收相关的数据结构 ********************/
ST_SERIAL_DECODE stSerial_decode;     //解析上位机的结构体 
extern ST_PC_CMD st_pc_cmd;              //计算器指令结构体，用于缓冲上位机的指令
uchar ucSerial_rec_bytes[16] = {0};    //从上位机获取的握手信息
uchar ucSerial_buffer_rec_bytes[16] = {0};    //串口接收的缓冲数组
uint u32Error_count = 0;              // 错误计数
uchar ucShake_success = 0;       // serial receive Loop status
uchar ucSerial_rec_current_byte = 0;               // 串口接收的当前的字节
uchar ucSerial_Rec_Success = 0;    // 本次串口接收是否成功，only if ucRec_success == 1, 进行解析扫描
uchar uiSerial_rec_bytes_len = 0;    // 上位机串口接收长度 5 or 16
uchar ucSerial_Rec_Count = 0;     // 接收数据位计数器， 0-16 or 0-5

/**************** 上位机发送相关的数据结构 **********************/
extern ST_SERIAL_DATA stSerial_data;     // 内部状态结构体
uchar ucSerial_send_status = 0;  // serial send Loop status 0: 什么都不发送； 1. 发送自检结果 ； 2. 发送检测结果
uchar ucSerial_send_dataBits[22] = {0};        // 发送的数据：工作的六个角度
uchar ucSerial_send_bytes[26] = {0};           // 正常工作所有的字节数组
uint u32Package_count = 0;            			// 包计数 
uchar ucRerial_Send_Bytes_Len = 0;                 // 接收的数据位长度   ？？ 需要修改的变量

/***************** 激光板接收相关的数据结构 *******************/
ST_SERIAL_DECODE stLaser_decode = {0};     //解析激光板的结构体
uchar ucLaser_success = 0;       // laser launch result feedback
uchar ucLaser_rec_bytes[26] = {0};      // 接收激光板的数组
uchar ucLaser_buffer_rec_bytes[26];     // 接收激光板的缓冲数组
uchar ucLaser_rec_current_byte = 0;               // 串口接收的当前的字节
uint uiLaser_Rec_Count = 0;                // 激光板接收的计数器
uchar ucLaser_rec_bytes_len = 0;        // 接收激光板的数据长度         
uchar ucLaser_rec_status = 0;          // 判断是否接收成功

/******************激光板发送相关的数据结构 *********************/
uchar ucLaser_query_bytes[16] = {0};    // 激光板发送的所有字节
uchar ucLaser_query_datas[12] = {0};    // 激光板发送的所有数据 
uchar ucLaser_send_bytes_len = 0;       // 向激光板发送的数据长度
uchar ucLaser_send_byte = 0;            // 激光板发送的字节
uchar ucLaser_send_count = 0;           // 记录激光板当前发送的字节是哪一帧
uchar ucLaser_send_status = 0;   // Laser send loop status  0: 什么都不发送； 1. 发送自检指令；  2. 发送上位机的控制指令
uchar ucLaser_send_cmd = 0;            // 控制激光板是否发送， 0：发送， 1：发送
uint laser_time_count = 0;            // 定时计数器，1000个计数发送一次初始化 ， 10个计数发送一次查询
uint laser_bind_count =0;             // 
void Sci0ReFunc()
{
}
void Sci0TrFunc()
{
}
void Sci6ReFunc()
{
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
/********************* 上位机接收扫描 **********************************/
void serial_receive_loop()
{
	int iswape = 0;
	if(SCI6.SSR.BIT.RDRF == 1)
	{
		ucSerial_rec_current_byte = SCI6.RDR;
		serial_decode_byte(ucSerial_rec_current_byte, &stSerial_decode, 0);
		SCI6.SSR.BIT.RDRF = 0;
	} // 读写结束
	
	SCI6.SSR.BIT.ORER = 0;   // 溢出标志量，清零
	SCI6.SSR.BIT.FER = 0; 
}
/****************** 上位机接收的解析扫描 *****************/
void serial_loop()
{     
	switch(ucSerial_send_status){          //串口发送
		case 0:        //IDLE state
				break;            
		case 1:	  // shake with upper machine
				ucRerial_Send_Bytes_Len = 2;   // 握手的时候只发送两个字节的数据
				ucSerial_send_dataBits[0] = 0x02;
				ucSerial_send_dataBits[1] = 0x00;
				serial_build_protocol(ucSerial_send_dataBits, ucSerial_send_bytes, ucRerial_Send_Bytes_Len);  // 根据协议进行组帧
				serial_send(ucSerial_send_bytes, ucRerial_Send_Bytes_Len+4);// 将数组发送出去
				ucSerial_send_status = 0;
				break;			
		case 2:   // connection work 
				if (ucShake_success){
					u32Package_count++;
					stSerial_data.package_count = u32Package_count;
					ucRerial_Send_Bytes_Len = 22;
					serial_encode(stSerial_data, ucSerial_send_dataBits);    // 将当前的内部数据状态结构体，转换成数组
					serial_build_protocol(ucSerial_send_dataBits, ucSerial_send_bytes, ucRerial_Send_Bytes_Len);  // 
					serial_send(ucSerial_send_bytes, ucRerial_Send_Bytes_Len+4);   // 向上位机发送当前指令
			
					ucSPI_62TB_cmd = SPI_SEND_CMD;    // 向62T发送指令
					ucSPI_62TA_cmd = SPI_SEND_CMD;	
					
					ucLaser_send_status = 2;         // 向激光板发送指令
					ucSerial_send_status = 0;
				}
				break;
	}	
}
/********************* 激光板串口接收 **********************************/
void laser_receive_loop()
{
	int iswape = 0;
	if(SCI6.SSR.BIT.RDRF == 1)
	{
		ucLaser_rec_current_byte = SCI6.RDR;
		serial_decode_byte(ucLaser_rec_current_byte, &stLaser_decode, 1);
		SCI6.SSR.BIT.RDRF = 0;
	} // 读写结束
	if(SCI6.SSR.BIT.ORER)
	{
		SCI6.SSR.BIT.ORER = 0;   // 溢出标志量，清零	
	}
	if(SCI6.SSR.BIT.FER)
	{
		SCI6.SSR.BIT.FER = 0; 	
	}
}
/******************** 激光板发送扫描 **********************/
void laser_loop()
{
	/*********   定时发送 **************/
	if(ucLaser_success == 0)   // 自检状态
	{
		laser_time_count++;
		if(laser_time_count > 10000 )    //1S发送一次
		{
			ucLaser_send_status = 1;  // 发送自检指令
			laser_time_count = 0;
		}
	}
	else if(ucLaser_success == 1)   // 自检通过
	{
		laser_time_count++;
		if(laser_time_count > 999 )    //30ms发送一次
		{
			if(laser_bind_count < 2)  // 装订状态
			{
				st_pc_cmd.ucCapture = 0XFF;
				st_pc_cmd.ucMod_type = 0x01;
				ucLaser_send_status = 2;  // 发送自检指令
				laser_bind_count++;
				laser_time_count = 0;
			}
			
			else if(laser_bind_count > 1)
			{
				st_pc_cmd.ucCapture = 0X55;
				st_pc_cmd.ucMod_type = 0x01;
				ucLaser_send_status = 2;  // 发送自检指令
				laser_bind_count = 3;
				laser_time_count = 0;
			}
		}	
	}
	switch(ucLaser_send_status)          
	{
		case 0:
			break;
		case 1:
			ucLaser_send_bytes_len = 5;    //向激光板发送5个字节
			ucLaser_query_bytes[0]  = 0X55;
			ucLaser_query_bytes[1]  = 0XAA;
			ucLaser_query_bytes[2]  = 0X01;              //0X01;
			ucLaser_query_bytes[3]  = 0X01;
			ucLaser_query_bytes[4]  = 0X02;
			ucLaser_send_cmd = 1;
			//laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // 发送一次
			
			ucLaser_send_status = 0;   // 状态置零
			break;
		case 2:
			ucLaser_send_bytes_len = 16;    //向激光板发送5个字节
			ucLaser_query_datas[4] = st_pc_cmd.ucCapture;      // 发送捕获指令
			//ucLaser_query_datas[5] = st_pc_cmd.ucMod_type;     // 发送码型,默认的码型是1
			ucLaser_query_datas[5] = 0x01;
			serial_build_protocol(ucLaser_query_datas, ucLaser_query_bytes, 12);
			//laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // 发送一次
			ucLaser_send_cmd = 1;
			ucLaser_send_status = 0; // 状态置零
			break;
	}	
}
void laser_send_loop()
{
	if(ucLaser_send_cmd == 1)  // 激光板处于发送状态
	{
		if(ucLaser_rec_status == SERIAL_IDLE)	
		{
			ucLaser_send_count++;
			if(ucLaser_send_count == 1)
			{
				SCI6.SCR.BIT.RE = 0X00;
				SCI6.SCR.BIT.TE = 0X01;
			}
			if(ucLaser_send_count - 2 < ucLaser_send_bytes_len && ucLaser_send_count > 1)
			{
				ucLaser_send_byte = ucLaser_query_bytes[ucLaser_send_count - 2];
				SCI6.TDR = ucLaser_send_byte;
			}
			if(ucLaser_send_count - 2 == ucLaser_send_bytes_len)   // 发送完毕
			{
				SCI6.SCR.BIT.TEIE = 0X01;	
			}
			if(ucLaser_send_count - 2 > ucLaser_send_bytes_len)   // 发送完毕
			{
				SCI6.SCR.BIT.TE = 0X00;
				SCI6.SCR.BIT.TEIE = 0X00;
				SCI6.SCR.BIT.RE = 0X01;
				ucLaser_send_cmd = 0;
				ucLaser_send_count = 0;
			}
			
		}
	}
}
/***************   串口发送 **********************/
void serial_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C6(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // 通过SCI的方式将数组发送出去

}
/***************   激光板串口发送 **********************/
void laser_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C6(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // 通过SCI的方式将数组发送出去
}

/*************** 上位机编码 **********************/
/************* serial protocol *****************
1	起始字节	2	0x55AA	
2	数据长度	1	0x18	
3~6	包计数	4		
7	xx头工作状态信号	1	该字节由高到低依次为D7、D6…、 
D0=0 未捕获     D0=1捕获
D1=0无光电信号  D1=1有光电信号
D2=0无光电信号  D2=1有光电信号
D3=0未进入盲区  D3=1进入盲区	
8	码型	1	见表4	
9~10	俯仰框架角	2	度	-17.5~+17.5	100	
11~12	偏航框架角	2	度	-17.5~+17.5	100	
13~14	俯仰视线角速度	2	度/秒	-10~+10	100	
15~16	偏航视线角速度	2		-10~+10	100	
17~18	俯仰跟踪角偏差	2	度	-15~+15	100	
19~20	偏航跟踪角偏差	2	度	-15~+15	100	
21~24	备用	4				
25	校验和	1	************************************/
void serial_encode(const ST_SERIAL_DATA stSerial_data, uchar *ucSerial_send_dataBits)    
{	
	int uintGenetate_Count = 0;
	const float fpDeg_center[6] = {17.5, 17.5, 10, 10, 15, 15};          // 角度的均值，0 相当于-17.5°
	const float fpdeg[6] = {stSerial_data.elevation_deg, stSerial_data.sheer_deg,\
	 stSerial_data.elevation_view_deg_speed, stSerial_data.sheer_view_deg_speed,\
	 stSerial_data.elevation_trace_deg_offset, stSerial_data.sheer_trace_deg_offset};    // 各种传感器测出来的角度值
	int i32Scale = 100;             // 角度转换的比
	uint package_count = stSerial_data.package_count;
	uchar ucPackages[4] = {0};
		
	serial_u32toucArr(package_count, ucPackages);    // 将包计数转换成4个字节
	for (uintGenetate_Count=0; uintGenetate_Count < 4;uintGenetate_Count++){
		ucSerial_send_dataBits[uintGenetate_Count] = ucPackages[uintGenetate_Count];   // 将四个字节赋值串口数组
	}                              // 3~6. package count
	ucSerial_send_dataBits[4] = stSerial_data.work_status; 			//7. 工作状态
	ucSerial_send_dataBits[5] = stSerial_data.code_pattern;           //8. 码型	
                                           
	for(uintGenetate_Count = 0; uintGenetate_Count < 6; uintGenetate_Count++){
		uchar ucDegs[2] = {0};
		serial_fpdegtoucArr(fpdeg[uintGenetate_Count], fpDeg_center[uintGenetate_Count], i32Scale, ucDegs);
		ucSerial_send_dataBits[6 + uintGenetate_Count*2] = ucDegs[0];    //9~ 将字节数组中的角度值的低八位赋值给字节数组
		ucSerial_send_dataBits[7 + uintGenetate_Count*2] = ucDegs[1];    //10~ 将字节数组中的角度值的高八位赋值给字节数组
	}
}
/**************************************************
Function: // serial_build_protocol
Description: // 将数据位组合成符合协议的包
Input: // 数据位、包的指针
Others: // 
**************************************************/
void serial_build_protocol(uchar *ucSerial_datasBits, uchar *ucSerial_bytes, uchar ucDataBytes_Len)
{
	int i32count = 0;
	char ucCheckout_real = 0;  
		
	ucSerial_bytes[0] = 0x55;    // 1. headline1
	ucSerial_bytes[1] = 0xAA;    // 2. headline2
	ucSerial_bytes[2] = ucDataBytes_Len;    // 3.数据长度
	for (i32count = 0; i32count < ucDataBytes_Len; i32count++)
	{
		ucSerial_bytes[3 + i32count] = ucSerial_datasBits[i32count];          // 4. 数据位读入
	}
	ucSerial_bytes[3 + i32count] = serial_cal_checkout(ucSerial_datasBits, ucDataBytes_Len);  //校验和	
}
/****************** 串口解码 ********************/
/********************** upper machine to slave  protocol *****************************
序号	名称	字节数	单位	范围(处理后)	比例尺	备注
1	起始字节	2	0x55AA	
2	数据长度	1	0x0C	
3~4	俯仰下倾角指令	2	度	-17.5~+17.5	100	
5~6	偏航下倾角指令	2	度	-17.5~+17.5	100	
7	捕获指令	1	0x55：捕获  0xFF:不捕获	1	
8	码型	1	见表4	1	
9~14	备用	6				
15	校验和	1			1	
****************************************************
校验和：有效数据长度和数据内容按字节累加和的低八位（1个字节）
*************************************************/
void serial_decode(const uchar *ucSerial_rec_bits, ST_SERIAL_DECODE *stSerial_decode, uchar ucByte_len, uchar ucMac_type)
{
	int i32Decode_count = 0;
	uchar ucCurrent_byte = 0;
	for (i32Decode_count = 0; i32Decode_count < ucByte_len; i32Decode_count++){
		ucCurrent_byte = ucSerial_rec_bits[i32Decode_count];
		switch(stSerial_decode->ucSerial_decode_status){
			case 0:    // headline1
				if(ucCurrent_byte == 0x55){
					stSerial_decode->ucSerial_decode_status = 1; // 字节头校验通过
				}
				else 
				{
					u32Error_count++;	
				}
				break;
			case 1:    // headline2
				if(ucCurrent_byte == 0xAA){
					stSerial_decode->ucSerial_decode_status = 2; // 字节头2校验通过
				}else {
					stSerial_decode->ucSerial_decode_status = 0;
					u32Error_count++;
				}
				break;
			case 2:    // data length
				stSerial_decode->ucSerial_data_length = ucCurrent_byte; // 得到数据长度
				stSerial_decode->ucSerial_decode_status = 3;  // 切换到接收到数据模式
				break;
			case 3:    // receive data				
				stSerial_decode->ucSerial_dataBits[stSerial_decode->ucSerial_cur_data_len] = ucCurrent_byte;  
				stSerial_decode->ucSerial_cur_data_len++;
				if(stSerial_decode->ucSerial_cur_data_len >= stSerial_decode->ucSerial_data_length){
					stSerial_decode->ucSerial_decode_status = 4;    //切换校验模式
				}
				break;
			case 4:     // checkout 
			
				if(serial_cal_checkout(stSerial_decode->ucSerial_dataBits, stSerial_decode->ucSerial_data_length) == ucCurrent_byte )  //校验和通过
				{
					if(ucMac_type == 0)
					{
						if(stSerial_decode->ucSerial_data_length == 1 && stSerial_decode->ucSerial_dataBits[0] == 1)
						{
							ucSerial_send_status = 1;
							ucShake_success = 1;
						}
						else if(stSerial_decode->ucSerial_data_length == 12)
						{
							st_pc_cmd.fpPitchDeg = ((float)(stSerial_decode->ucSerial_dataBits[0] + stSerial_decode->ucSerial_dataBits[1] * 256 - 1750))/100;    // 接收角度
							st_pc_cmd.fpSailDeg = ((float)(stSerial_decode->ucSerial_dataBits[2] + stSerial_decode->ucSerial_dataBits[3] * 256 - 1750))/100;
							st_pc_cmd.ucCapture = stSerial_decode->ucSerial_dataBits[4];
							st_pc_cmd.ucMod_type = stSerial_decode->ucSerial_dataBits[5];
							ucSerial_send_status = 2;    // 其他的工作放在外面去做，比如像两个62T发送电机指令
						}
					}
					else if (ucMac_type == 1)
					{
						uiLaser_Rec_Count++;
						if(stSerial_decode->ucSerial_dataBits[1] == 0 && stSerial_decode->ucSerial_data_length == 2)
						{
							ucLaser_success = 1;
							unAllsensor_states.STATE.LASER = 0x01;	
						}
						else if(stSerial_decode->ucSerial_data_length == 22)
						{ 
							ucLaser_success = 1;
							stSerial_data.work_status = stSerial_decode->ucSerial_dataBits[4];    //接收激光板状态
							stSerial_data.code_pattern = stSerial_decode->ucSerial_dataBits[5];    //接收码型
							stSerial_data.elevation_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[14] + stSerial_decode->ucSerial_dataBits[15] * 256 - 1500)/100;
							stSerial_data.sheer_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[16] + stSerial_decode->ucSerial_dataBits[17] * 256 - 1500)/100; 
							
							ucSerial_send_status = 2;    // 其他的工作放在外面去做，比如像两个62T发送电机指令
							st_pc_cmd.fpPitchDeg = -stSerial_data.elevation_trace_deg_offset;
							st_pc_cmd.fpSailDeg = -stSerial_data.sheer_trace_deg_offset;
							ucSPI_62TB_cmd = SPI_SEND_CMD;    // 向62T发送指令
							ucSPI_62TA_cmd = SPI_SEND_CMD;	
						}
					}
					
				}
				else {
					u32Error_count++;
				}
		
				stSerial_decode->ucSerial_data_length = 0; // 状态机置0 ，循环重新开始
				stSerial_decode->ucSerial_decode_status = 0;
				stSerial_decode->ucSerial_cur_data_len = 0;
				
				break;
			default:
				break;
		}
	}
	memset(ucSerial_rec_bits,0,ucByte_len*sizeof(unsigned char));

}

void serial_decode_byte(const uchar ucCurrent_byte, ST_SERIAL_DECODE *stSerial_decode, uchar ucMac_type)
{
	switch(stSerial_decode->ucSerial_decode_status){
		case 0:    // headline1
			if(ucCurrent_byte == 0x55){
				ucLaser_rec_status = SERIAL_RECEVING;           // 串口处于接收状态
				stSerial_decode->ucSerial_decode_status = 1; // 字节头校验通过
			}
			else 
			{
				u32Error_count++;
			}
			break;
		case 1:    // headline2
			if(ucCurrent_byte == 0xAA){
				stSerial_decode->ucSerial_decode_status = 2; // 字节头2校验通过
			}else {
				stSerial_decode->ucSerial_decode_status = 0;
				u32Error_count++;
			}
			break;
		case 2:    // data length
			stSerial_decode->ucSerial_data_length = ucCurrent_byte; // 得到数据长度
			stSerial_decode->ucSerial_decode_status = 3;  // 切换到接收到数据模式
			break;
		case 3:    // receive data				
			stSerial_decode->ucSerial_dataBits[stSerial_decode->ucSerial_cur_data_len] = ucCurrent_byte;  
			stSerial_decode->ucSerial_cur_data_len++;
			if(stSerial_decode->ucSerial_cur_data_len >= stSerial_decode->ucSerial_data_length){
				stSerial_decode->ucSerial_decode_status = 4;    //切换校验模式
			}
			break;
		case 4:     // checkout 
			if(serial_cal_checkout(stSerial_decode->ucSerial_dataBits, stSerial_decode->ucSerial_data_length) == ucCurrent_byte )  //校验和通过
			{
				ucLaser_rec_status = SERIAL_IDLE;
				if(ucMac_type == 0)
				{
					if(stSerial_decode->ucSerial_data_length == 1 && stSerial_decode->ucSerial_dataBits[0] == 1)
					{
						ucSerial_send_status = 1;
						ucShake_success = 1;
					}
					else if(stSerial_decode->ucSerial_data_length == 12)
					{
						st_pc_cmd.fpPitchDeg = ((float)(stSerial_decode->ucSerial_dataBits[0] + stSerial_decode->ucSerial_dataBits[1] * 256 - 1750))/100;    // 接收角度
						st_pc_cmd.fpSailDeg = ((float)(stSerial_decode->ucSerial_dataBits[2] + stSerial_decode->ucSerial_dataBits[3] * 256 - 1750))/100;
						st_pc_cmd.ucCapture = stSerial_decode->ucSerial_dataBits[4];
						st_pc_cmd.ucMod_type = stSerial_decode->ucSerial_dataBits[5];
						ucSerial_send_status = 2;    // 其他的工作放在外面去做，比如像两个62T发送电机指令
					}
				}
				else if (ucMac_type == 1)
				{
					uiLaser_Rec_Count++;
					if(stSerial_decode->ucSerial_dataBits[1] == 0 && stSerial_decode->ucSerial_data_length == 2)
					{
						ucLaser_success = 1;
						unAllsensor_states.STATE.LASER = 0x01;	
					}
					else if(stSerial_decode->ucSerial_data_length == 22)
					{ 
						ucLaser_success = 1;
						stSerial_data.work_status = stSerial_decode->ucSerial_dataBits[4];    //接收激光板状态
						stSerial_data.code_pattern = stSerial_decode->ucSerial_dataBits[5];    //接收码型
						stSerial_data.elevation_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[14] + stSerial_decode->ucSerial_dataBits[15] * 256 - 1500)/100;
						stSerial_data.sheer_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[16] + stSerial_decode->ucSerial_dataBits[17] * 256 - 1500)/100; 
						
						ucSerial_send_status = 2;    // 其他的工作放在外面去做，比如像两个62T发送电机指令
						st_pc_cmd.fpPitchDeg = -stSerial_data.elevation_trace_deg_offset;
						st_pc_cmd.fpSailDeg = -stSerial_data.sheer_trace_deg_offset;
						ucSPI_62TB_cmd = SPI_SEND_CMD;    // 向62T发送指令
						ucSPI_62TA_cmd = SPI_SEND_CMD;	
					}
				}
				
			}
			else {
				u32Error_count++;
			}
			
			stSerial_decode->ucSerial_data_length = 0; // 状态机置0 ，循环重新开始
			stSerial_decode->ucSerial_decode_status = 0;
			stSerial_decode->ucSerial_cur_data_len = 0;
			break;
		default:
			break;
	}
}

/*************************************************
Function: // serial_u32toucArr
Description: // 将四个字节的数转换成四个字节的数组
Input: // 输入uint的数和获取的字节数组
Others: // 小在前的解析协议
*************************************************/
void serial_u32toucArr(uint uiData, uchar *ucByteArr)
{
	ucByteArr[0] = uiData % 256;      // 低八位在前
	uiData = uiData / 256;            // 将后面的八位去掉
	ucByteArr[1] = uiData % 256; 	  
	uiData = uiData / 256;
	ucByteArr[2] = uiData % 256; 	     
	uiData = uiData / 256;
	ucByteArr[3] = uiData % 256; 	  
	uiData = uiData / 256;
}

/*************************************************
Function: // serial_fpdegtoucArr
Description: // 将角度float类型的转换成两个字节的数组
Input: // 输入角度，角度平均值，比例尺，待转换的字节数组
Others: // 协议同上
*************************************************/
//static void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr)
void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr)
{
	ucByteArr[0] = (ushort)((deg +deg_center) * scale)% 256;    // 低八位在前
	ucByteArr[1] = (ushort)((deg +deg_center) * scale) / 256;    // 高八位在后
}

/*************************************************
Function: // serial_cal_checkout
Description: // 串口校验和
Input: // 数据和数据长度和校验位s
Others: // 校验数据和数据长度，取低八位进行校验
*************************************************/
uchar serial_cal_checkout(const uchar *ucSerial_datasBits, const uchar ucDataBytes_Len)
{
	uint uiCheckout_sum = 0;
	uchar ucCheckout_count = 0;
	uchar ucCheckout_real;
	
	for (ucCheckout_count = 0 ; ucCheckout_count < ucDataBytes_Len; ucCheckout_count++){
		uiCheckout_sum += ucSerial_datasBits[ucCheckout_count];
	}
	uiCheckout_sum += ucDataBytes_Len;
	ucCheckout_real = uiCheckout_sum % 256;
	return ucCheckout_real;
}
