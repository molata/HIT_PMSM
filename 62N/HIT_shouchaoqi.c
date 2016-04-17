#include"HIT_shouchaoqi.h"
#include"iodefine.h"
#include<math.h>
#include<mathf.h>
#include "HIT_cmt0intfunc.h"
#include	<machine.h>
#include	<_h_c_lib.h>
#include	"typedefine.h"		// Define Types
#include	"stacksct.h"		// Stack Sizes (Interrupt and User)

#include "math.h"
#include "mathf.h"
unsigned char HIT_pwm_mode_choose = 0;
unsigned short HIT_servo_count = 0;
unsigned char HIT_en_tog_start_flag = 0;
char HIT_unable_send_enc = 0;
extern float HIT_alarm;
unsigned char HIT_sv_sta_i = 0;
unsigned char HIT_sv_sta_send_buff[8];
unsigned char HIT_sv_sta_send_count = 0;
unsigned char HIT_high_sv_sta ;
unsigned char HIT_low_sv_sta ;
signed int HIT_sv_sta_int;
char HIT_unable_send_sta = 0;
extern int HIT_virtual_ps_sig_int;
int HIT_xianshi = 0;
extern int HIT_new_angle_int;


unsigned char HIT_rec_adrr_i =0;
unsigned short HIT_rec_adrr_short_0;
unsigned short HIT_rec_adrr_short_1;
unsigned short HIT_rec_adrr_short_2;
unsigned short HIT_rec_adrr_short_3;
unsigned short HIT_rec_adrr_short;
unsigned int HIT_send_adrr_int;
unsigned char HIT_case1 = 0;
unsigned char HIT_case2 = 0;
unsigned char HIT_case3 = 0;
unsigned char HIT_case4 = 0;
//extern unsigned char HIT_rec_adrr_buff[8];

unsigned char HIT_iic_word_rec_1;
unsigned char HIT_iic_word_rec_2;
unsigned char HIT_iic_word_write[2] ;
extern union {
		unsigned char HIT_rec_adrr_buff_char;
		struct {
			unsigned char HIT_rec_data:4;//最低位
			unsigned char HIT_rec_state:1;//中间位
			unsigned char HIT_rec_serial:3;//最高位
		} BIT;
	} HIT_rec_adrr_buff[8];
union {
		unsigned char HIT_send_adrr_buff_char;
		struct {
			unsigned char HIT_send_data:4;//最低位
			unsigned char HIT_send_state:1;//中间位
			unsigned char HIT_send_serial:3;//最高位
		} BIT;
	} HIT_send_adrr_buff[8];
extern union {
		unsigned char HIT_rec_adrr_real_char;
		struct {
			unsigned char HIT_rec_adrr_real_data:4;//最低位
			unsigned char HIT_rec_adrr_real_state:1;//中间位
			unsigned char HIT_rec_adrr_real_serial:3;//最高位
		} BIT;
	} HIT_rec_adrr_real[8];
