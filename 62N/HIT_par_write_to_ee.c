#include"HIT_FNnum.h"
#include"HIT_PNnum.h"
#include"HIT_SNnum.h"
unsigned short HIT_w_to_ee_i = 0;
extern unsigned short HIT_change_num;
extern unsigned short HIT_change_num_H;
extern unsigned short HIT_change_num_L;
extern unsigned char HIT_iic_word_send[2] ;
extern unsigned short HIT_rec_adrr_short;
extern unsigned short HIT_start_address ;
extern unsigned char HIT_ee_con_byte_0 ;
extern unsigned int HIT_ee_delay ;
unsigned char HIT_w_buffer_num = 0;
unsigned char HIT_page_write_num = 21;
extern unsigned char HIT_iic_write_choose;
unsigned char HIT_data_write_buff_num = 1;
unsigned char HIT_ee_buf_MAX_num = 0;
unsigned char HIT_enable_par_initial = 1;
void HIT_par_write_to_ee()
{


		switch(HIT_data_write_buff_num)
		{
			case 1:
			HIT_ee_con_byte_0 = 0xa4;//Sn
			HIT_change_num = HIT_SNnum[HIT_w_to_ee_i];
			HIT_ee_buf_MAX_num = 21;
			break;
			case 2:
			HIT_ee_con_byte_0 = 0xa2;//Fn
			HIT_change_num = HIT_FNnum[HIT_w_to_ee_i];
			HIT_ee_buf_MAX_num = 21;
			break;
			case 3:
			HIT_ee_con_byte_0 = 0xa0;//Pn
			HIT_change_num = HIT_PNnum[HIT_w_to_ee_i];
			HIT_ee_buf_MAX_num = 102;
			break;
		}
			HIT_change_num_H = (HIT_change_num&0xff00)>>8;
			HIT_change_num_L = HIT_change_num&0x00ff;
			HIT_iic_word_send[0] = HIT_w_to_ee_i*2;//(HIT_rec_adrr_short-HIT_start_address)*2;
			HIT_iic_word_send[1] = HIT_w_to_ee_i*2+1;//HIT_w_to_ee_i*2 + 1;//(HIT_rec_adrr_short-HIT_start_address)*2 + 1;

			if((HIT_data_write_buff_num == 2)&&(HIT_w_to_ee_i == 7))
			{
				HIT_change_num = HIT_FNnum[6];
				HIT_change_num_H = (HIT_change_num&0xff00)>>8;
				HIT_change_num_L = HIT_change_num&0x00ff;
				HIT_iic_word_send[0] = 12;
				HIT_iic_word_send[1] = 13;	
			}	
			if(HIT_enable_par_initial == 1)
			{
				HIT_write_ee_addr();
			}

			if(HIT_iic_write_choose == 32)
			{
				HIT_iic_write_choose = 1;
				HIT_w_to_ee_i++;	
			}
			if(HIT_w_to_ee_i == HIT_ee_buf_MAX_num)
			{
				HIT_w_to_ee_i = 0;	
				HIT_data_write_buff_num++;
				if(HIT_data_write_buff_num == 4)
				{
					HIT_data_write_buff_num = 1;
					HIT_enable_par_initial = 0;	
				}
			}
			for(HIT_ee_delay=0;HIT_ee_delay<70000;HIT_ee_delay++)
			{
				;
			}
			
}


