#include"HIT_servo_on_first.h"
#include"iodefine.h"
extern int HIT_virtual_ps_int_err_int_int;
extern int HIT_position_fb_err_16_int;
extern int HIT_positionfir_fb_16_int;
extern unsigned short HIT_xi_d_count;
extern float HIT_xi_d_num_count;
extern float HIT_xi_d_w_num_count;
extern float HIT_id_out;
extern float HIT_xi_d_w_out;
extern float HIT_iq_org;
extern float HIT_id_org;
extern float HIT_M_12_pos_sum;
extern int HIT_M_12_count;
extern unsigned short HIT_new_angle_short;
extern float HIT_WLw_ref_mode_2;
void HIT_servo_on_first()
{
	HIT_pos_count = 0;								//ʹHIT_servo_onÿ�ν�ִ��1��
	HIT_position1_fb_16_int = (int)HIT_new_angle_short;//HIT_new_angle_int;	//λ�û��� ����ǰ�Ƕ�ֵ����λ�ò�ּ����ϸ�����ֵ
	HIT_positionfir_fb_16_int = (int)HIT_new_angle_short;//HIT_new_angle_int;
	HIT_sita1 = HIT_sita; 							//���ٶȻ��� �����ϸ������ٶ�ֵ 
	
	HIT_virtual_ps_int_sec = HIT_virtual_ps_int;	//λ�û��� �������ڼ�����ָ���ֵ��ϸ�����ֵ
	HIT_a_phase_sum = 0;							//λ�û��� ���ָ������ƶ�ƽ����
	HIT_pos_org_int = 0;							//λ�û��� ����������ŵ��������ֻ��ֺ�����
	HIT_pos_org_f = 0.0;							//λ�û��� ����������ŵ��������ֻ��ֺ�����	
	HIT_virtual_ps_int_err = 0;
	
	HIT_WLw_org = 0.0;								//�ٶȻ��� �ٶȻ���ֵ����
	HIT_wtwo=0.0;										//�ٶȻ��� �ٶ���һ����ֵ
	HIT_speedlpf=0.0;								//�ٶ��˲�����ڵ�һ���ŷ���������
	HIT_virtual_ps_int_err_sum_f = 0.0;
	for (HIT_filter_i=0;HIT_filter_i<16;HIT_filter_i++)
	{
		HIT_a_phase_filter[HIT_filter_i] = 0;
	}
	HIT_virtual_ps_int_err_int_int = 0;
	HIT_position_fb_err_16_int = 0;
	HIT_xi_d_count = 1;//��D��ģʽ8��D�ŷ������ĳ�ʼ�Ƕ�
	HIT_xi_d_num_count = 0;
	HIT_xi_d_w_num_count = 0;
	HIT_id_out = 0;
	HIT_xi_d_w_out = 0;
	
	/////////////////////////
	HIT_iq_org = 0;//add 20130606
	HIT_id_org = 0;
	//////////////////////////
	HIT_M_12_pos_sum = 0;
	HIT_M_12_count = 0;
	//////////////////////////
	HIT_WLw_ref_mode_2 = 0;
	
}