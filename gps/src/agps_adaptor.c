#if defined(__GPS_SUPPORT__)
#ifdef __GPS_ADAPTOR_SUPPORT__
#ifdef __AGPS_SUPPORT__


#include "agps_adaptor.h"
#include "gps_adaptor.h"


gpsadaptor_agps_manager_context_struct g_gpsadaptor_agps_ctx;
extern gps_uart_context_struct g_gps_cntx;
extern epodownload_function_struct epodownload_function;

#ifdef __IOT_CUSTOMIZE__
char     *g_cust_ssl_peer_cn = NULL;
char     supl_ca_cer[] = "";

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

void gpsadaptor_agps_get_qop_setting(gpsadaptor_agps_qop_struct *agps_qop_setting)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	agps_qop_setting->horacc= 18;
    agps_qop_setting->veracc_used= 0;
    agps_qop_setting->veracc= 18;
    agps_qop_setting->maxLocAge_used= 0;
    agps_qop_setting->maxLocAge= 60;
    agps_qop_setting->delay_used= 0;
    agps_qop_setting->delay= 6;
	
}


kal_uint32 gpsadaptor_agps_setting_get_data_account(gpsadaptor_agps_setting_prefer_sim_enum sim){
	return 0;
}
void gpsadaptor_agps_setting_get_profile_interface(gpsadaptor_agps_profile_struct* agps_profile){

	nvram_ef_agps_profile_struct profile;

	memset(agps_profile, 0 , sizeof(*agps_profile));
	
    #ifdef __IOT_CUSTOMIZE__
	if (agps_adaptor_get_supl_name_lens() >0)
    {
	    agps_adaptor_get_supl_name(agps_profile->addr);
        agps_profile->port = agps_adaptor_get_supl_port();
    }
    else
    {
        gpsadaptor_agps_setting_get_profile(&profile);
    	app_ucs2_str_to_asc_str((kal_int8*)agps_profile->addr, (kal_int8*)profile.addr);
    	app_ucs2_str_to_asc_str((kal_int8*)agps_profile->name, (kal_int8*)profile.name);
    	agps_profile->port = profile.port;
    }
    #else
    gpsadaptor_agps_setting_get_profile(&profile);
	app_ucs2_str_to_asc_str((kal_int8*)agps_profile->addr, (kal_int8*)profile.addr);
	app_ucs2_str_to_asc_str((kal_int8*)agps_profile->name, (kal_int8*)profile.name);
	agps_profile->port = profile.port;
	#endif

	
    kal_prompt_trace(MOD_GPSADAPTOR,"[AGPS_ADAPTOR] SUPL addr=%s, name=%s, port=%d\n", agps_profile->addr, agps_profile->name, agps_profile->port);
	return;
}
gpsadaptor_agps_setting_prefer_sim_enum gpsadaptor_agps_setting_get_sim_interface(void){
	return 0;
}
void gpsadaptor_agps_setting_get_up_setting_interface(gpsadaptor_agps_up_setting_struct* agps_up_setting){
	nvram_em_minigps_up_setting_struct setting;
	#ifdef __IOT_CUSTOMIZE__
	if (agps_adaptor_get_supl_name_lens() > 0)
	{
        gpsadaptor_agps_supl_setting(&setting);
	}
	else
	#endif
	{
	gpsadaptor_agps_setting_get_up_setting(&setting);
	}
	agps_up_setting->payload = setting.payload;
	agps_up_setting->use_tls = setting.use_tls;
	agps_up_setting->ut_timer = setting.ut_timer;
	agps_up_setting->molr_prefer = setting.molr_prefer;
	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_GET_AGPS_UP_SETTING,
					agps_up_setting->payload,
					agps_up_setting->molr_prefer,
					agps_up_setting->use_tls,
					agps_up_setting->ut_timer));
	g_gpsadaptor_agps_ctx.work_mode = setting.molr_prefer;
	return;
}
kal_bool gpsadaptor_agps_setting_get_is_agps_on_interface(void){
	g_gpsadaptor_agps_ctx.agps_on_off = gpsadaptor_agps_setting_get_is_agps_on();
	//kal_prompt_trace(MOD_GPSADAPTOR, "agps is %d\n", g_gpsadaptor_agps_ctx.agps_on_off);
	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_GET_AGPS_ONOFF,
					g_gpsadaptor_agps_ctx.agps_on_off));
	return g_gpsadaptor_agps_ctx.agps_on_off;
}



static void gpsadaptor_agps_set_state(gpsadaptor_agps_state_enum state)
{
	// add log : pre state-> current state
	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_SET_STATE,
					g_gpsadaptor_agps_ctx.state,
					state));
	g_gpsadaptor_agps_ctx.state = state;
}

static kal_bool gpsadaptor_agps_check_state_right(void)
{
	if(g_gpsadaptor_agps_ctx.agps_on_off == KAL_FALSE ||
		g_gpsadaptor_agps_ctx.state == GPSADAPTOR_AGPS_STATE_TERMINATE ||
		g_gpsadaptor_agps_ctx.state == GPSADAPTOR_AGPS_STATE_ABORT){
		GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_STATE_MACHINE_WRONG,
			g_gpsadaptor_agps_ctx.state));
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}


void gpsadaptor_agps_register_p_callback(void (*gps_uart_p_callback)(gpsadaptor_gps_parser_p_info_enum type))
{
    g_gpsadaptor_agps_ctx.gps_uart_p_callback = gps_uart_p_callback;
}
static void gpsadaptor_agps_send_cmd_req(gps_common_uart_cmd_type_enum cmd)
{
	gps_uart_write_req_struct	*local_param_ptr;
	kal_uint32 adatpor_return_val=0; 

	if(gpsadaptor_agps_check_state_right() == KAL_FALSE){
		return;
	}
	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_SEND_CMD,cmd));
	local_param_ptr = construct_local_para(sizeof(gps_uart_write_req_struct),TD_CTRL);
	
	if(local_param_ptr == NULL){
		return;
	}
	local_param_ptr->port = GPS_Get_UART_Port();
	local_param_ptr->is_rawdata=KAL_FALSE;
    local_param_ptr->cmd=cmd;
	
	local_param_ptr->return_val = &adatpor_return_val;
	local_param_ptr->module_id = MOD_GPSADAPTOR;
	local_param_ptr->event_id = NULL ;
	send_msg_to_gps_task(MOD_GPSADAPTOR,MOD_GPS,MSG_ID_GPS_UART_WRITE_REQ,local_param_ptr,
                        sizeof(gps_uart_write_req_struct));
}



