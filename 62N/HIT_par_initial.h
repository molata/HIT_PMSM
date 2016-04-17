#ifndef PAR_INITIAL
#define PAR_INITIAL

#include<math.h>
extern float HIT_curr_sen;//mV/A

extern float HIT_kv;
extern float HIT_iq_kv;
extern float HIT_ki;
extern float HIT_iq_ki;
extern float HIT_Ki;
extern float HIT_iq_Ki;
float HIT_Ti = 0.001;//s(second)

extern float HIT_lm;////h
extern float HIT_Ts;
float HIT_Ts_iden = 0.0001;
float HIT_pwm_tcbr =500.0;
float HIT_pwm_center;

extern float HIT_adad;
extern float HIT_curr;
extern float HIT_Tsa;
extern float HIT_lpfv1A;
extern float HIT_lpfv1B;
extern float HIT_lpfcurr_1A;
extern float HIT_lpfcurr_1B;
extern float HIT_lpfUm_standard_1A;
extern float HIT_lpfUm_standard_1B;

extern float HIT_tal;
extern float HIT_curr_tal;
extern float HIT_Um_standard_tal ;

extern float HIT_Um;

extern float HIT_adad_10wei;
extern int HIT_current_inte_mode_select;

extern float HIT_WLMech_Ki;
extern float HIT_WLMechki;

extern float HIT_MechTi;
extern float HIT_faif;

#define HIT_VOLFIVE 5
#define HIT_VOLCENTER 2.5
#define HIT_AD12 4096
#define HIT_AD10 1024
unsigned char ucParameter_init_success = 0;   // 参数初始化状态位 0: 什么都不干 ； 1： 开始参数初始化； 
void HIT_par_initial(void);
void HIT_par_loop();
#endif