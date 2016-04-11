#ifndef POSITIONCONTROL_H
#define POSITIONCONTROL_H

extern int HIT_virtual_ps_int;
extern int HIT_virtual_ps_int_fir;
extern int HIT_virtual_ps_int_sec;
extern int HIT_virtual_ps_int_err;
extern int HIT_positioncontrol_num;
extern float HIT_sitaerr;

extern float HIT_sita1; 
extern float HIT_sitafir;


extern int HIT_pos_org_int ;
extern int HIT_position_err_int;

extern int HIT_positionfir_fb_16_int;
extern float HIT_position_fb_f;
extern int HIT_position_fb_err_16_int;
extern int HIT_position1_fb_16_int;
extern float HIT_pos_org_f ;
extern float HIT_WLw_ref;
extern float HIT_positon_Kp_f;

extern float HIT_virtual_ps_int_err_f;
extern float HIT_virtual_ps_int_err_sum_f;
extern float HIT_virtual_ps_int_err_int_f;
extern int HIT_position_client_int;
extern float HIT_position_client_f;
extern int HIT_virtual_ps_int_err_int_int;
extern float HIT_virtual_ps_int_err_float_f;
extern float HIT_sita;

#define HIT_POSITIONERR_16WEI 10430.378
#define HIT_ANGLE_16 65536
#define HIT_angle_zero_pass_lim 30000
#endif