static kal_bool gpsadaptor_agps_get_history_pos(gpsadaptor_agps_qop_struct *qop,
                                        supl_mmi_position_struct *pos,
                                        supl_mmi_req_assist_data_struct *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_pos_qop_struct gps_qop;
    gps_pos_result_struct gps_history_pos;
    kal_uint16 gps_bitmap;
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_qop.semi_maj_uncertain = qop->horacc;
    gps_qop.semi_min_uncertain = qop->horacc;
    gps_qop.altitude_uncertain_valid = qop->veracc_used;
    gps_qop.altitude_uncertain = qop->veracc;
    gps_qop.delay_valid = qop->delay_used;
    gps_qop.delay = qop->delay;
    gps_qop.age_valid = qop->maxLocAge_used;
    gps_qop.age = qop->maxLocAge;

    memset(&gps_history_pos, 0, sizeof(gps_pos_result_struct));
    ret = gps_agps_get_history_pos(&gps_qop, &gps_history_pos, &gps_bitmap);

    pos->time_stamp = gps_history_pos.tow;
    pos->week       = gps_history_pos.week;

    if (gps_history_pos.pos_estimate.sign_latitude == KAL_FALSE)
    {
        pos->pos_estimate.latitude_sign = SUPL_MMI_SIGN_NORTH;
    }
    else
    {
        pos->pos_estimate.latitude_sign = SUPL_MMI_SIGN_SOUTH;
    }
    pos->pos_estimate.latitude = gps_history_pos.pos_estimate.latitude;
    pos->pos_estimate.longtude = gps_history_pos.pos_estimate.longtitude;
    pos->pos_estimate.uncertainty_used = KAL_TRUE;
    pos->pos_estimate.uncertainty.major_axis = gps_history_pos.pos_estimate.unc_bear;
    pos->pos_estimate.uncertainty.semi_major = gps_history_pos.pos_estimate.unc_major;
    pos->pos_estimate.uncertainty.semi_minor = gps_history_pos.pos_estimate.unc_minor;
    pos->pos_estimate.confidence_used = KAL_TRUE;
    pos->pos_estimate.confidence = gps_history_pos.pos_estimate.confidence;
    pos->pos_estimate.altitude_info_used = KAL_TRUE;
    pos->pos_estimate.altitude_info.altitude = gps_history_pos.pos_estimate.altitude;
    if (gps_history_pos.pos_estimate.sign_altitude == KAL_FALSE)
    {
        pos->pos_estimate.altitude_info.direction = SUPL_MMI_DIRECTION_HEIGHT;
    }
    else
    {
        pos->pos_estimate.altitude_info.direction = SUPL_MMI_DIRECTION_DEPTH;
    }
    pos->pos_estimate.altitude_info.uncertainty = gps_history_pos.pos_estimate.unc_altitude;

    pos->velocity_used = KAL_TRUE;

    /* reset flags if not valid */
    if (ret == KAL_FALSE)
    {
        pos->pos_estimate.uncertainty_used = KAL_FALSE;
        pos->pos_estimate.confidence_used = KAL_FALSE;
        pos->pos_estimate.altitude_info_used = KAL_FALSE;
        pos->velocity_used = KAL_FALSE;
    }

    switch (gps_history_pos.pos_estimate.velocity.type)
    {
        case GPS_VELOCITY_HOR:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR;
            if (gps_history_pos.pos_estimate.velocity.v.hor_velocity.hor_speed == 0 &&
                gps_history_pos.pos_estimate.bearing == 0)
            {
                pos->velocity_used = KAL_FALSE;
            }
            else
            {
                pos->velocity.v.hor_velocity.bearing.data[0] = gps_history_pos.pos_estimate.bearing & 0xff;
                pos->velocity.v.hor_velocity.bearing.data[1] = gps_history_pos.pos_estimate.bearing >> 8;
                pos->velocity.v.hor_velocity.bearing.num_bits = 2;
                pos->velocity.v.hor_velocity.hor_speed.data[0] = gps_history_pos.pos_estimate.velocity.v.hor_velocity.hor_speed & 0xff;
                pos->velocity.v.hor_velocity.hor_speed.data[1] = gps_history_pos.pos_estimate.velocity.v.hor_velocity.hor_speed >> 8;
                pos->velocity.v.hor_velocity.hor_speed.num_bits = 2;
            }
            break;
        case GPS_VELOCITY_HOR_AND_VER:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR_AND_VER;
            /*pos->velocity.v.hor_uncertainty.bearing.data
            pos->velocity.v.hor_uncertainty.bearing.num_bits
            pos->velocity.v.hor_uncertainty.hor_speed.data
            pos->velocity.v.hor_uncertainty.hor_speed.num_bits
            pos->velocity.v.hor_uncertainty.hor_speed_uncertainty.data
            pos->velocity.v.hor_uncertainty.hor_speed_uncertainty.num_bits*/
            pos->velocity_used = KAL_FALSE;
            break;
        case GPS_VELOCITY_HOR_UNCERT:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR_UNCERT;
            /*pos->velocity.v.hv_velocity.bearing.data =
            pos->velocity.v.hv_velocity.bearing.num_bits =
            pos->velocity.v.hv_velocity.hor_speed.data
            pos->velocity.v.hv_velocity.hor_speed.num_bits*/
            pos->velocity_used = KAL_FALSE;
            break;
        case GPS_VELOCITY_HOR_AND_VER_UNCERT:
            pos->velocity.type = SUPL_MMI_VELOCITY_HOR_AND_VER_UNCERT;
            /*pos->velocity.v.hv_uncertainty.bearing.data
            pos->velocity.v.hv_uncertainty.bearing.num_bits =
            pos->velocity.v.hv_uncertainty.hor_speed.data
            pos->velocity.v.hv_uncertainty.hor_speed.num_bits
            pos->velocity.v.hv_uncertainty.hor_speed_uncertainty.data
            pos->velocity.v.hv_uncertainty.hor_speed_uncertainty.num_bits
            pos->velocity.v.hv_uncertainty.ver_direction.data
            pos->velocity.v.hv_uncertainty.ver_direction.num_bits
            pos->velocity.v.hv_uncertainty.ver_speed.data
            pos->velocity.v.hv_uncertainty.ver_speed.num_bits
            pos->velocity.v.hv_uncertainty.ver_speed_uncertainty.data
            pos->velocity.v.hv_uncertainty.ver_speed_uncertainty.num_bits*/
            pos->velocity_used = KAL_FALSE;
            break;
        default:
            pos->velocity_used = KAL_FALSE;
            break;
    }

    filter->almanac =            (gps_bitmap & GPS_ASSIST_MASK_ALMANAC)?KAL_TRUE:KAL_FALSE;
    filter->utc_model =          (gps_bitmap & GPS_ASSIST_MASK_UTC)?KAL_TRUE:KAL_FALSE;
    filter->ionospheric_model =  (gps_bitmap & GPS_ASSIST_MASK_IONOSPHERE)?KAL_TRUE:KAL_FALSE;
    filter->dgps_correction =    (gps_bitmap & GPS_ASSIST_MASK_DGPS_CORRECTION)?KAL_TRUE:KAL_FALSE;
    filter->ref_location =       (gps_bitmap & GPS_ASSIST_MASK_REF_LOCATION)?KAL_TRUE:KAL_FALSE;
    filter->ref_time =           (gps_bitmap & GPS_ASSIST_MASK_REF_TIME)?KAL_TRUE:KAL_FALSE;
    filter->acquisition_assist = (gps_bitmap & GPS_ASSIST_MASK_ACQUISITION)?KAL_TRUE:KAL_FALSE;
    filter->realtime_integrity = (gps_bitmap & GPS_ASSIST_MASK_RTI)?KAL_TRUE:KAL_FALSE;
    filter->navigation_model =   (gps_bitmap & GPS_ASSIST_MASK_NAVIGATION_MODEL)?KAL_TRUE:KAL_FALSE;
    /*filter->nav_model_data*/

    return ret;
}
static void gpsadaptor_agps_set_pos(supl_mmi_position_struct *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gpsadaptor_agps_set_pos_struct gps_pos;
	gps_agps_set_pos_struct new_pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_pos.gps_week    = pos->week;
    gps_pos.tow         = pos->time_stamp;
    gps_pos.latitude = pos->pos_estimate.latitude;
    if (pos->pos_estimate.latitude_sign == SUPL_MMI_SIGN_NORTH)
    {
        gps_pos.sign_latitude = KAL_FALSE;
    }
    else
    {
        gps_pos.sign_latitude = KAL_TRUE;
    }

    gps_pos.longtitude = pos->pos_estimate.longtude;
    if (pos->pos_estimate.altitude_info_used)
    {
        if (pos->pos_estimate.altitude_info.direction == SUPL_MMI_DIRECTION_HEIGHT)
        {
            gps_pos.sign_altitude = KAL_FALSE;
        }
        else
        {
            gps_pos.sign_altitude = KAL_TRUE;
        }
        gps_pos.altitude = pos->pos_estimate.altitude_info.altitude;
        gps_pos.unc_vert = pos->pos_estimate.altitude_info.uncertainty;
    }
    else
    {
        gps_pos.sign_altitude = KAL_FALSE;
        gps_pos.altitude = 0;
        gps_pos.unc_vert = 0;
    }
    if (pos->pos_estimate.uncertainty_used)
    {
        gps_pos.unc_major = pos->pos_estimate.uncertainty.semi_major;
        gps_pos.unc_minor = pos->pos_estimate.uncertainty.semi_minor;
        gps_pos.unc_bear = pos->pos_estimate.uncertainty.major_axis;
    }
    else
    {
        gps_pos.unc_major = 0;
        gps_pos.unc_minor = 0;
        gps_pos.unc_bear = 0;
    }
    if (pos->pos_estimate.confidence_used)
    {
        gps_pos.confidence = pos->pos_estimate.confidence;
    }
    else
    {
        gps_pos.confidence = 0;
    }
    if (pos->velocity_used)
    {
        switch (pos->velocity.type)
        {
            case SUPL_MMI_VELOCITY_HOR:
                if (pos->velocity.v.hor_velocity.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hor_velocity.hor_speed.data[0];
                }
                else if (pos->velocity.v.hor_velocity.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hor_velocity.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hor_velocity.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }
                gps_pos.bearing = 0;
                break;
            case SUPL_MMI_VELOCITY_HOR_AND_VER:
                if (pos->velocity.v.hv_velocity.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hv_velocity.hor_speed.data[0];
                }
                else if (pos->velocity.v.hv_velocity.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hv_velocity.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hv_velocity.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }

                if (pos->velocity.v.hv_velocity.ver_direction.num_bits == 1)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_velocity.ver_direction.data[0];
                }
                else if (pos->velocity.v.hv_velocity.ver_direction.num_bits == 2)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_velocity.ver_direction.data[0];
                }
                else
                {
                    gps_pos.bearing = 0;
                }
                break;
            case SUPL_MMI_VELOCITY_HOR_UNCERT:
                if (pos->velocity.v.hor_uncertainty.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hor_uncertainty.hor_speed.data[0];
                }
                else if (pos->velocity.v.hor_uncertainty.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hor_uncertainty.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hor_uncertainty.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }
                gps_pos.bearing = 0;
                break;
            case SUPL_MMI_VELOCITY_HOR_AND_VER_UNCERT:
                if (pos->velocity.v.hv_uncertainty.hor_speed.num_bits == 1)
                {
                    gps_pos.h_speed = (U32)pos->velocity.v.hv_uncertainty.hor_speed.data[0];
                }
                else if (pos->velocity.v.hv_uncertainty.hor_speed.num_bits == 2)
                {
                    gps_pos.h_speed = (U32)((pos->velocity.v.hv_uncertainty.hor_speed.data[1] << 8) +
                                             pos->velocity.v.hv_uncertainty.hor_speed.data[0]);
                }
                else
                {
                    gps_pos.h_speed = 0;
                }

                if (pos->velocity.v.hv_uncertainty.ver_direction.num_bits == 1)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_uncertainty.ver_direction.data[0];
                }
                else if (pos->velocity.v.hv_uncertainty.ver_direction.num_bits == 2)
                {
                    gps_pos.bearing = (U16)pos->velocity.v.hv_uncertainty.ver_direction.data[0];
                }
                else
                {
                    gps_pos.bearing = 0;
                }
                break;
        }
    }
    else
    {
        gps_pos.h_speed = 0;
        gps_pos.bearing = 0;
    }
	new_pos.latitude      =gps_pos.latitude;     
    new_pos.sign_latitude =gps_pos.sign_latitude;
    new_pos.longtitude    =gps_pos.longtitude;   
    new_pos.sign_altitude =gps_pos.sign_altitude;
    new_pos.altitude      =gps_pos.altitude;     
    new_pos.unc_major     =gps_pos.unc_major;    
    new_pos.unc_minor     =gps_pos.unc_minor;    
    new_pos.unc_bear      =gps_pos.unc_bear;     
    new_pos.unc_vert      =gps_pos.unc_vert;     
    new_pos.confidence    =gps_pos.confidence;   
    new_pos.h_speed       =gps_pos.h_speed;      
    new_pos.bearing       =gps_pos.bearing;      
    new_pos.gps_week      =gps_pos.gps_week;      
    new_pos.tow           =gps_pos.tow;      
    gps_agps_set_history_pos(&new_pos);
}

