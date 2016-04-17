#ifndef GPT0CMVINTFUNCH
#define GPT0CMVINTFUNCH

extern int HIT_systemcontrol_mode;
extern unsigned short HIT_p_getad[4];
extern unsigned short HIT_n_getad[4];   
extern unsigned short HIT_a_n_hall;
extern unsigned short HIT_b_n_hall;
extern unsigned short HIT_c_n_hall;
extern unsigned short HIT_u_sensor;
extern unsigned short HIT_w_sensor;
extern unsigned short HIT_v_sensor;
extern unsigned short HIT_a_p_hall;
extern unsigned short HIT_b_p_hall;
extern unsigned short HIT_c_p_hall; 
extern float HIT_a_hall;
extern float HIT_b_hall;
extern float HIT_c_hall;
extern float HIT_d_hall;
extern float HIT_q_hall;


extern unsigned short HIT_filter_initial;
extern unsigned short HIT_filter_depth;
//extern unsigned short HIT_a_phase_filter[4];
//extern unsigned short HIT_a_phase_sum;
extern unsigned short HIT_b_phase_filter[4];
extern unsigned short HIT_b_phase_sum;

extern unsigned short HIT_current_filter_initial;
extern unsigned short HIT_current_filter_depth;
extern unsigned short HIT_u_phase_filter[4];
extern unsigned short HIT_u_phase_sum;
extern unsigned short HIT_w_phase_filter[4];
extern unsigned short HIT_w_phase_sum;
extern unsigned short HIT_v_phase_filter[4];
extern unsigned short HIT_v_phase_sum;

extern unsigned short HIT_u_sensor_sum;
extern unsigned short HIT_w_sensor_sum;
extern unsigned short HIT_v_sensor_sum;

extern unsigned short HIT_Uad;
extern unsigned short HIT_Umsensor;
extern signed int HIT_a_n_int;
extern signed int HIT_a_p_int;

extern float HIT_pwm_mode;
extern float HIT_pwm_mode_Um;
extern signed int HIT_pwm_aint;
extern float HIT_pwm_af;
extern signed int HIT_pwm_bint;
extern float HIT_pwm_bf;
extern signed int HIT_pwm_cint;
extern float HIT_pwm_cf;
extern unsigned int HIT_pwm_en_out;

extern int HIT_sitadian_check;



#define HIT_PWMOUTULIM 1732//3464//3464//1732//762
#define HIT_ANGLE_OFFSET 0.11427//175.2/1000000/6.28*4096
#define HIT_GPT_CYCLE 0.014349//0.00002///w*trad(20.5us)/6.28*4096
#define HIT_GPT_TWO_CYCLE 0.028698
#define HIT_GPT_THREE_CYCLE 0.0430471
#endif