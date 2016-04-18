#ifndef HITMAKE_ANGLEC
#define HITMAKE_ANGLEC
#include "HIT_make_angle.h"
#include "iodefine.h"
#include<math.h>
#include<mathf.h>
extern unsigned char HIT_pwm_mode_choose ;
signed int HIT_s0TX_buffer1_judge;
signed int HIT_s0TX_buffer2_judge;
extern float HIT_alarm;
extern float HIT_run_mode;
float HIT_xi_d_w = 2;
extern float HIT_Ts;
extern int HIT_sitadian;
float HIT_sita_d = 0;
extern char HIT_ready_go;
unsigned short HIT_xi_d_count = 1;
float HIT_xi_d_num_count = 0;
extern float HIT_xi_d_num;
float HIT_id_out = 0;
extern float HIT_xi_d_step;
extern float HIT_id_ref;
float HIT_xi_d_w_num_count = 0;
extern float HIT_xi_d_w_num;
float HIT_xi_d_w_out = 0;
extern float HIT_xi_d_w_step;
extern int HIT_alarm_num;
float HIT_sita_mode_10_f;
//extern float HIT_i_vector_ref;
extern int HIT_mode_10_check_en;
extern int HIT_mode_10_mag_sita_int;
extern float HIT_mode_10_sita_err[];


void HIT_make_angle(void)
{


}
#endif