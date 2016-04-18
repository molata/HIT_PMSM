#ifndef HIT_SHOUCAOQI_H
#define HIT_SHOUCAOQI_H
extern unsigned char HIT_iic_word_send[2] ;/////// address and data to iic send
unsigned char HIT_iic_word_rec;
unsigned char HIT_iic_word_rec_ad = 0x02;// address of iic read ///////////////////////////////////
unsigned char HIT_iic_send_num = 0;
unsigned char HIT_iic_rec_num = 0;
unsigned int HIT_int_send = 0;
unsigned int HIT_rec_num = 0;
unsigned char rcvbuff_char_gr[8];
unsigned short HIT_cmt = 0;
unsigned char HIT_send_data;
unsigned char HIT_rec_i = 0;
unsigned char HIT_iic_send_buff_i=0;
unsigned char HIT_iic_send_buff[8];
unsigned char HIT_iic_send_count = 0;
unsigned char HIT_rewrite_eep = 0;
unsigned char HIT_iic_word_rec_judge;
unsigned char HIT_change_num_title_judge;

unsigned char HIT_angle_send_buff_i = 0;
unsigned char HIT_angle_send_buff[8];
unsigned char HIT_angle_send;
extern int HIT_sitaintf_curr_int;
extern char HIT_ready_go;
unsigned char HIT_iic_choose = 0;

unsigned char HIT_iic_word_rec_1;
unsigned char HIT_iic_word_rec_2;
unsigned short HIT_iic_word_rec_short;
unsigned short HIT_iic_word_rec_short_judge;
unsigned char HIT_iic_word_send_fir;
unsigned char HIT_iic_word_send_sec;
unsigned char HIT_iic_write_choose = 0;
unsigned short HIT_change_num_H;
unsigned short HIT_change_num_L;

unsigned short HIT_p_getad_cmt[4];
unsigned short HIT_n_getad_cmt[4]; 
int HIT_make_angle_mode_cmt;
unsigned short HIT_a_p_hall_cmt;
unsigned short HIT_a_n_hall_cmt;
float HIT_a_hall_cmt;
float HIT_b_hall_cmt;
float HIT_c_hall_cmt;
float HIT_d_hall_cmt;
float HIT_q_hall_cmt;
signed int HIT_a_n_int_cmt;
signed int HIT_a_p_int_cmt;
signed int HIT_s0TX_buffer1_cmt;
signed int HIT_s0TX_buffer2_cmt;
signed int HIT_s0TX_buffer3_cmt;
float HIT_sita_cmt;
float HIT_sitaintf_curr_mech_f_cmt;
signed int HIT_sitaintf_curr_mech_int_cmt;
unsigned short HIT_sitaintf_curr_mech_short_cmt;
unsigned char HIT_sitaintf_curr_mech_char_buff[8];
unsigned char HIT_enc_buff_i = 0;

unsigned char HIT_enc_count=0;
int HIT_sitaintf_curr_mech_int_cmt_bia;

int HIT_check_area_int_cmt;
int HIT_check_area_bia_int_cmt;
float HIT_y_a1_f_cmt;
float HIT_y_a2_f_cmt;
float HIT_x_a1_f_cmt;
float HIT_k_f_cmt ;
float HIT_b_f_cmt ;
float HIT_add_point_f_cmt;
int HIT_add_point_int_cmt;
extern float HIT_biaodingarry[1024];
float HIT_biaoding_ang_f_cmt ;
float HIT_biaoding_f_cmt;
float HIT_new_angle_f_cmt;
int HIT_new_angle_int_cmt;
signed int HIT_sitaintf_curr_int_cmt;
unsigned char HIT_iic_write_choose_U_phase = 0;
extern unsigned short HIT_new_angle_short;
unsigned short HIT_change_num_H_U_phase;
unsigned short HIT_change_num_L_U_phase;
extern int HIT_sitaintf_curr_mech_int;
extern unsigned short rcvbuff_char_1;
extern unsigned short rcvbuff_char_2;
extern unsigned short rcvbuff_char_3;
extern unsigned short rcvbuff_char_4;
extern unsigned short rcvbuff_char_5;
extern unsigned short rcvbuff_char_6;
extern unsigned short rcvbuff_char_7;
extern unsigned short rcvbuff_char_8;
//extern unsigned char HIT_ceshi[];
extern unsigned char HIT_judge;
extern unsigned short rcvbuff_short_title;
extern unsigned short HIT_change_num_title;
extern unsigned short rcvbuff_short_num;
extern unsigned short HIT_change_num;
#define HIT_HALFPIE 1.5708
#define HIT_PIE 3.1415926
#define HIT_TWOTHIRDPIE 4.71239
#define HIT_TWOPIE 6.28319
#define HIT_MAKE16WEI_ANGLE 10430.378//10420.6
void shoucaoqi_loop();
void HIT_shouchaoqi();
#endif