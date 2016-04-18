#ifndef GPT0CMVINTFUNCC
#define GPT0CMVINTFUNCC
#include "iodefine.h"
#include "HIT_current_pi.h"
#include "HIT_check_table.h"
#include "HIT_make_angle.h"
//#include "HIT_make_angleab.h"
#include "HIT_vectorcontrol.h"
#include "HIT_spacevectorcontrol.h"
#include "HIT_gpt0cmvintfunc.h"
#include "HIT_servoon.h"
#include "HIT_controlsystem_servoon.h"	
extern char HIT_ready_go;
unsigned short HIT_RX;
union {
		unsigned short HIT_RX_buff_short;
		struct {
			unsigned short HIT_RX_buff_low:12;//最低位
			unsigned short HIT_RX_buff_high:4;//最高位
		} BIT;
	} HIT_RX_buff;
unsigned short HIT_RX_buff_high_1 = 0;
unsigned short HIT_first_spi = 1;
unsigned short HIT_RX_buff_high_2 = 0;
unsigned short HIT_first_spi_count = 0;
unsigned short HIT_spi_make_right = 0;
float HIT_RX_buff_high_err = 0;
extern int HIT_alarm_num;
unsigned short HIT_RX_sita_short = 0;
unsigned short HIT_sita_spi_rec_short = 0;
#define HITtwopie 6.28319
float HIT_sita_M_8_1;
float HIT_sita_M_8_2;
float HIT_sita_M_8_err;
float HIT_sita_M_8_w;
extern float HIT_run_mode;
extern float HIT_sita_mode_10_f;
int HIT_mode_10_mag_sita_int;
float HIT_sita_mode_15_run_first_f;
unsigned short HIT_DA_mode_15_angle = 1;
float HIT_sita_mode_15_run_err_f = 0;
extern float HIT_lpfmode_10_1A;
extern float HIT_lpfmode_10_1B;
float HIT_sita_mode_10_fone = 0.0;
float HIT_sita_mode_10_ftwo = 0.0;
float HIT_sita_mode_10_f_lpf = 0.0;
void Gpt0CmVIntFunc()
{

}

#endif