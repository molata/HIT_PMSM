#ifndef HIT_COMMON_H
#define HIT_COMMON_H


unsigned short HIT_pwm=0;
signed int HIT_s0TX_buffer1;
signed int HIT_s0TX_buffer2;
signed int HIT_s0TX_buffer3;
float HIT_sita;
unsigned short HIT_p_getad[4];
unsigned short HIT_n_getad[4]; 
unsigned short HIT_p_getad_iden[4];    
unsigned short HIT_n_getad_iden[4]; 
unsigned short HIT_u_sensor;
unsigned short HIT_w_sensor;
unsigned short HIT_u_sensor_sum;
unsigned short HIT_w_sensor_sum;
unsigned short HIT_v_sensor_sum;
unsigned short HIT_v_sensor_10wei;
unsigned short HIT_v_sensor;

unsigned short HIT_a_n_hall;
unsigned short HIT_b_n_hall;
unsigned short HIT_c_n_hall;
unsigned short HIT_a_p_hall;
unsigned short HIT_b_p_hall;
unsigned short HIT_c_p_hall; 

signed int HIT_a_n_int;
signed int HIT_b_n_int;
signed int HIT_c_n_int;
signed int HIT_a_p_int;
signed int HIT_b_p_int;
signed int HIT_c_p_int; 

float HIT_a_hall;
float HIT_b_hall;
float HIT_c_hall;
float HIT_d_hall;
float HIT_q_hall;
signed int HIT_sitadf_int = 0x2968;//0xD26E;//0xF6AE;//0xD782;//0xD962;//0xD818;//0xADD9;//0xD6AE;//0x2d78;//0X2A89;//0X312D;//ce shi modify 2012.4.2
int HIT_sitaintf_pole_int;
int HIT_sitadian;

int HIT_sitadianab;


float HIT_id_org=0;
float HIT_iq_org=0;
char HIT_xw;
#pragma address HIT_y=0x00100000
#include "HIT_address.h"
//float HIT_y[1024];/////////////////////////////////////////////////////
//#pragma address HITparameter=0x00101000
//#pragma address HITsystemparameter=0x00101800
//#pragma address HIT_biaodingarry=0x00101000 //modify 20130616
//#include"HIT_biaoding.h" //modify 20130616

float HIT_sinzhi_a = 0;
float HIT_coszhi_a = 0;
float HIT_sinzhi_b = 0;
float HIT_coszhi_b = 0;
float HIT_sinzhi_c = 0;
float HIT_coszhi_c = 0;
float HIT_sinzhi_3a=0;
float HIT_coszhi_3a=0;
int HIT_sitacheck;

 int HIT_3sitacheck;
int HIT_3sitacheck_sin;
int HIT_3sitacheck_cos;
int HIT_3sitadian_check;


float HIT_tal = 0.0005;//0.0005 ;
float HIT_curr_tal = 0.001;//0.0001;//add20141228
float HIT_Um_standard_tal = 0.002;
float HIT_reflpf_tal = 0.0001;
//float HIT_reflpf_tal = 0.002;

float HIT_lpfv1A=0;
float HIT_lpfv1B=0;
float HIT_lpfUm_standard_1A;
float HIT_lpfUm_standard_1B;
float HIT_lpfcurr_1A;
float HIT_lpfcurr_1B;
float HIT_lpfUm_standard_1A;
float HIT_lpfUm_standard_1B;
float HIT_reflpf_standard_1A;
float HIT_reflpf_standard_1B;

float HIT_sitaerr=0;
float HIT_sitafir;

float HIT_sita1 = 0;


float HIT_Tsa;
float HIT_we;
int HIT_lpfcount = 0;

float HIT_wone=0;
float HIT_wtwo=0 ;

float HIT_speedlpf=0.0;
float HIT_speedlpf_iden_fai;
unsigned short HIT_dir;
unsigned int HIT_dircount = 0;
unsigned int HIT_dircount1 = 0;