unsigned short HIT_start_address = 0;
unsigned char HIT_qwereqw = 0;
unsigned short HIT_change_num_num1;
unsigned short HIT_change_num_num2;
unsigned short HIT_change_num_num3;
unsigned short HIT_change_num_num4;
extern unsigned char HIT_ling_zhi;
void HIT_read_sci_adrress();
void Sci2ReFunc()
{
}
void Sci2TrFunc()
{
}
unsigned int HIT_123 = 0;
unsigned char HIT_ee_con_byte_0 = 0;
unsigned char HIT_ee_con_byte_1 = 0;
unsigned short HIT_change_num_1;
unsigned char HIT_ee_write_time = 1;
int HIT_jogon_count = 501;
extern float HIT_Umsensor_f; 
int psw_value;
char HIT_SERVO_PORT = 1;
extern unsigned char HIT_pwm_mode_choose ;
extern char HIT_ready_go;
extern float HIT_alarm;
extern float HIT_run_mode;
extern float HIT_WLw_ref;
extern float HIT_pos_org_f;
unsigned short HIT_baozha_num = 1;
extern int HIT_a_phase_sum;
extern int HIT_pos_org_int ;
extern float HIT_alarm;
unsigned char ucSCI5_send_datas[2] = {0x55, 0xaa};
void Sci5ReFunc()
{
}
void Sci5TrFunc()
{
}
void shoucaoqi_loop()
{
	//R_PG_SCI_StartSending_C5(ucSCI5_send_datas, 2);
	PORT1.DR.BIT.B1 = 1;
	psw_value = get_psw();//////////////////////////
	psw_value |= 0x00010000;
	set_psw(psw_value);

	
//	HIT_now_voltage_f_out = 37;//27.2;
	HIT_curren_aa_q_max_cmt0 = HIT_now_voltage_f_out/HIT_kv;//calculate the current_sum_lim  MAX
/* short current alarm */
	HIT_id_fb_square = HIT_id_fb*HIT_id_fb;
	HIT_iq_fb_square = HIT_iq_fb*HIT_iq_fb;
	HIT_idq_square = HIT_id_fb_square+HIT_iq_fb_square;
	
	if(HIT_idq_square > HIT_IDQ_SPE_SQUARE)
	{
		HIT_shortime_cur_count++;
		if(HIT_shortime_cur_count > 9)//serial 10ms match
		{
			//HIT_shortime_curr_alam
			HIT_shortime_cur_count = 0;	
		}	
	}
	else
	{
		HIT_shortime_cur_count = 0;		
	}
/* short current alarm end */ 
	HIT_positon_Kp_trans_f = HIT_positon_Kp_int_float;//(float)HIT_positon_Kp_int;//HIT_positon_Kp_int_float;//(float)HIT_positon_Kp_int;//transfer to trsmit parameter
	HIT_positon_Kp_trans_f = HIT_positon_Kp_trans_f * HIT_TWOPIE/HIT_POSITION_16WEI;
	HIT_positon_Kp_f = HIT_positon_Kp_trans_f;//transfer to real register
	
	HIT_shouchaoqi();
/////////////////////////////////////////////////////////////////////////
/*if((HIT_run_mode == 3)||(HIT_run_mode == 4))//((HIT_run_mode == 2)||(HIT_run_mode == 3))
{
	HIT_SERVO_PORT = PORT1.PORT.BIT.B0;
	if(HIT_SERVO_PORT == 0)
	{
		HIT_pwm_mode_choose = 1;	
	}
	if(HIT_pwm_mode_choose == 1)
	{
		HIT_ready_go = 1;	
	}
	if(HIT_SERVO_PORT == 1)
	{
		HIT_pwm_mode_choose = 2;	
	}
}*/
/////////////////////////////////////////////////////////////////////////
	if(HIT_alarm == 1)// 报警输出
	{
		PORT9.DR.BIT.B2 = 0;//ALM 	
	}
	if((HIT_ready_go == 0)||(HIT_alarm == 1))//伺服准备未完成
	{
		PORT9.DR.BIT.B1 = 1;//S_RDY	
	}
	if((HIT_ready_go == 1)&&(HIT_alarm == 0))//伺服准备完成
	{
		HIT_baozha_num++;
		if(HIT_baozha_num > 500)
		{
			PORT9.DR.BIT.B1 = 0;//S_RDY	
			HIT_baozha_num = 501;
		}
	}
//	if((HIT_WLw_ref == 0)&&((HIT_pos_org_f > -0.5)&&(HIT_pos_org_f < 0.5)))//&&(HIT_speedlpf == 0))
	if(((HIT_a_phase_sum <= 3)&&(HIT_a_phase_sum >= -3))&&((HIT_pos_org_int <= 200)&&(HIT_pos_org_int > -200)))//&&(HIT_speedlpf == 0))
	{
		PORT2.DR.BIT.B4 = 0;//CUIN
	}
	else
	{
		PORT2.DR.BIT.B4 = 1;//CUIN	
	}
/////////////////////////////////////////////////////////////////////////
	PORT1.DR.BIT.B1 = 0;


}   /**** shoucaoqi_loop stop here ****/

