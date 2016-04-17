//float HIT_i_vector_fb = 0.0;
extern float HIT_run_mode;
float HIT_i_vector_err;
//float HIT_i_vector_ref = 0.5;
float HIT_i_vector_org;
float HIT_U_vector;
extern float HIT_Ki;
extern float HIT_curren_aa_q_max;
extern float HIT_alfa;
extern float HIT_kv;
extern float HIT_Rs;
extern float HIT_Ud;
extern float HIT_Uq;
void HIT_moth_line_vector()
{
//	HIT_i_vector_err = HIT_i_vector_ref-HIT_i_vector_fb;////iu_fb 12nit AD
	HIT_i_vector_err = HIT_i_vector_err*HIT_Ki;
	HIT_i_vector_org = HIT_i_vector_org+HIT_i_vector_err;

	if(HIT_i_vector_org > HIT_curren_aa_q_max)
	{
		HIT_i_vector_org = HIT_curren_aa_q_max;	
	}
	if(HIT_i_vector_org < -HIT_curren_aa_q_max)
	{
		HIT_i_vector_org = -HIT_curren_aa_q_max;	
	}
//	HIT_U_vector = (HIT_i_vector_org+HIT_alfa*HIT_i_vector_ref-HIT_i_vector_fb)*HIT_kv;
//	HIT_U_vector = HIT_U_vector + HIT_Rs*HIT_i_vector_fb;
//		HIT_Ud = HIT_Ud-HIT_speedlpf_pole*HIT_Lq*HIT_iq_fb;/*claculate Ud*/ 
	HIT_Ud = HIT_U_vector;
	HIT_Uq = 0;	
}