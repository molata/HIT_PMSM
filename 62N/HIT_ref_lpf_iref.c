extern float HIT_I_FF_ref;
float HIT_I_FF_err;
float HIT_I_FF = 0;
//float HIT_Ki;
float HIT_I_FF_org;
float HIT_U_F = 0;
float HIT_Kp_c_FF ;
float HIT_L_FF = 0.0007;
extern float HIT_Rs_FF ;
float HIT_U_FF_lim = 48;//30;
extern float HIT_Ts;
float HIT_Ki_c_FF ;

void  HIT_ref_lpf_iref()
{
	
//	HIT_I_FF_ref = 5;
//		HIT_U_FF_lim = 30;
		HIT_I_FF_err = HIT_I_FF_ref-HIT_I_FF;////
		HIT_I_FF_err = HIT_I_FF_err*HIT_Ki_c_FF;
		HIT_I_FF_org = HIT_I_FF_org+HIT_I_FF_err;
	
		
		HIT_U_F = (HIT_I_FF_org - HIT_I_FF)*HIT_Kp_c_FF*HIT_L_FF;
		
		
		if(HIT_U_F > HIT_U_FF_lim)
		{
			HIT_U_F = HIT_U_FF_lim;
		}
		if(HIT_U_F < -HIT_U_FF_lim)
		{
			HIT_U_F = -HIT_U_FF_lim;
		}		
		HIT_U_F = HIT_U_F - HIT_I_FF*HIT_Rs_FF;

		
		HIT_I_FF = HIT_U_F/HIT_L_FF*HIT_Ts + HIT_I_FF;
		
	
			
}