#include "HIT_par_initial.h"
#include<math.h>
#include<mathf.h>
#include"iodefine.h"
unsigned char HIT_star_R_ee_buff[20];
unsigned char HIT_star_R_ee;
unsigned char HIT_star_R_ee_i = 0;
unsigned char HIT_iic_word_send[];
extern unsigned short HIT_change_num;
extern unsigned char HIT_iic_word_rec_ad;
unsigned int HIT_ee_delay = 0;

unsigned char HIT_run_time_L;
unsigned char HIT_run_time_H;
unsigned short HIT_run_time;
unsigned char HIT_id_sc_H;
unsigned char HIT_id_sc_L;
unsigned char HIT_Mech_Kv_sc_H;
unsigned char HIT_Mech_Kv_sc_L;
unsigned char HIT_w_sc_H;
unsigned char HIT_w_sc_L;

unsigned short HIT_id_sc;
unsigned char HIT_Kp_sc_H;
unsigned char HIT_Kp_sc_L;
unsigned short HIT_Kp_sc;

unsigned short HIT_run_time_H_short;
unsigned short HIT_run_time_L_short;
unsigned short HIT_run_time_2;
unsigned int HIT_run_time_int = 0;
unsigned int HIT_run_time_2_int = 0;

unsigned short HIT_Mech_Kv_sc_H_short;
unsigned short HIT_Mech_Kv_sc_L_short;
unsigned short HIT_Mech_Kv_sc;
float HIT_Mech_Kv_sc_f;
extern float HIT_WLMechkv;

