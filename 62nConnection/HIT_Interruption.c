/********************* ���͵��ж� *****************/
#include "iodefine.h"
#include "Serial.h"
#include "typedefine.h"   

/**** ��λ����ص����ݽṹ ****/
ST_SERIAL_DECODE stSerial_decode;     //������λ���Ľṹ��
extern uchar ucSerial_send_bytes[26];           // �����������е��ֽ�����
extern uchar ucSerial_Send_Bytes_Len;                 // ���յ�����λ����   ���� ��Ҫ�޸ĵı���
extern uchar ucSerial_cur_send_len;               // ���ڵ�ǰ�Ѿ������˶����ֽ�

/**** �������ص����ݽṹ ****/
ST_SERIAL_DECODE stLaser_decode = {0};     //���������Ľṹ��
extern uchar ucLaser_query_bytes[16];    // ����巢�͵������ֽ�
extern uchar ucLaser_send_bytes_len;       // �򼤹�巢�͵����ݳ���
extern uchar ucLaser_send_count;           // ��¼����嵱ǰ���͵��ֽ�����һ֡

/*********** ��λ������  *******************/
#if FAST_INTC_VECTOR == VECT_SCI6_TXI6
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6)
#endif
void Interrupt_SCI6_TXI6(void)
{
	SCI6.TDR = ucSerial_send_bytes[ucSerial_cur_send_len];    // ��buffer��ȡ�����ݣ�д��
	ucSerial_cur_send_len++;
	if(ucSerial_cur_send_len >= ucSerial_Send_Bytes_Len)       // ȫ��������
	{
		SCI6.SCR.BIT.TIE = 0X00;                           // �رշ����ж�
		SCI6.SCR.BIT.TEIE = 0X01;                          // ��������ֹͣ�ж�
		ucSerial_cur_send_len = 0;                            // ����ָʾ��λ
	}
}
/************ ��λ�����ͽ����ж� ************/
#if FAST_INTC_VECTOR == VECT_SCI6_TEI6
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6)
#endif
void Interrupt_SCI6_TEI6(void)
{
	/* Disable interrupt request generation, and try to disable transmission */
	SCI6.SCR.BIT.TEIE = 0;     // ���ͽ����жϹر�
	SCI6.SCR.BIT.TE = 0;       // ����ʹ�ܹر�
}
/*********** ����巢�� **********************/
#if FAST_INTC_VECTOR == VECT_SCI0_TXI0
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0)
#endif
void Interrupt_SCI0_TXI0(void)
{
	SCI0.TDR = ucLaser_query_bytes[ucLaser_send_count];    // ��buffer��ȡ�����ݣ�д��
	ucLaser_send_count++;
	if(ucLaser_send_count >= ucLaser_send_bytes_len)       // ȫ��������
	{
		SCI0.SCR.BIT.TIE = 0X00;                           // �رշ����ж�
		SCI0.SCR.BIT.TEIE = 0X01;                          // ��������ֹͣ�ж�
		ucLaser_send_count = 0;                            // ����ָʾ��λ
	}
}

/*********** ����巢�ͽ����ж� **********************/
#if FAST_INTC_VECTOR == VECT_SCI0_TEI0
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0)
#endif
void Interrupt_SCI0_TEI0(void)
{
	/* Disable interrupt request generation, and try to disable transmission */
	SCI0.SCR.BIT.TEIE = 0;     // ���ͽ����жϹر�
	SCI0.SCR.BIT.TE = 0;       // ����ʹ�ܹر�
}
/*********** ��λ������  *******************/
#if FAST_INTC_VECTOR == VECT_SCI6_RXI6
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6)
#endif
void Interrupt_SCI6_RXI6(void)
{
	uchar ucSerial_rec_current_byte = 0;               // ���ڽ��յĵ�ǰ���ֽ�
	
	if(SCI0.SSR.BIT.RDRF == 1)
	{
		ucSerial_rec_current_byte = SCI6.RDR;
		serial_decode_byte(ucSerial_rec_current_byte, &stSerial_decode, 0);

	} // ��д����
	SCI6CheckError();             // SCI0�������
}

/*********** ����巢��  *******************/
#if FAST_INTC_VECTOR == VECT_SCI0_RXI0
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0)
#endif
void Interrupt_SCI0_RXI0(void)
{
	uchar ucLaser_rec_current_byte = 0; 
	if(SCI0.SSR.BIT.RDRF == 1)
	{
		ucLaser_rec_current_byte = SCI0.RDR;
		serial_decode_byte(ucLaser_rec_current_byte, &stLaser_decode, 1);

	} // ��д����

}