void HIT_shouchaoqi()
{
	
	R_PG_SCI_StartReceiving_C5(HIT_rec_adrr_buff,8);//接收数据

	SCI5.SSR.BIT.RDRF = 0;	
////////////////////////Jogsvon////////////////////	
	HIT_jogon_count++;
	if(HIT_jogon_count > 500)
	{
		HIT_jogon_count = 501;	
	}
////////////////////////Jogsvon////////////////////
	HIT_get_sci_buf_data();
	if((HIT_rec_adrr_real[0].BIT.HIT_rec_adrr_real_state == 0)&&(HIT_rec_adrr_real[1].BIT.HIT_rec_adrr_real_state == 0))
	{
		HIT_read_sci_address();//获取发来的地址
		if((HIT_rec_adrr_short>7000)&&(HIT_rec_adrr_short<7800))//Fn 7600
		{
			HIT_ee_con_byte_0 = 0xa2;
			HIT_ee_con_byte_1 = 0xa3;
			HIT_start_address = 7600;
			if((HIT_rec_adrr_short!= 7605)&&(HIT_rec_adrr_short!=7601)&&(HIT_rec_adrr_short!=7600)&&(HIT_rec_adrr_short!=7607)&&(HIT_rec_adrr_short!=7614))
			{
				HIT_Fn_read_ee_addr_fnc();//ee block1
			}
			
	/*		if(HIT_rec_adrr_short == 7602)
			
			{
				PORT7.DR.BIT.B0 = 0;
				
			  }*/
			switch(HIT_rec_adrr_short)
			{
				case 7605://参数初始化 Fn005
				HIT_par_write_to_ee();
				break;
				case 7602://伺服启动   Fn002
				HIT_shouchaoqi_con_servon();
				break;
				case 7607://写EE角度值  Fn007
				HIT_write_U_angle_to_EE();
				break;
				case 7601://读取角度值  Fn001
				HIT_iic_word_rec_short = HIT_new_angle_short;
				HIT_send_ee_data();
				break;
				case 7614://读取角度值  Fn00E
				HIT_iic_word_rec_short = HIT_Umsensor_f;
				HIT_send_ee_data();
				break;
				case 7600://读取状态值  Fn000
				HIT_read_servo_state();
				break;
				case 7610://读取脉冲值  Fn00A
				HIT_iic_word_rec_short = HIT_virtual_ps_sig_int;
//				HIT_send_ee_data();
				break;
			}
		}
		if((HIT_rec_adrr_short>7900)&&(HIT_rec_adrr_short<8600))//NN 8000
		{
			HIT_ee_con_byte_0 = 0xa6;
			HIT_ee_con_byte_1 = 0xa7;
			HIT_start_address = 8000;
			HIT_Fn_read_ee_addr_fnc();//ee block3	
		}
		if((HIT_rec_adrr_short>8700)&&(HIT_rec_adrr_short<9000))//Pn 8800
		{
			HIT_ee_con_byte_0 = 0xa0;
			HIT_ee_con_byte_1 = 0xa1;
			HIT_start_address = 8800;

			HIT_Fn_read_ee_addr_fnc();//ee block0
				
		}
		if((HIT_rec_adrr_short>9000)&&(HIT_rec_adrr_short<10000))/////////////////////////////////Un 9200
		{
			HIT_ee_con_byte_0 = 0xa4;
			HIT_ee_con_byte_1 = 0xa5;
			HIT_start_address = 9200;
			HIT_Fn_read_ee_addr_fnc();//ee block2	
		}
		if((HIT_rec_adrr_short != 7605)&&(HIT_rec_adrr_short!=7601)&&(HIT_rec_adrr_short!=7600)&&(HIT_rec_adrr_short!=7607)&&(HIT_rec_adrr_short!=7614))
		{
			HIT_send_ee_data();
		}
	}
	
	if((HIT_rec_adrr_real[0].BIT.HIT_rec_adrr_real_state == 1)&&(HIT_rec_adrr_real[1].BIT.HIT_rec_adrr_real_state == 1))
	{
		HIT_read_sci_address();//获取发来的数据
		HIT_change_num = HIT_rec_adrr_short;
		if(HIT_change_num != 0)
		{
						
			if(HIT_iic_write_choose == 32)
			{
				HIT_iic_write_choose = 1;	
			}	
			
			HIT_change_num_H = (HIT_change_num&0xff00)>>8;
			HIT_change_num_L = HIT_change_num&0x00ff;
			if(HIT_ling_zhi == 1)
			{
				HIT_change_num_H = 0x00;
				HIT_change_num_L = 0x00;	
				HIT_iic_word_write[1] = 0x00;
			}
				HIT_write_ee_addr();//写入EE地址内
			
		}
	}

}