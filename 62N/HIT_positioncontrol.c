#ifndef POSITIONCONTROLC
#define POSITIONCONTROLC
#include"HIT_positioncontrol.h"
#include<math.h>
#include<mathf.h>
unsigned short HIT_filter_initial = 1;
extern unsigned short HIT_filter_depth;
unsigned short HIT_filter_i;
int HIT_a_phase_filter[16];
int HIT_a_phase_sum;
char HIT_speed_zero = 0;
extern int HIT_new_angle_int;
extern int HIT_sitaintf_curr_int;
extern float HIT_alarm;
extern float HIT_run_mode;
float HIT_gear_num_f = 65536;
extern int HIT_alarm_num;
extern float HIT_M_12_w_out;
extern unsigned short HIT_new_angle_short;
extern float HIT_M_12_w_ref;
extern float HIT_bf_m_open;
extern float HIT_bf_a;
extern float HIT_W_FF;
extern float HIT_w_F_FF_out;
extern float HIT_w_F_FF;
float  HIT_virtual_ps_int_err_f_org = 0;
int HIT_virtual_ps_int_err_f_org_int = 0;
int HIT_virtual_ps_int_err_f_org_int_1 = 0;
int HIT_virtual_ps_int_err_f_org_int_err = 0;
int HIT_virtual_ps_int_err_f_org_int_2 = 0;
int HIT_virtual_ps_int_err_int =0 ;
int HIT_virtual_ps_int_err_int_org = 0;
float HIT_OBW_Err_P_f = 0;
extern float HIT_OBW_Err;
float HIT_OBW_kc = 0;
#define HIT_PIE 3.1415926
float HIT_FF_REF_err_out_f = 0;
extern float HIT_M_12_w_out_org;
float HIT_mode_15_fb_angle_f_org = 0;
float HIT_FB_REF_err_out_f = 0;
float HIT_BF_REF_err_out_f = 0; //20140112 «∞¿°”Î∑¥¿°≤Ó
void HIT_positioncontrol()
{

		
}
#endif