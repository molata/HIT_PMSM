float HIT_OBC_L1_d;
float HIT_OBC_L2_d;
float HIT_OBC_L1_q;
float HIT_OBC_L2_q;
extern float HIT_OBC_Ld;
extern float HIT_OBC_Lq;
float HIT_OBC_id_ob_1;
float HIT_OBC_id_ob_2;
float HIT_OBC_id_ob_3;
float HIT_OBC_iq_ob_1;
float HIT_OBC_iq_ob_2;
float HIT_OBC_iq_ob_3;
extern float HIT_OBC_current_wn;
extern float HIT_OBC_current_kexi;
extern float HIT_OBC_Rs;
extern float HIT_Ts;
extern float HIT_OBW_l1;
extern float HIT_OBW_l2;
extern float HIT_OBW_l3;
float HIT_OBW_kexi1;
float HIT_OBW_kexi2;
float HIT_OBW_w;
void HIT_OBC_intial_cal()
{
	HIT_OBC_L1_d = HIT_OBC_Ld*HIT_OBC_current_wn*HIT_OBC_current_wn;
	HIT_OBC_L2_d = 2*HIT_OBC_current_kexi*HIT_OBC_current_wn - HIT_OBC_Rs/HIT_OBC_Ld;
	HIT_OBC_L1_q = HIT_OBC_Lq*HIT_OBC_current_wn*HIT_OBC_current_wn;
	HIT_OBC_L2_q = 2*HIT_OBC_current_kexi*HIT_OBC_current_wn - HIT_OBC_Rs/HIT_OBC_Lq;

	HIT_OBC_id_ob_1 = HIT_OBC_Rs/HIT_OBC_Ld*HIT_Ts;
	HIT_OBC_id_ob_2 = HIT_OBC_L1_d;//*HIT_Ts;
	HIT_OBC_id_ob_3 = HIT_OBC_L2_d;//*HIT_Ts;
	HIT_OBC_iq_ob_1 = HIT_OBC_Rs/HIT_OBC_Lq*HIT_Ts;
	HIT_OBC_iq_ob_2 = HIT_OBC_L1_q;//*HIT_Ts; 
	HIT_OBC_iq_ob_3 = HIT_OBC_L2_q;//*HIT_Ts;
	
	HIT_OBW_l1 = 3*HIT_OBW_kexi1*HIT_OBW_w;//3-HIT_OBW_kexi1*HIT_OBW_w;//3*HIT_OBW_kexi1*HIT_OBW_w;
	HIT_OBW_l2 = 3*HIT_OBW_kexi2*HIT_OBW_w*HIT_OBW_w;//(5-9*HIT_OBW_kexi1*HIT_OBW_w + 3*HIT_OBW_kexi2*HIT_OBW_w*HIT_OBW_w +  HIT_OBW_w*HIT_OBW_w*HIT_OBW_w)/2;//3*HIT_OBW_kexi2*HIT_OBW_w*HIT_OBW_w;
	HIT_OBW_l3 = HIT_OBW_w*HIT_OBW_w*HIT_OBW_w;//1-3*HIT_OBW_kexi1*HIT_OBW_w + 3*HIT_OBW_kexi2*HIT_OBW_w*HIT_OBW_w - HIT_OBW_w*HIT_OBW_w*HIT_OBW_w;//HIT_OBW_w*HIT_OBW_w*HIT_OBW_w;
}