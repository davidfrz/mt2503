/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*****************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  mmi_rp_screen.h
*
* Project:
* --------
*   Resgen XML header file of screen resource
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef RESXML_SCREEN_H
#define RESXML_SCREEN_H


#include "MMIDataType.h"


typedef struct
{
    U8 *scr_id_str;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_scr_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_scr_id_struct *screens;
}mmi_rp_scr_data_struct;

typedef struct
{
    mmi_rp_scr_data_struct *app_scr_data;
    mmi_rp_hash_struct *hash;
}mmi_rp_scr_cntx_struct;

extern void mmi_rp_scr_init(void);
extern void mmi_rp_scr_set_app_range(void);

extern int mmi_rp_scr_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_scr_end_handler(void *data, const kal_char *el);
extern int mmi_rp_scr_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_scr_filter(void);

extern void mmi_rp_scr_output_phase1(void);
extern void mmi_rp_scr_output_phase2(void);

#endif /* RESXML_SCREEN_H */
