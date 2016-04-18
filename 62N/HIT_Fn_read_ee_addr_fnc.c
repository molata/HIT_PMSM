
extern unsigned char HIT_iic_word_send[];
extern unsigned short HIT_rec_adrr_short;
extern unsigned char HIT_iic_word_rec_ad;
extern unsigned char HIT_iic_word_rec_1;
extern unsigned char HIT_iic_word_rec_2;
extern unsigned char HIT_ee_con_byte_0 ;
extern unsigned char HIT_ee_con_byte_1 ;
extern unsigned short HIT_start_address;
extern unsigned short HIT_iic_word_rec_short;
void HIT_Fn_read_ee_addr_fnc()
{
	/**** 从EEPROM中读取数据 *****/
	{
		HIT_iic_word_send[0] = (HIT_rec_adrr_short-HIT_start_address)*2;///////the address iic read  
		HIT_iic_word_rec_ad = HIT_iic_word_send[0];
		R_PG_I2C_MasterSend_C0(HIT_ee_con_byte_0, &HIT_iic_word_rec_ad, 1);//R_PG_I2C_MasterSend_C0(0xa2, &HIT_iic_word_rec_ad, 1);//EE block 1
		R_PG_I2C_MasterReceive_C0(HIT_ee_con_byte_1,&HIT_iic_word_rec_1,1);//读取到HIT_iic_word_rec_1
	}
	
	{
		HIT_iic_word_send[1] = (HIT_rec_adrr_short-HIT_start_address)*2 + 1;/////the address iic read
		HIT_iic_word_rec_ad = HIT_iic_word_send[1];
		R_PG_I2C_MasterSend_C0(HIT_ee_con_byte_0, &HIT_iic_word_rec_ad, 1);//EE block 1
		R_PG_I2C_MasterReceive_C0(HIT_ee_con_byte_1,&HIT_iic_word_rec_2,1);//读取到HIT_iic_word_rec_2
	}	
	
	HIT_iic_word_rec_short = (((unsigned short)(HIT_iic_word_rec_1))<<8) + HIT_iic_word_rec_2;
	
	/*** 第二部分将数据发送到62T中 ***/
	
}