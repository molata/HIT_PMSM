
extern union {
		unsigned char HIT_rec_adrr_buff_char;
		struct {
			unsigned char HIT_rec_data:4;//最低位
			unsigned char HIT_rec_state:1;//中间位
			unsigned char HIT_rec_serial:3;//最高位
		} BIT;
	} HIT_rec_adrr_buff[8];
extern unsigned short HIT_servo_count;
extern unsigned char HIT_en_tog_start_flag;
extern unsigned char HIT_pwm_mode_choose;
extern char HIT_ready_go;
extern int HIT_jogon_count ;
#include "iodefine.h"
void HIT_shouchaoqi_con_servon()
{
	HIT_rec_adrr_buff[0].BIT.HIT_rec_data = 0;
	HIT_rec_adrr_buff[1].BIT.HIT_rec_data = 0;
	HIT_rec_adrr_buff[2].BIT.HIT_rec_data = 0;
	HIT_rec_adrr_buff[3].BIT.HIT_rec_data = 0;
	HIT_servo_count++;
/*	if(HIT_servo_count > 200)
	{
		HIT_en_tog_start_flag = 1;
	}*/	
	if(HIT_jogon_count > 500)//modify 20131003
	{
		if(HIT_servo_count > 1)//modify 20131003
		{
			HIT_en_tog_start_flag = 1;
			HIT_jogon_count = 0;
			
		}	
	}
	if(HIT_en_tog_start_flag == 1)
	{
		HIT_servo_count = 0;
		HIT_en_tog_start_flag = 0;
		HIT_pwm_mode_choose++;
		if(HIT_pwm_mode_choose == 3)
		{
			HIT_pwm_mode_choose = 1;	
		}
		
			
	}
	if(HIT_pwm_mode_choose == 1)
	{
		 HIT_ready_go =1;
		 	
	}	
}