
//long long int HIT_s_ref_f_out_long = 0;
extern float HIT_s_ref_f_out;
//long long int HIT_s_ref_f_out_err_long;
float HIT_s_ref_f_out_err_f = 0;
//long long int HIT_s_ref_f_out_long_FF = 0;
float HIT_w_F_ref;
extern float HIT_Ts;
float HIT_w_F_FF_err;
float HIT_w_F_FF = 0;
float HIT_KV_FF = 1000;
float HIT_KI_FF = 3000;
float HIT_w_F_FF_org = 0;
float HIT_FF_i_lim=20;  // modfiy 20140112 10
extern float HIT_I_FF_ref;
float HIT_Kp_FF = 330;
float HIT_Tn_FF;
extern float HIT_I_FF;
extern float HIT_WL_Jm;
float HIT_Tn_FF_org = 0;
float HIT_s_ref_f_out_FF_1;
float HIT_s_ref_f_out_FF = 0;
extern float HIT_WL_Jm_FF;
extern float HIT_w_F_ref_shou;
float HIT_s_ref_f_out_long_ceshi_f;
float HIT_s_ref_f_out_err_long_ceshi_f;
float HIT_s_ref_f_out_long_FF_ceshi_f;
extern float HIT_M_12_w_ref;
extern float HIT_WL_T_factor_FF;
#define HIT_PIE 3.1415926
void HIT_ref_lpf_pref()
{
	
/*	HIT_s_ref_f_out_long = (long long int)(	HIT_s_ref_f_out_long + HIT_s_ref_f_out*65536);
//	HIT_s_ref_f_out_long = 1000;
//	HIT_s_ref_f_out_err_long = HIT_s_ref_f_out_long - HIT_s_ref_f_out_long_FF;
	
	HIT_s_ref_f_out_long_ceshi_f = 1000;
	HIT_s_ref_f_out_err_long_ceshi_f = HIT_s_ref_f_out_long_ceshi_f - HIT_s_ref_f_out_long_FF_ceshi_f;
	
	
//	HIT_s_ref_f_out_err_f = (float)HIT_s_ref_f_out_err_long;
	HIT_w_F_ref = HIT_s_ref_f_out_err_long_ceshi_f*HIT_Kp_FF/65536*2*HIT_PIE/HIT_Ts;
	
//	HIT_w_F_ref = HIT_s_ref_f_out_err_f*HIT_Kp_FF/65536/65536*2*HIT_PIE/HIT_Ts;*/
	HIT_w_F_ref = HIT_M_12_w_ref;
///////////////////////////////////////////////////////////////////////////	
	HIT_w_F_FF_err = HIT_w_F_ref - HIT_w_F_FF;
	HIT_w_F_FF_err = HIT_w_F_FF_err*HIT_KV_FF;       
	HIT_w_F_FF_err = (HIT_w_F_FF_err - HIT_w_F_FF);
	
	HIT_w_F_FF_err = HIT_w_F_FF_err*HIT_KI_FF;
	HIT_w_F_FF_org = HIT_w_F_FF_org + HIT_w_F_FF_err;
	HIT_w_F_FF_org = HIT_w_F_FF_org*HIT_WL_Jm_FF/HIT_WL_T_factor_FF;
	
	if(HIT_w_F_FF_org > HIT_FF_i_lim)
	{
		HIT_w_F_FF_org = HIT_FF_i_lim;
	}
	if(HIT_w_F_FF_org < -HIT_FF_i_lim)
	{
		HIT_w_F_FF_org = -HIT_FF_i_lim;
	}
	HIT_I_FF_ref = HIT_w_F_FF_org;
	HIT_ref_lpf_iref();
	
	HIT_Tn_FF = HIT_I_FF*HIT_WL_T_factor_FF;
	HIT_Tn_FF = HIT_Tn_FF/HIT_WL_Jm_FF*HIT_Ts;///20000/20000*HIT_Ts;


	HIT_w_F_FF = HIT_Tn_FF_org;
	
	HIT_Tn_FF_org = HIT_Tn_FF_org + HIT_Tn_FF;
	

/*	
	HIT_w_F_FF_org = HIT_w_F_FF_org + HIT_w_F_FF*HIT_Ts;
// 	HIT_s_ref_f_out_FF_1 = HIT_w_F_FF_org;
//	HIT_s_ref_f_out_FF = HIT_s_ref_f_out_FF + HIT_s_ref_f_out_FF_1*HIT_Ts;
	HIT_s_ref_f_out_FF = HIT_w_F_FF_org;
//	HIT_s_ref_f_out_long_FF = (long long int)(HIT_s_ref_f_out_FF/2/HIT_PIE*65536*65536);
	HIT_s_ref_f_out_long_FF_ceshi_f = (HIT_s_ref_f_out_FF/2/HIT_PIE*65536);*/
}

	
