
extern float HIT_OBW_Err;
extern float HIT_OBW_w_OBW;
extern float HIT_OBW_D_OBW;
extern float HIT_OBW_u;
extern float HIT_OBW_sita_int_2;
extern float HIT_OBW_sita_OBW;
extern float HIT_OBW_sita_err;
extern float HIT_OBW_Err_before;
float HIT_OBW_sita_f_1 = 0;
float HIT_OBW_sita_f_err;
extern unsigned short HIT_new_angle_short;
extern float HIT_OBW_sita_f_2;
float HIT_OBW_sita_err_OBW = 0;
float HIT_OBW_sita_Err_OBW = 0;
extern float HIT_Ts;
float HIT_OBW_l1;
float HIT_OBW_l2;
float HIT_OBW_l3;
extern float HIT_Jm_OBW;
extern float HIT_iq_fb;
extern float HIT_WL_T_factor;
#define HIT_PIE 3.1415926
float HIT_WL_T_factor_OBW = 0.008;
unsigned short HIT_OBW_ini = 1;
extern float HIT_sitaerr;
#define HIT_TS_SQUARE_HALF 0.00000000125 // HIT_Ts*HIT_Ts/2
#define HIT_TS_CUBE_OXE 0.00000000000002083333333 // HIT_Ts*HIT_Ts*HIT_Ts/6
float HIT_OBW_Err_old3 = 0;
float HIT_OBW_Err_old2 = 0;
float HIT_OBW_Err_old1 = 0;
float HIT_OBW_Err_Time = 0;
//float HIT_OBW_Err_old3 = 0;
void HIT_OBW_state()
{
	
	HIT_OBW_u = HIT_iq_fb*HIT_WL_T_factor_OBW/HIT_Jm_OBW;
	
/*	HIT_OBW_sita_f_1 = (float)HIT_new_angle_short;
 	HIT_OBW_sita_f_err = HIT_OBW_sita_f_1 - HIT_OBW_sita_f_2;
	HIT_OBW_sita_f_2 = HIT_OBW_sita_f_1;
	
	if(HIT_OBW_ini == 1)
	{
		HIT_OBW_sita_f_err = 0;	
		HIT_OBW_ini = 0;
	}
	if(HIT_OBW_sita_f_err > 32768)
	{
		HIT_OBW_sita_f_err = HIT_OBW_sita_f_err - 65535;	
	}
		if(HIT_OBW_sita_f_err < -32768)
	{
		HIT_OBW_sita_f_err = HIT_OBW_sita_f_err + 65535;	
	}
	
	HIT_OBW_sita_f_err = HIT_OBW_sita_f_err/65535*2*HIT_PIE;
	
	HIT_OBW_sita_f_err = HIT_OBW_sita_f_err*20000;*/
//	HIT_OBW_sita_f_err = ;
	
	HIT_OBW_sita_err = HIT_sitaerr;//HIT_we;
	
//	HIT_OBW_Err_before = HIT_OBW_Err;
/*	HIT_OBW_Err_old3 = HIT_OBW_Err_old2;
	HIT_OBW_Err_old2 = HIT_OBW_Err_old1;
	HIT_OBW_Err_old1 = HIT_OBW_Err;
	
	HIT_OBW_Err_Time = HIT_OBW_Err_old1;*/



	HIT_OBW_Err = HIT_OBW_Err + HIT_OBW_sita_err - HIT_OBW_sita_Err_OBW;
		
	HIT_OBW_sita_Err_OBW = HIT_OBW_w_OBW*HIT_Ts + HIT_TS_SQUARE_HALF*HIT_OBW_D_OBW + HIT_TS_SQUARE_HALF*HIT_OBW_u + HIT_OBW_l1*HIT_Ts*HIT_OBW_Err;

	HIT_OBW_sita_Err_OBW = 	HIT_OBW_sita_Err_OBW +HIT_OBW_l2*HIT_TS_SQUARE_HALF*HIT_OBW_Err+HIT_OBW_l3*HIT_TS_CUBE_OXE*HIT_OBW_Err;

	HIT_OBW_w_OBW = HIT_OBW_w_OBW + HIT_OBW_D_OBW*HIT_Ts + HIT_OBW_u*HIT_Ts + HIT_OBW_l2*HIT_OBW_Err*HIT_Ts;
	HIT_OBW_w_OBW = HIT_OBW_w_OBW + HIT_OBW_l3*HIT_OBW_Err*HIT_TS_SQUARE_HALF;
	
	HIT_OBW_D_OBW = HIT_OBW_D_OBW + HIT_OBW_l3*HIT_OBW_Err*HIT_Ts;
	
	
	
}