#include"iodefine.h"
extern float HIT_iu_fb;
extern float HIT_iv_fb;
extern float HIT_iw_fb;
extern char HIT_ready_go;
float HIT_alarm = 0;
unsigned char HIT_current_onems_alarm_count = 0;
unsigned char HIT_current_onesec_alarm_count = 0;
#define HIT_ins_cur_ala 40  //modify 20140112 10
#define HIT_10ms_cur_ala 39 //modify 20140112 10
#define HIT_1s_cur_ala 38//modify 20140112 10
int HIT_alarm_num;
extern unsigned char HIT_pwm_mode_choose ;
void HIT_alarmnew()
{
/////////////////////////////////////////////////////instant  18A  alarm///////////////////////////////////////	
	if((HIT_iu_fb>HIT_ins_cur_ala)||(HIT_iv_fb>HIT_ins_cur_ala)||(HIT_iw_fb>HIT_ins_cur_ala)||(HIT_iu_fb<-HIT_ins_cur_ala)||(HIT_iv_fb<-HIT_ins_cur_ala)||(HIT_iw_fb<-HIT_ins_cur_ala))
		{
			HIT_alarm = 1;
			HIT_alarm_num = 1;
		//	PORT7.DR.BIT.B0 = 0;
		}
/////////////////////////////////////////////////////1ms  15A  alarm///////////////////////////////////////	
	if((HIT_iu_fb>HIT_10ms_cur_ala)||(HIT_iv_fb>HIT_10ms_cur_ala)||(HIT_iw_fb>HIT_10ms_cur_ala)||(HIT_iu_fb<-HIT_10ms_cur_ala)||(HIT_iv_fb<-HIT_10ms_cur_ala)||(HIT_iw_fb<-HIT_10ms_cur_ala))
	{
		HIT_current_onems_alarm_count++;
		if(HIT_current_onems_alarm_count == 10)
		{
			HIT_alarm = 1;	
			HIT_alarm_num = 2;
		//	PORT7.DR.BIT.B0 = 0;
		}	
	}
	else
	{
		HIT_current_onems_alarm_count = 0;
	//	PORT7.DR.BIT.B0 = 0;	
	}
/////////////////////////////////////////////////////1s  13A  alarm///////////////////////////////////////	
	if((HIT_iu_fb>HIT_1s_cur_ala)||(HIT_iv_fb>HIT_1s_cur_ala)||(HIT_iw_fb>HIT_1s_cur_ala)||(HIT_iu_fb<-HIT_1s_cur_ala)||(HIT_iv_fb<-HIT_1s_cur_ala)||(HIT_iw_fb<-HIT_1s_cur_ala))
	{
		HIT_current_onesec_alarm_count++;
		if(HIT_current_onesec_alarm_count == 100000)
		{
			HIT_alarm = 1;	
			HIT_alarm_num = 3;
		//	PORT7.DR.BIT.B0 = 0;
		}	
	}
	else
	{
		HIT_current_onesec_alarm_count = 0;	
	}
//////////////////////////////////////Alarm flag///////////////////////////////////////////////////////////////
	if(HIT_alarm == 1)
	{
		PORT7.DR.BIT.B0 = 0;
		HIT_pwm_mode_choose = 2;
		HIT_ready_go = 0;
		PORT7.DR.BIT.B1 = 0;
		PORT7.DR.BIT.B2 = 0;
		PORT7.DR.BIT.B3 = 0;
		PORT7.DR.BIT.B4 = 0;
		PORT7.DR.BIT.B5 = 0;
		PORT7.DR.BIT.B6 = 0;

			
	}
}