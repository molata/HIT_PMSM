#ifndef IDENTIFICATIONH
#define IDENTIFICATIONH

extern unsigned short HIT_p_getad_iden[4];
extern unsigned short HIT_n_getad_iden[4];
extern float HIT_now_voltage_iden_f;
extern float HIT_Vol_adj_fac_iden;


extern float HIT_iq_fb_iden_L;
extern float HIT_id_fb_iden_L;
extern float HIT_id_fb_iden_org_L ;
extern float HIT_Ts_iden;
extern float HIT_Umsensor_f_standard;
extern float HIT_curr_sen;
extern float HIT_id_fb;
extern float HIT_iq_fb;
extern float HIT_WLw_ref_iden;//rad/s
extern float HIT_WLw_ref;
extern float HIT_speedlpf_iden_fai;
extern float HIT_speedlpf;
extern float HIT_Uq;
extern unsigned short HIT_p_getad[4];
extern unsigned short HIT_n_getad[4];
extern unsigned short HIT_v_sensor_10wei;
extern unsigned short HIT_u_sensor;
extern unsigned short HIT_w_sensor;
extern unsigned short HIT_iu_fbad;
extern unsigned short HIT_iw_fbad;
extern unsigned short HIT_v_sensor_10weiad;
extern float HIT_iu_fbadf;
extern float HIT_iw_fbadf;
extern float HIT_v_sensor_10weiadf;
extern float HIT_iu_fb;
extern float HIT_iw_fb;
extern float HIT_adad;
extern float HIT_curr;
extern float HIT_iv_fb_10wei;
extern float HIT_adad_10wei;
extern float HIT_iu_fb_sum;
extern float HIT_iv_fb_sum;
extern float HIT_iw_fb_sum;
extern float HIT_iu_fb_avg;
extern float HIT_iv_fb_avg;
extern float HIT_iw_fb_avg;


#define HIT_pwm_full_iden 4800
#define HIT_volfive_iden 5
#define HIT_ad12_iden 4096
#define HIT_volcenter_iden 2.5
#define HIT_VOLCENTER 2.5
#endif