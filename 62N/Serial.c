#include "Serial.h"
#include "iodefine.h"
#include "HIT_common.h"
#include <string.h>
extern ST_SERIAL_DECODE stSerial_decode;     //解析上位机的结构体
extern ST_SERIAL_DECODE stLaser_decode;     // 解析激光板的结构体
extern ST_SERIAL_DATA stSerial_data;     // 内部状态结构体
extern ST_PC_CMD st_pc_cmd;              // 计算器指令结构体           
extern uint u32Error_count;              // 错误计数
extern uchar ucSerial_send_status;     // 判断到底要给上位机回复什么指令的控制位
extern uchar ucLaser_send_status;      // 判断到底要给激光板发送什么指令
extern uchar ucShake_success;          // 握手是否成功的标志量
extern uchar ucLaser_success;          // 激光板测试是否成功

uchar ucSerial_byte_len = 0;
uint u32Package_count = 0;            // 包计数           
uint uiRec_bytes_num = 0;                  // 控制接收的字节数
uchar ucDataBytes_Len = 0;                 // 接收的数据位长度   ？？ 需要修改的变量
uchar ucRecBytes_len = 0;                  // 获取当前Buffer中的内存的数目

uchar ucSerial_shake_send_dataBits[2] = {2, 0};   // 发送的数据： 握手指令
uchar ucSerial_shake_send_bytes[6] = {0};      // 握手的所有字节数组
uchar ucSerial_send_dataBits[22] = {0};        // 发送的数据：工作的六个角度
uchar ucSerial_send_bytes[26] = {0};           // 正常工作所有的字节数组
uchar ucSerial_rec_bytes[5] = {0};    //从上位机获取的握手信息

