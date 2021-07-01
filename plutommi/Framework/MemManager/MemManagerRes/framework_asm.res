/* Needed header files of the compile option in XML files, if you need others need to add here */

/*
 * __MMI_FRM_ASM_OMM_SCREEN__'s defination is copied from plutommi/Framework/CommonFiles/CommonInc/mmi_frm_mem_gprot.h 
 * Need sync if change.
*/
#if !defined(__32_32_SEG__)
#define __MMI_FRM_ASM_OOM_SCREEN__
#endif

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="FRAMEWORK_ASM">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    <STRING id="STR_ID_APPMEM_ATTR_STOPPING"/>
    <STRING id="STR_ID_APPMEM_PROMPT_STOP_APP"/>
    <STRING id="STR_ID_APPMEM_STOP"/>
    <STRING id="STR_ID_APPMEM_WAIT"/>
    <STRING id="STR_ID_APPMEM_NOTIFY_STARTING_NEW"/>    
    <STRING id="STR_ID_APPMEM_NOTIFY_STOPPED"/>
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
   

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->


</APP>


