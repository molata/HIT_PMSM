extern float HIT_pos_org_f;
extern float HIT_M_12_w_ref;
extern float HIT_iq_fb;
extern float HIT_I_FF;
extern float HIT_speedlpf_out;
extern float HIT_w_F_FF;
float HIT_DA_out = 0;
extern unsigned short HIT_DA_chnl;
extern float HIT_DA_one;
extern float HIT_DA_two;
int HIT_DA_chose = 0;
extern float HIT_OBC_id;
extern float HIT_OBC_iq;
extern float HIT_OBC_Dd;
extern float HIT_OBC_Dq;
extern float HIT_U_F;
extern float HIT_OBW_w;
extern float HIT_OBW_w_OBW;
extern float HIT_OBW_Err;
#define HIT_PIE 3.1415926
extern float HIT_we;
extern float HIT_sita_mode_15_run_err_f;
extern float HIT_FF_REF_err_out_f;
extern float HIT_FB_REF_err_out_f;
extern float HIT_sita_mode_10_f;
extern float HIT_sita_mode_10_f_lpf;
extern float HIT_10_photo_Ts_val_DA;
extern int HIT_mode_10_mag_sita_int_DA;
extern float HIT_10_err_val;
extern float HIT_10_err_val_DA;
extern float HIT_10_err_val_err;
extern float HIT_id_fb;
extern float HIT_id_ref;
extern float HIT_iq_ref;
extern float HIT_iq_fb;
extern float HIT_BF_REF_err_out_f;
extern float HIT_speedlpf_out_OBW;
extern float HIT_WL_Mech_spee_out;
extern float HIT_WL_Mech_spee_out_Tmc;
extern float HIT_WLw_ref;
extern unsigned short HIT_RX;
extern unsigned short HIT_new_angle_short;
extern int HIT_sitadian;
extern int HIT_sitaintf_pole_int;
extern float HIT_iu_fb;
extern float HIT_Uq;
extern float HIT_Ud;
extern float HIT_WLw_err_orig;
extern float HIT_iu_fb;
extern float HIT_iv_fb;
extern float HIT_iw_fb;
void HIT_DA_out_fuc()
{
	
	if(HIT_DA_chnl == 1)
	{
		HIT_DA_chose = (int)HIT_DA_one;	
	}
	else
	{
		HIT_DA_chose = (int)HIT_DA_two;	
	}
	switch(HIT_DA_chose)
	{
		case 1://DA1  位置误差
		HIT_DA_out = HIT_pos_org_f;
		break;
		case 2://DA1  Pn000
		HIT_DA_out = HIT_M_12_w_ref;
		break;
		case 3://DA1  Pn000
		HIT_DA_out = HIT_iq_fb;
		break;
		case 4://DA1  Pn000
		HIT_DA_out = HIT_I_FF;
		break;
		case 5://DA1  Pn000
		HIT_DA_out = HIT_speedlpf_out;
		break;
		case 6://DA1  Pn000
		HIT_DA_out = HIT_w_F_FF;
		break;
		case 7://DA1  Pn000
		HIT_DA_out = HIT_OBC_id;
		break;
		case 8://DA1  Pn000
		HIT_DA_out = HIT_OBC_iq;
		break;
		case 9://DA1  Pn000
		HIT_DA_out = HIT_OBC_Dd;
		break;
		case 10://DA1  Pn000
		HIT_DA_out = HIT_OBC_Dq;
		break;
		case 11://DA1  Pn000
		HIT_DA_out = HIT_U_F;
		break;
		case 12:
		HIT_DA_out = HIT_OBW_w_OBW;
		break;
		case 13:
		HIT_DA_out = HIT_OBW_Err/2/HIT_PIE*65536;
		break;
		case 14:
		HIT_DA_out = HIT_we;
		break;
		case 15:
		HIT_DA_out = HIT_sita_mode_15_run_err_f;
		break;
		case 16:
		HIT_DA_out = HIT_FF_REF_err_out_f;
		break;
		case 17:
		HIT_DA_out = HIT_FB_REF_err_out_f;
		break;
		case 18:
		HIT_DA_out = HIT_mode_10_mag_sita_int_DA;
		break;
		case 19:
		HIT_DA_out = HIT_sita_mode_10_f_lpf;
		break;
		case 20:
		HIT_DA_out = HIT_10_photo_Ts_val_DA;
		break;
		case 21:
		HIT_DA_out = HIT_10_err_val;
		break;
		case 22:
		HIT_DA_out = HIT_10_err_val_err;
		break;
		case 23:
		HIT_DA_out = HIT_id_fb;
		break;
		case 24:
		HIT_DA_out = HIT_id_ref;
		break;
		case 25:
		HIT_DA_out = HIT_iq_fb;
		break;
		case 26:
		HIT_DA_out = HIT_iq_ref;
		break;
		case 27:
		HIT_DA_out = HIT_BF_REF_err_out_f; //20140112 前馈与反馈差
		break;
		case 28:
		HIT_DA_out = HIT_speedlpf_out_OBW; //20140313机械环速度
		break;
		case 29:
		HIT_DA_out = HIT_WL_Mech_spee_out; //20140313
		break;
	    case 30:
		HIT_DA_out = HIT_WL_Mech_spee_out_Tmc; //20140313
		break;
		case 31:
		HIT_DA_out = HIT_WLw_ref;
		break;
		case 32:
		HIT_DA_out = HIT_sitadian;//HIT_new_angle_short/2; 电角度
		break;
		case 33:
       	HIT_DA_out = HIT_new_angle_short;
		break;
		case 34:
		HIT_DA_out = HIT_iu_fb*5;//AD采样的反馈电流
		break;
		case 35:
		HIT_DA_out = HIT_Uq;//
		break;
		case 36:
		HIT_DA_out = HIT_Ud;//
		break;
	    case 37:
		HIT_DA_out = HIT_WLw_err_orig;//指令速度与反馈速度的偏差rad/s105-
		break;
		case 38:
		HIT_DA_out = HIT_iu_fb;
		break;
	    case 39:
		HIT_DA_out = HIT_iv_fb;
		break;
		case 40:
		HIT_DA_out = HIT_iw_fb;
		break;
	}	
}