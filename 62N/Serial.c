#include "Serial.h"
#include "iodefine.h"
#include "HIT_common.h"
#include <string.h>
extern ST_SERIAL_DECODE stSerial_decode;     //������λ���Ľṹ��
extern ST_SERIAL_DECODE stLaser_decode;     // ���������Ľṹ��
extern ST_SERIAL_DATA stSerial_data;     // �ڲ�״̬�ṹ��
extern ST_PC_CMD st_pc_cmd;              // ������ָ��ṹ��           
extern uint u32Error_count;              // �������
extern uchar ucSerial_send_status;     // �жϵ���Ҫ����λ���ظ�ʲôָ��Ŀ���λ
extern uchar ucLaser_send_status;      // �жϵ���Ҫ������巢��ʲôָ��
extern uchar ucShake_success;          // �����Ƿ�ɹ��ı�־��
extern uchar ucLaser_success;          // ���������Ƿ�ɹ�

uchar ucSerial_byte_len = 0;
uint u32Package_count = 0;            // ������           
uint uiRec_bytes_num = 0;                  // ���ƽ��յ��ֽ���
uchar ucDataBytes_Len = 0;                 // ���յ�����λ����   ���� ��Ҫ�޸ĵı���
uchar ucRecBytes_len = 0;                  // ��ȡ��ǰBuffer�е��ڴ����Ŀ

uchar ucSerial_shake_send_dataBits[2] = {2, 0};   // ���͵����ݣ� ����ָ��
uchar ucSerial_shake_send_bytes[6] = {0};      // ���ֵ������ֽ�����
uchar ucSerial_send_dataBits[22] = {0};        // ���͵����ݣ������������Ƕ�
uchar ucSerial_send_bytes[26] = {0};           // �����������е��ֽ�����
uchar ucSerial_rec_bytes[5] = {0};    //����λ����ȡ��������Ϣ

