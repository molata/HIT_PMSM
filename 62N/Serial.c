#include "Serial.h"
#include "iodefine.h"
#include "HIT_common.h"
#include <string.h>
#include "HIT_SPI.h"
/****************** 207����ͨ����� ********************************/
extern UNSENSOR_STATES unAllsensor_states;   // �ڲ����д�������״̬
extern uchar ucSPI_62TB_cmd;                 // �����Ƿ�Ҫ�������62TA
extern uchar ucSPI_62TA_cmd;                // �����Ƿ�Ҫ��������62TB

/**************** ��λ��������ص����ݽṹ ********************/
ST_SERIAL_DECODE stSerial_decode;     //������λ���Ľṹ�� 
extern ST_PC_CMD st_pc_cmd;              //������ָ��ṹ�壬���ڻ�����λ����ָ��
uchar ucSerial_rec_bytes[16] = {0};    //����λ����ȡ��������Ϣ
uchar ucSerial_buffer_rec_bytes[16] = {0};    //���ڽ��յĻ�������
uint u32Error_count = 0;              // �������
uchar ucShake_success = 0;       // serial receive Loop status
uchar ucSerial_rec_current_byte = 0;               // ���ڽ��յĵ�ǰ���ֽ�
uchar ucSerial_Rec_Success = 0;    // ���δ��ڽ����Ƿ�ɹ���only if ucRec_success == 1, ���н���ɨ��
uchar uiSerial_rec_bytes_len = 0;    // ��λ�����ڽ��ճ��� 5 or 16
uchar ucSerial_Rec_Count = 0;     // ��������λ�������� 0-16 or 0-5

/**************** ��λ��������ص����ݽṹ **********************/
extern ST_SERIAL_DATA stSerial_data;     // �ڲ�״̬�ṹ��
uchar ucSerial_send_status = 0;  // serial send Loop status 0: ʲô�������ͣ� 1. �����Լ��� �� 2. ���ͼ����
uchar ucSerial_send_dataBits[22] = {0};        // ���͵����ݣ������������Ƕ�
uchar ucSerial_send_bytes[26] = {0};           // �����������е��ֽ�����
uint u32Package_count = 0;            			// ������ 
uchar ucRerial_Send_Bytes_Len = 0;                 // ���յ�����λ����   ���� ��Ҫ�޸ĵı���

/***************** ����������ص����ݽṹ *******************/
ST_SERIAL_DECODE stLaser_decode = {0};     //���������Ľṹ��
uchar ucLaser_success = 0;       // laser launch result feedback
uchar ucLaser_rec_bytes[26] = {0};      // ���ռ���������
uchar ucLaser_buffer_rec_bytes[26];     // ���ռ����Ļ�������
uchar ucLaser_rec_current_byte = 0;               // ���ڽ��յĵ�ǰ���ֽ�
uint uiLaser_Rec_Count = 0;                // �������յļ�����
uchar ucLaser_rec_bytes_len = 0;        // ���ռ��������ݳ���         
uchar ucLaser_rec_status = 0;          // �ж��Ƿ���ճɹ�

