
#include"iodefine.h"
#include <math.h>
#include <mathf.h>
extern unsigned short HIT_p_getad_cmt[];
extern unsigned short HIT_p_getad_cmt[];
extern unsigned short HIT_n_getad_cmt[]; 
extern int HIT_make_angle_mode_cmt;
extern unsigned short HIT_a_p_hall_cmt;
extern unsigned short HIT_a_n_hall_cmt;
extern float HIT_a_hall_cmt;
extern float HIT_b_hall_cmt;
extern float HIT_c_hall_cmt;
extern float HIT_d_hall_cmt;
extern float HIT_q_hall_cmt;
extern signed int HIT_a_n_int_cmt;
extern signed int HIT_a_p_int_cmt;
extern signed int HIT_s0TX_buffer1_cmt;
extern signed int HIT_s0TX_buffer2_cmt;
extern signed int HIT_s0TX_buffer3_cmt;
extern float HIT_sita_cmt;
extern float HIT_sitaintf_curr_mech_f_cmt;
extern signed int HIT_sitaintf_curr_mech_int_cmt;
extern unsigned short HIT_sitaintf_curr_mech_short_cmt;
extern unsigned char HIT_enc_count;
extern int HIT_sitaintf_curr_mech_int_cmt_bia;
extern int HIT_check_area_int_cmt;
extern int HIT_check_area_bia_int_cmt;
extern float HIT_y_a1_f_cmt;
extern float HIT_y_a2_f_cmt;
extern float HIT_x_a1_f_cmt;
extern float HIT_k_f_cmt ;
extern float HIT_b_f_cmt ;
extern int HIT_add_point_int_cmt;
extern float HIT_biaodingarry[];
extern float HIT_add_point_f_cmt;
extern float HIT_biaoding_ang_f_cmt ;
extern float HIT_biaoding_f_cmt;
extern float HIT_new_angle_f_cmt;
extern int HIT_new_angle_int_cmt;
extern signed int HIT_sitaintf_curr_int_cmt;
extern unsigned char HIT_sitaintf_curr_mech_char_buff[];