uchar ucLaser_query_bytes[16] = {0};    // ����巢�͵������ֽ�
uchar ucLaser_query_datas[12] = {0};    // ����巢�͵��������� 
uchar ucLaser_rec_bytes[26] = {0};      // ����巢�͵�����
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
/****************** ���ڵĽ����ж� *****************/
void serial_loop()
{     		
	uiRec_bytes_num = 5;
	//R_PG_SCI_GetSentDataCount_C6(&ucRecBytes_len);
	if(serial_receive(ucSerial_rec_bytes, uiRec_bytes_num))   // ���ڽ���
	{
		//serial_receive(ucSerial_rec_bytes, uiRec_bytes_num);
		serial_decode(ucSerial_rec_bytes, &stSerial_decode, uiRec_bytes_num, 0);
	}

	switch(ucSerial_send_status){          //���ڷ���
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
	/*********   ��ʱ���� **************/
	if(ucLaser_success == 0)   // �Լ�״̬
	{
		laser_time_count++;
		if(laser_time_count > 1000 )    //1S����һ��
		{
			ucLaser_send_status = 1;  // �����Լ�ָ��
			laser_time_count = 0;
		}
	}
	
	switch(ucLaser_send_status)          
	{
		case 0:
			break;
		case 1:
			ucLaser_send_bytes_len = 5;    //�򼤹�巢��5���ֽ�
			ucLaser_query_bytes[0]  = 0X55;
			ucLaser_query_bytes[1]  = 0XAA;
			ucLaser_query_bytes[2]  = 0X01;
			ucLaser_query_bytes[3]  = 0X01;
			ucLaser_query_bytes[4]  = 0X02;
			laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // ����һ��
			break;
		case 2:
			ucLaser_send_bytes_len = 16;    //�򼤹�巢��5���ֽ�
			ucLaser_query_datas[4] = st_pc_cmd.ucCapture;      // ���Ͳ���ָ��
			ucLaser_query_datas[5] = st_pc_cmd.ucMod_type;     // ��������
			serial_build_protocol(ucLaser_query_datas, ucLaser_query_bytes, 12);
			laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // ����һ��
			break;
	}
	/********* ��ʱ���ճ��� ************/
	ucLaser_rec_bytes_len = 6;      // ����Ҫ����һ���ȴӴ��ڵ�buffer�ж�ȡ�ֽ�����Ȼ���ٽ����ж�
	if(laser_receive(ucLaser_rec_bytes, ucLaser_rec_bytes_len))   // ���ڽ���
	{
		serial_decode(ucLaser_rec_bytes, &stLaser_decode, ucLaser_rec_bytes_len, 1);
	}
	
}
/***************   ���ڷ��� **********************/
void serial_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C6(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // ͨ��SCI�ķ�ʽ�����鷢�ͳ�ȥ
	//SCI6.SSR.BIT.TDRE = 0X01;

}
/***************   ����崮�ڷ��� **********************/
void laser_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C0(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // ͨ��SCI�ķ�ʽ�����鷢�ͳ�ȥ
	//SCI6.SSR.BIT.TDRE = 0X01;

}

/********************* ���ڽ��� **********************************/
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
/********************* ����崮�ڽ��� **********************************/
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
25	У���	1	************************************/
void serial_encode(const ST_SERIAL_DATA stSerial_data, uchar *ucSerial_send_dataBits)    
{	
	int uintGenetate_Count = 0;
	const float fpDeg_center[6] = {17.5, 17.5, 10, 10, 15, 15};          // �Ƕȵľ�ֵ��0 �൱��-17.5��
	const float fpdeg[6] = {stSerial_data.elevation_deg, stSerial_data.sheer_deg,\
	 stSerial_data.elevation_view_deg_speed, stSerial_data.sheer_view_deg_speed,\
	 stSerial_data.elevation_trace_deg_offset, stSerial_data.sheer_trace_deg_offset};    // ���ִ�����������ĽǶ�ֵ
	int i32Scale = 100;             // �Ƕ�ת���ı�
	uint package_count = stSerial_data.package_count;
	uchar ucPackages[4] = {0};
		
	serial_u32toucArr(package_count, ucPackages);    // ��������ת����4���ֽ�
	for (uintGenetate_Count=0; uintGenetate_Count < 4;uintGenetate_Count++){
		ucSerial_send_dataBits[uintGenetate_Count] = ucPackages[uintGenetate_Count];   // ���ĸ��ֽڸ�ֵ��������
	}                              // 3~6. package count
	ucSerial_send_dataBits[4] = stSerial_data.work_status; 			//7. ����״̬
	ucSerial_send_dataBits[5] = stSerial_data.code_pattern;           //8. ����	
                                           
	for(uintGenetate_Count = 0; uintGenetate_Count < 6; uintGenetate_Count++){
		uchar ucDegs[2] = {0};
		serial_fpdegtoucArr(fpdeg[uintGenetate_Count], fpDeg_center[uintGenetate_Count], i32Scale, ucDegs);
		ucSerial_send_dataBits[6 + uintGenetate_Count*2] = ucDegs[0];    //9~ ���ֽ������еĽǶ�ֵ�ĵͰ�λ��ֵ���ֽ�����
		ucSerial_send_dataBits[7 + uintGenetate_Count*2] = ucDegs[1];    //10~ ���ֽ������еĽǶ�ֵ�ĸ߰�λ��ֵ���ֽ�����
	}
}
/**************************************************
Function: // serial_build_protocol
Description: // ������λ��ϳɷ���Э��İ�
Input: // ����λ������ָ��
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
	ucSerial_bytes[2] = ucDataBytes_Len;    // 3.���ݳ���
	for (i32count = 0; i32count < ucDataBytes_Len; i32count++)
	{
		ucSerial_bytes[3 + i32count] = ucSerial_datasBits[i32count];          // 4. ����λ����
	}
	ucSerial_bytes[3 + i32count] = serial_cal_checkout(ucSerial_datasBits, ucDataBytes_Len);  //У���	
}
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
					stSerial_decode->ucSerial_decode_status = 1; // �ֽ�ͷУ��ͨ��
				}
				break;
			case 1:    // headline2
				if(ucCurrent_byte == 0xAA){
					stSerial_decode->ucSerial_decode_status = 2; // �ֽ�ͷ2У��ͨ��
				}else {
					stSerial_decode->ucSerial_decode_status = 0;
					u32Error_count++;
				}
				break;
			case 2:    // data length
				stSerial_decode->ucSerial_data_length = ucCurrent_byte; // �õ����ݳ���
				stSerial_decode->ucSerial_decode_status = 3;  // �л������յ�����ģʽ
				break;
			case 3:    // receive data				
				stSerial_decode->ucSerial_dataBits[stSerial_decode->ucSerial_cur_data_len] = ucCurrent_byte;  
				stSerial_decode->ucSerial_cur_data_len++;
				if(stSerial_decode->ucSerial_cur_data_len >= stSerial_decode->ucSerial_data_length){
					stSerial_decode->ucSerial_decode_status = 4;    //�л�У��ģʽ
				}
				break;
			case 4:     // checkout 
			
				if(serial_cal_checkout(stSerial_decode->ucSerial_dataBits, stSerial_decode->ucSerial_data_length) == ucCurrent_byte )  //У���ͨ��
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
							stSerial_data.work_status = stSerial_decode->ucSerial_dataBits[4];    //���ռ����״̬
							stSerial_data.code_pattern = stSerial_decode->ucSerial_dataBits[5];    //��������
							stSerial_data.elevation_view_deg_speed = stSerial_decode->ucSerial_dataBits[14];
							stSerial_data.sheer_view_deg_speed = stSerial_decode->ucSerial_dataBits[15];
							stSerial_data.elevation_trace_deg_offset = stSerial_decode->ucSerial_dataBits[16];
							stSerial_data.sheer_trace_deg_offset = stSerial_decode->ucSerial_dataBits[17];
							ucSerial_send_status = 2;                     // �������ճɹ�����������͸���λ��
						}
					}
					
				}
				else {
					u32Error_count++;
				}
		
				stSerial_decode->ucSerial_data_length = 0; // ״̬����0 ��ѭ�����¿�ʼ
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
Description: // ���ĸ��ֽڵ���ת�����ĸ��ֽڵ�����
Input: // ����uint�����ͻ�ȡ���ֽ�����
Others: // С��ǰ�Ľ���Э��
*************************************************/
//static void serial_u32toucArr(uint uiData, uchar *ucByteArr)
void serial_u32toucArr(uint uiData, uchar *ucByteArr)
{
	ucByteArr[0] = uiData % 256;      // �Ͱ�λ��ǰ
	uiData = uiData / 256;            // ������İ�λȥ��
	ucByteArr[1] = uiData % 256; 	  
	uiData = uiData / 256;
	ucByteArr[2] = uiData % 256; 	     
	uiData = uiData / 256;
	ucByteArr[3] = uiData % 256; 	  
	uiData = uiData / 256;
}

/*************************************************
Function: // serial_fpdegtoucArr
Description: // ���Ƕ�float���͵�ת���������ֽڵ�����
Input: // ����Ƕȣ��Ƕ�ƽ��ֵ�������ߣ���ת�����ֽ�����
Others: // Э��ͬ��
*************************************************/
//static void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr)
void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr)
{
	ucByteArr[0] = (ushort)((deg +deg_center) * scale)% 256;    // �Ͱ�λ��ǰ
	ucByteArr[1] = (ushort)((deg +deg_center) * scale) / 256;    // �߰�λ�ں�
}

/*************************************************
Function: // serial_cal_checkout
Description: // ����У���
Input: // ���ݺ����ݳ��Ⱥ�У��λs
Others: // У�����ݺ����ݳ��ȣ�ȡ�Ͱ�λ����У��
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
