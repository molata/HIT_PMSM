#ifndef HITSERVOONC
#define HITSERVOONC
#include "HIT_servoon.h"
#include"iodefine.h"
extern unsigned short HIT_run_time;
extern unsigned short HIT_run_time_2;
extern unsigned int HIT_run_time_int;
extern unsigned int HIT_run_time_2_int;
extern char HIT_ready_go;
int HIT_speed_run_time = 0;
char HIT_pos_count = 0;
extern int HIT_position1_fb_16_int;
extern int HIT_new_angle_int;
extern float HIT_id_ref;
extern float HIT_run_mode;
unsigned short HIT_ceshi = 0;
unsigned short HIT_ceshi_1 = 2048;
unsigned short HIT_DA_chnl = 0;
unsigned int tx = 1;
unsigned int qwe = 1;
float HIT_speed_con_time[40];
float HIT_speed_time[40];
float HIT_speed_a[40];
float HIT_speed_command[40];
unsigned short V_comm_i = 0;
float HIT_speed_rond_v0 = 0;
//unsigned short HIT_speed_rond_num = 0;
float HIT_speed_rond_a;
unsigned short i;
unsigned short HIT_mode_5_i = 0;
float HIT_speed_command_ref = 0;
float HIT_speed_command_0 = 0;
extern unsigned short V_comm_i_max;
unsigned char HIT_enable_mode_5 = 1;
float HIT_speed_rond_num_f;
float HIT_speed_command_f;
float HIT_speed_a_f;
float HIT_speed_command_ref_out;
float HIT_sudu_jian_val = 0;
extern float HIT_WLw_ref_in;
extern unsigned char HIT_pwm_mode_choose;
union {
		unsigned short HIT_send_sci_DA;
		struct {
			unsigned short low_8:8;//最低位
			unsigned short high_8:8;//最位
		} BYTE;
		struct {
			unsigned short BIT_1:1;//最低位
			unsigned short BIT_2:1;//最位
			unsigned short BIT_3:1;//最位
			unsigned short BIT_4:1;//最位
			unsigned short BIT_5:1;//最位
			unsigned short BIT_6:1;//最位
			unsigned short BIT_7:1;//最位
			unsigned short BIT_8:1;//最高位
			unsigned short BIT_9:1;//最高位
			unsigned short BIT_10:1;//最高位
			unsigned short BIT_11:1;//最高位
			unsigned short BIT_12:1;//最高位
			unsigned short BIT_13:1;//最高位
			unsigned short BIT_14:1;//最高位
			unsigned short BIT_15:1;//最高位
			unsigned short BIT_16:1;//最高位
		} BIT;
	} HIT_send_sci_DA_buff;
unsigned short HIT_DA_data_trans = 0;
extern float HIT_iq_fb;
extern float HIT_OBC_iq;
int HIT_M_12_count = 0;
extern float HIT_M_12_r_time_num;
extern float HIT_M_12_k_time_num;
extern float HIT_M_12_it_time_num;
extern float HIT_M_12_w_ref;
extern float HIT_M_12_speed_step;
float HIT_M_12_w_ref = 0;
float HIT_M_12_w_out = 0 ;
float HIT_M_12_pos_sum = 0;
extern int HIT_virtual_ps_int;
extern float HIT_pos_org_f;
extern float HIT_M_12_max_speed;
float HIT_M_12_w_ref_1 = 0;
float HIT_M_12_w_ref_2 = 0;
float HIT_M_12_w_ref_err;
extern float HIT_sita_M_8_w;
extern float HIT_v_ref_f_out;
extern float HIT_s_ref_f_out;
extern float HIT_a_ref_f_out;
extern float HIT_U_FF;
extern float HIT_I_FF_ref;
extern float HIT_w_F_FF;
extern float HIT_I_FF_ref;
extern float HIT_I_FF;
extern float HIT_U_F;
extern float HIT_w_F_ref;
float HIT_w_F_FF_out = 0;
extern int HIT_virtual_ps_int_err_f_org_int;
extern float HIT_speedlpf_out;
extern int HIT_pos_org_int ;
extern int HIT_M_12_w_out_org_int;
extern float HIT_DA_one_out;
extern float HIT_DA_two_out;
extern float HIT_DA_one_full;
extern float HIT_DA_two_full;
extern float HIT_DA_out;
int HIT_run_mode_10_int = 0;
float HIT_mode_10_sita;
float HIT_mode_10_enc_mag;
char HIT_mode_10_first_time = 1;
float HIT_mode_10_enc_mag_fir;
char HIT_mode_10_jump = 0;
float HIT_mode_10_sita_err[1024];
signed short HIT_err_10_i=0;
extern float HIT_sita_mode_10_f;
float HIT_mode_10_enc_mag_err;
float HIT_mode_10_enc_mag_1;
float HIT_mode_10_enc_mag_2;
signed short HIT_mode_10_enc_mag_fir_short;
unsigned short HIT_mode_factor_num = 1;
int HIT_start_bd_int_num =0;
float HIT_mode_10_err_ser;
int run_run_time = 0;
float HIT_DA_float_1 = 2150;
float HIT_DA_float_2 = 2150;
unsigned short HIT_cur_test = 1;
extern float HIT_WLw_ref_mode_2;
extern float HIT_WLw_ref_mode_2_step;
extern float HIT_WLw_ref_mode_2_max;
#include"HIT_mechanicalpi.h"
extern float HIT_alarm ;
extern int HIT_alarm_num;
void HIT_servoon()
{

}
#endif