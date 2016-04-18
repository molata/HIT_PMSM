#ifndef HITVECTORCONTROLC
#define HITVECTORCONTROLC
#include "HIT_vectorcontrol.h"
#include <math.h>
#include <mathf.h>
extern float HIT_now_voltage_f_out;
extern float HIT_Ud_Uq_sqrt;
float HIT_vector_pwm_center_f = 860;
float HIT_ft_Um = 129.90375;    //==150*0.8
extern float HIT_ft;
float HIT_ft_Umax;
float HIT_ft_Umin;
float HIT_ft_Ucenter;

int x=0;
#define HIT_voltage_utility 0.86
float HIT_UH_lim_wjw = 1760;//3760=(4000-240)--�����ڿ���ʱ��õ������������(������1us-80,���������趨Ϊ3us)
float HIT_UL_lim_wjw = 40;//�����ڿ���ʱ��õ���С��ʵ������
#define UP_LIMIT 1800
void HIT_vectorcontrol()
	{


///////////////////////////////////////////////////////////////////////////////////////////////
		
		HIT_Uu_3to2 =HIT_coszhi_a*HIT_Ud -HIT_sinzhi_a*HIT_Uq;//1.153*((HIT_coszhi_a-HIT_coszhi_3a/6)*HIT_Ud - (HIT_sinzhi_a+HIT_sinzhi_3a/6)*HIT_Uq);
		HIT_Uu_3to2 = HIT_Uu_3to2*0.6667;
		HIT_Uv_3to2 = HIT_coszhi_c*HIT_Ud -HIT_sinzhi_c*HIT_Uq;//1.153*((HIT_coszhi_c-HIT_coszhi_3a/6)*HIT_Ud - (HIT_sinzhi_c+HIT_sinzhi_3a/6)*HIT_Uq);
		HIT_Uv_3to2 = HIT_Uv_3to2*0.6667;
		HIT_Uw_3to2 = HIT_coszhi_b*HIT_Ud -HIT_sinzhi_b*HIT_Uq;//1.153*((HIT_coszhi_b-HIT_coszhi_3a/6)*HIT_Ud - (HIT_sinzhi_b+HIT_sinzhi_3a/6)*HIT_Uq);
		HIT_Uw_3to2 = HIT_Uw_3to2*0.6667;
////////////////////20141227///////////////////////////////////
        if (HIT_Ud_Uq_sqrt > 25*0.7)
		{
			if (HIT_Uu_3to2 >= HIT_Uv_3to2)
			  {
				 HIT_ft_Umax = HIT_Uu_3to2;
				 HIT_ft_Umin = HIT_Uv_3to2;  
			   }
	        else
			{  HIT_ft_Umax = HIT_Uv_3to2;
			   HIT_ft_Umin = HIT_Uu_3to2;
			 }
			if (HIT_Uw_3to2 >= HIT_ft_Umax)
			{
				HIT_ft_Umax = HIT_Uw_3to2;
			}
			else if (HIT_Uw_3to2 <= HIT_ft_Umin)
			
			{
				HIT_ft_Umin = HIT_Uw_3to2;
			}
			
		   HIT_ft_Ucenter = HIT_ft_Umax + HIT_ft_Umin;
		   HIT_ft_Ucenter = HIT_ft_Ucenter*0.5;
		   HIT_Uu_3to2 = HIT_Uu_3to2 - HIT_ft_Ucenter;
		   HIT_Uv_3to2 = HIT_Uv_3to2 - HIT_ft_Ucenter;
		   HIT_Uw_3to2 = HIT_Uw_3to2 - HIT_ft_Ucenter;
		 }
		
/*		if(HIT_Uu_3to2 > HIT_Um)
		{
			HIT_Uu_3to2 = HIT_Um;
		}
		if(HIT_Uu_3to2 < -HIT_Um)
		{
			HIT_Uu_3to2 = -HIT_Um;
		}*/
		HIT_pwm_af = (HIT_Uu_3to2/HIT_Um/HIT_voltage_utility*HIT_vector_pwm_center_f+HIT_vector_pwm_center_f+40);//*HIT_Vol_adj_fac;
	/*	if(HIT_Uv_3to2 > HIT_Um)
		{
			HIT_Uv_3to2 = HIT_Um;
		}
		if(HIT_Uv_3to2 < -HIT_Um)
		{
			HIT_Uv_3to2 = -HIT_Um;
		}*/
		HIT_pwm_bf = (HIT_Uv_3to2/HIT_Um/HIT_voltage_utility*HIT_vector_pwm_center_f+HIT_vector_pwm_center_f+40);//*HIT_Vol_adj_fac;
/*		if(HIT_Uw_3to2 > HIT_Um)
		{
			HIT_Uw_3to2 = HIT_Um;
		}
		if(HIT_Uw_3to2 < -HIT_Um)
		{
			HIT_Uw_3to2 = -HIT_Um;
		}*/
		HIT_pwm_cf =  (HIT_Uw_3to2/HIT_Um/HIT_voltage_utility*HIT_vector_pwm_center_f+HIT_vector_pwm_center_f+40);//*HIT_Vol_adj_fac;
		
/*dead off*/
//		HIT_pwm_af = HIT_pwm_af-HIT_pwm_deadoff;
			
//		HIT_pwm_bf = HIT_pwm_bf-HIT_pwm_deadoff;
		
//		HIT_pwm_cf = HIT_pwm_cf-HIT_pwm_deadoff;
/*dead off end*/
/*
		if(HIT_pwm_af < HIT_pwm_off_vector_min)
		{
			HIT_pwm_af = HIT_pwm_off_vector_min;		
		}
		if(HIT_pwm_bf < HIT_pwm_off_vector_min)
		{
			HIT_pwm_bf = HIT_pwm_off_vector_min;		
		}
		if(HIT_pwm_cf < HIT_pwm_off_vector_min)
		{
			HIT_pwm_cf = HIT_pwm_off_vector_min;		
		}*/
/*		
				if(HIT_pwm_af >=UP_LIMIT)
		{
			if (HIT_pwm_bf>=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_af = HIT_pwm_af-HIT_pwm_cf;
			  HIT_pwm_bf = HIT_pwm_bf-HIT_pwm_cf;
			  HIT_pwm_cf = 0;
			}
			else if (HIT_pwm_cf>=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_af = HIT_pwm_af-HIT_pwm_bf;
			  HIT_pwm_cf = HIT_pwm_cf-HIT_pwm_bf;
			  HIT_pwm_bf = 0;
			}
			else
			{
			HIT_pwm_bf = HIT_pwm_bf+UP_LIMIT-HIT_pwm_af;
			HIT_pwm_cf = HIT_pwm_cf+UP_LIMIT-HIT_pwm_af;
			HIT_pwm_af = UP_LIMIT;
			}
		}
		else if(HIT_pwm_bf >= UP_LIMIT)
		{
			if (HIT_pwm_af>=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_af = HIT_pwm_af-HIT_pwm_cf;
			  HIT_pwm_bf = HIT_pwm_bf-HIT_pwm_cf;
			  HIT_pwm_cf = 0;
			  }
			
			else if (HIT_pwm_cf>=HIT_vector_pwm_center_f)
			{
		      HIT_pwm_bf = HIT_pwm_bf-HIT_pwm_af;
			  HIT_pwm_cf = HIT_pwm_cf-HIT_pwm_af;
			  HIT_pwm_af = 0;
			}
			else
			{
			HIT_pwm_af = HIT_pwm_af+UP_LIMIT-HIT_pwm_bf;
			HIT_pwm_cf = HIT_pwm_cf+UP_LIMIT-HIT_pwm_bf;
			HIT_pwm_bf = UP_LIMIT;
			}
		}
		else if(HIT_pwm_cf >= UP_LIMIT )
		{
			if (HIT_pwm_af>=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_af = HIT_pwm_af-HIT_pwm_bf;
			  HIT_pwm_cf = HIT_pwm_cf-HIT_pwm_bf;
			  HIT_pwm_bf = 0;
			}
			else if (HIT_pwm_bf>=HIT_vector_pwm_center_f)
			{
		      HIT_pwm_bf = HIT_pwm_bf-HIT_pwm_af;
			  HIT_pwm_cf = HIT_pwm_cf-HIT_pwm_af;
			  HIT_pwm_af = 0;
			}
			else
			{
			HIT_pwm_af = HIT_pwm_af+UP_LIMIT-HIT_pwm_cf;
			HIT_pwm_bf = HIT_pwm_bf+UP_LIMIT-HIT_pwm_cf;
			HIT_pwm_cf = UP_LIMIT;
			}
		}
/////////////////////////////////////////////////////////////////////
		if(HIT_pwm_af < HIT_pwm_off_vector_min)
		{
			if (HIT_pwm_bf<=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_af = HIT_pwm_af+UP_LIMIT-HIT_pwm_cf;
			  HIT_pwm_bf = HIT_pwm_bf+UP_LIMIT-HIT_pwm_cf;
			  HIT_pwm_cf = UP_LIMIT;
			}
			else if (HIT_pwm_cf<=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_af = HIT_pwm_af+UP_LIMIT-HIT_pwm_bf;
			  HIT_pwm_cf = HIT_pwm_cf+UP_LIMIT-HIT_pwm_bf;
			  HIT_pwm_bf = UP_LIMIT;
			}
			else
			{
			HIT_pwm_bf = HIT_pwm_bf+HIT_pwm_off_vector_min-HIT_pwm_af;
			HIT_pwm_cf = HIT_pwm_cf+HIT_pwm_off_vector_min-HIT_pwm_af;
			HIT_pwm_af = HIT_pwm_off_vector_min;
			}
		}
		if(HIT_pwm_bf < HIT_pwm_off_vector_min)
		{
			if (HIT_pwm_af<=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_af = HIT_pwm_af+UP_LIMIT-HIT_pwm_cf;
			  HIT_pwm_bf = HIT_pwm_bf+UP_LIMIT-HIT_pwm_cf;
			  HIT_pwm_cf = UP_LIMIT;
			}
			else if (HIT_pwm_cf<=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_bf = HIT_pwm_bf+UP_LIMIT-HIT_pwm_af;
			  HIT_pwm_cf = HIT_pwm_cf+UP_LIMIT-HIT_pwm_af;
			  HIT_pwm_af = UP_LIMIT;
			}
			else
			{
			HIT_pwm_af = HIT_pwm_af+HIT_pwm_off_vector_min-HIT_pwm_bf;
			HIT_pwm_cf = HIT_pwm_cf+HIT_pwm_off_vector_min-HIT_pwm_bf;
			HIT_pwm_bf = HIT_pwm_off_vector_min;
			}		
		}
		if(HIT_pwm_cf < HIT_pwm_off_vector_min)
		{
			if (HIT_pwm_af<=HIT_vector_pwm_center_f)
			{
			HIT_pwm_af = HIT_pwm_af+UP_LIMIT-HIT_pwm_bf;
			HIT_pwm_cf = HIT_pwm_cf+UP_LIMIT-HIT_pwm_bf;
			HIT_pwm_bf = UP_LIMIT;
			}
			else if (HIT_pwm_bf<=HIT_vector_pwm_center_f)
			{
			  HIT_pwm_bf = HIT_pwm_bf+UP_LIMIT-HIT_pwm_af;
			  HIT_pwm_cf = HIT_pwm_cf+UP_LIMIT-HIT_pwm_af;
			  HIT_pwm_af = UP_LIMIT;
			}
			else 
			{
			HIT_pwm_af = HIT_pwm_af+HIT_pwm_off_vector_min-HIT_pwm_cf;
			HIT_pwm_bf = HIT_pwm_bf+HIT_pwm_off_vector_min-HIT_pwm_cf;
			HIT_pwm_cf = HIT_pwm_off_vector_min;
			}		
		}
		
		
		/*if(HIT_pwm_af > HIT_PWMOUTULIM)
		{
			HIT_pwm_af = HIT_PWMOUTULIM;
		}
		if(HIT_pwm_bf > HIT_PWMOUTULIM)
		{
			HIT_pwm_bf = HIT_PWMOUTULIM;
		}
		if(HIT_pwm_cf > HIT_PWMOUTULIM)
		{
			HIT_pwm_cf = HIT_PWMOUTULIM;
		}*/
			if(HIT_pwm_af < HIT_UL_lim_wjw)//ʵ��õ���С����Ϊ40ʱ����ʵ��Ϊ0.5us,����С����20,30����ֵ����
		{
			HIT_pwm_af = HIT_UL_lim_wjw;
			
		  }
		if(HIT_pwm_af > HIT_UH_lim_wjw)//ʵ��õ��������Ϊ3760-����ʵ��47us,���ٱ�3760�󲻿�ʵ�֡�
		{
			HIT_pwm_af = HIT_UH_lim_wjw;
			
		  }
		if(HIT_pwm_bf < HIT_UL_lim_wjw)
		{
			HIT_pwm_bf = HIT_UL_lim_wjw;
			
		  }
		if(HIT_pwm_bf > HIT_UH_lim_wjw)
		{
			HIT_pwm_bf = HIT_UH_lim_wjw;
			
		  }
		if(HIT_pwm_cf < HIT_UL_lim_wjw)
		{
			HIT_pwm_cf = HIT_UL_lim_wjw;
			
		  }
		if(HIT_pwm_cf > HIT_UH_lim_wjw)
		{
			HIT_pwm_cf = HIT_UH_lim_wjw;
			
		  }
	}
#endif