float HIT_iulpf;
float HIT_iwlpf;
float HIT_ivlpf;
float HIT_iuone;
float HIT_iutwo;
float HIT_iwone;
float HIT_iwtwo;
float HIT_ivone;
float HIT_ivtwo;

float HIT_pwm_af = 0;
float HIT_pwm_bf = 0;
float HIT_pwm_cf = 0;

signed int HIT_pwm_aint = 0;
signed int HIT_pwm_bint = 0;
signed int HIT_pwm_cint = 0;


unsigned short HIT_Umsensor;

unsigned short HIT_Uad;
float HIT_Umsensor_f; 
float HIT_now_voltage_f;
float HIT_now_voltage_iden_f;
float HIT_Um=135;//===270/2;
float HIT_iden_Um=37;//27.2;
float HIT_Vol_adj_fac = 1;
float HIT_Vol_adj_fac_iden;

float HIT_iu_fb_sum=0;
float HIT_iv_fb_sum=0;
float HIT_iw_fb_sum=0;
float HIT_iu_fb_avg;
float HIT_iv_fb_avg;
float HIT_iw_fb_avg;
float HIT_iu_fb;
float HIT_iv_fb;
float HIT_iw_fb;
float HIT_iu_fb_iden;
float HIT_iv_fb_iden;
float HIT_iw_fb_iden;
float HIT_iv_fb_10wei;

unsigned short HIT_iu_fbad;
unsigned short HIT_iw_fbad;
unsigned short HIT_iv_fbad;
unsigned short HIT_iu_fbad_iden;
unsigned short HIT_iw_fbad_iden;
unsigned short HIT_v_sensor_10weiad;
float HIT_iu_fbadf;
float HIT_iv_fbadf;
float HIT_iw_fbadf;
float HIT_iu_fbadf_iden;
float HIT_iw_fbadf_iden;
float HIT_v_sensor_10weiadf;

float HIT_adad;
float HIT_adad_10wei;

float HIT_curr;

float HIT_iq_fb = 0.0;
float HIT_id_fb = 0.0;

float HIT_curren_aa_q_max;  //the max value of integralter 

float HIT_now_voltage_f_out = 0;
float HIT_now_voltage_one;
float HIT_now_voltage_two;
int HIT_sitadian_pole_max_int;

float HIT_iq_one;
float HIT_iq_two;
float HIT_iq_ref_out = 0;

float HIT_kv ;
float HIT_iq_kv;
int HIT_current_inte_mode_select;
float HIT_curren_aa_q_max_cmt0;
float HIT_drain;
float HIT_id_fb_square;
float HIT_iq_fb_square;
int HIT_shortime_cur_count = 0;
float HIT_idq_square;

float HIT_Um_standard = 30;//23.6;//26.7;//24;//15;//300;//26.9;//35;//27.2 ;//v
float HIT_Umsensor_f_standard = 564;//1766;//204;//2755;//226;//124;//187;//2232;//224;//344;//350;//473;//481;

int HIT_pwm_stop = 1;//common work
float HIT_WLw_err_orig; 
int HIT_sitacheck_sin = 0;
int HIT_sitacheck_cos = 0;

int HIT_sitacheck_ab;
float HIT_coszhi_a_ab;
float HIT_coszhi_b_ab;
float HIT_coszhi_c_ab;
float HIT_sinzhi_a_ab;
float HIT_sinzhi_b_ab;
float HIT_sinzhi_c_ab;
int HIT_sitacheck_cos_ab;
int HIT_sitacheck_sin_ab;
float HIT_pwm_mode;
float HIT_pwm_mode_Um;
float HIT_Uu_3to2; 
float HIT_Uv_3to2;
float HIT_Uw_3to2;

float HIT_Ualfa_transfer = 0.0;
int HIT_sitaintf_curr_int = 0;
float HIT_sitaintf_curr_mech_f = 0.0;
int HIT_sitaintf_curr_mech_int = 0;
int HIT_virtual_ps_int_fir = 0;
int HIT_virtual_ps_int_sec = 0;
int HIT_virtual_ps_int_err = 0;
int HIT_positioncontrol_num = 0;

