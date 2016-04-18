float HIT_10_photo_Ts_num = 1;
float HIT_10_photo_Ts_k = 0.0;
int HIT_10_photo_count = 0;
extern float HIT_Ts;
extern float HIT_xi_d_w;
float HIT_10_photo_Ts_val = 0.0;
extern int HIT_10_photo_Ts_num_int;
float HIT_10_photo_Ts_val_DA = 0.0;
int HIT_mode_10_mag_sita_int_DA;
float HIT_10_err_val = 0.0;
extern int HIT_mode_10_mag_sita_int;
extern int HIT_run_mode_10_int;
int HIT_10_en_OK = 0;
int HIT_mode_10_mag_sita_int_1 = 0;
int HIT_mode_10_mag_sita_int_2 = 0;
int HIT_mode_10_mag_sita_int_err = 0;
extern int HIT_10_err_sample_ser;
extern int HIT_start_bd_int_num;
extern signed short HIT_err_10_i;
extern float HIT_mode_10_sita_err[];
int HIT_mode_10_check_en = 0;
int HIT_mode_10_fresh = 1;
float HIT_10_err_val_1 = 0;
float HIT_10_err_val_2 = 0;
float HIT_10_err_val_err = 0;
float HIT_10_err_val_DA = 0;
int HIT_mode_10_loop = 0;
int HIT_mode_10_high_10 = 0;
int HIT_mode_10_high_10_old = 1;
int HIT_ang_fir = 1;
int j = 0;
float A1_fil_group[32] ;
int HIT_k = 0;
float A1_fil_group_err[32];
float A1_fil_group_err_org = 0;
float A1_fil_group_err_org_mean = 0;
int A1_fil_group_err_org_mean_out = 0;
float HIT_10_fil_deep = 32;

