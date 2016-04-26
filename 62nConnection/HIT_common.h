#ifndef HIT_COMMON_H
#define HIT_COMMON_H

#include "Serial.h"
#pragma address HIT_y=0x00100000

/*********************************************************
���	����	�ֽ���	��λ	��Χ(�����)	������	��ע
1	��ʼ�ֽ�	2	0x55AA	
2	���ݳ���	1	0x0C	
3~4	���������ָ��	2	��	-17.5~+17.5	100	
5~6	���������ָ��	2	��	-17.5~+17.5	100	
7	����ָ��	1	0x55������  0xFF:������	1	
8	����	1	����4	1	
9~14	����	6				
15	У���	1			1	
*********************************************************/
typedef struct st_pc_cmd{
	float fpPitchDeg;   // ���������ָ��  
	float fpSailDeg;   // ���������ָ��
	unsigned char ucCapture;  //����ָ��  for �����
	unsigned char ucMod_type;  // ����    for �����
}ST_PC_CMD;                 // �����ָ��

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
typedef struct st_serial_data{
	unsigned int package_count;
	unsigned char work_status;
	unsigned char code_pattern;
	float elevation_deg;
	float sheer_deg;
	float elevation_view_deg_speed;
	float sheer_view_deg_speed;
	float elevation_trace_deg_offset;
	float sheer_trace_deg_offset;
}ST_SERIAL_DATA;             // �ڲ�״̬������

/************************************************************
ucLaser_work_states�� �����Ĺ���״̬
uc62TA_work_states:   62TA�Ĺ���״̬
uc62TB_work_states:   62TB�Ĺ���״̬
*************************************************************/
typedef union unSensor_states{
		unsigned char ucSerial_states;
		struct {
			unsigned char LASER:1;    // �ṹ��ĵ�һ�������λ
			unsigned char Motor62TA:1;
			unsigned char Motor62TB:1;
			unsigned char BITE:5;
		} STATE;
} UNSENSOR_STATES;

#define HIT_BOUN1 0
#define HIT_BOUN2 682
#define HIT_BOUN3 1364
#define HIT_BOUN4 2046
#define HIT_BOUN5 2728
#define HIT_BOUN6 3410
#define HIT_BOUN7 4096
#define HIT_PWMOUTULIM 1732//3464//1732//762//450//900//866/*4000:output Max*86.6%*/
#define HIT_UALFAMAX_K 1.15473
#define HIT_KR 0.866
#define HIT_VOLCENTER 2.5
#define HIT_IDQ_SPE_SQUARE 9//special current:3  3*3=9
#define HIT_POSITIONERR_16WEI 10430.378
#define HIT_POSITION_16WEI 65536
#define HIT_PWM_FULL 2000//4000//2000//880
#define HIT_HALFPIE 1.5708
#define HIT_PIE 3.1415926
#define HIT_TWOTHIRDPIE 4.71239
#define HIT_TWOPIE 6.28319
#define HIT_MAKE16WEI_ANGLE 10430.378//10420.6
#define HIT_AD16WEI 65536



#endif