int HIT_pos_org_int = 0;

int HIT_virtual_ps_sig_int = 0;
int HIT_virtual_ps_int = 0;
int HIT_position_err_int = 0;
int HIT_position_fb_16_int = 0;
int HIT_servofirst_begin = 1;

float HIT_position_fb_f = 0.0;
int HIT_positionfir_fb_16_int = 0;
int HIT_position_fb_err_16_int = 0;
int HIT_position1_fb_16_int = 0;
float HIT_positon_Kp_trans_f = 0.0;
float HIT_positon_Kp_int_float = 14;//7;
//int HIT_positon_Kp_int = 14;//7;
float HIT_positon_Kp_f = 0.0;
float HIT_pos_org_f = 0.0;
int HIT_virtual_ps_cycle_count = 0;

float HIT_virtual_ps_int_err_f;
float HIT_virtual_ps_int_err_sum_f;
float HIT_virtual_ps_int_err_int_f;
int HIT_position_client_int = 625;//65536;
float HIT_position_client_f;
int HIT_virtual_ps_int_err_int_int;
float HIT_virtual_ps_int_err_float_f;

unsigned short HIT_tgr_b_val3;
unsigned short HIT_tgr_d_val3;
unsigned short HIT_tgr_a_val4;
unsigned short HIT_tgr_c_val4;
unsigned short HIT_tgr_b_val4;
unsigned short HIT_tgr_d_val4;

unsigned short HIT_counter_val0=0;
unsigned short HIT_gtccr_a_val0=1200;
unsigned short HIT_gtccr_b_val0=1200;

unsigned short HIT_counter_val1=0;
unsigned short HIT_gtccr_a_val1=1200;
unsigned short HIT_gtccr_b_val1=1200;


unsigned short HIT_counter_val2=0;
unsigned short HIT_gtccr_a_val2=1200;
unsigned short HIT_gtccr_b_val2=1200;


unsigned int HIT_qa=0;
unsigned int HIT_system_count = 0;
int HIT_systemcontrol_mode = 1;
int HIT_make_angle_mode = 0;

float HIT_Ki;
float HIT_iq_Ki;
float HIT_id_err;
float HIT_iq_err;
float HIT_Ud;
float HIT_Uq;
float HIT_Ua;
float HIT_Ub;
float HIT_Usquare;
float HIT_Ualfa;
float HIT_Ulim;
float HIT_Ualfam;
int HIT_sitaintab;
float HIT_sitalfa;
float HIT_U_a;
float HIT_U_b;
float HIT_U_c;

unsigned short HIT_sci;
float HIT_iv_fbadf;
unsigned short HIT_iv_fbad;
unsigned short HIT_sci;
unsigned short HIT_sci_1;
unsigned short HIT_sci_2;
unsigned short HIT_sci_3;
unsigned short HIT_sci_4;
unsigned short HIT_sci_5;
unsigned short HIT_sci_6;
unsigned short HIT_sci_7;
unsigned short HIT_sci_8;
unsigned short HIT_sci_9;
unsigned short HIT_sci_10;
unsigned short HIT_sci_11;
unsigned short HIT_sci_12;
unsigned short HIT_sci_13;
unsigned short HIT_sci_14;
unsigned short HIT_sci_15;
unsigned short HIT_sci_16;
unsigned short HIT_DA_t;
unsigned short HIT_DA_channel = 1;

