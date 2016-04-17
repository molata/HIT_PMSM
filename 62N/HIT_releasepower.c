#ifndef HITRELEASEPOWERC
#define HITRELEASEPOWERC

void hitreleasepower()
{
	/****
	HITpower_now = (-HIT_speedlpf*HITWL_Mech_spee_out_Tmc);
	HITpower_reles_out = HITpower_now - HITpower_reles_system_o;
	HITpower_R_w = HIT_Um*HIT_Um/HITR_release;
	HITpower_RelesUse_s = HITpower_RelesUse_s + HITpower_reles_out;
	if(HITpower_RelesUse_s > 0)
	{
		if(HITpower_RelesUse_s > HITpower_R_w)
		{
			HIT_relese_pwm = HIT_relese_pwm_full;
			HITpower_RelesUse_s = HITpower_RelesUse_s - HITpower_R_w;	
		}	
		else
		{
			HIT_relese_pwm = HITpower_RelesUse_s/HITpower_R_w * HIT_relese_pwm_full;	
			HITpower_RelesUse_s = 0;
		}
	}
	else
	{
		HITpower_RelesUse_s = 0;	
	}
	****/	
}

#endif