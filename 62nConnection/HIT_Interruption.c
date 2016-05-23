/********************* 发送的中断 *****************/
#include "iodefine.h"
#include "Serial.h"
#include "typedefine.h"   

/**** 上位机相关的数据结构 ****/
ST_SERIAL_DECODE stSerial_decode;     //解析上位机的结构体
extern uchar ucSerial_send_bytes[26];           // 正常工作所有的字节数组
extern uchar ucSerial_Send_Bytes_Len;                 // 接收的数据位长度   ？？ 需要修改的变量
extern uchar ucSerial_cur_send_len;               // 串口当前已经发送了多少字节

/**** 激光板相关的数据结构 ****/
ST_SERIAL_DECODE stLaser_decode = {0};     //解析激光板的结构体
extern uchar ucLaser_query_bytes[16];    // 激光板发送的所有字节
extern uchar ucLaser_send_bytes_len;       // 向激光板发送的数据长度
extern uchar ucLaser_send_count;           // 记录激光板当前发送的字节是哪一帧

/*********** 上位机发送  *******************/
#if FAST_INTC_VECTOR == VECT_SCI6_TXI6
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6)
#endif
void Interrupt_SCI6_TXI6(void)
{
	SCI6.TDR = ucSerial_send_bytes[ucSerial_cur_send_len];    // 从buffer中取出数据，写入
	ucSerial_cur_send_len++;
	if(ucSerial_cur_send_len >= ucSerial_Send_Bytes_Len)       // 全部发完了
	{
		SCI6.SCR.BIT.TIE = 0X00;                           // 关闭发送中断
		SCI6.SCR.BIT.TEIE = 0X01;                          // 开启发送停止中断
		ucSerial_cur_send_len = 0;                            // 发送指示复位
	}
}
/************ 上位机发送结束中断 ************/
#if FAST_INTC_VECTOR == VECT_SCI6_TEI6
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6)
#endif
void Interrupt_SCI6_TEI6(void)
{
	/* Disable interrupt request generation, and try to disable transmission */
	SCI6.SCR.BIT.TEIE = 0;     // 发送结束中断关闭
	SCI6.SCR.BIT.TE = 0;       // 发送使能关闭
}
/*********** 激光板发送 **********************/
#if FAST_INTC_VECTOR == VECT_SCI0_TXI0
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0)
#endif
void Interrupt_SCI0_TXI0(void)
{
	SCI0.TDR = ucLaser_query_bytes[ucLaser_send_count];    // 从buffer中取出数据，写入
	ucLaser_send_count++;
	if(ucLaser_send_count >= ucLaser_send_bytes_len)       // 全部发完了
	{
		SCI0.SCR.BIT.TIE = 0X00;                           // 关闭发送中断
		SCI0.SCR.BIT.TEIE = 0X01;                          // 开启发送停止中断
		ucLaser_send_count = 0;                            // 发送指示复位
	}
}

/*********** 激光板发送结束中断 **********************/
#if FAST_INTC_VECTOR == VECT_SCI0_TEI0
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0)
#endif
void Interrupt_SCI0_TEI0(void)
{
	/* Disable interrupt request generation, and try to disable transmission */
	SCI0.SCR.BIT.TEIE = 0;     // 发送结束中断关闭
	SCI0.SCR.BIT.TE = 0;       // 发送使能关闭
}
/*********** 上位机接收  *******************/
#if FAST_INTC_VECTOR == VECT_SCI6_RXI6
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6)
#endif
void Interrupt_SCI6_RXI6(void)
{
	uchar ucSerial_rec_current_byte = 0;               // 串口接收的当前的字节
	
	if(SCI0.SSR.BIT.RDRF == 1)
	{
		ucSerial_rec_current_byte = SCI6.RDR;
		serial_decode_byte(ucSerial_rec_current_byte, &stSerial_decode, 0);

	} // 读写结束
	SCI6CheckError();             // SCI0清除错误
}

/*********** 激光板发送  *******************/
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

	} // 读写结束

}