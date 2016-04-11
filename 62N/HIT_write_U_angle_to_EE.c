extern unsigned char HIT_ee_con_byte_0 ;
extern unsigned short HIT_change_num_H;
extern unsigned short HIT_change_num_L;
extern unsigned short HIT_new_angle_short;
extern unsigned char HIT_iic_word_send[2] ;
unsigned short HIT_filter_initial_7 = 1;
unsigned short HIT_filter_depth_7;
unsigned short HIT_filter_i_7;
int HIT_a_phase_filter_7[16];
extern int HIT_new_angle_int;
int HIT_a_phase_sum_7;
unsigned short HIT_new_angle_7;
unsigned short HIT_run_mode_7_count = 0;
void HIT_write_U_angle_to_EE()
{
	if(HIT_filter_initial_7 == 1)
		{
			HIT_filter_initial_7 = 0;
			HIT_filter_depth_7 = 0;
			for (HIT_filter_i_7=0;HIT_filter_i_7<16;HIT_filter_i_7++)
			{
				HIT_a_phase_filter_7[HIT_filter_i_7] = HIT_new_angle_int;
				HIT_a_phase_sum_7 = HIT_new_angle_int << 4;
			}		
		}
		HIT_a_phase_sum_7 -= HIT_a_phase_filter_7[HIT_filter_depth_7];
		HIT_a_phase_filter_7[HIT_filter_depth_7] = HIT_new_angle_int;
		HIT_a_phase_sum_7 += HIT_new_angle_int;
		++HIT_filter_depth_7;
		if(HIT_filter_depth_7 == 16)
		{
			HIT_filter_depth_7 = 0;
		}
		HIT_new_angle_7 = (unsigned short)(HIT_a_phase_sum_7/16);
		
	
	HIT_run_mode_7_count++;
	if(HIT_run_mode_7_count > 25)
	{
		HIT_ee_con_byte_0 = 0xa2;
		HIT_change_num_H = (HIT_new_angle_7&0xff00)>>8;
		HIT_change_num_L = HIT_new_angle_7&0x00ff;
		HIT_iic_word_send[0] = 14;
		HIT_iic_word_send[1] = 15;
		HIT_write_ee_addr();
		HIT_run_mode_7_count = 26;
	}	
}