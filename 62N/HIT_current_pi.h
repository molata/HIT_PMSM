#ifndef HIGH
#define HIGH
void HIT_current_pi(void);
extern unsigned short HIT_tgr_b_val3;
extern unsigned short HIT_tgr_d_val3;
extern unsigned short HIT_tgr_a_val4;
extern unsigned short HIT_tgr_c_val4;
extern unsigned short HIT_tgr_b_val4;
extern unsigned short HIT_tgr_d_val4;
extern unsigned short HIT_set_counter_val3;
extern unsigned short HIT_set_counter_val4;

extern float HIT_ki;
extern float HIT_iq_ki;
extern float HIT_Ki;
extern float HIT_iq_Ki;
extern float HIT_iu_fbadf;
extern float HIT_iv_fbadf;
extern float HIT_iw_fbadf;
extern float HIT_iu_fb;
extern float HIT_iv_fb;
extern float HIT_iw_fb;
extern unsigned int HIT_qa;


extern float HIT_id_org;
extern float HIT_iq_org;
extern float HIT_Um ;
extern float HIT_alfa;
extern float HIT_kv;
extern float HIT_iq_kv;
extern float HIT_pwm_tcbr;
extern float HIT_pwm_center;
extern unsigned short HIT_tcbr_val;
extern unsigned short HIT_u_sensor;
extern unsigned short HIT_w_sensor;
extern float HIT_adad;
extern float HIT_curr;
extern unsigned short HIT_iu_fbad;
extern unsigned short HIT_iv_fbad;
extern unsigned short HIT_iw_fbad;
extern float HIT_id_fb;
extern float HIT_id_fb1;
extern float HIT_id_fb2;
extern float HIT_id_fb3;
extern float HIT_id_fb4;
extern float HIT_iq_fb;
extern float HIT_id_ref;
extern float HIT_iq_ref;
extern float HIT_id_err;
extern float HIT_iq_err;

extern float HIT_Ud;
extern float HIT_Uq;
extern float HIT_Ualfa;
extern float HIT_Ua;
extern float HIT_Ub;
extern float HIT_Usquare;
extern float HIT_Ulim;
extern float HIT_Ualfam;
extern float HIT_U_a;
extern float HIT_U_b;
extern float HIT_U_c;
extern float HIT_sitalfa;
extern int HIT_sitaintab;
extern int HIT_sitadianab;


extern signed int HIT_pwm_aint;
extern signed int HIT_pwm_bint;
extern signed int HIT_pwm_cint;

extern float HIT_sinzhi_a;
extern float HIT_coszhi_a;
extern float HIT_sinzhi_b;
extern float HIT_coszhi_b;
extern float HIT_sinzhi_c;
extern float HIT_coszhi_c;
extern int HIT_sitadian;
extern int HIT_sitadf_int;
extern int HIT_sitaintf_pole_int;
extern float HIT_pwm_off;
extern int HIT_sitacheck;
extern char HIT_xw;
extern float HIT_y[];

extern float HIT_iulpf;
extern float HIT_iwlpf;
extern float HIT_ivlpf;
extern float HIT_iuone;
extern float HIT_iutwo;
extern float HIT_iwone;
extern float HIT_iwtwo;
extern float HIT_ivone;
extern float HIT_ivtwo;

extern float HIT_pwm_deadoff;
extern float HIT_Vol_adj_fac;
extern float HIT_iu_fb_avg;
extern float HIT_iv_fb_avg;
extern float HIT_iw_fb_avg;

extern float HIT_curren_aa_q_max;  //the max value of integralter 
extern float HIT_now_voltage_f_out;
extern float HIT_curren_aa_q_max_cmt0;
extern unsigned int HIT_system_count;
extern int HIT_current_inte_mode_select;
extern float HIT_drain;
extern float HIT_Um_standard;

extern int HIT_pwm_stop;

extern float HIT_lpfcurr_1A;
extern float HIT_lpfcurr_1B;

extern int HIT_sitacheck_ab;
extern float HIT_coszhi_a_ab;
extern float HIT_coszhi_b_ab;
extern float HIT_coszhi_c_ab;
extern float HIT_sinzhi_a_ab;
extern float HIT_sinzhi_b_ab;
extern float HIT_sinzhi_c_ab;

extern float HIT_pwm_mode;
extern float HIT_pwm_mode_Um;
extern float HIT_Uu_3to2; 
extern float HIT_Uv_3to2;
extern float HIT_Uw_3to2;

extern float HIT_faif;
extern float HIT_iv_fbadf;
extern float HIT_Lq;
extern float HIT_Rs;
extern unsigned int HIT_pwm_en_out ;

extern float HIT_pwm_af;
extern float HIT_pwm_bf;
extern float HIT_pwm_cf;

extern float HIT_speedlpf_pole;

extern float HIT_iq_ref_out;
extern float HIT_iq_one;
extern float HIT_iq_two;

#define HIT_VOLCENTER 2.5
#define HIT_BOUN1 0
#define HIT_BOUN2 682
#define HIT_BOUN3 1364
#define HIT_BOUN4 2046
#define HIT_BOUN5 2728
#define HIT_BOUN6 3410
#define HIT_BOUN7 4096
#define HIT_KR 0.866
#define HIT_KHALF 0.5
#define HIT_PWM_FULL 2000//2000//880
#define HIT_UALFAMAX_K 1.15473
#define HIT_PWMOUTULIM 1732//3464//1732//762//450//900//866//1732/*4000:output Max*86.6%*/

#define HIT_CURRENT_INS_MAX 1844
#define HIT_CURRENT_INS_MIN 204
#endif