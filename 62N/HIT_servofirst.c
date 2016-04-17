#ifndef HITSERVO_FIRSTC
#define HITSERVO_FIRSTC
#include"HIT_servofirst.h"
#include<math.h>
#include<mathf.h>
extern int HIT_new_angle_int;
extern float HIT_WLw_ref_mode_2;
void HIT_servofirst()
{
	HIT_make_angle();
	HIT_servo_on_first();
	HIT_position_fb_f  = HIT_sita;

//	HIT_sita1 = HIT_sitafir;//void mechanicalpi() calculate for HIT_speedlpf
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	HIT_virtual_ps_int_sec = 0x64;//void HITpositioncontrol() 	calculate for position control HITvirtual_ps_int_sec
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
//	HIT_position1_fb_16_int = (int)(HIT_position_fb_f * HIT_POSITIONERR_16WEI);//void HITpositioncontrol()  calculate for position control positon_fb
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
//	HIT_position1_fb_16_int = HIT_sita*HIT_POSITIONERR_16WEI;
//	HIT_position1_fb_16_int = HIT_new_angle_int;//HIT_sita*HIT_POSITIONERR_16WEI;
	HIT_positon_Kp_f = HIT_positon_Kp_int_float;//(float)HIT_positon_Kp_int;//HIT_positon_Kp_int_float;//(float)HIT_positon_Kp_int;//the first value of HITpositon_Kp_f use in void positioncontrol()
	HIT_positon_Kp_f = HIT_positon_Kp_f*HIT_TWOPIE/HIT_POSITION_16WEI;
//	HIT_pos_org_f = 0.0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*get HIT_iu_fb HIT_iv_fb HIT_iw_fb*/	
	HIT_iu_fbad = HIT_u_sensor;
	HIT_iw_fbad = HIT_w_sensor;
	HIT_iv_fbad = HIT_v_sensor;
	
	HIT_iu_fbadf = (float)HIT_iu_fbad;
	HIT_iw_fbadf = (float)HIT_iw_fbad;
	HIT_iv_fbadf = (float)HIT_iv_fbad;
	
	HIT_iu_fb = -(HIT_iu_fbadf*HIT_adad-HIT_VOLCENTER);
	HIT_iu_fb = HIT_iu_fb*HIT_curr;
	HIT_iu_fb = HIT_iu_fb-HIT_iu_fb_avg;//calculate Iu
	HIT_iw_fb = -(HIT_iw_fbadf*HIT_adad-HIT_VOLCENTER);
	HIT_iw_fb = HIT_iw_fb*HIT_curr;
	HIT_iw_fb = HIT_iw_fb-HIT_iw_fb_avg;//calculate Iw

	HIT_iv_fb = -(HIT_iv_fbadf*HIT_adad-HIT_VOLCENTER);
	HIT_iv_fb = HIT_iv_fb*HIT_curr;
	HIT_iv_fb = HIT_iv_fb-HIT_iv_fb_avg;//calculate Iw


	HIT_drain = HIT_iu_fb + HIT_iv_fb + HIT_iw_fb;
	HIT_drain = HIT_drain/3;
	HIT_iu_fb = HIT_iu_fb - HIT_drain;//get iu_fb,iv_fb,iw_fb
	HIT_iv_fb = HIT_iv_fb - HIT_drain;
	HIT_iw_fb = HIT_iw_fb - HIT_drain;/*end*/
	HIT_iutwo = HIT_iu_fb;//current filter  the first value of HITiutwo use in current_pi()
	HIT_ivtwo = HIT_iv_fb;//current filter  the first value of HITivtwo use in current_pi()
	HIT_iwtwo = HIT_iw_fb;//current filter  the first value of HITiwtwo use in current_pi()
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	HIT_Umsensor_f = (float)HIT_Umsensor;/*calculate voltage*/
	HIT_now_voltage_f = (HIT_Um_standard/HIT_Umsensor_f_standard)* HIT_Umsensor_f;
	HIT_now_voltage_two = HIT_now_voltage_f;/*voltage filter u*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
//	HIT_sita1 = HIT_sita; //calculate the HITsita1   use for calculate speed 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	HIT_servofirst_begin = 0;//go to servo_on 
	HIT_WLw_ref_mode_2 = 0;
}
#endif