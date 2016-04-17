#include"iodefine.h"
extern unsigned int HIT_send_adrr_int;
extern unsigned short HIT_iic_word_rec_short;
extern unsigned char HIT_iic_word_rec_1;
extern unsigned char HIT_iic_word_rec_2;
extern unsigned char HIT_iic_send_count;
extern union {
		unsigned char HIT_send_adrr_buff_char;
		struct {
			unsigned char HIT_send_data:4;//最低位
			unsigned char HIT_send_state:1;//中间位
			unsigned char HIT_send_serial:3;//最高位
		} BIT;
	} HIT_send_adrr_buff[8];
void HIT_send_ee_data()
{
	
		
		{
		
		  HIT_send_adrr_int = (int)HIT_iic_word_rec_short;
		  
		  HIT_send_adrr_buff[7].BIT.HIT_send_serial = 7;//数据序号
		  HIT_send_adrr_buff[6].BIT.HIT_send_serial = 6;
		  HIT_send_adrr_buff[5].BIT.HIT_send_serial = 5;
		  HIT_send_adrr_buff[4].BIT.HIT_send_serial = 4;
		  HIT_send_adrr_buff[3].BIT.HIT_send_serial = 3;
		  HIT_send_adrr_buff[2].BIT.HIT_send_serial = 2;
		  HIT_send_adrr_buff[1].BIT.HIT_send_serial = 1;
		  HIT_send_adrr_buff[0].BIT.HIT_send_serial = 0;
		  
		  HIT_send_adrr_buff[0].BIT.HIT_send_state = 1;//1 1数据数据
		  HIT_send_adrr_buff[1].BIT.HIT_send_state = 1;
		  
		  
		  HIT_send_adrr_buff[7].BIT.HIT_send_data = (unsigned char)(HIT_send_adrr_int&0x000f);
		  HIT_send_adrr_buff[6].BIT.HIT_send_data = (unsigned char)((HIT_send_adrr_int&0x00f0)>>4);
		  HIT_send_adrr_buff[5].BIT.HIT_send_data = (unsigned char)((HIT_send_adrr_int&0x0f00)>>8);
		  HIT_send_adrr_buff[4].BIT.HIT_send_data = (unsigned char)((HIT_send_adrr_int&0xf000)>>12);
		  HIT_send_adrr_buff[3].BIT.HIT_send_data = (unsigned char)(HIT_send_adrr_int&0x000f);
		  HIT_send_adrr_buff[2].BIT.HIT_send_data = (unsigned char)((HIT_send_adrr_int&0x00f0)>>4);
		  HIT_send_adrr_buff[1].BIT.HIT_send_data = (unsigned char)((HIT_send_adrr_int&0x0f00)>>8);
		  HIT_send_adrr_buff[0].BIT.HIT_send_data = (unsigned char)((HIT_send_adrr_int&0xf000)>>12);
		} 
		
		
/*			if(SCI2.SSR.BIT.RDRF == 1)
		{
			HIT_iic_send_count = 0;	
		}*/
		
		if(HIT_iic_send_count == 1)
		{
			R_PG_SCI_StartSending_C5(HIT_send_adrr_buff,8);	
		}
		HIT_iic_send_count++;
		if(HIT_iic_send_count == 4)
		{
			HIT_iic_send_count = 1;	
		}
		
}