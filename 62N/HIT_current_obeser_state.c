//float HIT_Vd = 0;
//float HIT_Vq = 0;
extern float HIT_Lq;
extern float HIT_Ld;
extern float HIT_speedlpf_pole;
extern float HIT_iq_fb;
extern float HIT_id_fb;
extern float HIT_id_org;
extern float HIT_iq_org;
extern float HIT_alfa;
extern float HIT_id_ref;
extern float HIT_iq_ref;
extern float HIT_Ud;
extern float HIT_Uq;
extern float HIT_faif;
float HIT_id_state = 0;
float HIT_iq_state = 0;
extern float HIT_Rs;
extern float HIT_Ts;
float HIT_Dd = 0;
float HIT_Dq = 0;
float HIT_L1_q = 0;
float HIT_L2_q = 0;
float HIT_L1_d = 0;
float HIT_L2_d = 0;
void HIT_current_obeser_state()
{
	/***
//	HIT_Vd = (HIT_speedlpf_pole*HIT_Lq*HIT_iq_fb)/HIT_Ld;
//	HIT_Vd = (HIT_id_org+HIT_alfa*HIT_id_ref-HIT_id_fb)*HIT_kv/HIT_Ld + HIT_Vd;
	
	HIT_Vd = (HIT_speedlpf_pole*HIT_Lq*HIT_iq_fb+ HIT_Ud)/HIT_Ld ;
	
//	HIT_Vq = (-HIT_speedlpf_pole*HIT_Ld*HIT_id_fb - HIT_speedlpf_pole*HIT_faif)/HIT_Lq;
//	HIT_Vq = HIT_Vq + (HIT_iq_org + HIT_alfa * HIT_iq_ref - HIT_iq_fb) * HIT_kv/HIT_Lq;	
	
	HIT_Vq = (-HIT_speedlpf_pole*HIT_Ld*HIT_id_fb - HIT_speedlpf_pole*HIT_faif + HIT_Uq)/HIT_Lq;
	
	HIT_id_state = HIT_id_state - HIT_Rs/HIT_Ld*HIT_Ts*HIT_id_state + HIT_Dd*HIT_Ts;
	HIT_id_state = HIT_id_state + HIT_Vd*HIT_Ts;
	HIT_id_state = HIT_id_state + HIT_L1_d*HIT_Ts*(HIT_id_fb - HIT_id_state);
	
	HIT_Dd = HIT_Dd + HIT_L2_d*HIT_Ts*(HIT_id_fb - HIT_id_state);
	
	HIT_iq_state = HIT_iq_state - HIT_Rs/HIT_Lq*HIT_Ts*HIT_iq_state + HIT_Dq*HIT_Ts;
	HIT_iq_state = HIT_iq_state + HIT_Vq*HIT_Ts;
	HIT_iq_state = HIT_iq_state + HIT_L1_q*HIT_Ts*(HIT_iq_fb - HIT_iq_state);
	
	HIT_Dq = HIT_Dq + HIT_L2_q*HIT_Ts*(HIT_iq_fb - HIT_iq_state);
	***/
}