float HIT_run_mode = 1;//
float HIT_poles = 5.0;//1.0;
float HIT_curr_sen =100;//4.167;//100;//100;//66;//185;//66;//mV/A
float HIT_iq_ref = 0.1;//1;//2;//1;//2;
float HIT_id_ref = 0.0;
float HIT_pwm_off_vector_min = 40;
float HIT_pwm_off=240;//130;//360;//240;//120;//360;
float HIT_pwm_deadoff = 40;//80;//120;//3.5us
float HIT_lm = 0.00008;//0.00224;//0.0007;//0.025;//0.000189;//0.025;//0.000189;//0.00126;//0.000165;//0.00002118;//0.0001;//0.000165;//0.02118;//0.000065;//0.025;//0.000065;
float HIT_Lq = 0.00006;//0.0000007;//0.00224;//0.0007;//0.025;//0.07924391;//0.000189;//0.07924391;//0.000189;//0.00126;//0.000165;//0.00002118;//0.0001;//0.000165;//0.02118;//0.000065;//0.07924391;//0.2;//0.07924391;
float HIT_Ld = 0.00006;//0.0000007;
float HIT_Rs = 0.001;//1.5;//11.2;//1.5;//7.771897;//8.3677;//7.771897;//0.54;//0.07912;//7.771897;//0.07912;//7.771897;//7.6253//7.771897//4.2
float HIT_Ts = 0.00005;
float HIT_ki = 800;//200;//380;//200;//300;//1040;//1000;
float HIT_iq_ki=800;
float HIT_kv = 5000;//1600;//800;//1400;//800;//1200;//1045;//4000;
float HIT_iq_kv=800;
float HIT_faif =  0.0036;//0.000395;//0.0395;//0.238845;//0.00402979194;//0.0402979194;//0.0422;//0.00139;//0.9530334;//0.006067;//29.08731;//25.8472;//0.006067;//0.0422;/9.5493
float HIT_WL_Jm = 0.00000069808;//0.0000850742;//0.00023061;//0.0000850742;//0.0002166;//0.0000313;//0.0002166;//0.00012;
float HIT_alfa = 0.0;//1.0;
float HIT_WLMechkv = 60;//20;//120;
float HIT_Mech_alfa = 0;//1.0;
float HIT_WLw_ref = 0.0;//52.36;//20.9;//100;//5.233;//42;//0;//5.233;//2.093//0.0010467;//5.233;//0.01047;//31.4;//0.1046;//104.7;//rad/s
float HIT_MechTi = 0.05;//0.2;//s
float HIT_WL_T_factor = 4.941;//0.03;//0.4;//0.012;//0.4;//0.012; 
float HIT_WLw_ref_iden = 3;//rad/s
float HIT_WLw_err;
float HIT_WLMech_Ki;
float HIT_WLMechki;
float HIT_WL_Mech_spee_out_Tmc;
float HIT_WL_Mech_spee_out;
float HIT_WLw_org;
float HIT_v_max = 418.667;//628;//104.667;//837.33;//628;//628;//20.932;//5.233;//104.667;//523.333;//314;//52.333;//314;//52.333;//314;//261.667;//209.33;//157;//104.67;//83.73;//62.8;//52.333;//20.932;
float HIT_max_speed_err = 2.0932;
float HIT_max_speed_err_neg = -2.0932;

float HIT_WL_A = 62800;//10r/ms*6.28*1000/////speed step 62800*84/1000000=5.2752rad/s==>50.4rpm
float HIT_speed_err;

//unsigned short HIT_filter_initial; 
unsigned short HIT_filter_depth;
//unsigned short HIT_a_phase_filter[4];
//unsigned short HIT_a_phase_sum;
unsigned short HIT_b_phase_filter[4];
unsigned short HIT_b_phase_sum;

unsigned short HIT_current_filter_initial;
unsigned short HIT_current_filter_depth;
unsigned short HIT_u_phase_filter[4];
unsigned short HIT_u_phase_sum;
unsigned short HIT_w_phase_filter[4];
unsigned short HIT_w_phase_sum;
unsigned short HIT_v_phase_filter[4];
unsigned short HIT_v_phase_sum;

unsigned int HIT_pwm_en_out = 0;