#define HIT_PIE 3.1415926
void HIT_mode_10_bd()
{

		HIT_run_mode_10_int++;
		if((HIT_run_mode_10_int > 100000)&&((HIT_mode_10_mag_sita_int > 0)&&(HIT_mode_10_mag_sita_int < 5)))
		{
			HIT_10_en_OK = 1;//制表使能位	
		}
		if(HIT_10_en_OK == 1)//开始制表
		{
//////////////光电
			HIT_10_photo_Ts_val = HIT_10_photo_Ts_k*HIT_10_photo_count;
			HIT_10_photo_count++;
			
			
			
			HIT_mode_10_mag_sita_int_1 = HIT_mode_10_mag_sita_int;
			HIT_mode_10_mag_sita_int_err = HIT_mode_10_mag_sita_int_1 - HIT_mode_10_mag_sita_int_2;
			HIT_mode_10_mag_sita_int_2 = HIT_mode_10_mag_sita_int_1;
			if(HIT_mode_10_mag_sita_int_err < -60000)
			{
				HIT_10_photo_count = 0;		
			}
			
			
/*			if(HIT_10_photo_count == (int)HIT_10_photo_Ts_num)
			{
				HIT_10_photo_count = 0;	
			}*/
//////////////光电
//////////////差值制表			
			HIT_10_err_val = HIT_10_photo_Ts_val - (float)HIT_mode_10_mag_sita_int;
		
			HIT_10_err_val_1 = HIT_10_err_val;
			HIT_10_err_val_err = HIT_10_err_val_1 - HIT_10_err_val_2;
			
/*			if(HIT_10_err_val_err > 1000)
			{
				HIT_10_err_val = HIT_10_err_val_2;//0;//HIT_10_err_val - 65535;//HIT_10_err_val_2;//HIT_10_err_val_err - 65535;	
				HIT_10_err_val_1 = HIT_10_err_val;
			}
			if(HIT_10_err_val_err < -1000)
			{
				HIT_10_err_val = HIT_10_err_val_2;//0;//HIT_10_err_val + 65535;//HIT_10_err_val = 0;//HIT_10_err_val_2;//HIT_10_err_val_err + 65535;	
				HIT_10_err_val_1 = HIT_10_err_val;
			}*/
			HIT_10_err_val_2 = HIT_10_err_val_1;
//////////////差值制表
//////////////存表			
//			if((HIT_10_photo_count%HIT_10_err_sample_ser == 0))//词典角度归零 保存1024个点
//////////////////////角度滤波////////////////////////

	if (HIT_ang_fir == 1)
	{ 
        for (j=0;j<HIT_10_fil_deep;j++)
		{
            A1_fil_group[j] = HIT_mode_10_mag_sita_int;//A1(1);
		}
        HIT_ang_fir = 0; 
        j = 0;
		
	}
    if(HIT_ang_fir == 0)
	{
        A1_fil_group[j] = (float)HIT_mode_10_mag_sita_int;//A1(i);
        for (HIT_k=0;HIT_k<HIT_10_fil_deep;HIT_k++)
		{
            A1_fil_group_err[HIT_k] = A1_fil_group[HIT_k] - A1_fil_group[j];
            if (A1_fil_group_err[HIT_k] > 60000)
			{
                A1_fil_group_err[HIT_k] = A1_fil_group_err[HIT_k] - 65535;
			}
            if (A1_fil_group_err[HIT_k] < -60000)
			{
                A1_fil_group_err[HIT_k] = A1_fil_group_err[HIT_k] + 65535;
			}
            A1_fil_group_err_org = A1_fil_group_err[HIT_k] + A1_fil_group_err_org;
            if (HIT_k == HIT_10_fil_deep - 1)
			{
                A1_fil_group_err_org_mean = A1_fil_group_err_org/HIT_10_fil_deep;
                A1_fil_group_err_org = 0;
			}
	
		}
        A1_fil_group_err_org_mean_out = A1_fil_group[j] + A1_fil_group_err_org_mean;
        j = j+1;
        if(j == HIT_10_fil_deep)//HIT_10_fil_deep
		{
            j=0;
		}
	}


//////////////////////角度滤波////////////////////////
			HIT_mode_10_high_10 = A1_fil_group_err_org_mean_out&0x0000ffc0;//HIT_mode_10_mag_sita_int&0x0000ffc0;// high 10wei
			HIT_mode_10_high_10 = HIT_mode_10_high_10>>6;
			if(HIT_mode_10_high_10 != HIT_mode_10_high_10_old)
			{
				if(HIT_mode_10_fresh == 1)//保存1024个点值使能位
				{
				//	if(HIT_mode_10_high_10 != HIT_mode_10_high_10_old)
					{
						HIT_mode_10_sita_err[HIT_err_10_i] = HIT_10_err_val;//HIT_mode_10_err_ser;//HIT_mode_10_sita - HIT_mode_10_enc_mag;//HIT_mode_10_enc_mag;//HIT_mode_10_sita ;//- HIT_new_angle_f;//HIT_mode_10_enc_mag;//- HIT_mode_10_enc_mag_fir - HIT_mode_10_sita;
					//	HIT_err_10_i++;
						if(HIT_err_10_i == 1023)
						{
							HIT_mode_10_check_en = 1;//查表使能位
							HIT_mode_10_fresh = 0;	
						}
					}
					
				}
				
				HIT_err_10_i++;
				if(HIT_err_10_i == 1024)
				{
					HIT_err_10_i = 0;	
				}
			
			}
			HIT_mode_10_high_10_old = HIT_mode_10_high_10;
	/*		if((HIT_10_photo_count%HIT_10_err_sample_ser == 0))//词典角度归零 保存1024个点
			{
				if(HIT_mode_10_fresh == 1)//保存1024个点值使能位
				{
					HIT_mode_10_sita_err[HIT_err_10_i] = HIT_mode_10_sita_err[HIT_err_10_i] + HIT_10_err_val;//HIT_mode_10_err_ser;//HIT_mode_10_sita - HIT_mode_10_enc_mag;//HIT_mode_10_enc_mag;//HIT_mode_10_sita ;//- HIT_new_angle_f;//HIT_mode_10_enc_mag;//- HIT_mode_10_enc_mag_fir - HIT_mode_10_sita;
					HIT_err_10_i++;
					if(HIT_err_10_i == 1024)
					{
					//	HIT_mode_10_check_en = 1;//查表使能位
					//	HIT_mode_10_fresh = 0;	
						HIT_err_10_i = 0;
						if(HIT_mode_10_loop == 10)
						{
							HIT_mode_10_fresh = 0;	
						}
						HIT_mode_10_loop++;
					}
					
				}
				if(HIT_mode_10_fresh == 0)
				{
					HIT_mode_10_sita_err[HIT_err_10_i] = HIT_mode_10_sita_err[HIT_err_10_i]/10;
					HIT_err_10_i++;	
					HIT_mode_10_fresh = 2;
					HIT_mode_10_check_en = 1;//查表使能位
				}
			}*/
//////////////存表	
		}
	
		
		HIT_10_photo_Ts_val_DA = HIT_10_photo_Ts_val/2;
		HIT_mode_10_mag_sita_int_DA = HIT_mode_10_mag_sita_int/2;
		
}