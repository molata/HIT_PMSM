/************************************************************
Copyright (C), 1988-1999, Tech. Co., Ltd.
FileName: test.cpp
Author: 
Version : 
Date:
Description: // ģ������ 
Version: // �汾��Ϣ
Function List: // ��Ҫ�������书��
1. -------
History: // ��ʷ�޸ļ�¼
<author> <time> <version > <desc>
David 96/10/12 1.0 build this moudle 
***********************************************************/

#ifndef HIT_SERIAL
#define HIT_SERIAL
#include "typedefine.h"
/**********************************************************
1	��ʼ�ֽ�	2	0x55AA	
2	���ݳ���	1	0x18	
3~6	������	4		
7	xxͷ����״̬�ź�	1	���ֽ��ɸߵ�������ΪD7��D6���� 
D0=0 δ����     D0=1����
D1=0�޹���ź�  D1=1�й���ź�
D2=0�޹���ź�  D2=1�й���ź�
D3=0δ����ä��  D3=1����ä��	
8	����	1	����4	
9~10	������ܽ�	2	��	-17.5~+17.5	100	
11~12	ƫ����ܽ�	2	��	-17.5~+17.5	100	
13~14	�������߽��ٶ�	2	��/��	-10~+10	100	
15~16	ƫ�����߽��ٶ�	2		-10~+10	100	
17~18	�������ٽ�ƫ��	2	��	-15~+15	100	
19~20	ƫ�����ٽ�ƫ��	2	��	-15~+15	100	
21~24	����	4				
25	У���	1				
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
���	����	�ֽ���	��λ	��Χ(�����)	������	��ע
1	��ʼ�ֽ�	2	0x55AA	
2	���ݳ���	1	0x0C	
3~4	���������ָ��	2	��	-17.5~+17.5	100	
5~6	ƫ�������ָ��	2	��	-17.5~+17.5	100	
7	����ָ��	1	0x55������  0xFF:������	1	
8	����	1	����4	1	
9~14	����	6				
15	У���	1			1	
*********************************************************/
typedef struct {
	uchar ucSerial_decode_status;     // 1. headline1; 2. headline2; 3. data length; 4. data 5. checkout
	uchar ucSerial_data_length;    // data length
	uchar ucSerial_dataBits[2];   // serial data has not decode
}ST_SERIAL_SHAKE_DECODE;

typedef struct {
	uchar ucSerial_decode_status;     // 1. headline1; 2. headline2; 3. data length; 4. data 5. checkout
	uchar ucSerial_data_length;    // data length
	uchar ucSerial_cur_data_len;   //  ��ǰ�Ѿ����յ������ݵĳ���
	uchar ucSerial_dataBits[12];   // serial data has not decode
}ST_SERIAL_DECODE;
/***************   ���ڷ��� **********************/
void serial_send(uchar *ucArrData, uchar ucBytes_len);

/*************** ���ڱ��� **********************/
/************* serial protocol *****************
1	��ʼ�ֽ�	2	0x55AA	
2	���ݳ���	1	0x18	
3~6	������	4		
7	xxͷ����״̬�ź�	1	���ֽ��ɸߵ�������ΪD7��D6���� 
D0=0 δ����     D0=1����
D1=0�޹���ź�  D1=1�й���ź�
D2=0�޹���ź�  D2=1�й���ź�
D3=0δ����ä��  D3=1����ä��	
8	����	1	����4	
9~10	������ܽ�	2	��	-17.5~+17.5	100	
11~12	ƫ����ܽ�	2	��	-17.5~+17.5	100	
13~14	�������߽��ٶ�	2	��/��	-10~+10	100	
15~16	ƫ�����߽��ٶ�	2		-10~+10	100	
17~18	�������ٽ�ƫ��	2	��	-15~+15	100	
19~20	ƫ�����ٽ�ƫ��	2	��	-15~+15	100	
21~24	����	4				
25	У���	1	
Function: // serial_encode
Description: // ��Ҫ���͵�����ת����dataBits
Input: // ����uint�����ͻ�ȡ���ֽ�����
Others: // С��ǰ�Ľ���Э��			
*************************************************/
void serial_encode(const ST_SERIAL_DATA stSerial_data, uchar *ucArrSerial_Data);
/************************ ������λ��ϳɰ����� *******************************/
void serial_build_protocol(uchar *ucSerial_dataBits, uchar *ucSerial_bytes , uchar ucDataBytes_Len);
/****************** ���ڽ��� ********************/
/********************** upper machine to slave  protocol *****************************
���	����	�ֽ���	��λ	��Χ(�����)	������	��ע
1	��ʼ�ֽ�	2	0x55AA	
2	���ݳ���	1	0x0C	
3~4	���������ָ��	2	��	-17.5~+17.5	100	
5~6	ƫ�������ָ��	2	��	-17.5~+17.5	100	
7	����ָ��	1	0x55������  0xFF:������	1	
8	����	1	����4	1	
9~14	����	6				
15	У���	1			1	
****************************************************
У��ͣ���Ч���ݳ��Ⱥ��������ݰ��ֽ��ۼӺ͵ĵͰ�λ��1���ֽڣ�
*************************************************/
void serial_decode(const uchar *ucSerial_rec_bits, ST_SERIAL_DECODE *stSerial_decode, uchar ucByte_len);

/********************* ���ڽ��� **********************************/
bool serial_receive(uchar * ucSerial_data, const uint uiCount);

/*************************************************
Function: // serial_u32toucArr
Description: // ���ĸ��ֽڵ���ת�����ĸ��ֽڵ�����
Input: // ����uint�����ͻ�ȡ���ֽ�����
Others: // С��ǰ�Ľ���Э��
*************************************************/
//static void serial_u32toucArr(uint uiData, uchar *ucByteArr);
void serial_u32toucArr(uint uiData, uchar *ucByteArr);
/*************************************************
Function: // serial_fpdegtoucArr
Description: // ���Ƕ�float���͵�ת���������ֽڵ�����
Input: // ����Ƕȣ��Ƕ�ƽ��ֵ�������ߣ���ת�����ֽ�����
Others: // Э��ͬ��
*************************************************/
//static void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr);
void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr);
/*************************************************
Function: // serial_checkout_sum
Description: // ����У���
Input: // ���ݺ����ݳ��Ⱥ�У��λ
Others: // У�����ݺ����ݳ��ȣ�ȡ�Ͱ�λ����У��
*************************************************/
uchar serial_cal_checkout(const uchar *ucArrData, const uchar ucData_len);

#endif