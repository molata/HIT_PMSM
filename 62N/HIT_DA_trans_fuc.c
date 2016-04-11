#include"iodefine.h"
extern union {
		unsigned short HIT_send_sci_DA;
		struct {
			unsigned short low_8:8;//最低位
			unsigned short high_8:8;//最位
		} BYTE;
		struct {
			unsigned short BIT_1:1;//最低位
			unsigned short BIT_2:1;//最位
			unsigned short BIT_3:1;//最位
			unsigned short BIT_4:1;//最位
			unsigned short BIT_5:1;//最位
			unsigned short BIT_6:1;//最位
			unsigned short BIT_7:1;//最位
			unsigned short BIT_8:1;//最高位
			unsigned short BIT_9:1;//最高位
			unsigned short BIT_10:1;//最高位
			unsigned short BIT_11:1;//最高位
			unsigned short BIT_12:1;//最高位
			unsigned short BIT_13:1;//最高位
			unsigned short BIT_14:1;//最高位
			unsigned short BIT_15:1;//最高位
			unsigned short BIT_16:1;//最高位
		} BIT;
	} HIT_send_sci_DA_buff;	
	extern unsigned int tx;
	extern unsigned short HIT_DA_data_trans;
void HIT_DA_trans_fuc()
{	
	/****
	HIT_send_sci_DA_buff.HIT_send_sci_DA = tx;
			//	RSPI0.SPDR.WORD.L = 1;//tx;//0X8000;//tx;//0X8F51;//tx;//0XFFFF;//0x0001;
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_16;
	HIT_send_sci_DA_buff.BIT.BIT_16 = HIT_send_sci_DA_buff.BIT.BIT_9;
	HIT_send_sci_DA_buff.BIT.BIT_9 = HIT_DA_data_trans;
	
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_15;
	HIT_send_sci_DA_buff.BIT.BIT_15 = HIT_send_sci_DA_buff.BIT.BIT_10;
	HIT_send_sci_DA_buff.BIT.BIT_10 = HIT_DA_data_trans;
	
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_14;
	HIT_send_sci_DA_buff.BIT.BIT_14 = HIT_send_sci_DA_buff.BIT.BIT_11;
	HIT_send_sci_DA_buff.BIT.BIT_11 = HIT_DA_data_trans;
	
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_13;
	HIT_send_sci_DA_buff.BIT.BIT_13 = HIT_send_sci_DA_buff.BIT.BIT_12;
	HIT_send_sci_DA_buff.BIT.BIT_12 = HIT_DA_data_trans;
	
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_8;
	HIT_send_sci_DA_buff.BIT.BIT_8 = HIT_send_sci_DA_buff.BIT.BIT_1;
	HIT_send_sci_DA_buff.BIT.BIT_1 = HIT_DA_data_trans;
	
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_7;
	HIT_send_sci_DA_buff.BIT.BIT_7 = HIT_send_sci_DA_buff.BIT.BIT_2;
	HIT_send_sci_DA_buff.BIT.BIT_2 = HIT_DA_data_trans;
	
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_6;
	HIT_send_sci_DA_buff.BIT.BIT_6 = HIT_send_sci_DA_buff.BIT.BIT_3;
	HIT_send_sci_DA_buff.BIT.BIT_3 = HIT_DA_data_trans;
	
	HIT_DA_data_trans = HIT_send_sci_DA_buff.BIT.BIT_5;
	HIT_send_sci_DA_buff.BIT.BIT_5 = HIT_send_sci_DA_buff.BIT.BIT_4;
	HIT_send_sci_DA_buff.BIT.BIT_4 = HIT_DA_data_trans;
				SCI1.TDR = HIT_send_sci_DA_buff.BYTE.high_8;
				SCI1.TDR = HIT_send_sci_DA_buff.BYTE.low_8;
	****/
}