static gpsadaptor_agps_result_enum gpsadaptor_agps_send_start_supl_req(kal_bool force_default_slp)
{
    supl_mmi_start_req_struct *local_param_ptr = NULL;
    kal_bool plmn_ret;
    kal_int8 PLMNNum[GPSADAPTOR_AGPS_MAX_PLMN_LEN];
    gpsadaptor_agps_profile_struct agps_profile;
    ilm_struct *ilm_ptr = NULL;
    gpsadaptor_agps_up_setting_struct agps_up_setting;
    supl_mmi_position_struct pos;
    supl_mmi_req_assist_data_struct filter;

	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_SEND_START_REQ));
	if(gpsadaptor_agps_check_state_right() == KAL_FALSE){
		return GPSADAPTOR_AGPS_STATE_MACHINE_WRONG;
	}
    local_param_ptr = (supl_mmi_start_req_struct*)construct_local_para(sizeof(supl_mmi_start_req_struct), TD_CTRL);
	if(local_param_ptr == NULL){
		GPSADAPTOR_TRACE((TRACE_GROUP_2,GPSADAPOOR_AGPS_ALLOC_FAILURE));
		return GPSADAPTOR_AGPS_ALLOC_MEMORY_FAILURE;
	}
	#ifndef __IOT_CUSTOMIZE__ 
	gpsadaptor_agps_setting_get_up_setting_interface(&agps_up_setting);
	#endif
	if (g_gpsadaptor_agps_ctx.work_mode == GPSADAPTOR_AGPS_WORK_MODE_MA)
    {
        local_param_ptr->pos_method = SUPL_MMI_POS_METHOD_SET_ASSIST;
    }
    else
    {
        local_param_ptr->pos_method = SUPL_MMI_POS_METHOD_SET_BASE;
    }
    gpsadaptor_agps_get_history_pos(&g_gpsadaptor_agps_ctx.qop, &pos, &filter);
    memcpy(&local_param_ptr->qop, &g_gpsadaptor_agps_ctx.qop, sizeof(supl_mmi_qop_struct));
    //data_account = gpsadaptor_agps_setting_get_data_account(g_gpsadaptor_agps_ctx.sim);
    gpsadaptor_agps_setting_get_profile_interface(&agps_profile);
    local_param_ptr->nwk_account_id = g_gpsadaptor_agps_ctx.data_account;
    if (local_param_ptr->nwk_account_id == 0xffffffff)
    {
    	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_NO_NETWORK));
        free_local_para((local_para_struct*) local_param_ptr);
        return GPSADAPTOR_AGPS_NETWORK_ACCOUNT_FAILURE;
    }
    switch (g_gpsadaptor_agps_ctx.sim)
    {
    case GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO1:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM1;
        break;
    case GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO2:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM2;
        break;
    case GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO3:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM3;
        break;
    case GPSADAPTOR_AGPS_SETTING_PREFER_SIM_NO4:
        local_param_ptr->sim_id = SUPL_SIM_ID_SIM4;
        break;
    default:
        ASSERT(0);
    }
    