#define HIT_HALFPIE 1.5708
#define HIT_PIE 3.1415926
#define HIT_TWOTHIRDPIE 4.71239
#define HIT_TWOPIE 6.28319
#define HIT_MAKE16WEI_ANGLE 10430.378
void HIT_shouchaoqi_angle()
{
	/**
			HIT_a_p_hall_cmt = (HIT_p_getad_cmt[0]>>4 );//hall signal A
			HIT_a_n_hall_cmt = (HIT_n_getad_cmt[0]>>4  );//hall signal B


			HIT_a_p_int_cmt = (signed int)HIT_a_p_hall_cmt;
			HIT_a_n_int_cmt = (signed int)HIT_a_n_hall_cmt;	

			HIT_s0TX_buffer1_cmt = HIT_a_p_int_cmt - 2048;
			HIT_s0TX_buffer2_cmt = HIT_a_n_int_cmt - 2048;
		
			HIT_s0TX_buffer3_cmt = -(HIT_s0TX_buffer1_cmt + HIT_s0TX_buffer2_cmt);
			HIT_a_hall_cmt = (float)HIT_s0TX_buffer1_cmt ;
			HIT_b_hall_cmt = (float)HIT_s0TX_buffer2_cmt ;
			HIT_c_hall_cmt = (float)HIT_s0TX_buffer3_cmt ;
			HIT_d_hall_cmt = HIT_a_hall_cmt-0.5*(HIT_b_hall_cmt+HIT_c_hall_cmt);/*angle 3->2*/
		//	HIT_q_hall_cmt = 0.866025*(HIT_b_hall_cmt-HIT_c_hall_cmt);
	/*angle zone calculate*/
	/**
			if(HIT_q_hall_cmt >= 0)
			{
				if(HIT_d_hall_cmt >=0)
				{
					if(HIT_d_hall_cmt > HIT_q_hall_cmt)
					{
						HIT_make_angle_mode_cmt = 1;	
					}
					if(HIT_d_hall_cmt > 0)
					{
						if(HIT_d_hall_cmt <= HIT_q_hall_cmt)
						{
							HIT_make_angle_mode_cmt = 2;	
						}	
					}
					else
					{
						if(HIT_q_hall_cmt == 0)
						{
							HIT_make_angle_mode_cmt = 9;	
						}	
					}	
				}
				else
				{
					if(HIT_q_hall_cmt >= -HIT_d_hall_cmt)	
					{
						HIT_make_angle_mode_cmt = 3;	
					}
					else
					{
						HIT_make_angle_mode_cmt = 4;	
					}
				}	
			}
			else
			{
				if(HIT_d_hall_cmt >=0)
				{
					if(HIT_d_hall_cmt > -HIT_q_hall_cmt)
					{
						HIT_make_angle_mode_cmt = 8;	
					}
					if(HIT_d_hall_cmt >0)
					{
						if(HIT_d_hall_cmt <= -HIT_q_hall_cmt)	
						{
							HIT_make_angle_mode_cmt = 7;	
						}
					}	
				}
				else
				{
					if(HIT_d_hall_cmt < HIT_q_hall_cmt)
					{
						HIT_make_angle_mode_cmt = 5;	
					}	
					else
					{
						HIT_make_angle_mode_cmt = 6;	
					}
				}	
			}
			switch(HIT_make_angle_mode_cmt)
			{
				case 1:
					HIT_sita_cmt=atan(HIT_q_hall_cmt/HIT_d_hall_cmt);
				break;	
				case 2:
					HIT_sita_cmt=HIT_HALFPIE-atan(HIT_d_hall_cmt/HIT_q_hall_cmt);
				break;	
				case 3:
					HIT_sita_cmt=HIT_HALFPIE+atan(-HIT_d_hall_cmt/HIT_q_hall_cmt);
				break;	
				case 4:
					HIT_sita_cmt=HIT_PIE-atan(HIT_q_hall_cmt/-HIT_d_hall_cmt);
				break;
				case 5:
					HIT_sita_cmt=HIT_PIE+atan(HIT_q_hall_cmt/HIT_d_hall_cmt);	
				break;
				case 6:
					HIT_sita_cmt=HIT_TWOTHIRDPIE-atan(HIT_d_hall_cmt/HIT_q_hall_cmt);	
				break;
				case 7:
					HIT_sita_cmt=HIT_TWOTHIRDPIE+atan(HIT_d_hall_cmt/-HIT_q_hall_cmt);	
				break;
				case 8:
					HIT_sita_cmt=HIT_TWOPIE-atan(-HIT_q_hall_cmt/HIT_d_hall_cmt);		
				break;
			}

	/*calculate end*/
	/***
			HIT_enc_count++;
			
			HIT_sitaintf_curr_mech_f_cmt = HIT_sita_cmt*HIT_MAKE16WEI_ANGLE;
			HIT_sitaintf_curr_mech_int_cmt = (signed int)HIT_sitaintf_curr_mech_f_cmt;
			HIT_sitaintf_curr_mech_int_cmt_bia = (signed int)HIT_sitaintf_curr_mech_f_cmt;
			
	//		HIT_sitaintf_curr_mech_short_cmt = (unsigned short)HIT_sitaintf_curr_mech_int_cmt;
////////check table////////	
			HIT_check_area_int_cmt = HIT_sitaintf_curr_mech_int_cmt_bia&0x0000ffc0;// high 10wei
			HIT_add_point_int_cmt = HIT_sitaintf_curr_mech_int_cmt_bia&0x0000003f;//low 6wei
			HIT_check_area_bia_int_cmt = HIT_check_area_int_cmt>>6;
	
		//	HIT_check_area_bia_f = (float)HIT_check_area_bia_int;
			if(HIT_check_area_bia_int_cmt==1023)
			{
				HIT_y_a1_f_cmt = HIT_biaodingarry[1023];
				HIT_y_a2_f_cmt = HIT_biaodingarry[0];	
			}
			else
			{
				HIT_y_a1_f_cmt = HIT_biaodingarry[HIT_check_area_bia_int_cmt];
				HIT_y_a2_f_cmt = HIT_biaodingarry[HIT_check_area_bia_int_cmt+1];	
			}

	
			HIT_x_a1_f_cmt = (float)HIT_check_area_bia_int_cmt;
			
			HIT_k_f_cmt = HIT_y_a2_f_cmt - HIT_y_a1_f_cmt;
			HIT_b_f_cmt = HIT_y_a1_f_cmt - HIT_k_f_cmt * HIT_x_a1_f_cmt;
	
			HIT_add_point_f_cmt = (float)HIT_add_point_int_cmt/64;
			HIT_biaoding_ang_f_cmt = HIT_k_f_cmt*(HIT_x_a1_f_cmt +  HIT_add_point_f_cmt) + HIT_b_f_cmt;

			HIT_biaoding_f_cmt = (float)HIT_sitaintf_curr_mech_int_cmt;
			HIT_new_angle_f_cmt = HIT_biaoding_ang_f_cmt + HIT_biaoding_f_cmt;
			if(HIT_new_angle_f_cmt > 65535)
			{
				HIT_new_angle_f_cmt = HIT_new_angle_f_cmt - 65535;	
			}
			if(HIT_new_angle_f_cmt < 0)
			{
				HIT_new_angle_f_cmt = HIT_new_angle_f_cmt + 65535;	
			}
			HIT_new_angle_int_cmt = (int)HIT_new_angle_f_cmt;

			HIT_sitaintf_curr_int_cmt = HIT_new_angle_int_cmt;
			HIT_sitaintf_curr_mech_int_cmt = HIT_sitaintf_curr_int_cmt;
////////check table end////////	
***/	
}