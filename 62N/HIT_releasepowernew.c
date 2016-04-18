#include "iodefine.h"
float HIT_power_now;
float HIT_power_now_sum = 0;
float HIT_R_power = 450;
float HIT_R_power_T = 0;
extern float HIT_speedlpf;
extern float HIT_WL_Mech_spee_out_Tmc;
extern float HIT_iq_fb;
extern float HIT_release_time_f ;
void HIT_releasepowernew()
{
	
	HIT_power_now = HIT_speedlpf*HIT_iq_fb;
	HIT_power_now_sum = HIT_power_now_sum - HIT_power_now;	
	if(HIT_power_now_sum < 0)
	{
		HIT_power_now_sum = 0;
	}
//	if(HIT_power_now < 0)
//	{
//		HIT_power_now_sum = HIT_power_now_sum - HIT_power_now;	
//	}
	HIT_R_power_T = HIT_release_time_f*HIT_R_power;
	if(HIT_power_now_sum > HIT_R_power_T)
	{
		PORTA.DR.BIT.B2	= 1;
		HIT_power_now_sum = HIT_power_now_sum - HIT_R_power;
	}	
	else
	{
		PORTA.DR.BIT.B2	= 0;	
	}
}