#ifndef __IOT_CUSTOMIZE__
    memcpy(&local_param_ptr->filter, &filter, sizeof(supl_mmi_req_assist_data_struct));
#else
    memset(&local_param_ptr->filter, 0, sizeof(supl_mmi_req_assist_data_struct));
#endif

#ifndef __IOT_CUSTOMIZE__
    local_param_ptr->filter.almanac = KAL_TRUE;
    local_param_ptr->filter.utc_model= KAL_TRUE;
    local_param_ptr->filter.ionospheric_model= KAL_TRUE;
    local_param_ptr->filter.dgps_correction= KAL_TRUE;
    local_param_ptr->filter.ref_location= KAL_TRUE;
    local_param_ptr->filter.ref_time = KAL_TRUE;
    local_param_ptr->filter.acquisition_assist= KAL_TRUE;
    local_param_ptr->filter.realtime_integrity= KAL_TRUE;
    local_param_ptr->filter.navigation_model= KAL_TRUE;
#else
    local_param_ptr->filter.almanac = KAL_FALSE;
    local_param_ptr->filter.utc_model= KAL_FALSE;
    local_param_ptr->filter.ionospheric_model= KAL_FALSE;
    local_param_ptr->filter.dgps_correction= KAL_FALSE;
    local_param_ptr->filter.ref_location= KAL_TRUE;
    local_param_ptr->filter.ref_time = KAL_FALSE;
    local_param_ptr->filter.acquisition_assist= KAL_FALSE;
    local_param_ptr->filter.realtime_integrity= KAL_FALSE;
    local_param_ptr->filter.navigation_model= KAL_FALSE;
 #endif

	#ifndef __IOT_CUSTOMIZE__
 	memcpy(local_param_ptr->slp_addr, agps_profile.addr,sizeof(agps_profile.addr));
 	#else
 	strcpy(local_param_ptr->slp_addr,agps_profile.addr);
 	#endif
    local_param_ptr->slp_port = (kal_uint16)agps_profile.port;

