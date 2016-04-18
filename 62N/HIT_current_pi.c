#ifndef CURRENT
#define CURRENT

#include "HIT_current_pi.h"
#include "HIT_check_table.h"
#include "HIT_make_angle.h"
#include "iodefine.h"
#include <math.h>
#include <mathf.h>
extern unsigned short  pwm;
extern unsigned char HIT_pwm_mode_choose ;
extern char HIT_ready_go;
extern int HIT_pos_org_int ;
extern char HIT_pos_count;
extern unsigned short HIT_xi_d_count;
//extern float HIT_i_vector_fb;
extern float HIT_run_mode;
extern float HIT_bf_u_open;
//float HIT_i_vector_err;
//float HIT_i_vector_ref = 0.5;
//float HIT_i_vector_org;
//float HIT_U_vector;
extern float HIT_U_FF;
extern float HIT_U_F;
 extern float HIT_bf_c;
 extern float HIT_bf_c_open;
 extern float HIT_I_FF;
 extern float HIT_bf_b;
 int countf=0;
 float HIT_iq_ft_max = 25;
 float HIT_ft = 0.86;
 float HIT_Ud_Uq_sqrt;
void HIT_current_pi()
{

		
}
#endif
