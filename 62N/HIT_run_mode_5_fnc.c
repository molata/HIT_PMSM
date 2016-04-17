extern unsigned char HIT_enable_mode_5;
extern float HIT_speed_con_time[];
extern unsigned short V_comm_i;
extern float HIT_speed_time[];
extern float HIT_speed_rond_num_f;
extern float HIT_speed_command_f;
extern float HIT_speed_command[];
extern float HIT_speed_rond_a;
extern unsigned short HIT_mode_5_i ;
extern float HIT_speed_command_ref;
extern float HIT_speed_command_ref_out;
extern unsigned short V_comm_i_max;
extern float HIT_WLw_ref;
void HIT_run_mode_5_fnc()
{
	if(HIT_enable_mode_5 == 1)
	{
		HIT_speed_con_time[V_comm_i] = HIT_speed_time[V_comm_i]*20;
		HIT_speed_rond_num_f = HIT_speed_con_time[V_comm_i];
		HIT_speed_command_f = HIT_speed_command[V_comm_i];
		if(V_comm_i == 0)
		{
			HIT_speed_rond_a = HIT_speed_command_f/HIT_speed_rond_num_f;	
		}
		else
		{
			HIT_speed_rond_a = (HIT_speed_command[V_comm_i] - HIT_speed_command[V_comm_i-1])/HIT_speed_rond_num_f;	
		}					
		if(HIT_mode_5_i<HIT_speed_rond_num_f)
		{
			
			HIT_speed_command_ref = HIT_speed_command_ref + HIT_speed_rond_a ;	
		}
		HIT_speed_command_ref_out = HIT_speed_command_ref;
		HIT_mode_5_i++;
		if(HIT_mode_5_i == HIT_speed_rond_num_f)
		{
			V_comm_i++;
			HIT_mode_5_i = 0;	
		}
	}
	if(V_comm_i == V_comm_i_max)
	{
		HIT_enable_mode_5 = 0;
		HIT_speed_command_ref_out = 0;	
	}	
	HIT_WLw_ref = HIT_speed_command_ref_out;
/*	if(V_comm_i == 2)
	{
		HIT_enable_mode_5 = 0;
		HIT_speed_command_ref_out = 0;	
	}*/
}