#ifndef __IOT_CUSTOMIZE__
	if(local_param_ptr->slp_addr[0] == '0' ||
		   force_default_slp == KAL_TRUE)
	{
			memset(local_param_ptr->slp_addr, 0, SUPL_MMI_MAX_ADDR_LEN);
			plmn_ret = srv_sim_ctrl_get_home_plmn((gpsadaptor_agps_sim_enum)(local_param_ptr->sim_id + 1),
				PLMNNum,
				GPSADAPTOR_AGPS_MAX_PLMN_LEN);
			if(plmn_ret == KAL_FALSE)
			{
				GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_GET_PLMN_FAIL));
				free_local_para((local_para_struct*) local_param_ptr);
	
				return GPSADAPTOR_AGPS_GET_MCCMNC;
			}
			kal_sprintf((local_param_ptr->slp_addr),
						 "h-slp.mnc0%c%c.mcc%c%c%c.pub.3gppnetwork.org",
						 PLMNNum[3],
						 PLMNNum[4],
						 PLMNNum[0],
						 PLMNNum[1],
						 PLMNNum[2]);
			GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_GET_MCCMNC,
					local_param_ptr->slp_addr));
			local_param_ptr->slp_port = 7275;
			g_gpsadaptor_agps_ctx.need_retry=KAL_FALSE;
			g_gpsadaptor_agps_ctx.is_retrying=KAL_TRUE;
	}
#endif	
    /* read setttings from NVRAM */
    gpsadaptor_agps_setting_get_up_setting_interface(&agps_up_setting);
    local_param_ptr->use_tls = agps_up_setting.use_tls;
    local_param_ptr->ut_timer_value = agps_up_setting.ut_timer;
    switch (agps_up_setting.payload)
    {
    case GPSADAPTOR_AGPS_UP_PAYLOAD_BOTH:
        local_param_ptr->payload_capability = SUPL_USE_RRC | SUPL_USE_RRLP;
        break;
    case GPSADAPTOR_AGPS_UP_PAYLOAD_RRLP:
        local_param_ptr->payload_capability = SUPL_USE_RRLP;
        break;
    case GPSADAPTOR_AGPS_UP_PAYLOAD_RRC:
        local_param_ptr->payload_capability = SUPL_USE_RRC;
        break;
    default:
        local_param_ptr->payload_capability = SUPL_USE_RRC | SUPL_USE_RRLP;
        break;
    }
    kal_prompt_trace(MOD_GPSADAPTOR,"[AGPS_ADAPTOR] SUPL addr=%s, port=%d, tls_use=%d\n", local_param_ptr->slp_addr, local_param_ptr->slp_port,local_param_ptr->use_tls);

    local_param_ptr->req_id = g_gpsadaptor_agps_ctx.req_id;
    ilm_ptr = allocate_ilm(MOD_GPSADAPTOR);
    ilm_ptr->src_mod_id = MOD_GPSADAPTOR;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_START_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
	//kal_prompt_trace(MOD_GPSADAPTOR, "[AGPS_ADAPTOR]:3\n");
    msg_send_ext_queue(ilm_ptr);

	gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_WORKING);
    return GPSADAPTOR_AGPS_RESULT_SUCCESS;
}

static void gpsadaptor_agps_send_abort_error_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_rsp_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    gpsadaptor_agps_profile_struct agps_profile;
    U32 data_account;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_SEND_ERR_RESPONSE));

	if(gpsadaptor_agps_check_state_right() == KAL_FALSE){
		return ;
	}
    local_param_ptr = (supl_mmi_status_rsp_struct*)construct_local_para(sizeof(supl_mmi_status_rsp_struct), TD_CTRL);
	if(local_param_ptr == NULL){
		GPSADAPTOR_TRACE((TRACE_GROUP_2,GPSADAPOOR_AGPS_ALLOC_FAILURE));
		return;
	}
    local_param_ptr->req_id = g_gpsadaptor_agps_ctx.req_id;
    local_param_ptr->obj_valid = 0;
    local_param_ptr->notify_rsp.result = SUPL_MMI_RESULT_ERROR;
    SUPL_MMI_USE_NOTIFY_RSP(local_param_ptr->obj_valid);

    //data_account = gpsadaptor_agps_setting_get_data_account(g_gpsadaptor_agps_ctx.sim);
    gpsadaptor_agps_setting_get_profile_interface(&agps_profile);
	local_param_ptr->nwk_account_id = g_gpsadaptor_agps_ctx.data_account;

    ilm_ptr = allocate_ilm(MOD_GPSADAPTOR);
    ilm_ptr->src_mod_id = MOD_GPSADAPTOR;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_RSP;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
	return;
}