float HIT_kr = 0.866;
float HIT_khalf= 0.5;
int HIT_boun1= 0;
int HIT_boun2 = 682;
int HIT_boun3 = 1364;
int HIT_boun4 = 2046;
int HIT_boun5 = 2728;
int HIT_boun6 = 3410;
int HIT_boun7 = 4096;
float HIT_ualfamax_k = 1.15473;
int HIT_pwm_full = 2000;//4000;//2000;//880;

int HIT_sitadian_check;
float HIT_speedlpf_pole;

//unsigned char HIT_ceshi[4];
unsigned char rcvbuff_char;
unsigned char HIT_judge;
unsigned short HIT_tran_start;
unsigned short rcvbuff_char_1;
unsigned short rcvbuff_char_2;
unsigned short rcvbuff_char_3;
unsigned short rcvbuff_char_4;
unsigned short rcvbuff_char_5;
unsigned short rcvbuff_char_6;
unsigned short rcvbuff_char_7;
unsigned short rcvbuff_char_8;
unsigned short rcvbuff_short_title;
unsigned short HIT_change_num_title;
unsigned short rcvbuff_short_num;
unsigned short HIT_change_num;

unsigned char HIT_ready_go = 0;

int HIT_biaoding_int;
int HIT_biaoding_int_bia;
int HIT_check_area_int;
int HIT_add_point_int;
int HIT_check_area_int;
int HIT_check_area_bia_int;
float HIT_y_a1_f;
float HIT_y_a2_f;
float HIT_x_a1_f;
float HIT_k_f ;
float HIT_b_f ;
float HIT_add_point_f ;
float HIT_biaodingarry[];
float HIT_biaoding_ang_f ;
float HIT_biaoding_f;
float HIT_new_angle_f;
int HIT_new_angle_int;
float HIT_iq_ref_mech_max = 25;//25;40dianji//20;//15;//20140428

unsigned short HIT_new_angle_short;

#define HIT_BOUN1 0
#define HIT_BOUN2 682
#define HIT_BOUN3 1364
#define HIT_BOUN4 2046
#define HIT_BOUN5 2728
#define HIT_BOUN6 3410
#define HIT_BOUN7 4096
#define HIT_PWMOUTULIM 1732//3464//1732//762//450//900//866/*4000:output Max*86.6%*/
#define HIT_UALFAMAX_K 1.15473
#define HIT_KR 0.866
#define HIT_VOLCENTER 2.5
#define HIT_IDQ_SPE_SQUARE 9//special current:3  3*3=9
#define HIT_POSITIONERR_16WEI 10430.378
#define HIT_POSITION_16WEI 65536
#define HIT_PWM_FULL 2000//4000//2000//880
#define HIT_HALFPIE 1.5708
#define HIT_PIE 3.1415926
#define HIT_TWOTHIRDPIE 4.71239
#define HIT_TWOPIE 6.28319
#define HIT_MAKE16WEI_ANGLE 10430.378//10420.6
#define HIT_AD16WEI 65536

/****************** 207程序通信相关 ********************************/
uchar ucShake_success = 0;       // serial receive Loop status
uchar ucLaser_success = 0;       // laser launch result feedback
uchar ucCapture_success = 0;     // 指令捕获结果
uchar ucSerial_send_status = 0;  // serial send Loop status 0: 什么都不发送； 1. 发送自检结果 ； 2. 发送检测结果
uchar ucLaser_send_status = 0;   // Laser send loop status  0: 什么都不发送； 1. 发送自检指令；  2. 发送上位机的控制指令
ST_SERIAL_DECODE stSerial_decode = {0};     //解析数据的结构体
ST_SERIAL_DECODE stLaser_decode = {0};     //解析激光板的结构体
ST_SERIAL_DATA stSerial_data = {0};       // 发送数据的结构体
ST_PC_CMD st_pc_cmd = {0};                // 计算机指令
uint u32Error_count = 0;              // 错误计数
uint laser_time_count = 0;            // 定时计数器，1000个计数发送一次初始化 ， 10个计数发送一次查询
#endif