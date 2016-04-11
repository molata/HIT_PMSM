/************************************************************
Copyright (C), 1988-1999, Tech. Co., Ltd.
FileName: test.cpp
Author: 
Version : 
Date:
Description: // 模块描述 
Version: // 版本信息
Function List: // 主要函数及其功能
1. -------
History: // 历史修改记录
<author> <time> <version > <desc>
David 96/10/12 1.0 build this moudle 
***********************************************************/

#ifndef HIT_SERIAL
#define HIT_SERIAL
#include "typedefine.h"
/**********************************************************
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
25	校验和	1				
***********************************************************/
typedef struct{
	unsigned int package_count;
	unsigned char work_status;
	unsigned char code_pattern;
	float elevation_deg;
	float sheer_deg;
	float elevation_view_deg_speed;
	float sheer_view_deg_speed;
	float elevation_trace_deg_offset;
	float sheer_trace_deg_offset;
}ST_SERIAL_DATA;
/*********************************************************
序号	名称	字节数	单位	范围(处理后)	比例尺	备注
1	起始字节	2	0x55AA	
2	数据长度	1	0x0C	
3~4	俯仰下倾角指令	2	度	-17.5~+17.5	100	
5~6	偏航下倾角指令	2	度	-17.5~+17.5	100	
7	捕获指令	1	0x55：捕获  0xFF:不捕获	1	
8	码型	1	见表4	1	
9~14	备用	6				
15	校验和	1			1	
*********************************************************/
typedef struct {
	uchar ucSerial_decode_status;     // 1. headline1; 2. headline2; 3. data length; 4. data 5. checkout
	uchar ucSerial_data_length;    // data length
	uchar ucSerial_dataBits[2];   // serial data has not decode
}ST_SERIAL_SHAKE_DECODE;

typedef struct {
	uchar ucSerial_decode_status;     // 1. headline1; 2. headline2; 3. data length; 4. data 5. checkout
	uchar ucSerial_data_length;    // data length
	uchar ucSerial_cur_data_len;   //  当前已经接收到的数据的长度
	uchar ucSerial_dataBits[12];   // serial data has not decode
}ST_SERIAL_DECODE;
/***************   串口发送 **********************/
void serial_send(uchar *ucArrData, uchar ucBytes_len);

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
25	校验和	1	
Function: // serial_encode
Description: // 将要发送的数据转换成dataBits
Input: // 输入uint的数和获取的字节数组
Others: // 小在前的解析协议			
*************************************************/
void serial_encode(const ST_SERIAL_DATA stSerial_data, uchar *ucArrSerial_Data);
/************************ 将数据位组合成包发送 *******************************/
void serial_build_protocol(uchar *ucSerial_dataBits, uchar *ucSerial_bytes , uchar ucDataBytes_Len);
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
void serial_decode(const uchar *ucSerial_rec_bits, ST_SERIAL_DECODE *stSerial_decode, uchar ucByte_len);

/********************* 串口接收 **********************************/
bool serial_receive(uchar * ucSerial_data, const uint uiCount);

/*************************************************
Function: // serial_u32toucArr
Description: // 将四个字节的数转换成四个字节的数组
Input: // 输入uint的数和获取的字节数组
Others: // 小在前的解析协议
*************************************************/
//static void serial_u32toucArr(uint uiData, uchar *ucByteArr);
void serial_u32toucArr(uint uiData, uchar *ucByteArr);
/*************************************************
Function: // serial_fpdegtoucArr
Description: // 将角度float类型的转换成两个字节的数组
Input: // 输入角度，角度平均值，比例尺，待转换的字节数组
Others: // 协议同上
*************************************************/
//static void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr);
void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr);
/*************************************************
Function: // serial_checkout_sum
Description: // 串口校验和
Input: // 数据和数据长度和校验位
Others: // 校验数据和数据长度，取低八位进行校验
*************************************************/
uchar serial_cal_checkout(const uchar *ucArrData, const uchar ucData_len);

#endif