/*****************************************************************************
 * FUNCTION
 *  gpsadaptor_gps_mgr_supl_gpsadaptor_status_terminated
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gpsadaptor_agps_supl_status_terminated(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_ind_struct *supl_mmi_status_ind_p = (supl_mmi_status_ind_struct*)msg;
    U32 id;
    U8 i;
    U8 index;
    U32 pos_end_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = supl_mmi_status_ind_p->req_id;
	if( g_gpsadaptor_agps_ctx.req_id != id )
    {
        return;
    }

#ifdef MMI_AGPS_NEED_TLS
    if (supl_mmi_status_ind_p->cause == SUPL_MMI_CAUSE_TLS_AUTH_FAIL &&
        g_gpsadaptor_agps_ctx.start_mode == MMI_GPS_START_MODE_SI &&
        g_gpsadaptor_agps_ctx.need_retry == MMI_TRUE)
    {
    	gpsadaptor_agps_send_start_supl_req(KAL_TRUE);
        return;
    }
	if (g_gpsadaptor_agps_ctx.need_retry == KAL_FALSE)
    {
    	gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_TERMINATE);
        return;
    }
	

    if (supl_gpsadaptor_status_ind_p->cause == SUPL_GPSADAPTOR_CAUSE_TLS_AUTH_FAIL &&
        g_gpsadaptor_agps_ctx.start_mode == GPSADAPTOR_AGPS_START_MODE_NI &&
        g_gpsadaptor_agps_ctx.need_retry == KAL_TRUE)
    {
        return;
    }

#endif /* GPSADAPTOR_AGPS_NEED_TLS */

    if (SUPL_MMI_IF_POSITION_USED(supl_mmi_status_ind_p->obj_valid))
    {
        gpsadaptor_agps_set_pos(&supl_mmi_status_ind_p->position);
    }

    if (g_gpsadaptor_agps_ctx.state == GPSADAPTOR_AGPS_STATE_WORKING)
    {
        if (g_gpsadaptor_agps_ctx.start_mode == GPSADAPTOR_AGPS_START_MODE_NI ||
            (g_gpsadaptor_agps_ctx.start_mode == GPSADAPTOR_AGPS_START_MODE_SI &&
            g_gpsadaptor_agps_ctx.work_mode == GPSADAPTOR_AGPS_WORK_MODE_MA))
        {

		}
        else if (g_gpsadaptor_agps_ctx.start_mode == GPSADAPTOR_AGPS_START_MODE_SI &&
                 g_gpsadaptor_agps_ctx.work_mode == GPSADAPTOR_AGPS_WORK_MODE_MB)
        {
            gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_WAIT_POS);
        }
    }
    else if (g_gpsadaptor_agps_ctx.state == GPSADAPTOR_AGPS_STATE_ABORT)
    {
        gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_TERMINATE);
    }
    else if (g_gpsadaptor_agps_ctx.state == GPSADAPTOR_AGPS_STATE_START ||
            g_gpsadaptor_agps_ctx.state == GPSADAPTOR_AGPS_STATE_NI_ERROR)
    {
        
    }
    else if (g_gpsadaptor_agps_ctx.state == GPSADAPTOR_AGPS_STATE_WAIT_CNF)    // multiple SUPL push case
    {
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  gpsadaptor_gps_mgr_supl_gpsadaptor_status_activated
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gpsadaptor_agps_supl_status_activated(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_ind_struct *supl_mmi_status_ind_p = (supl_mmi_status_ind_struct*)msg;
    U32 id;
    supl_mmi_position_struct pos;
    supl_mmi_req_assist_data_struct filter;
    supl_mmi_status_rsp_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;
    gpsadaptor_agps_profile_struct agps_profile;
    U32 data_account;
    U8 i;
    U8 j;
    U8 index;
    kal_bool is_usd;
    kal_bool pos_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = supl_mmi_status_ind_p->req_id;
	if (g_gpsadaptor_agps_ctx.req_id != id ){
        return;
    }
    
    if (supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_SET_ASSIST)
    {
        g_gpsadaptor_agps_ctx.work_mode = GPSADAPTOR_AGPS_WORK_MODE_MA;
    }
    else if(supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_SET_BASE)
    {
        g_gpsadaptor_agps_ctx.work_mode = GPSADAPTOR_AGPS_WORK_MODE_MB;
    }
    else if(supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_AUTO ||
            supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_NO_POSITION)
    {
        g_gpsadaptor_agps_ctx.work_mode = GPSADAPTOR_AGPS_WORK_MODE_MB;
    }
    else if(supl_mmi_status_ind_p->pos_method == SUPL_MMI_POS_METHOD_UNSUPPORTED)
    {
        g_gpsadaptor_agps_ctx.work_mode = GPSADAPTOR_AGPS_WORK_MODE_MB;
    }
    else
    {
        ASSERT(0);
    }
    memcpy(&g_gpsadaptor_agps_ctx.qop, &supl_mmi_status_ind_p->qop, sizeof(supl_mmi_status_ind_struct));

    /* L modify */
    
	if (SUPL_MMI_IF_NOTIFY_USED(supl_mmi_status_ind_p->obj_valid) &&
			(supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_ONLY ||
			 supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_ALLOW_NO_ANSWER ||
			 supl_mmi_status_ind_p->notify.notify_type == SUPL_MMI_NOTIFY_DENY_NO_ANSWER ))
	{
		return;
	}
    
    gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_ACTIVITATE);

    local_param_ptr = (supl_mmi_status_rsp_struct*)construct_local_para(sizeof(supl_mmi_status_rsp_struct), TD_CTRL);
	if(local_param_ptr == NULL){
		return;
	}
    local_param_ptr->req_id = id;
    local_param_ptr->obj_valid = 0;
    local_param_ptr->notify_rsp.result = SUPL_MMI_RESULT_OK;
    SUPL_MMI_USE_NOTIFY_RSP(local_param_ptr->obj_valid);
    if (pos_ret == KAL_TRUE)
    {
        SUPL_MMI_USE_POSITION(local_param_ptr->obj_valid);
    }

	pos_ret = gpsadaptor_agps_get_history_pos(&g_gpsadaptor_agps_ctx.qop, &pos, &filter);
	//data_account = gpsadaptor_agps_setting_get_data_account(g_gpsadaptor_agps_ctx.sim);
    gpsadaptor_agps_setting_get_profile_interface(&agps_profile);
    local_param_ptr->nwk_account_id = g_gpsadaptor_agps_ctx.data_account;
    if (local_param_ptr->nwk_account_id == 0xffffffff)
    {
        free_local_para((local_para_struct*) local_param_ptr);
		gpsadaptor_agps_send_abort_error_rsp();
        return;
    }

    memcpy(&local_param_ptr->pos, &pos, sizeof(supl_mmi_position_struct));
    if (pos_ret == KAL_TRUE)
    {
    	SUPL_MMI_USE_POSITION(local_param_ptr->obj_valid);
    }

    /* L modify */
    #ifndef __MTK_TARGET__
    kal_mem_set((void*)&filter, 0, sizeof(supl_mmi_req_assist_data_struct));
    filter.ref_location = KAL_TRUE;
    filter.ref_time = KAL_TRUE;
    filter.navigation_model = KAL_TRUE;
    #endif
    memcpy(&local_param_ptr->filter, &filter, sizeof(supl_mmi_req_assist_data_struct));
    SUPL_MMI_USE_FILTER(local_param_ptr->obj_valid);

    ilm_ptr = allocate_ilm(MOD_GPSADAPTOR);
    ilm_ptr->src_mod_id = MOD_GPSADAPTOR;
    ilm_ptr->dest_mod_id = MOD_SUPL;
    ilm_ptr->sap_id = SUPL_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_STATUS_RSP;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
    gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_WORKING);
}


