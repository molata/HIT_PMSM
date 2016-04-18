
extern float HIT_Ki_c_FF;
float HIT_ff_c_w = 10000;
float HIT_ff_c_kexi = 1;
float HIT_ff_p_kexi2 = 2.2;
float HIT_ff_p_kexi1 = 2.2;
extern float HIT_Rs;
extern float HIT_lm;
extern float HIT_Kp_c_FF;
extern float HIT_KV_FF;
//float HIT_ff_p_w = 1900;
extern float HIT_Kp_FF;
extern float HIT_KI_FF;
extern float HIT_WL_Jm;
//float HIT_WL_T_factor_FF = 0.015;
extern float HIT_Ts;
float HIT_WL_Jm_FF = 0.00000059808;//0.0000003250742;//
void HIT_ff_cal_gain()
{
//	HIT_ff_c_w = 10000;
//	HIT_ff_c_kexi = 1;
////////////qian kui current//////////////
/***
	HIT_Ki_c_FF = HIT_ff_c_w*HIT_ff_c_w/(2*HIT_ff_c_kexi*HIT_ff_c_w - HIT_Rs/HIT_lm)*HIT_Ts;
	HIT_Kp_c_FF = 2*HIT_ff_c_kexi*HIT_ff_c_w -  HIT_Rs/HIT_lm;
	
	HIT_KV_FF = HIT_ff_p_kexi2*HIT_ff_p_w/HIT_ff_p_kexi1;
	HIT_Kp_FF = HIT_ff_p_w/3/HIT_ff_p_kexi2;
	HIT_KI_FF = 3*HIT_ff_p_kexi1*HIT_ff_p_w*HIT_Ts;
	***/
}