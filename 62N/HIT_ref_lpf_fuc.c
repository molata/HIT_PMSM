
float  HIT_s_ref = 0;
float  HIT_v_ref = 0;
float  HIT_a_ref = 0;
extern float HIT_M_12_w_out;
extern float HIT_M_12_w_ref;
extern float HIT_M_12_w_ref_err;
extern float  HIT_Tsa;
float HIT_s_ref_one = 0;
float HIT_s_ref_two = 0;
float HIT_v_ref_one = 0;
float HIT_v_ref_two = 0;
float HIT_a_ref_one = 0;
float HIT_a_ref_two = 0;
float HIT_s_ref_f_out = 0;
float HIT_v_ref_f_out = 0;
float HIT_a_ref_f_out = 0;
extern float HIT_reflpf_standard_1A;
extern float HIT_reflpf_standard_1B;
float HIT_W_FF = 0;
float HIT_I_FF_ref = 0;
float HIT_U_FF = 0;
extern float HIT_bf_a;
extern float HIT_bf_b;
float HIT_bf_c;
extern float HIT_WL_Jm;
extern float HIT_WL_T_factor_FF;
float HIT_a_ref_f_out_1 = 0;
float HIT_a_ref_f_out_2 = 0;
float HIT_a_ref_f_out_err = 0;
extern float HIT_Ts;
extern float HIT_lm;
unsigned short HIT_reflpf_num = 1;
unsigned short HIT_reflpf_num_1 = 1;
float HIT_s_ref_f_mat[3];
float HIT_v_ref_f_mat[2];
float HIT_a_ref_f_mat[1];
int HIT_ref_zong_num = 0;
int HIT_M_12_w_out_org_int = 0;
float HIT_M_12_w_out_org = 0;
float HIT_WL_T_factor_FF = 0.015;
void HIT_ref_lpf_fuc()
{

	HIT_s_ref = HIT_M_12_w_out;//Âö³å/¿ØÖÆÖÜÆÚ
	HIT_v_ref = HIT_M_12_w_ref;//rad/s
	HIT_a_ref = HIT_M_12_w_ref_err/HIT_Tsa;//rad/s2	
		
	HIT_M_12_w_out_org = HIT_M_12_w_out + HIT_M_12_w_out_org;
	HIT_M_12_w_out_org_int = (int)HIT_M_12_w_out_org;
/*	
	HIT_s_ref_one = HIT_s_ref;
	HIT_s_ref_f_out = HIT_reflpf_standard_1A*HIT_s_ref_f_out;
	HIT_s_ref_f_out = HIT_s_ref_f_out +HIT_reflpf_standard_1B*HIT_s_ref_one;
	HIT_s_ref_f_out = HIT_s_ref_f_out +HIT_reflpf_standard_1B*(HIT_s_ref_two-HIT_s_ref_f_out);
	HIT_s_ref_two = HIT_s_ref_one;*/
	
/*	HIT_v_ref_one = HIT_v_ref;
	HIT_v_ref_f_out = HIT_reflpf_standard_1A*HIT_v_ref_f_out;
	HIT_v_ref_f_out = HIT_v_ref_f_out +HIT_reflpf_standard_1B*HIT_v_ref_one;
	HIT_v_ref_f_out = HIT_v_ref_f_out +HIT_reflpf_standard_1B*(HIT_v_ref_two-HIT_v_ref_f_out);
	HIT_v_ref_two = HIT_v_ref_one;
	
	HIT_a_ref_one = HIT_a_ref;
	HIT_a_ref_f_out = HIT_reflpf_standard_1A*HIT_a_ref_f_out;
	HIT_a_ref_f_out = HIT_a_ref_f_out +HIT_reflpf_standard_1B*HIT_a_ref_one;
	HIT_a_ref_f_out = HIT_a_ref_f_out +HIT_reflpf_standard_1B*(HIT_a_ref_two-HIT_a_ref_f_out);
	HIT_a_ref_two = HIT_a_ref_one;*/
	
/*	
	HIT_s_ref_f_mat[HIT_s_lpf_i] = HIT_s_ref_f_out;
	HIT_s_lpf_i++;	
	if(HIT_s_lpf_i > 3)
	{
		HIT_s_lpf_i = 0;	
	}
	if (HIT_s_lpf_i - 3 < 0)
	{
		HIT_s_lpf_i = HIT_s_lpf_i + 3;	
	}
	HIT_s_ref_f_out = HIT_s_ref_f_mat[HIT_s_lpf_i];
	
	
	HIT_v_ref_f_mat[HIT_v_lpf_i] = HIT_v_ref_f_out;
	HIT_v_lpf_i++;	
	if(HIT_v_lpf_i > 2)
	{
		HIT_v_lpf_i = 0;	
	}
	if (HIT_v_lpf_i - 2 < 0)
	{
		HIT_v_lpf_i = HIT_v_lpf_i + 2;	
	}
	HIT_v_ref_f_out = HIT_v_ref_f_mat[HIT_v_lpf_i];
	
	HIT_a_ref_f_mat[HIT_a_lpf_i] = HIT_a_ref_f_out;
	HIT_a_lpf_i++;	
	if(HIT_a_lpf_i > 1)
	{
		HIT_a_lpf_i = 0;	
	}
	if (HIT_a_lpf_i - 1 < 0)
	{
		HIT_a_lpf_i = HIT_a_lpf_i + 1;	
	}
	HIT_a_ref_f_out = HIT_a_ref_f_mat[HIT_a_lpf_i ];
*/
	
	HIT_ref_lpf_pref();

/*	if(HIT_reflpf_num == 1)
	{
		HIT_s_ref_f_out = 0;
		HIT_v_ref_f_out = 0;
		HIT_a_ref_f_out = 0;
		HIT_reflpf_num = 0;			
	}
	

	HIT_W_FF = HIT_v_ref_f_out*HIT_bf_a;
	HIT_I_FF_ref = HIT_a_ref_f_out*HIT_WL_Jm/HIT_WL_T_factor* HIT_bf_b;//HIT_M_12_w_ref_err*HIT_WL_Jm/HIT_WL_T_factor*HIT_bf_b
	
//	HIT_ref_lpf_iref();
	
	
	
	
	HIT_a_ref_f_out_1 = HIT_a_ref_f_out;
	HIT_a_ref_f_out_err = HIT_a_ref_f_out_1 - HIT_a_ref_f_out_2;
	HIT_a_ref_f_out_2 = HIT_a_ref_f_out_1;
	
	if(HIT_reflpf_num_1 == 1)
	{
		HIT_a_ref_f_out_err = 0;
		HIT_reflpf_num_1 = 0;			
	}
		
	HIT_U_FF = HIT_a_ref_f_out_err/HIT_Ts/HIT_WL_T_factor*HIT_lm*HIT_bf_c;//
	
	
	HIT_ref_zong_num ++;*/
}