/*****************************************************************************
 * FUNCTION
 *  gpsadaptor_gps_mgr_supl_gpsadaptor_status_stand_by
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gpsadaptor_agps_supl_status_stand_by(void *msg)
{
    return ;
}
void gpsadaptor_agps_supl_status_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supl_mmi_status_ind_struct *supl_mmi_status_ind_p = (supl_mmi_status_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (supl_mmi_status_ind_p->status)
    {
        case SUPL_MMI_STATUS_TERMINATED:
            gpsadaptor_agps_supl_status_terminated(msg);
            break;
        case SUPL_MMI_STATUS_ACTIVATED:
            gpsadaptor_agps_supl_status_activated(msg);
            break;
        case SUPL_MMI_STATUS_STAND_BY:
            gpsadaptor_agps_supl_status_stand_by(msg);
            break;
        default:
            break;
    }
}




void gpsadaptor_agps_p_callback(gpsadaptor_gps_parser_p_info_enum type);

kal_bool gpsadaptor_agps_initial(void){
	kal_bool ret = KAL_TRUE;
	g_gpsadaptor_agps_ctx.state = GPSADAPTOR_AGPS_STATE_TERMINATE;
	if(KAL_FALSE == gpsadaptor_agps_setting_get_is_agps_on_interface()){
		return KAL_FALSE;
	}
	gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_START);
	
	g_gpsadaptor_agps_ctx.req_id = 0;

	if(srv_mode_switch_is_network_service_available()== KAL_FALSE){
		GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_NO_NETWORK));
		gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_TERMINATE);
        return KAL_FALSE;
	}
	if(g_gpsadaptor_agps_ctx.app_id == 0){
        cbm_app_info_struct info;
        memset(&info, 0, sizeof(info));
        g_gpsadaptor_agps_ctx.app_id = 0;
        info.app_str_id = 0;
        info.app_icon_id = 0;
        #if defined(__CMCC_AGPS_SUPPORT__)
            /* do not use WIFI in CMCC server */
            info.app_type = DTCNT_APPTYPE_GPS | DTCNT_APPTYPE_SKIP_WIFI;
        #else
            info.app_type = DTCNT_APPTYPE_GPS;
        #endif
        cbm_register_app_id_with_app_info(&info, &g_gpsadaptor_agps_ctx.app_id);
		if (g_gpsadaptor_agps_ctx.account_id != 0xffffffff)
		{
			g_gpsadaptor_agps_ctx.data_account = cbm_encode_data_account_id(g_gpsadaptor_agps_ctx.account_id, g_gpsadaptor_agps_ctx.sim, 
				g_gpsadaptor_agps_ctx.app_id,KAL_FALSE);
		}
		else
		{
		g_gpsadaptor_agps_ctx.data_account = cbm_encode_data_account_id(0, g_gpsadaptor_agps_ctx.sim, 
			g_gpsadaptor_agps_ctx.app_id,KAL_FALSE);
    }
    }
	if (g_gpsadaptor_agps_ctx.data_account == 0xffffffff)
    {
		GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_NO_NETWORK));
		gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_TERMINATE);
        return KAL_FALSE;
    }

	g_gpsadaptor_agps_ctx.agps_on_off = KAL_TRUE;

	g_gpsadaptor_agps_ctx.start_mode = GPSADAPTOR_AGPS_START_MODE_SI;
	#ifdef __IOT_CUSTOMIZE__
	g_gpsadaptor_agps_ctx.work_mode = GPSADAPTOR_AGPS_WORK_MODE_MB;
	#endif
	g_gpsadaptor_agps_ctx.need_retry= KAL_TRUE;
	g_gpsadaptor_agps_ctx.is_retrying= KAL_FALSE;
	
	g_gpsadaptor_agps_ctx.sim = (kal_uint8)gpsadaptor_agps_setting_get_sim_interface();
	
	gpsadaptor_agps_get_qop_setting(&g_gpsadaptor_agps_ctx.qop);
	return KAL_TRUE;
	//g_gpsadaptor_agps_ctx.qop;
}
void gpsadaptor_agps_deinitial(void){
	g_gpsadaptor_agps_ctx.req_id = -1;
	g_gpsadaptor_agps_ctx.need_retry= KAL_TRUE;
	g_gpsadaptor_agps_ctx.is_retrying= KAL_FALSE;
	g_gpsadaptor_agps_ctx.state = GPSADAPTOR_AGPS_STATE_TERMINATE;
	gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_START_MODE_END);
	g_gpsadaptor_agps_ctx.work_mode = GPSADAPTOR_AGPS_WORK_MODE_END;
}

kal_uint32 gpsadaptor_agps_send_abort_supl_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    supl_mmi_abort_req_struct *local_param_ptr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GPSADAPTOR_TRACE((TRACE_GROUP_2, GPSADAPOOR_AGPS_SEND_STOP_REQ));
	
	if(gpsadaptor_agps_check_state_right() == KAL_FALSE){
		return GPSADAPTOR_AGPS_STATE_MACHINE_WRONG;
	}else if (g_gpsadaptor_agps_ctx.state != GPSADAPTOR_AGPS_STATE_SET_WORK_MODE){
        ilm_ptr = allocate_ilm(MOD_GPSADAPTOR);
        local_param_ptr = (supl_mmi_abort_req_struct*)construct_local_para(sizeof(supl_mmi_abort_req_struct), TD_CTRL);
		if(local_param_ptr == NULL){
			GPSADAPTOR_TRACE((TRACE_GROUP_2,GPSADAPOOR_AGPS_ALLOC_FAILURE));
			return;
		}

        local_param_ptr->req_id = g_gpsadaptor_agps_ctx.req_id;
        ilm_ptr->src_mod_id = MOD_GPSADAPTOR;
        ilm_ptr->dest_mod_id = MOD_SUPL;
        ilm_ptr->sap_id = SUPL_MMI_SAP;
        ilm_ptr->msg_id = (msg_type) MSG_ID_SUPL_MMI_ABORT_REQ;
        ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

        msg_send_ext_queue(ilm_ptr);
        gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_ABORT);
		return GPSADAPTOR_AGPS_RESULT_SUCCESS;
    }
    else
    {
        return GPSADAPTOR_AGPS_RESULT_SUCCESS;
    }
}


static void gpsadaptor_agps_supl_abort_ind_hdlr(void *msg)
{
    gpsadaptor_agps_deinitial();
}


void gpsadaptor_agps_p_callback(gpsadaptor_gps_parser_p_info_enum type)
{
    GPSADAPTOR_TRACE( (TRACE_GROUP_2, GPSADAPTOR_AGPS_UART_P_CALLBACK, type));
    if(type == GPSADAPTOR_GPS_PARSER_P_SYSTEM_START_OK)
    {
    	if(gpsadaptor_agps_initial() == KAL_FALSE){
			return;
		}
		#ifdef __IOT_CUSTOMIZE__
		gpsadaptor_agps_send_start_supl_req(KAL_FALSE);
    	gpsadaptor_agps_send_cmd_req(GPS_UART_GPS_SWITCH_MODE_MB);
		gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_WORKING);
		#else
    	gpsadaptor_agps_send_cmd_req(GPS_UART_GPS_SWITCH_MODE_MB);
		gpsadaptor_agps_set_state(GPSADAPTOR_AGPS_STATE_SET_WORK_MODE);
		#endif
    }
    else if(type == GPSADAPTOR_GPS_PARSER_P_GPS_MODE_SWITCH_OK)
    {
        gpsadaptor_agps_send_start_supl_req(KAL_FALSE);
    }
}