unsigned char HIT_Uphase_H;
unsigned char HIT_Uphase_L;
unsigned short HIT_Uphase_H_short;
unsigned short HIT_Uphase_L_short;
unsigned short HIT_Uphase;
int HIT_Uphase_int;
unsigned short HIT_id_sc_H_short = 0;
unsigned short HIT_id_sc_L_short = 0;
unsigned int HIT_id_sc_int;
float HIT_id_sc_f = 0;
unsigned short HIT_w_sc_H_short = 0;
unsigned short HIT_w_sc_L_short = 0;
unsigned short HIT_w_sc;
unsigned int HIT_w_sc_int;
float HIT_w_sc_f = 0;
float HIT_release_time_f = 0;
extern float HIT_WLw_ref;
extern float HIT_id_ref;
extern float HIT_iq_ref;
extern int HIT_position_client_int;
extern float HIT_positon_Kp_int_float;
//extern int HIT_positon_Kp_int;
extern float HIT_run_mode;
extern int HIT_sitadf_int;
unsigned char HIT_star_R_round = 0;
extern unsigned char HIT_ee_con_byte_0 ;
extern unsigned char HIT_ee_con_byte_1 ;
extern unsigned short HIT_start_address ;
extern unsigned short HIT_rec_adrr_short;
unsigned short HIT_ceshishi[10];
extern unsigned short HIT_iic_word_rec_short;
unsigned char HIT_faefn = 9;
extern unsigned short V_comm_i;
unsigned short V_comm_i_max;
extern float HIT_speed_command[];
unsigned short HIT_speed_command_i = 0;
unsigned short HIT_speed_time_i = 0;
extern float HIT_speed_time[];
unsigned char HIT_geishu_ser = 0;
float HIT_WLw_ref_in= 0;
extern float HIT_sudu_jian_val;
#define HIT_PIE 3.1415926
extern float HIT_xi_d_w;
float HIT_xi_d_curr_time = 0;
float HIT_xi_d_num = 1;
float HIT_xi_d_step = 1;
float HIT_xi_d_w_time = 0;
float HIT_xi_d_w_num = 1;
float HIT_xi_d_w_step = 1;
//extern float HIT_i_vector_ref;
//extern float HIT_i_vector_ref;
//float HIT_current_wn = 0.9;
//float HIT_current_kexi = 0.9;
extern float HIT_L1_d;
extern float HIT_L2_d;
extern float HIT_L1_q;
extern float HIT_L2_q;
extern float HIT_Ld;
extern float HIT_Lq;
extern float HIT_Rs;
float HIT_M_12_r_time = 1;
float HIT_M_12_k_time = 1;
float HIT_M_12_it_time = 1;
float HIT_M_12_max_speed = 1;
float HIT_M_12_k_time_num = 1;
float HIT_M_12_r_time_num = 1;
float HIT_M_12_it_time_num = 1;
float HIT_M_12_speed_step = 0;
float HIT_bf_a = 0;
float HIT_bf_b = 0;
float HIT_bf_m_open = 0;
float HIT_bf_c_open = 0;
float HIT_bf_u_open = 0;
extern float HIT_reflpf_standard_1A;
extern float HIT_reflpf_standard_1B;
extern float HIT_reflpf_tal;
extern float HIT_bf_c;
extern float HIT_ff_c_kexi;
extern float HIT_ff_c_w;
extern float HIT_U_FF_lim;
extern float HIT_ff_p_w;
extern float HIT_ff_p_kexi1;
extern float HIT_ff_p_kexi2;
extern float HIT_w_F_ref;
extern float HIT_WL_T_factor_FF;
float HIT_w_F_ref_shou;
extern float HIT_WL_T_factor;
extern float HIT_WL_Jm_FF;
extern float HIT_WL_Jm;
float HIT_DA_one_out = 2048;
float HIT_DA_two_out = 2048;
float HIT_DA_one = 12048;
float HIT_DA_two = 22048;
float HIT_DA_one_full = 1;
float HIT_DA_two_full = 1;
extern float HIT_OBC_current_wn;
extern float HIT_OBC_current_kexi;
extern float HIT_OBC_Rs;
extern float HIT_OBC_Ld;
extern float HIT_OBC_Lq;
extern float HIT_OBC_faif;
extern float HIT_L_FF;
extern float HIT_OBW_kexi1;
extern float HIT_OBW_kexi2;
extern float HIT_OBW_w;
float HIT_Jm_OBW;
extern float HIT_WL_T_factor_OBW;
extern float HIT_OBW_kc;
extern float HIT_alfa;
float HIT_w_OBW_foctor = 0;
extern float HIT_Mech_alfa;
extern unsigned short HIT_cur_test;
float HIT_mode_10_tal = 0.0001;
float HIT_lpfmode_10_1A;
float HIT_lpfmode_10_1B;
extern float HIT_10_photo_Ts_num;
extern float HIT_10_photo_Ts_k;
extern float HIT_Umsensor_f_standard;
int HIT_10_photo_Ts_num_int = 0;
int HIT_10_err_sample_ser = 0;
float HIT_WLw_ref_mode_2_max;
float HIT_WLw_ref_mode_2_step;
float HIT_WLw_ref_mode_2;
float HIT_mode_2_v_rise_time = 1;
extern float HIT_iq_ref_mech_max;
extern unsigned char ucParameter_init_success;
void HIT_par_initial()    
{
	
	HIT_adad = (float)HIT_VOLFIVE/HIT_AD12;//use for calculat current
	HIT_curr = (float)1000/HIT_curr_sen;//trans current sensity to Voltage

	HIT_adad_10wei = (float)HIT_VOLFIVE/HIT_AD10;//use for calculat current
		

	HIT_kv=HIT_kv*HIT_lm;//use for control mode-calculate Kv
	

	
	HIT_WLMech_Ki = HIT_WLMechki*HIT_Ts;//add 2012.4.1
	
	HIT_pwm_center = HIT_pwm_tcbr/2;///pwm center
	
	
	HIT_Tsa = HIT_Ts;//use for calculate speed control cycle time
	HIT_lpfv1A = (2*HIT_tal)/(2*HIT_tal+HIT_Ts);//the factor of speed filter  of NUM 1_A
	HIT_lpfv1B = HIT_Ts/(2*HIT_tal+HIT_Ts);//the factor of speed filter  of NUM 1_B
	
	HIT_lpfcurr_1A = (2*HIT_curr_tal)/(2*HIT_curr_tal+HIT_Ts);//the factor of current filter  of NUM 1_A
	HIT_lpfcurr_1B = HIT_Ts/(2*HIT_curr_tal+HIT_Ts);//the factor of current filter of NUM 1_B
	
	HIT_lpfUm_standard_1A = (2*HIT_Um_standard_tal)/(2*HIT_Um_standard_tal+HIT_Ts);//the factor of Um_now filter of NUM 1_A
	HIT_lpfUm_standard_1B = HIT_Ts/(2*HIT_Um_standard_tal+HIT_Ts);//the factor of Um_now filter of NUM 1_B
	
	HIT_reflpf_standard_1A = (2*HIT_reflpf_tal)/(2*HIT_reflpf_tal+HIT_Ts);//the factor of Um_now filter of NUM 1_A
	HIT_reflpf_standard_1B = HIT_Ts/(2*HIT_reflpf_tal+HIT_Ts);//the factor of Um_now filter of NUM 1_B
	
	HIT_lpfmode_10_1A = (2*HIT_mode_10_tal)/(2*HIT_mode_10_tal+HIT_Ts);//the factor of Um_now filter of NUM 1_A
	HIT_lpfmode_10_1B = HIT_Ts/(2*HIT_mode_10_tal+HIT_Ts);//the factor of Um_now filter of NUM 1_B
	
	HIT_current_inte_mode_select = 0.001/HIT_Ts;//0.001(1ms-interrupt)
	HIT_WLMechki= 1/HIT_MechTi;
	HIT_WLMech_Ki  = HIT_WLMechki*HIT_Ts;
	
//	HIT_faif = HIT_faif*6.2832/60;//rpm==>rad/s
	
	for(HIT_star_R_round=0;HIT_star_R_round<4;HIT_star_R_round++)
	{
		for(HIT_star_R_ee_i=0;HIT_star_R_ee_i<205;HIT_star_R_ee_i++)//Pn block0 ,Fn block1 ,Sn block2,nn block3
		{
			switch(HIT_star_R_round)
			{
				case 0:
				HIT_ee_con_byte_0 = 0xa2;//Fn  block1
				HIT_ee_con_byte_1 = 0xa3;
				HIT_start_address = 7600;
				HIT_rec_adrr_short = HIT_start_address + (unsigned short)HIT_star_R_ee_i;
				break;
				case 1:
				HIT_ee_con_byte_0 = 0xa4;//Sn  block2
				HIT_ee_con_byte_1 = 0xa5;
				HIT_start_address = 9200;
				HIT_rec_adrr_short = HIT_start_address + (unsigned short)HIT_star_R_ee_i;
				break;
				case 2:
				HIT_ee_con_byte_0 = 0xa0;//Pn  block0
				HIT_ee_con_byte_1 = 0xa1;
				HIT_start_address = 8800;
				HIT_rec_adrr_short = HIT_start_address + (unsigned short)HIT_star_R_ee_i;
				break;
				case 3:
				HIT_ee_con_byte_0 = 0xa6;//nn  block3
				HIT_ee_con_byte_1 = 0xa7;
				HIT_start_address = 8000;
				HIT_rec_adrr_short = HIT_start_address + (unsigned short)HIT_star_R_ee_i;
				break;	
			}
			
			HIT_Fn_read_ee_addr_fnc();       // 从IIC中读取数据
/***************************************** 将这些内容放置到62T中 ***************************/
/****
			switch(HIT_rec_adrr_short)
			{
				case 8800://DA1  Pn000
				HIT_DA_one = (float)(HIT_iic_word_rec_short);
				break;
				case 8802://DA2  Pn001
				HIT_DA_two = (float)(HIT_iic_word_rec_short);
				break;
				case 8801://DA1 full  Pn002
				HIT_DA_one_full = (float)(HIT_iic_word_rec_short);
				break;
				case 8803://DA2 full  Pn003
				HIT_DA_two_full = (float)(HIT_iic_word_rec_short);
				break;
				
				case 8804://iq jifen
				HIT_iq_ki = (float)HIT_iic_word_rec_short;//800;//(float)HIT_iic_word_rec_short;	
//				HIT_ki = 1/HIT_Ti;//calculate the ki
				HIT_iq_Ki = HIT_iq_ki*HIT_Ts;
				break;
				
				case 8805://iq zengyi
				HIT_iq_kv = (float)HIT_iic_word_rec_short;//1200;//(float)HIT_iic_word_rec_short;
				HIT_lm = 0.000073;	
				HIT_iq_kv=HIT_iq_kv*HIT_lm;
				break;
				
				case 8808://速度环Ti(1/100)  Pn008
				HIT_MechTi = (float)HIT_iic_word_rec_short;//5000;//(float)HIT_iic_word_rec_short;//单位ms
				HIT_MechTi = HIT_MechTi/1000;//转化成秒
				HIT_MechTi = HIT_MechTi/100;
				HIT_WLMechki= 1/HIT_MechTi;
				HIT_WLMech_Ki  = HIT_WLMechki*HIT_Ts;//HIT_Ts = 0.00005;开关频率，积分dt
				break;
				case 8807://速度环KV  Pn007(1/10)
				HIT_WLMechkv = (float)HIT_iic_word_rec_short;//40;//(float)(HIT_iic_word_rec_short);
	//			HIT_WLMechkv = HIT_WLMechkv/10;
				break;
				case 8809://位置环增益Pn009
				HIT_positon_Kp_int_float = (float)HIT_iic_word_rec_short;
				HIT_positon_Kp_int_float = HIT_positon_Kp_int_float/10;
//				HIT_positon_Kp_int = (int)HIT_iic_word_rec_short;
				break;
				case 7604://HIT_run_mode  Fn004
				HIT_run_mode = (float)HIT_iic_word_rec_short;//1;//(float)HIT_iic_word_rec_short;
				break;
				case 7607://Fn007
				HIT_sitadf_int = (int)HIT_iic_word_rec_short;
				HIT_ceshishi[0] = HIT_iic_word_rec_short;
				break;
				case 7608://Fn008 电流环测试时间开关 2时打开测试开关
				HIT_cur_test = (unsigned short)HIT_iic_word_rec_short;
				break;
				case 8827://Pn01B HIT_id_ref
				HIT_id_ref = (float)HIT_iic_word_rec_short/10;//6;//(float)HIT_iic_word_rec_short/10;	
				break;
				case 8828://Pn01C HIT_iq_ref
				HIT_iq_ref = (float)HIT_iic_word_rec_short/10;//1;//(float)HIT_iic_word_rec_short/10;	
				break;
				case 9200://Sn000 HITki
				HIT_ki = (float)HIT_iic_word_rec_short;//2500;//(float)HIT_iic_word_rec_short;	
//				HIT_ki = 1/HIT_Ti;//calculate the ki
				HIT_Ki = HIT_ki*HIT_Ts; //use for jifen Ki   change HITki from 1/HITTs to 1/HITTi 2012.3.26 wl
				break;
				case 9204://Sn004 HITkv
				HIT_kv = (float)HIT_iic_word_rec_short;//4000;//(float)HIT_iic_word_rec_short;
				HIT_lm = 0.000075;		
				HIT_kv=HIT_kv*HIT_lm;
				break;
				case 8826:
				HIT_mode_2_v_rise_time = (float)HIT_iic_word_rec_short;//4;//(float)HIT_iic_word_rec_short;
				HIT_mode_2_v_rise_time = HIT_mode_2_v_rise_time*1000000/50;  //1000000/50;   //2014.07.18 wjw
				break;
				case 8829://Pn01D HIT_WLw_ref
				HIT_WLw_ref = (float)HIT_iic_word_rec_short*2*HIT_PIE/60;//2000*2*HIT_PIE/60;//(float)HIT_iic_word_rec_short*2*HIT_PIE/60;
				HIT_WLw_ref_mode_2_max = HIT_WLw_ref;
				HIT_WLw_ref_mode_2_step = HIT_WLw_ref_mode_2_max/HIT_mode_2_v_rise_time;
				HIT_WLw_ref_in = HIT_WLw_ref;
				HIT_sudu_jian_val = HIT_WLw_ref_in/30000;	
				break;
				case 8000://nn000 运行点数
				V_comm_i_max = HIT_iic_word_rec_short;
				break;
				case 8830://pn01e 吸D轴速度rpm
				HIT_xi_d_w = (float)HIT_iic_word_rec_short;//400;//(float)HIT_iic_word_rec_short;
				if(HIT_run_mode == 10)//0.1rpm/div
				{
					HIT_xi_d_w = HIT_xi_d_w/1000;	
				}
				HIT_xi_d_w = HIT_xi_d_w*2*HIT_PIE/60;
				break;
				case 8831://pn01f 吸D轴电流上升时间
				HIT_xi_d_curr_time = (float)HIT_iic_word_rec_short;//1500;//(float)HIT_iic_word_rec_short;
				HIT_xi_d_num = HIT_xi_d_curr_time*20;
				break;
				case 8832://pn01f 吸D轴电流上升时间
				HIT_xi_d_w_time = (float)HIT_iic_word_rec_short;//1500;//(float)HIT_iic_word_rec_short;
				HIT_xi_d_w_num = HIT_xi_d_w_time*20;
				HIT_xi_d_w_step = HIT_xi_d_w/HIT_xi_d_w_num;
				break;
				case 9215://pn01f 吸D轴电流上升时间
				HIT_curr_sen = (float)HIT_iic_word_rec_short;
				break;
				case 8833://pn01f 吸D轴电流上升时间
//				HIT_i_vector_ref = (float)HIT_iic_word_rec_short;
//				HIT_i_vector_ref = HIT_i_vector_ref/10;
				break;
/*				case 8834://pn022 电流环状态观测wn
				HIT_current_wn = (float)HIT_iic_word_rec_short;
				HIT_current_wn = HIT_current_wn/10;
				break;
				case 8835://pn023 电流环状态观测kexi
				HIT_current_kexi = (float)HIT_iic_word_rec_short;
				HIT_current_kexi = HIT_current_kexi/10;
				break;*/
				
/***
				case 8836://pn024 模式12速度上升/下降时间（ms）
				HIT_M_12_r_time = (float)HIT_iic_word_rec_short;
				HIT_M_12_r_time = HIT_M_12_r_time/10;
				HIT_M_12_r_time_num = HIT_M_12_r_time*20;
				break;
				case 8837://pn025 模式12速度保持时间（ms）
				HIT_M_12_k_time = (float)HIT_iic_word_rec_short;
				HIT_M_12_k_time = HIT_M_12_k_time/10;
				HIT_M_12_k_time_num = HIT_M_12_k_time*20;
				break;
				case 8838://pn026 模式12速度最大值（rpm）
				HIT_M_12_max_speed = (float)HIT_iic_word_rec_short*2*HIT_PIE/60;
//				HIT_M_12_max_speed = HIT_M_12_max_speed*2*HIT_PIE/60;
				break;
				case 8839://pn027 模式12速度保持时间（ms）
				HIT_M_12_it_time = (float)HIT_iic_word_rec_short;
				HIT_M_12_it_time_num = HIT_M_12_it_time*20;
				break;
				case 7611://Fn00B 速度环前馈开启
				HIT_bf_m_open = (float)HIT_iic_word_rec_short;//3;//(float)HIT_iic_word_rec_short;
				break;
				case 7612://Fn00C 速度环前馈开启
				HIT_bf_c_open = (float)HIT_iic_word_rec_short;//3;//(float)HIT_iic_word_rec_short;
				break;
				case 7613://Fn00D 电压控制前馈开启
				HIT_bf_u_open = (float)HIT_iic_word_rec_short;//3;//(float)HIT_iic_word_rec_short;
				break;
				case 8840://Pn028 速度环前馈系数（1/100）
				HIT_bf_a = (float)HIT_iic_word_rec_short/1000;
//				HIT_bf_a = HIT_bf_a/100;
				break;	
				case 8841://Pn029 电流环前馈系数（1/100）
				HIT_bf_b = (float)HIT_iic_word_rec_short/1000;
//				HIT_bf_b = HIT_bf_b/100;
				break;
				case 8842://Pn029 电压前馈系数（1/100）
				HIT_bf_c = (float)HIT_iic_word_rec_short/1000;
//				HIT_bf_c = HIT_bf_c/100;
				break;
				case 8843://Pn029 电压前馈系数（1/100）
				HIT_ff_c_w = (float)HIT_iic_word_rec_short* 100;
//				HIT_ff_c_w = HIT_ff_c_w * 100;
				break;
				case 8844://Pn029 电压前馈系数（1/100）
				HIT_ff_c_kexi = (float)HIT_iic_word_rec_short/100;
//				HIT_ff_c_kexi = HIT_ff_c_kexi/100;
				break;
				case 8845://电压限制（1/100）
				HIT_U_FF_lim = (float)HIT_iic_word_rec_short;
//				HIT_ff_c_kexi = HIT_U_FF_lim/100;
				break;
				case 8846://电压限制（1/100）
				HIT_ff_p_w = (float)HIT_iic_word_rec_short*100;
//				HIT_ff_p_w = HIT_ff_p_w*100;
				break;
				case 8847://电压限制（1/100）
				HIT_ff_p_kexi1 = (float)HIT_iic_word_rec_short/100;
//				HIT_ff_p_kexi1 = HIT_ff_p_kexi1/100;
				break;
				case 8848://电压限制（1/100）
				HIT_ff_p_kexi2 = ((float)HIT_iic_word_rec_short)/100;
//				HIT_ff_p_kexi2 = HIT_ff_p_kexi2/100;
				break;
				case 8849://电压限制（1/100）
				HIT_w_F_ref_shou = ((float)HIT_iic_word_rec_short)*2*HIT_PIE/60;
//				HIT_w_F_ref_shou = HIT_w_F_ref_shou*2*HIT_PIE/60;
				break;
				case 8850://HIT_WL_T_factor_FF（1/10000）
				HIT_WL_T_factor_FF = ((float)HIT_iic_word_rec_short)/100000;
//				HIT_WL_T_factor_FF = HIT_WL_T_factor_FF/10000;
				break;
				case 8851://HIT_WL_T_factor（1/10000）
				HIT_WL_T_factor = ((float)HIT_iic_word_rec_short)/10000;//(float)180/10000;//((float)HIT_iic_word_rec_short)/10000;
//				HIT_WL_T_factor = HIT_WL_T_factor/10000;
				break;
				case 8852://HIT_WL_Jm_FF/10000）
				HIT_WL_Jm_FF = ((float)HIT_iic_word_rec_short)/10000000000;
//				HIT_WL_Jm_FF = HIT_WL_Jm_FF/10000000000;
				break;
				case 8853://HIT_WL_Jm/100000000000
				HIT_WL_Jm  = ((float)HIT_iic_word_rec_short)/10000000000;//(float)53000/10000000000;//((float)HIT_iic_word_rec_short)/10000000000;//10000000000;
//				HIT_WL_Jm  = HIT_WL_Jm/10000000000;
				break;
				case 8859://HIT_OBC_current_wn
				HIT_OBC_current_wn  = ((float)HIT_iic_word_rec_short)/100;
//				HIT_OBC_current_wn  = HIT_OBC_current_wn/100;
				break;
				case 8860://HIT_OBC_current_kexi
				HIT_OBC_current_kexi  = ((float)HIT_iic_word_rec_short)/100;
//				HIT_OBC_current_kexi  = HIT_OBC_current_kexi/100;
				break;
				case 8861://HIT_OBC_Rs
				HIT_OBC_Rs  = ((float)HIT_iic_word_rec_short)/100;
//				HIT_OBC_Rs  = HIT_OBC_Rs/100;
				break;
				case 8862://HIT_OBC_Ld
				HIT_OBC_Ld  = ((float)HIT_iic_word_rec_short)/10000;
//				HIT_OBC_Ld  = HIT_OBC_Ld/10000;
				break;
				case 8863://HIT_OBC_Lq
				HIT_OBC_Lq  = ((float)HIT_iic_word_rec_short)/10000;
//				HIT_OBC_Lq  = HIT_OBC_Lq/10000;
				break;
				case 8864://HIT_OBC_faif
				HIT_OBC_faif  = ((float)HIT_iic_word_rec_short)/10000;
//				HIT_OBC_faif  = HIT_OBC_faif/10000;
				break;
				case 8854://HIT_L_FF
				HIT_L_FF  = ((float)HIT_iic_word_rec_short)/100000;
//				HIT_L_FF  = HIT_L_FF/100000;
				break;
				case 9205://HIT_lm
				HIT_lm  = ((float)HIT_iic_word_rec_short)/100000;
//				HIT_lm  = HIT_lm/100000;
				break;
				case 8865://HIT_OBW_kexi1（1/100）
				HIT_OBW_kexi1  = ((float)HIT_iic_word_rec_short)/100;
//				HIT_OBW_kexi1  = HIT_OBW_kexi1/100;
				break;
				case 8866://HIT_OBW_kexi2（1/100）
				HIT_OBW_kexi2  = ((float)HIT_iic_word_rec_short)/100;
//				HIT_OBW_kexi2  = HIT_OBW_kexi2/100;
				break;
				case 8867://HIT_OBW_w
				HIT_OBW_w  = (float)HIT_iic_word_rec_short;///100;
				break;
				case 8868://HIT_OBW_w
				HIT_Jm_OBW  = ((float)HIT_iic_word_rec_short)/10000000000;
//				HIT_Jm_OBW = HIT_Jm_OBW;//10000000000;//00000;
				break;
				case 8869://HIT_OBW_w
				HIT_WL_T_factor_OBW  = ((float)HIT_iic_word_rec_short)/10000;
		//		HIT_Jm_OBW = HIT_Jm_OBW/100000000;//10000000000;//00000;
				break;
				case 8870://HIT_OBW_w
				HIT_OBW_kc  = ((float)HIT_iic_word_rec_short)/100 - 0.1;
				break;
/*				case 8871://HIT_alfa
				HIT_alfa  = ((float)HIT_iic_word_rec_short)/100 - 0.1;
				break;*/
				
/***
				case 8872://HIT_alfa
				HIT_w_OBW_foctor  =((float)HIT_iic_word_rec_short)/100 - 0.1;// 0;//((float)HIT_iic_word_rec_short)/100 - 0.1;
				break;
				case 9201://HIT_alfa
				HIT_faif  = ((float)HIT_iic_word_rec_short)/10000;//36/10000;//((float)HIT_iic_word_rec_short)/10000;
				break;
				case 9212://HIT_Umsensor_f_standard Un00C
				HIT_Umsensor_f_standard  = 564;//(float)HIT_iic_word_rec_short;///10000;
				break;
				case 8873://HIT_alfa
				HIT_Mech_alfa  = ((float)HIT_iic_word_rec_short)/100 - 0.1;
				break;
				case 8874://HIT_alfa
				HIT_alfa  = ((float)HIT_iic_word_rec_short)/100 - 0.1;
				break;
	//			case 9220://HIT_iq_ref_mech_max//20140428
	//			HIT_iq_ref_mech_max = (float)HIT_iic_word_rec_short;
	//			break;
			}
***/
			for(HIT_ee_delay=0;HIT_ee_delay<25000;HIT_ee_delay++)
			{
				;
			}
		}
	}//for 循环结束
/////////////////////////////current observer l1 l2///////
	HIT_OBC_intial_par_obser();
//	HIT_OBC_intial_par();
	HIT_OBC_intial_cal();
/////////////////////////////current observer l1 l2///////
	HIT_ref_lpf_cal_gain();
	for(HIT_star_R_ee_i=0;HIT_star_R_ee_i<20;HIT_star_R_ee_i++)//Pn block0 ,Fn block1 ,Sn block2,nn block3
		{
				HIT_ee_con_byte_0 = 0xa6;//nn  block3
				HIT_ee_con_byte_1 = 0xa7;
				HIT_start_address = 8000;
				HIT_rec_adrr_short = HIT_start_address + (unsigned short)HIT_star_R_ee_i+1;
			HIT_Fn_read_ee_addr_fnc();
			if(HIT_rec_adrr_short%2 == 0)
			{
				HIT_speed_command[HIT_speed_command_i] = (float)HIT_iic_word_rec_short;//速度
				HIT_speed_command_i++;
			}
			else
			{
				HIT_speed_time[HIT_speed_time_i] = HIT_iic_word_rec_short;//时间
				HIT_speed_time_i++;	
			}
			for(HIT_ee_delay=0;HIT_ee_delay<25000;HIT_ee_delay++)
			{
				;
			}
		}
	if((HIT_run_mode == 12)||(HIT_run_mode == 13)||(HIT_run_mode == 14)||(HIT_run_mode == 15))
	{
		HIT_M_12_speed_step = HIT_M_12_max_speed/HIT_M_12_r_time_num;
	}
	if((HIT_run_mode == 8)||(HIT_run_mode == 10))
	{
		HIT_xi_d_step = HIT_id_ref/HIT_xi_d_num;
		if(HIT_run_mode == 10)
		{
			HIT_10_photo_Ts_num = 1/HIT_Ts/(HIT_xi_d_w/2/HIT_PIE);//rad/s->rad/Ts
			HIT_10_photo_Ts_k = 65535/HIT_10_photo_Ts_num;	
			HIT_10_photo_Ts_num_int = (int)HIT_10_photo_Ts_num;
			HIT_10_err_sample_ser = (int)(HIT_10_photo_Ts_num_int/1024);
		}
	}
/*	if(HIT_run_mode == 9)
	{
//		HIT_xi_d_step = HIT_i_vector_ref/HIT_xi_d_num;
	}*/
	if(HIT_run_mode == 2)
	{
//		HIT_WLw_ref = 0;//52;	
	}
/*	if(HIT_run_mode == 4)
	{
		SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
		MTU1.TMDR.BIT.MD = 0X06;
		MTU1.TCR.BIT.CCLR = 0X01;
		MTU1.TIOR.BIT.IOA = 0X09;
		MTU1.TIOR.BIT.IOB = 0X08;
		MTU1.TGRA = 0X00;
		MTU1.TGRB = 0X00;
		IOPORT.PFCMTU.BIT.TCLKS	= 0X00;
		PORT3.ICR.BIT.B2 = 1;
		PORT3.ICR.BIT.B3 = 1;
		PORTA.ICR.BIT.B5 = 1;	
		MTU.TSTRA.BIT.CST1 = 1;	
	}*/
	//ucParameter_init_success = 0; // 参数初始化结束
}