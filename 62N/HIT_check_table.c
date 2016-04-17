#include "HIT_check_table.h"
#include <math.h>
#include <mathf.h>

void HIT_check_table(void)
{

/*check start*/
		
		if(HIT_sitadian_check<1024)/*find table calculat sin(sita)and cos(sita) add process of zone line*/
		{
			HIT_sinzhi_a = HIT_y[HIT_sitadian_check];
			HIT_sitacheck_cos = 1023-HIT_sitadian_check;
			HIT_coszhi_a = HIT_y[HIT_sitacheck_cos];
			HIT_xw=1;	
		}
		else 
		{
			if(HIT_sitadian_check<2048)
			{
				HIT_sitacheck_sin = 2047 - HIT_sitadian_check;
				HIT_sinzhi_a = HIT_y[HIT_sitacheck_sin];
				HIT_sitacheck_cos = HIT_sitadian_check-1024;
				HIT_coszhi_a = -HIT_y[HIT_sitacheck_cos];
				HIT_xw=2;	
			}
			else
			{
				if(HIT_sitadian_check<3072)
				{
					HIT_sitacheck_sin = HIT_sitadian_check-2048;
					HIT_sinzhi_a =( -HIT_y[HIT_sitacheck_sin]);
					HIT_sitacheck_cos = 3071 - HIT_sitadian_check;
					HIT_coszhi_a = -HIT_y[HIT_sitacheck_cos];
					HIT_xw=3;
				}	
				else
				{
					HIT_sitacheck_sin = 4095 - HIT_sitadian_check;
					HIT_sinzhi_a = (-HIT_y[HIT_sitacheck_sin]);
					HIT_sitacheck_cos = HIT_sitadian_check - 3072;
					HIT_coszhi_a = HIT_y[HIT_sitacheck_cos];
					HIT_xw=4;	
				}	
			}
		}
		HIT_3sitadian_check=(3*HIT_sitadian_check)%4096;
		
if(HIT_3sitadian_check<1024)/*find table calculat sin(sita)and cos(sita) add process of zone line*/
		{
			HIT_sinzhi_3a = HIT_y[HIT_3sitadian_check];
			HIT_sitacheck_cos = 1023-HIT_3sitadian_check;
			HIT_coszhi_3a = HIT_y[HIT_3sitacheck_cos];
			HIT_xw=1;	
		}
		else 
		{
			if(HIT_3sitadian_check<2048)
			{
				HIT_3sitacheck_sin = 2047 - HIT_3sitadian_check;
				HIT_sinzhi_3a = HIT_y[HIT_3sitacheck_sin];
				HIT_3sitacheck_cos = HIT_3sitadian_check-1024;
				HIT_coszhi_3a = -HIT_y[HIT_3sitacheck_cos];
				HIT_xw=2;	
			}
			else
			{
				if(HIT_3sitadian_check<3072)
				{
					HIT_3sitacheck_sin = HIT_3sitadian_check-2048;
					HIT_sinzhi_3a =( -HIT_y[HIT_3sitacheck_sin]);
					HIT_3sitacheck_cos = 3071 - HIT_3sitadian_check;
					HIT_coszhi_3a = -HIT_y[HIT_3sitacheck_cos];
					HIT_xw=3;
				}	
				else
				{
					HIT_3sitacheck_sin = 4095 - HIT_3sitadian_check;
					HIT_sinzhi_3a = (-HIT_y[HIT_3sitacheck_sin]);
					HIT_3sitacheck_cos = HIT_3sitadian_check - 3072;
					HIT_coszhi_3a = HIT_y[HIT_3sitacheck_cos];
					HIT_xw=4;	
				}	
			}
		}
/*end*/
	
/*		if((HIT_sitacheck>=0)&&(HIT_sitacheck<1025))/*find table calculat sin(sita)and cos(sita) no process of zone line */
/*		{
			HIT_sinzhi_a = HIT_y[HIT_sitacheck];/*effect is bad*/
/*			HIT_coszhi_a = HIT_y[1024-HIT_sitacheck];
			HIT_xw=1;	
		}
		if((HIT_sitacheck>=1025)&&(HIT_sitacheck<2049))
		{
			HIT_sinzhi_a = HIT_y[2048-HIT_sitacheck];
			HIT_coszhi_a = -HIT_y[HIT_sitacheck-1024];
			HIT_xw=2;
		}
		
		if((HIT_sitacheck>=2049)&&(HIT_sitacheck<3073))
		{
			HIT_sinzhi_a =( -HIT_y[HIT_sitacheck-2049]);
			HIT_coszhi_a = -HIT_y[3072-HIT_sitacheck];
			HIT_xw=3;
		}
	
		if((HIT_sitacheck>=3073)&&(HIT_sitacheck<4096))
		{
			HIT_sinzhi_a = (-HIT_y[4095-HIT_sitacheck]);
			HIT_coszhi_a = HIT_y[HIT_sitacheck-3073];
			HIT_xw=4;
		}*//*end*/
		
		
		HIT_sinzhi_b = HIT_KR*HIT_coszhi_a - HIT_KHALF*HIT_sinzhi_a;//sin(120+sita)
		HIT_sinzhi_c = -HIT_KR*HIT_coszhi_a - HIT_KHALF*HIT_sinzhi_a;//sin(240+sita)
		HIT_coszhi_b = -HIT_KHALF*HIT_coszhi_a - HIT_KR*HIT_sinzhi_a;//cos(120+sita)
		HIT_coszhi_c = -HIT_KHALF*HIT_coszhi_a + HIT_KR*HIT_sinzhi_a;//cos(240+sita)
		if(HIT_sinzhi_b > 1)
		{
			HIT_sinzhi_b = 0.99999;	
		}
		if(HIT_sinzhi_c > 1)
		{
			HIT_sinzhi_c = 0.99999;	
		}
		if(HIT_sinzhi_b < -1)
		{
			HIT_sinzhi_b = -0.99999;	
		}
		if(HIT_sinzhi_c < -1)
		{
			HIT_sinzhi_c = -0.99999;	
		}
		if(HIT_coszhi_b > 1)
		{
			HIT_coszhi_b = 0.99999;	
		}
		if(HIT_coszhi_c > 1)
		{
			HIT_coszhi_c = 0.99999;	
		}
		if(HIT_coszhi_b < -1)
		{
			HIT_coszhi_b = -0.99999;	
		}
		if(HIT_coszhi_c < -1)
		{
			HIT_coszhi_c = -0.99999;	
		}
		if(HIT_coszhi_3a < -1)
		{
			HIT_coszhi_3a = -0.99999;	
		}
		if(HIT_coszhi_3a < -1)
		{
			HIT_coszhi_3a = -0.99999;	
		}
}