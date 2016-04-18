#ifndef CMT0INTFUNCH
#define CMT0INTFUNCH

extern float HIT_curren_aa_q_max_cmt0;
extern float HIT_now_voltage_f_out;
extern float HIT_kv;
extern float HIT_id_fb_square;
extern float HIT_id_fb;
extern float HIT_iq_fb;
extern float HIT_iq_fb_square;
extern float HIT_idq_square;
extern int HIT_shortime_cur_count;
extern float HIT_positon_Kp_trans_f;
extern float HIT_positon_Kp_int_float;
//extern int HIT_positon_Kp_int;
extern float HIT_positon_Kp_f;
//extern unsigned char HIT_ceshi[];
extern int HIT_sitaintf_curr_mech_int;
extern unsigned short HIT_Umsensor;

extern unsigned char rcvbuff_char;
extern unsigned char HIT_judge;
extern unsigned short HIT_tran_start;
extern unsigned short rcvbuff_char_1;
extern unsigned short rcvbuff_char_2;
extern unsigned short rcvbuff_char_3;
extern unsigned short rcvbuff_char_4;
extern unsigned short rcvbuff_char_5;
extern unsigned short rcvbuff_char_6;
extern unsigned short rcvbuff_char_7;
extern unsigned short rcvbuff_char_8;
extern unsigned short rcvbuff_short_title;
extern unsigned short HIT_change_num_title;
extern unsigned short rcvbuff_short_num;
extern unsigned short HIT_change_num;

#define HIT_IDQ_SPE_SQUARE 9//special current:3  3*3=9
#define HIT_TWOPIE 6.28319
#define HIT_POSITION_16WEI 65536
#endif