uchar ucLaser_query_bytes[16] = {0};    // 激光板发送的所有字节
uchar ucLaser_query_datas[12] = {0};    // 激光板发送的所有数据 
uchar ucLaser_rec_bytes[26] = {0};      // 激光板发送的数据
uchar ucLaser_send_bytes_len = 0; 
uchar ucLaser_rec_bytes_len = 0;
uchar ucSerial_tests[2] = {0x55, 0xAA};
void Sci6ReFunc()
{
}
void Sci6TrFunc()
{
}
void Sci0ReFunc()
{
}
void Sci0TrFunc()
{
}
/****************** 串口的解析中断 *****************/
void serial_loop()
{     		
	uiRec_bytes_num = 5;
	//R_PG_SCI_GetSentDataCount_C6(&ucRecBytes_len);
	if(serial_receive(ucSerial_rec_bytes, uiRec_bytes_num))   // 串口接收
	{
		//serial_receive(ucSerial_rec_bytes, uiRec_bytes_num);
		serial_decode(ucSerial_rec_bytes, &stSerial_decode, uiRec_bytes_num, 0);
	}

	switch(ucSerial_send_status){          //串口发送
		case 0:        //IDLE state
				break;            
		case 1:	  // shake with upper machine
				SCI0.SCR.BYTE = 0x04;
				ucDataBytes_Len = 2;
				serial_build_protocol(ucSerial_shake_send_dataBits, ucSerial_shake_send_bytes, ucDataBytes_Len);  // 
				serial_send(ucSerial_shake_send_bytes, ucDataBytes_Len+4);//R_PG_SCI_StartSending_C2(ucSerial_shake_send_bytes, 6);
				/***
				if (SCI0.SSR.BIT.ORER){
					SCI0.SSR.BIT.ORER = 0;
				}***/
				ucSerial_send_status = 0;
				break;			
		case 2:   // connection work 
				if (ucShake_success){
					SCI0.SCR.BYTE = 0x04;
					u32Package_count++;
					stSerial_data.package_count = u32Package_count;
					ucDataBytes_Len = 22;
					
					serial_encode(stSerial_data, ucSerial_send_dataBits); 
					serial_build_protocol(ucSerial_send_dataBits, ucSerial_send_bytes, ucDataBytes_Len);  // 
					serial_send(ucSerial_send_bytes, ucDataBytes_Len+4);  
					ucSerial_send_status = 0;
				
				}
				break;
	}	
}
void laser_loop()
{
	/*********   定时发送 **************/
	if(ucLaser_success == 0)   // 自检状态
	{
		laser_time_count++;
		if(laser_time_count > 1000 )    //1S发送一次
		{
			ucLaser_send_status = 1;  // 发送自检指令
			laser_time_count = 0;
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
			ucLaser_query_bytes[2]  = 0X01;
			ucLaser_query_bytes[3]  = 0X01;
			ucLaser_query_bytes[4]  = 0X02;
			laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // 发送一次
			break;
		case 2:
			ucLaser_send_bytes_len = 16;    //向激光板发送5个字节
			ucLaser_query_datas[4] = st_pc_cmd.ucCapture;      // 发送捕获指令
			ucLaser_query_datas[5] = st_pc_cmd.ucMod_type;     // 发送码型
			serial_build_protocol(ucLaser_query_datas, ucLaser_query_bytes, 12);
			laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // 发送一次
			break;
	}
	/********* 定时接收程序 ************/
	ucLaser_rec_bytes_len = 6;      // 后面要尝试一下先从串口的buffer中读取字节数，然后再进行判断
	if(laser_receive(ucLaser_rec_bytes, ucLaser_rec_bytes_len))   // 串口接收
	{
		serial_decode(ucLaser_rec_bytes, &stLaser_decode, ucLaser_rec_bytes_len, 1);
	}
	
}
/***************   串口发送 **********************/
void serial_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C6(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // 通过SCI的方式将数组发送出去
	//SCI6.SSR.BIT.TDRE = 0X01;

}
/***************   激光板串口发送 **********************/
void laser_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C0(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // 通过SCI的方式将数组发送出去
	//SCI6.SSR.BIT.TDRE = 0X01;

}

/********************* 串口接收 **********************************/
bool serial_receive(uchar * ucSerial_datas, uint uiCount){

	bool blResult = 0;
	int isCount = 0;
	R_PG_SCI_StartReceiving_C6(ucSerial_datas, 5);
	
	for(isCount = 0 ; isCount < 5; isCount++)
	{
		if(ucSerial_datas[isCount] != 0)
			blResult = 1;
			break;	
	}
	return blResult;
}
/********************* 激光板串口接收 **********************************/
bool laser_receive(uchar * ucSerial_datas, uint uiCount)
{

	bool blResult = 0;
	int isCount = 0;
	R_PG_SCI_StartReceiving_C0(ucSerial_datas, uiCount);
	SCI0.SSR.BIT.RDRF = 0;
	
	for(isCount = 0 ; isCount < uiCount; isCount++)
	{
		if(ucSerial_datas[isCount] != 0)
			blResult = 1;
			break;	
	}
	return blResult;
}

/*************** 串口编码 **********************/
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
	uint uiCheckout_sum = 0;
	uchar ucCheckout_count = 0;
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
	int i32Current_ArrSize = 0;
	int i32Clear_count = 0;
	uchar ucCurrent_byte = 0;
	for (i32Decode_count = 0; i32Decode_count < ucByte_len; i32Decode_count++){
		ucCurrent_byte = ucSerial_rec_bits[i32Decode_count];
		switch(stSerial_decode->ucSerial_decode_status){
			case 0:    // headline1
				if(ucCurrent_byte == 0x55){
					stSerial_decode->ucSerial_decode_status = 1; // 字节头校验通过
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
							st_pc_cmd.fpPitchDeg = stSerial_decode->ucSerial_dataBits[0];
							st_pc_cmd.fpSailDeg = stSerial_decode->ucSerial_dataBits[1];
							st_pc_cmd.ucCapture = stSerial_decode->ucSerial_dataBits[2];
							st_pc_cmd.ucMod_type = stSerial_decode->ucSerial_dataBits[3];
							
							ucSerial_send_status = 2;
						}
					}
					else if (ucMac_type == 1)
					{
						//if(stSerial_decode->ucSerial_dataBits[1] == 0 && stSerial_decode->ucSerial_data_length == 2)
						if(stSerial_decode->ucSerial_data_length == 2)
						{
							ucLaser_success = 1;	
						}
						else if(stSerial_decode->ucSerial_data_length == 22)
						{ 
							stSerial_data.work_status = stSerial_decode->ucSerial_dataBits[4];    //接收激光板状态
							stSerial_data.code_pattern = stSerial_decode->ucSerial_dataBits[5];    //接收码型
							stSerial_data.elevation_view_deg_speed = stSerial_decode->ucSerial_dataBits[14];
							stSerial_data.sheer_view_deg_speed = stSerial_decode->ucSerial_dataBits[15];
							stSerial_data.elevation_trace_deg_offset = stSerial_decode->ucSerial_dataBits[16];
							stSerial_data.sheer_trace_deg_offset = stSerial_decode->ucSerial_dataBits[17];
							ucSerial_send_status = 2;                     // 激光板接收成功，将结果发送给上位机
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

/*************************************************
Function: // serial_u32toucArr
Description: // 将四个字节的数转换成四个字节的数组
Input: // 输入uint的数和获取的字节数组
Others: // 小在前的解析协议
*************************************************/
//static void serial_u32toucArr(uint uiData, uchar *ucByteArr)
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