/******************����巢����ص����ݽṹ *********************/
uchar ucLaser_query_bytes[16] = {0};    // ����巢�͵������ֽ�
uchar ucLaser_query_datas[12] = {0};    // ����巢�͵��������� 
uchar ucLaser_send_bytes_len = 0;       // �򼤹�巢�͵����ݳ���
uchar ucLaser_send_byte = 0;            // ����巢�͵��ֽ�
uchar ucLaser_send_count = 0;           // ��¼����嵱ǰ���͵��ֽ�����һ֡
uchar ucLaser_send_status = 0;   // Laser send loop status  0: ʲô�������ͣ� 1. �����Լ�ָ�  2. ������λ���Ŀ���ָ��
uchar ucLaser_send_cmd = 0;            // ���Ƽ�����Ƿ��ͣ� 0�����ͣ� 1������
uint laser_time_count = 0;            // ��ʱ��������1000����������һ�γ�ʼ�� �� 10����������һ�β�ѯ
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
/********************* ��λ������ɨ�� **********************************/
void serial_receive_loop()
{
	int iswape = 0;
	if(SCI6.SSR.BIT.RDRF == 1)
	{
		ucSerial_rec_current_byte = SCI6.RDR;
		serial_decode_byte(ucSerial_rec_current_byte, &stSerial_decode, 0);
		SCI6.SSR.BIT.RDRF = 0;
	} // ��д����
	
	SCI6.SSR.BIT.ORER = 0;   // �����־��������
	SCI6.SSR.BIT.FER = 0; 
}
/****************** ��λ�����յĽ���ɨ�� *****************/
void serial_loop()
{     
	switch(ucSerial_send_status){          //���ڷ���
		case 0:        //IDLE state
				break;            
		case 1:	  // shake with upper machine
				ucRerial_Send_Bytes_Len = 2;   // ���ֵ�ʱ��ֻ���������ֽڵ�����
				ucSerial_send_dataBits[0] = 0x02;
				ucSerial_send_dataBits[1] = 0x00;
				serial_build_protocol(ucSerial_send_dataBits, ucSerial_send_bytes, ucRerial_Send_Bytes_Len);  // ����Э�������֡
				serial_send(ucSerial_send_bytes, ucRerial_Send_Bytes_Len+4);// �����鷢�ͳ�ȥ
				ucSerial_send_status = 0;
				break;			
		case 2:   // connection work 
				if (ucShake_success){
					u32Package_count++;
					stSerial_data.package_count = u32Package_count;
					ucRerial_Send_Bytes_Len = 22;
					serial_encode(stSerial_data, ucSerial_send_dataBits);    // ����ǰ���ڲ�����״̬�ṹ�壬ת��������
					serial_build_protocol(ucSerial_send_dataBits, ucSerial_send_bytes, ucRerial_Send_Bytes_Len);  // 
					serial_send(ucSerial_send_bytes, ucRerial_Send_Bytes_Len+4);   // ����λ�����͵�ǰָ��
			
					ucSPI_62TB_cmd = SPI_SEND_CMD;    // ��62T����ָ��
					ucSPI_62TA_cmd = SPI_SEND_CMD;	
					
					ucLaser_send_status = 2;         // �򼤹�巢��ָ��
					ucSerial_send_status = 0;
				}
				break;
	}	
}
/********************* ����崮�ڽ��� **********************************/
void laser_receive_loop()
{
	int iswape = 0;
	if(SCI6.SSR.BIT.RDRF == 1)
	{
		ucLaser_rec_current_byte = SCI6.RDR;
		serial_decode_byte(ucLaser_rec_current_byte, &stLaser_decode, 1);
		SCI6.SSR.BIT.RDRF = 0;
	} // ��д����
	if(SCI6.SSR.BIT.ORER)
	{
		SCI6.SSR.BIT.ORER = 0;   // �����־��������	
	}
	if(SCI6.SSR.BIT.FER)
	{
		SCI6.SSR.BIT.FER = 0; 	
	}
}
/******************** ����巢��ɨ�� **********************/
void laser_loop()
{
	/*********   ��ʱ���� **************/
	if(ucLaser_success == 0)   // �Լ�״̬
	{
		laser_time_count++;
		if(laser_time_count > 10000 )    //1S����һ��
		{
			ucLaser_send_status = 1;  // �����Լ�ָ��
			laser_time_count = 0;
		}
	}
	else if(ucLaser_success == 1)   // �Լ�ͨ��
	{
		laser_time_count++;
		if(laser_time_count > 999 )    //30ms����һ��
		{
			if(laser_bind_count < 2)  // װ��״̬
			{
				st_pc_cmd.ucCapture = 0XFF;
				st_pc_cmd.ucMod_type = 0x01;
				ucLaser_send_status = 2;  // �����Լ�ָ��
				laser_bind_count++;
				laser_time_count = 0;
			}
			
			else if(laser_bind_count > 1)
			{
				st_pc_cmd.ucCapture = 0X55;
				st_pc_cmd.ucMod_type = 0x01;
				ucLaser_send_status = 2;  // �����Լ�ָ��
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
			ucLaser_send_bytes_len = 5;    //�򼤹�巢��5���ֽ�
			ucLaser_query_bytes[0]  = 0X55;
			ucLaser_query_bytes[1]  = 0XAA;
			ucLaser_query_bytes[2]  = 0X01;              //0X01;
			ucLaser_query_bytes[3]  = 0X01;
			ucLaser_query_bytes[4]  = 0X02;
			ucLaser_send_cmd = 1;
			//laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // ����һ��
			
			ucLaser_send_status = 0;   // ״̬����
			break;
		case 2:
			ucLaser_send_bytes_len = 16;    //�򼤹�巢��5���ֽ�
			ucLaser_query_datas[4] = st_pc_cmd.ucCapture;      // ���Ͳ���ָ��
			//ucLaser_query_datas[5] = st_pc_cmd.ucMod_type;     // ��������,Ĭ�ϵ�������1
			ucLaser_query_datas[5] = 0x01;
			serial_build_protocol(ucLaser_query_datas, ucLaser_query_bytes, 12);
			//laser_send(ucLaser_query_bytes, ucLaser_send_bytes_len);    // ����һ��
			ucLaser_send_cmd = 1;
			ucLaser_send_status = 0; // ״̬����
			break;
	}	
}
void laser_send_loop()
{
	if(ucLaser_send_cmd == 1)  // ����崦�ڷ���״̬
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
			if(ucLaser_send_count - 2 == ucLaser_send_bytes_len)   // �������
			{
				SCI6.SCR.BIT.TEIE = 0X01;	
			}
			if(ucLaser_send_count - 2 > ucLaser_send_bytes_len)   // �������
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
/***************   ���ڷ��� **********************/
void serial_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C6(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // ͨ��SCI�ķ�ʽ�����鷢�ͳ�ȥ

}
/***************   ����崮�ڷ��� **********************/
void laser_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_StartSending_C6(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // ͨ��SCI�ķ�ʽ�����鷢�ͳ�ȥ
}

/*************** ��λ������ **********************/
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
	uchar ucCurrent_byte = 0;
	for (i32Decode_count = 0; i32Decode_count < ucByte_len; i32Decode_count++){
		ucCurrent_byte = ucSerial_rec_bits[i32Decode_count];
		switch(stSerial_decode->ucSerial_decode_status){
			case 0:    // headline1
				if(ucCurrent_byte == 0x55){
					stSerial_decode->ucSerial_decode_status = 1; // �ֽ�ͷУ��ͨ��
				}
				else 
				{
					u32Error_count++;	
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
							st_pc_cmd.fpPitchDeg = ((float)(stSerial_decode->ucSerial_dataBits[0] + stSerial_decode->ucSerial_dataBits[1] * 256 - 1750))/100;    // ���սǶ�
							st_pc_cmd.fpSailDeg = ((float)(stSerial_decode->ucSerial_dataBits[2] + stSerial_decode->ucSerial_dataBits[3] * 256 - 1750))/100;
							st_pc_cmd.ucCapture = stSerial_decode->ucSerial_dataBits[4];
							st_pc_cmd.ucMod_type = stSerial_decode->ucSerial_dataBits[5];
							ucSerial_send_status = 2;    // �����Ĺ�����������ȥ��������������62T���͵��ָ��
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
							stSerial_data.work_status = stSerial_decode->ucSerial_dataBits[4];    //���ռ����״̬
							stSerial_data.code_pattern = stSerial_decode->ucSerial_dataBits[5];    //��������
							stSerial_data.elevation_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[14] + stSerial_decode->ucSerial_dataBits[15] * 256 - 1500)/100;
							stSerial_data.sheer_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[16] + stSerial_decode->ucSerial_dataBits[17] * 256 - 1500)/100; 
							
							ucSerial_send_status = 2;    // �����Ĺ�����������ȥ��������������62T���͵��ָ��
							st_pc_cmd.fpPitchDeg = -stSerial_data.elevation_trace_deg_offset;
							st_pc_cmd.fpSailDeg = -stSerial_data.sheer_trace_deg_offset;
							ucSPI_62TB_cmd = SPI_SEND_CMD;    // ��62T����ָ��
							ucSPI_62TA_cmd = SPI_SEND_CMD;	
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

void serial_decode_byte(const uchar ucCurrent_byte, ST_SERIAL_DECODE *stSerial_decode, uchar ucMac_type)
{
	switch(stSerial_decode->ucSerial_decode_status){
		case 0:    // headline1
			if(ucCurrent_byte == 0x55){
				ucLaser_rec_status = SERIAL_RECEVING;           // ���ڴ��ڽ���״̬
				stSerial_decode->ucSerial_decode_status = 1; // �ֽ�ͷУ��ͨ��
			}
			else 
			{
				u32Error_count++;
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
						st_pc_cmd.fpPitchDeg = ((float)(stSerial_decode->ucSerial_dataBits[0] + stSerial_decode->ucSerial_dataBits[1] * 256 - 1750))/100;    // ���սǶ�
						st_pc_cmd.fpSailDeg = ((float)(stSerial_decode->ucSerial_dataBits[2] + stSerial_decode->ucSerial_dataBits[3] * 256 - 1750))/100;
						st_pc_cmd.ucCapture = stSerial_decode->ucSerial_dataBits[4];
						st_pc_cmd.ucMod_type = stSerial_decode->ucSerial_dataBits[5];
						ucSerial_send_status = 2;    // �����Ĺ�����������ȥ��������������62T���͵��ָ��
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
						stSerial_data.work_status = stSerial_decode->ucSerial_dataBits[4];    //���ռ����״̬
						stSerial_data.code_pattern = stSerial_decode->ucSerial_dataBits[5];    //��������
						stSerial_data.elevation_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[14] + stSerial_decode->ucSerial_dataBits[15] * 256 - 1500)/100;
						stSerial_data.sheer_trace_deg_offset = (float)(stSerial_decode->ucSerial_dataBits[16] + stSerial_decode->ucSerial_dataBits[17] * 256 - 1500)/100; 
						
						ucSerial_send_status = 2;    // �����Ĺ�����������ȥ��������������62T���͵��ָ��
						st_pc_cmd.fpPitchDeg = -stSerial_data.elevation_trace_deg_offset;
						st_pc_cmd.fpSailDeg = -stSerial_data.sheer_trace_deg_offset;
						ucSPI_62TB_cmd = SPI_SEND_CMD;    // ��62T����ָ��
						ucSPI_62TA_cmd = SPI_SEND_CMD;	
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

/*************************************************
Function: // serial_u32toucArr
Description: // ���ĸ��ֽڵ���ת�����ĸ��ֽڵ�����
Input: // ����uint�����ͻ�ȡ���ֽ�����
Others: // С��ǰ�Ľ���Э��
*************************************************/
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