void gpsadaptor_agps_test_handler( ilm_struct *ilm_ptr )
{
    tst_module_string_inject_struct* tst_inject = (tst_module_string_inject_struct*)ilm_ptr->local_para_ptr;
    nvram_ef_agps_profile_struct profile;
	kal_uint16 sub_command=0;
	
	if(strlen(tst_inject->string)){
		sscanf(tst_inject->string, "%d", &sub_command); 
		kal_prompt_trace(MOD_GPSADAPTOR,"[agps adaptor][%s] command=%d,subcommand=%d\n",
			__FUNCTION__,
			tst_inject->index,
			sub_command);
	}

	
	if (20 == tst_inject->index)
    {	
    	if(sub_command == 0){
			gpsadaptor_agps_initial();
		}else if(sub_command == 1){
		    gpsadaptor_agps_send_start_supl_req(KAL_FALSE);
	    }else if(sub_command == 2){
	        gpsadaptor_agps_register_p_callback(gpsadaptor_agps_p_callback);
			g_gpsadaptor_agps_ctx.gps_uart_p_callback(GPSADAPTOR_GPS_PARSER_P_SYSTEM_START_OK);	
		}else if(sub_command == 3){
		    gpsadaptor_agps_register_p_callback(gpsadaptor_agps_p_callback);
			g_gpsadaptor_agps_ctx.gps_uart_p_callback(GPSADAPTOR_GPS_PARSER_P_GPS_MODE_SWITCH_OK);	
		}else if(sub_command == 4){
			gpsadaptor_agps_send_abort_supl_req();
		}else if(sub_command == 5){
			gpsadaptor_agps_send_abort_error_rsp();
		}else if(sub_command == 6){
			gpsadaptor_agps_deinitial();
		}else if(sub_command == 7){ //Write supl port to nvram
		    kal_prompt_trace(MOD_GPSADAPTOR,"[agps adaptor] Port: 7275\n");
            gpsadaptor_agps_setting_get_profile(&profile);
			profile.port = 7275;
            gpsadaptor_agps_setting_set_profile(&profile);
        }else if(sub_command == 8){ //Write supl port to nvram
            kal_prompt_trace(MOD_GPSADAPTOR,"[agps adaptor] Port: 7276\n");
			gpsadaptor_agps_setting_get_profile(&profile);
			profile.port = 7276;
            gpsadaptor_agps_setting_set_profile(&profile);  
		}else{
		}
    }
	if (21 == tst_inject->index)
    {	
    	gpsadaptor_agps_set_state(sub_command);
    }
	if (22 == tst_inject->index)
    {	
    	gpsadaptor_agps_send_cmd_req(sub_command);
    }
    #ifdef __IOT_CUSTOMIZE__
    if (23 == tst_inject->index) //TLS enable/disable
    {	
        agps_adaptor_set_config(KAL_TRUE, "supl.google.com", 7275, KAL_TRUE);
    }
    if (24 == tst_inject->index) //SUPL server port
    {	
        agps_adaptor_set_config(KAL_TRUE, "supl.google.com", 7276, KAL_FALSE);
    }
    if (25 == tst_inject->index) //SUPL server name
    {	
        agps_adaptor_set_config(KAL_TRUE, "supl.nokia.com", 7275, KAL_TRUE);
    }
    if (26 == tst_inject->index) //SUPL enable/disable
    {	
        agps_adaptor_set_config(KAL_FALSE, "\0", 0, KAL_FALSE);
    }
    #endif
	return;
}

void gpsadaptor_agps_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 msg_id = ilm_ptr->msg_id;
	gps_uart_p_info_ind_struct* uart_p_info_data_ind = (gps_uart_p_info_ind_struct*)ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(msg_id)
    {
    case MSG_ID_GPS_UART_P_INFO_IND:
		gpsadaptor_agps_register_p_callback(gpsadaptor_agps_p_callback);
		g_gpsadaptor_agps_ctx.gps_uart_p_callback(uart_p_info_data_ind->type);		
		break;
	case MSG_ID_SUPL_MMI_STATUS_IND:
		gpsadaptor_agps_supl_status_ind_hdlr(ilm_ptr->local_para_ptr);
		break;
	case MSG_ID_SUPL_MMI_ABORT_CNF:
		gpsadaptor_agps_supl_abort_ind_hdlr(ilm_ptr->local_para_ptr);
		break;
	case MSG_ID_GPS_ASSIST_BIT_MASK_IND:
		//add something i don't known now.
		break;
    default:
        //ASSERT(0);
        break;
    }
}

#ifdef __IOT_CUSTOMIZE__

void agps_adaptor_set_config(MMI_BOOL supl_en, 
                        U8 *supl_name,
                        U16 supl_port,
                        MMI_BOOL use_tls)
{
	kal_prompt_trace(MOD_GPSADAPTOR,"[agps adaptor]set config, SE[%d]SN[%s]SP[%d]", supl_en, supl_name, supl_port);
    g_gpsadaptor_agps_ctx.agps_supl_enable = supl_en;
	if (supl_name == NULL)
	{
		return;
	}
    strcpy(&g_gpsadaptor_agps_ctx.agps_supl_name[0], supl_name);
    g_gpsadaptor_agps_ctx.agps_supl_port = supl_port;
    g_gpsadaptor_agps_ctx.agps_tls_en = use_tls;
}

kal_bool agps_adaptor_get_supl_enable(void)
{
    return (g_gpsadaptor_agps_ctx.agps_supl_enable);
}

kal_uint8 agps_adaptor_get_supl_name_lens(void)
{
    return strlen(g_gpsadaptor_agps_ctx.agps_supl_name);
}

void agps_adaptor_get_supl_name(U8 *supl_name)
{
    strcpy(supl_name, g_gpsadaptor_agps_ctx.agps_supl_name);
}

kal_uint16 agps_adaptor_get_supl_port(void)
{
    return g_gpsadaptor_agps_ctx.agps_supl_port;
}

kal_bool agps_adaptor_get_supl_use_tls(void)
{
    return (g_gpsadaptor_agps_ctx.agps_tls_en);
}

void agps_adaptor_set_accout_id(kal_uint32 account_id)
{
	g_gpsadaptor_agps_ctx.account_id = account_id;
}

#endif
#endif
#endif
#endif
