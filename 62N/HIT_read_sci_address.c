extern unsigned char HIT_case1 ;
extern unsigned char HIT_case2 ;
extern unsigned char HIT_case3 ;
extern unsigned char HIT_case4 ;
extern unsigned short HIT_rec_adrr_short_0;
extern unsigned short HIT_rec_adrr_short_1;
extern unsigned short HIT_rec_adrr_short_2;
extern unsigned short HIT_rec_adrr_short_3;
extern union {
		unsigned char HIT_rec_adrr_real_char;
		struct {
			unsigned char HIT_rec_adrr_real_data:4;//最低位
			unsigned char HIT_rec_adrr_real_state:1;//中间位
			unsigned char HIT_rec_adrr_real_serial:3;//最高位
		} BIT;
	} HIT_rec_adrr_real[8];
extern unsigned short HIT_rec_adrr_short;
unsigned short HIT_ling_zhi = 0;
void HIT_read_sci_address()
{
	//提取地址值
		if(HIT_rec_adrr_real[0].BIT.HIT_rec_adrr_real_data == HIT_rec_adrr_real[4].BIT.HIT_rec_adrr_real_data)
		{
			HIT_rec_adrr_short_0 = (unsigned short)(HIT_rec_adrr_real[0].BIT.HIT_rec_adrr_real_data);
			HIT_case1 = 1;
		} 
		if(HIT_rec_adrr_real[1].BIT.HIT_rec_adrr_real_data == HIT_rec_adrr_real[5].BIT.HIT_rec_adrr_real_data)
		{
			HIT_rec_adrr_short_1 = (unsigned short)(HIT_rec_adrr_real[1].BIT.HIT_rec_adrr_real_data); 
			HIT_case2 = 1;
		}
		if(HIT_rec_adrr_real[2].BIT.HIT_rec_adrr_real_data == HIT_rec_adrr_real[6].BIT.HIT_rec_adrr_real_data)
		{
			HIT_rec_adrr_short_2 = (unsigned short)(HIT_rec_adrr_real[2].BIT.HIT_rec_adrr_real_data);
			HIT_case3 = 1;
		} 
		if(HIT_rec_adrr_real[3].BIT.HIT_rec_adrr_real_data == HIT_rec_adrr_real[7].BIT.HIT_rec_adrr_real_data)
		{
			HIT_rec_adrr_short_3 = (unsigned short)(HIT_rec_adrr_real[3].BIT.HIT_rec_adrr_real_data);
			HIT_case4 = 1;
		}
		if((HIT_case1 == 1)&&(HIT_case2 == 1)&&(HIT_case3 == 1)&&(HIT_case4 == 1))
		{
	 		HIT_rec_adrr_short = (HIT_rec_adrr_short_0<<12) + (HIT_rec_adrr_short_1<<8) +	(HIT_rec_adrr_short_2<<4) + (HIT_rec_adrr_short_3); 
			HIT_case1 = 0;
			HIT_case2 = 0;
			HIT_case3 = 0;
			HIT_case4 = 0;
			if(HIT_rec_adrr_short == 0)
			{
				HIT_ling_zhi = 1;	
			}
			else
			{
				HIT_ling_zhi = 0;	
			}
		}
		else 
		{
			HIT_rec_adrr_short = 0;	
		}	
}