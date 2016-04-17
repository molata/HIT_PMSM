#ifndef HIT_GET_SCI_BUF_DATA
#define HIT_GET_SCI_BUF_DATA
//#include"iodefine.h"
extern unsigned char HIT_case1 ;
extern unsigned char HIT_case2 ;
extern unsigned char HIT_case3 ;
extern unsigned char HIT_case4 ;
extern char HIT_rec_adrr_i;
union {
		unsigned char HIT_rec_adrr_buff_char;
		struct {
			unsigned char HIT_rec_data:4;//最低位
			unsigned char HIT_rec_state:1;//中间位
			unsigned char HIT_rec_serial:3;//最高位
		} BIT;
	} HIT_rec_adrr_buff[8];
	
union {
		unsigned char HIT_rec_adrr_real_char;
		struct {
			unsigned char HIT_rec_adrr_real_data:4;//最低位
			unsigned char HIT_rec_adrr_real_state:1;//中间位
			unsigned char HIT_rec_adrr_real_serial:3;//最高位
		} BIT;
	} HIT_rec_adrr_real[8];
extern unsigned short HIT_rec_adrr_short_0;
extern unsigned short HIT_rec_adrr_short_1;
extern unsigned short HIT_rec_adrr_short_2;
extern unsigned short HIT_rec_adrr_short_3;
extern unsigned short HIT_rec_adrr_short;
void HIT_get_sci_buf_data()
{
	for(HIT_rec_adrr_i=0;HIT_rec_adrr_i<8;HIT_rec_adrr_i++)
	{
		switch(HIT_rec_adrr_buff[HIT_rec_adrr_i].BIT.HIT_rec_serial)//按序号重新排列数组
		{
			case 0:
			HIT_rec_adrr_real[0].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
			case 1:
			HIT_rec_adrr_real[1].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
			case 2:
			HIT_rec_adrr_real[2].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
			case 3:
			HIT_rec_adrr_real[3].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
			case 4:
			HIT_rec_adrr_real[4].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
			case 5:
			HIT_rec_adrr_real[5].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
			case 6:
			HIT_rec_adrr_real[6].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
			case 7:
			HIT_rec_adrr_real[7].HIT_rec_adrr_real_char = HIT_rec_adrr_buff[HIT_rec_adrr_i].HIT_rec_adrr_buff_char;
			break;
		}
	}
}
#endif