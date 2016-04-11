#ifndef MECH_PI
#define MECH_PI
#include"HIT_mechanicalpi.h"
#include<math.h>
#include<mathf.h>
float HIT_speedlpf_now = 0;
float HIT_speed_a_err = 0;
float HIT_speedlpf_before = 0;
float HIT_WL_Mech_spee_out_Tmc_pro = 0;
float HIT_spe_pro_back_beta = 0.9;
float HIT_mech_aa_q_max = 0;
extern float HIT_iq_ref_mech_max;
extern float HIT_M_12_w_ref;
extern float HIT_bf_c_open;
extern float HIT_bf_a;
extern float HIT_bf_b;
extern float HIT_M_12_speed_step;
extern float HIT_M_12_w_ref_err;
extern float HIT_I_FF_ref;
extern float HIT_run_mode;
extern float HIT_w_F_FF;
extern float HIT_I_FF;
extern float HIT_w_F_FF;
float HIT_speedlpf_out;
extern float HIT_bf_m_open;
//float HIT_OBW_we = 0;
float HIT_speedlpf_out_OBW = 0;
extern float HIT_w_OBW_foctor;
extern float HIT_OBW_w_OBW;
//20140719
float HIT_Wlw_iacc = 0;
float HIT_WLw_ref_old = 0;
float HIT_Wlw_Kacc = 0.5;
extern float HIT_WLw_ref_mode_2_max;
void HIT_mechanicalpi()
{
	
	
	
//		HIT_sitafir = HIT_sita;
   /*		if(HIT_lpfcount < 3)
		{
			HIT_sita1 = HIT_sitafir;
			HITlpf_count++;	
		}*/
//		HIT_sitaerr = HIT_sitafir - HIT_sita1;//HIT_sitafir - HIT_sita1;//HIT_sita1 - HIT_sitafir;//HITsitafir - HITsita1;
//		HIT_sita1 = HIT_sitafir;
	
		
//		if(HIT_sitaerr>HIT_PIE)//avoid happen the jump of the sitaerr
//		{
//			HIT_sitaerr = HIT_sitaerr-HIT_TWOPIE;	
//		}
//		if(HIT_sitaerr<-HIT_PIE)
//		{
//			HIT_sitaerr = HIT_TWOPIE+HIT_sitaerr;
//		}
//		HIT_we = HIT_sitaerr/HIT_Tsa;//*HIT_speedpar;//////* calculate speed rad/s */
    //		HIT_OBW_state();
    //		HIT_OBW_we = HIT_we;
//		HIT_wone = HIT_we;/*speed filter*/
//		HIT_speedlpf = HIT_lpfv1A * HIT_speedlpf;
//		HIT_speedlpf = HIT_speedlpf + HIT_lpfv1B * HIT_wone;
//		HIT_speedlpf = HIT_speedlpf + HIT_lpfv1B * (HIT_wtwo-HIT_speedlpf);
//		HIT_wtwo = HIT_wone;/*filter end*/ 
//		HIT_speedlpf_out = HIT_speedlpf;
		
		
		
		
		
		
		HIT_speedlpf_out_OBW = HIT_speedlpf_out*(1 - HIT_w_OBW_foctor) + HIT_w_OBW_foctor*HIT_OBW_w_OBW;
		
		if(HIT_run_mode == 15)
		{
//			HIT_speedlpf = HIT_w_F_FF;	
		}
		
//		HIT_speedlpf_pole = HIT_speedlpf*HIT_poles;
		HIT_speedlpf_pole = HIT_speedlpf_out_OBW*HIT_poles;
		
//		HIT_WLw_err_orig = HIT_WLw_ref-HIT_speedlpf;/*speed PI*/
		HIT_WLw_err_orig = HIT_WLw_ref-HIT_speedlpf_out_OBW;/*speed PI*/
/*		if(HIT_bf_m_open == 2)
		{
			HIT_WLw_err_orig = HIT_WLw_err_orig + HIT_w_F_FF*HIT_bf_a;//HIT_M_12_w_ref*HIT_bf_a;	
		}*/
/*		if(HITWLw_err_orig>50)
		{
			HIT_pwm_stop = 0;//stop PWM
			
		}
		else if(HITWLw_err_orig<-50)
		{
			HIT_pwm_stop = 0;//stop PWM
		}*/
		HIT_WLw_err = HIT_WLw_err_orig;
		HIT_WLw_err = HIT_WLMech_Ki*HIT_WLw_err;
		HIT_WLw_org = HIT_WLw_err+HIT_WLw_org;
		
///////////////add 20140428//////////////////////		
		HIT_mech_aa_q_max = HIT_iq_ref_mech_max*HIT_WL_T_factor/HIT_WL_Jm/HIT_WLMechkv+HIT_WLw_ref_mode_2_max;//20141226///100;
		
		if(HIT_WLw_org > HIT_mech_aa_q_max)
		{ 
			HIT_WLw_org = HIT_mech_aa_q_max;
		}
		if(HIT_WLw_org < -HIT_mech_aa_q_max)
		{
			HIT_WLw_org = -HIT_mech_aa_q_max;	
		}
///////////////add 20140428//////////////////////		
		
		HIT_WL_Mech_spee_out = HIT_WLw_org + HIT_Mech_alfa*HIT_WLw_ref;/////calculate 
//		HIT_WL_Mech_spee_out = HIT_WL_Mech_spee_out - HIT_speedlpf;
		HIT_WL_Mech_spee_out = HIT_WL_Mech_spee_out - HIT_speedlpf_out_OBW;
		if(HIT_bf_m_open == 2)
		{
			HIT_WL_Mech_spee_out = HIT_WL_Mech_spee_out + HIT_w_F_FF*HIT_bf_a;//HIT_M_12_w_ref*HIT_bf_a;	
		}
		HIT_WL_Mech_spee_out = HIT_WL_Mech_spee_out*HIT_WLMechkv;
		HIT_WL_Mech_spee_out_Tmc = HIT_WL_Mech_spee_out*HIT_WL_Jm;/////calculate Tmc
		/*speed PI end*/
		//Speed pro_back///////////////////////////////////
/*		HIT_speedlpf_now = HIT_speedlpf;
		HIT_speed_a_err = HIT_speedlpf_now - HIT_speedlpf_before;
		HIT_speedlpf_before = HIT_speedlpf_now;
		HIT_WL_Mech_spee_out_Tmc_pro = HIT_speed_a_err*HIT_WL_Jm*HIT_spe_pro_back_beta;
		HIT_WL_Mech_spee_out_Tmc = HIT_WL_Mech_spee_out_Tmc_pro + HIT_WL_Mech_spee_out_Tmc;*/
		//Speed pro_back END///////////////////////////////////
		
		HIT_iq_ref = HIT_WL_Mech_spee_out_Tmc/HIT_WL_T_factor;
	///////////20140719////////
		HIT_Wlw_iacc = 0;//(HIT_WLw_ref - HIT_WLw_ref_old)*HIT_Wlw_Kacc;
		if(HIT_Wlw_iacc < 0)
		{
			HIT_Wlw_iacc = 0;
		}
		HIT_WLw_ref_old = HIT_WLw_ref;
		HIT_iq_ref = HIT_iq_ref + HIT_Wlw_iacc;
		
///////////////add 20140428//////////////////////

//add20151116
/*zhengzhuan*/		
		if(HIT_iq_ref > HIT_iq_ref_mech_max)
		{
			HIT_iq_ref = HIT_iq_ref_mech_max;
		}
		if(HIT_iq_ref < 0)
		{
			HIT_iq_ref = 0.01;
		}
	
/*fanzhuan*/
/*
		if(HIT_iq_ref > 0)
		{
			HIT_iq_ref = -0.01;
		}
		if(HIT_iq_ref < -HIT_iq_ref_mech_max)
		{
			HIT_iq_ref = -HIT_iq_ref_mech_max;
		}

*/	
///////////////add 20140428//////////////////////
}


#endif