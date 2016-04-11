#ifndef SPACEVECTORCONTROL
#define SPACEVECTORCONTROL 
 
extern float HIT_Ua;
extern float HIT_Ub;
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
extern float HIT_pwm_af;
extern float HIT_pwm_bf;
extern float HIT_pwm_cf;
extern int HIT_sitacheck_ab;
extern float HIT_coszhi_a_ab;
extern float HIT_coszhi_b_ab;
extern float HIT_coszhi_c_ab;
extern float HIT_sinzhi_a_ab;
extern float HIT_sinzhi_b_ab;
extern float HIT_sinzhi_c_ab;
extern float HIT_sinzhi_a;
extern float HIT_coszhi_a;
extern float HIT_pwm_off;
extern float HIT_Um ;
extern float HIT_now_voltage_f_out;
extern float HIT_Vol_adj_fac;
extern float HIT_Um_standard;
extern float HIT_now_voltage_f;
extern int HIT_sitadianab;
extern float HIT_Ualfa_transfer;
extern float HIT_pwm_deadoff;

extern float HIT_kr ;
extern float HIT_khalf;
extern int HIT_boun1;
extern int HIT_boun2 ;
extern int HIT_boun3 ;
extern int HIT_boun4 ;
extern int HIT_boun5;
extern int HIT_boun6 ;
extern int HIT_boun7 ;
extern float HIT_ualfamax_k ;
extern int HIT_pwm_full;

#define HIT_KR 0.866
#define HIT_KHALF 0.5
#define HIT_BOUN1 0
#define HIT_BOUN2 682
#define HIT_BOUN3 1364
#define HIT_BOUN4 2046
#define HIT_BOUN5 2728
#define HIT_BOUN6 3410
#define HIT_BOUN7 4096
#define HIT_UALFAMAX_K 1.15473
#define HIT_PWM_FULL 2000//2000//880
#endif