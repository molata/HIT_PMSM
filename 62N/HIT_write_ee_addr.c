extern unsigned char HIT_iic_write_choose;
extern unsigned char HIT_iic_word_write[2] ;
extern unsigned char HIT_iic_word_send[2] ;
extern unsigned short HIT_change_num_H;
extern unsigned short HIT_change_num_L;
extern unsigned char HIT_ee_con_byte_0 ;
unsigned char HIT_iic_word_write_2[2];
unsigned char HIT_iic_word_write_1[2];
unsigned char HIThfuehf = 1;
void HIT_write_ee_addr()
{
	if(HIT_iic_write_choose == 1)
	{
		HIT_iic_word_write_1[0] = HIT_iic_word_send[0];
		HIT_iic_word_write_1[1] = 	(unsigned char)(HIT_change_num_H);
		//R_PG_I2C_MasterSend_C0(HIT_ee_con_byte_0, HIT_iic_word_write_1, 2);//block 1 dizhi 1 xie 2
	}
	if(HIT_iic_write_choose == 16)
	{
		HIT_iic_word_write_2[0] = HIT_iic_word_send[1];
		HIT_iic_word_write_2[1] = 	(unsigned char)(HIT_change_num_L);
	//	R_PG_I2C_MasterSend_C0(HIT_ee_con_byte_0, HIT_iic_word_write_2, 2);//block 1 dizhi 1 xie 2
		HIThfuehf = 2;
	}	
	HIT_iic_write_choose++;
}