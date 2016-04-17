#define HIT_WLw_ref_max 1361 //13000*HITtwopie/60             rad/s
#define HIT_fluxweak_start 1256 //12000*HITtwopie/60           rad/s
float HIT_fluxweak_f = 0.027;//-1A
extern float HIT_WLw_ref; //                                   rad/s
float HIT_id_ref_m;
extern float HIT_id_ref; 

void HIT_fluxwenkingcontrol()
{

   if((HIT_WLw_ref >=-HIT_fluxweak_start) &&(HIT_WLw_ref <= HIT_fluxweak_start) )
   {

    HIT_id_ref_m = 0;

    }
   else if((HIT_WLw_ref >= HIT_fluxweak_start) &&(HIT_WLw_ref <= HIT_WLw_ref_max))
   {
    HIT_id_ref_m = -(HIT_WLw_ref-HIT_fluxweak_start)*HIT_fluxweak_f;

    }

   else if((HIT_WLw_ref >= -HIT_WLw_ref_max )&& (HIT_WLw_ref <= -HIT_fluxweak_start ))
   {

   HIT_id_ref_m = (HIT_WLw_ref + HIT_fluxweak_start )*HIT_fluxweak_f;

    }
   else
   {

    HIT_id_ref_m = -(HIT_WLw_ref_max -HIT_fluxweak_start )*HIT_fluxweak_f;

    }
    HIT_id_ref = HIT_id_ref_m;
 
}