#ifndef MAKE_ANGLE
#define MAKE_ANGLE
void HIT_make_angle(void);
extern signed int HIT_s0TX_buffer1;
extern signed int HIT_s0TX_buffer2;
extern signed int HIT_s0TX_buffer3;
extern float HIT_sita;
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
extern int HIT_sitadian;


extern int HIT_sitadf_int;
extern int HIT_sitaintf_pole_int;
extern float HIT_poles;

extern float HIT_we;
extern float HIT_speedlpf;
extern float HIT_wone;
extern float HIT_wtwo;

extern float HIT_tal;
extern float HIT_curr_tal;
extern float HIT_Um_standard_tal;



extern float HIT_T;
extern float HIT_lpfv1A;
extern float HIT_lpfv1B;
extern float HIT_lpfUm_standard_1A;
extern float HIT_lpfUm_standard_1B;

extern int HIT_lpfcount;

extern unsigned int HIT_qa;
extern float HIT_sitaerr;
extern float HIT_sitafir;
extern float HIT_sita1;

extern float HIT_sitaerr;
extern float HIT_Tsa;


#define HIT_lpfv1Af 0.9972299
#define HIT_lpfv1Bf 0.002770083

extern unsigned short HIT_dir;
extern unsigned int HIT_dircount;
extern unsigned int HIT_dircount1;
extern unsigned short HIT_Umsensor;
extern unsigned short HIT_Uad;
extern float HIT_Umsensor_f; 
extern float HIT_now_voltage_f;
extern float HIT_now_voltage_f_out;
extern float HIT_now_voltage_one;
extern float HIT_now_voltage_two;
extern float HIT_Ulim;
extern signed int HIT_a_n_int;
extern signed int HIT_b_n_int;
extern signed int HIT_c_n_int;
extern signed int HIT_a_p_int;
extern signed int HIT_b_p_int;
extern signed int HIT_c_p_int; 
extern int HIT_sitadian_pole_max_int;
extern float HIT_Um_standard;
extern float HIT_Umsensor_f_standard;

extern int HIT_sitaintf_curr_int;
extern float HIT_sitaintf_curr_mech_f;
extern int HIT_sitaintf_curr_mech_int;

extern int HIT_pwm_stop;
extern int HIT_make_angle_mode;

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

extern int HIT_biaoding_int;
extern int HIT_biaoding_int_bia;
extern int HIT_check_area_int;
extern int HIT_add_point_int;
extern int HIT_check_area_int;
extern int HIT_check_area_bia_int;
extern float HIT_y_a1_f;
extern float HIT_y_a2_f;
extern float HIT_x_a1_f;
extern float HIT_k_f ;
extern float HIT_b_f ;
extern float HIT_add_point_f ;
//extern float HIT_biaodingarry[];
extern float HIT_biaoding_ang_f ;
extern float HIT_biaoding_f;
extern float HIT_new_angle_f;
extern int HIT_new_angle_int;
extern unsigned short HIT_new_angle_short;

#define HIT_HALFPIE 1.5708
#define HIT_PIE 3.1415926
#define HIT_TWOTHIRDPIE 4.71239
#define HIT_TWOPIE 6.28319
#define HIT_MAKE16WEI_ANGLE 10430.378//10420.6
#define HIT_AD16WEI 65536
#define HIT_AD12wei 4095


#define HIT_KR 0.866
#endif