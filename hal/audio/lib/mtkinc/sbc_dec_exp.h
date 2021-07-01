/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013 
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * sbc_dec_exp.h
 *
 * Project:
 * --------
 * SWIP
 *
 * Description:
 * ------------
 * SBC decoder export interface
 *
 * Author:
 * -------
 * -------
 *
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
 *
 *
 *******************************************************************************/

#ifndef __SBC_DEC_EXP_H__
#define __SBC_DEC_EXP_H__

// sampling frequency
#define SBC_FREQ_16000		0x00
#define SBC_FREQ_32000		0x01
#define SBC_FREQ_44100		0x02
#define SBC_FREQ_48000		0x03

// blocks
#define SBC_BLK_4		0x00
#define SBC_BLK_8		0x01
#define SBC_BLK_12		0x02
#define SBC_BLK_16		0x03

// subbands
#define SBC_SB_4		0x00
#define SBC_SB_8		0x01

// channel mode
#define SBC_MODE_MONO           0x00
#define SBC_MODE_DUAL_CHANNEL   0x01
#define SBC_MODE_STEREO         0x02
#define SBC_MODE_JOINT_STEREO   0x03

// allocation method
#define SBC_AM_LOUDNESS 0x00
#define SBC_AM_SNR      0x01

typedef struct {
	void *priv;
	unsigned char frequency;
	unsigned char blocks;
	unsigned char subbands;
	unsigned char mode;
	unsigned char allocation;
	unsigned char bitpool;
} SbcDec_Handle;

typedef struct {
    unsigned short magic_word;
    unsigned short prev_payload_size;
    unsigned char  prev_payload_header;
} SbcDec_MediaPayloadInfo;

/**************************************************************************|
|   Function:                                                              |
|       SbcDec_GetBufferSize                                               |
|                                                                          |
|   Description:                                                           |
|       Get buffer sizes of the SBC decoder                                |
|                                                                          |
|   Arguments:                                                             |
|       bitstream_buffer_size   [O] Maximum bitstream buffer size          |
|                                   for one SBC frame (unit: byte)         |
|       pcm_buffer_size         [O] Maximum PCM buffer size                |
|                                   for one SBC frame (unit: byte)         |
|       internal_buffer_size    [O] Internal buffer size (unit: byte)      |
|                                                                          |
|   Reture Value:                                                          |
|       N/A                                                                |
|**************************************************************************/
void SbcDec_GetBufferSize (
    int *bitstream_buffer_size, 
    int *pcm_buffer_size, 
    int *internal_buffer_size);

/**************************************************************************|
|   Function:                                                              |
|       SbcDec_Init                                                        |
|                                                                          |
|   Description:                                                           |
|       Initialize the SBC decoder handle                                  |
|                                                                          |
|   Arguments:                                                             |
|       p_internal_buf  [I] Pointer to the internal buffer                 |
|                                                                          |
|   Reture Value:                                                          |
|       NULL : Invalid "p_internal_buf"                                    |
|       else : Normal case, which represents the pointer to the SBC        |
|              decoder handle structure                                    |
|**************************************************************************/
SbcDec_Handle *SbcDec_Init(void *p_internal_buf);

/********************************************************************************|
|                                                                                |
|   Function:                                                                    |
|       SbcDec_Process                                                           |
|                                                                                |
|   Description:                                                                 |
|       Decode one or multiple SBC frame(s)                                      |
|                                                                                |
|   Arguments:                                                                   |
|       p_handle    [I] Pointer to the SBC decoder handle structure              |
|       p_in_buf    [I] Pointer to the input bitstream buffer                    |
|       consumed    [I] Pointer to the available input buffer size (unit: byte)  |
|                   [O] Pointer to the consumed input buffer size (unit: byte)   |
|       p_ou_buf    [I] Pointer to the output PCM buffer                         |
|       written     [I] Pointer to the available output buffer size (unit: byte) |
|                   [O] Pointer to the produced output buffer size (unit: byte)  |
|                                                                                |
|   Reture Value:                                                                |
|        0 : Normal case, including insufficient input / output buffer size      |
|       -1 : SBC frame sync byte incorrect                                       |
|       -2 : SBC frame CRC incorrect                                             |
|       -3 : SBC frame bitpool value out of bounds                               |
|       -4 : Invalid pointer(s), including "p_handle", "p_in_buf", "consumed",   |
|             "p_ou_buf", and / or "written"                                     |
|********************************************************************************/
int SbcDec_Process (
    SbcDec_Handle *p_handle,
    const void *p_in_buf, 
    unsigned int *consumed, 
    void *p_ou_buf, 
    unsigned int *written);

/**************************************************************************|
|   Function:                                                              |
|       SbcDecParser_GetBufferSize                                         |
|                                                                          |
|   Description:                                                           |
|       Get the buffer size of the SBC media payload parser                |
|                                                                          |
|   Arguments:                                                             |
|       internal_buffer_size    [O] Internal buffer size (unit: byte)      |
|                                                                          |
|   Reture Value:                                                          |
|       N/A                                                                |
|**************************************************************************/
void SbcDecParser_GetBufferSize (int *internal_buffer_size);

/*************************************************************************************|
|   Function:                                                                         |
|       SbcDecParser_Init                                                             |
|                                                                                     |
|   Description:                                                                      |
|       Initialize SBC media payload parser                                           |
|                                                                                     |
|   Arguments:                                                                        |
|       p_internal_buf  [I] Pointer to the internal buffer                            |
|       magic_word      [I] Magic sync word of the SBC media payload                  |
|                                                                                     |
|   Reture Value:                                                                     |
|       NULL : Invalid "p_internal_buf"                                               |
|       else : Normal case, which represents the pointer to the SBC media payload     |
|              information handle structure                                           |
|*************************************************************************************/
SbcDec_MediaPayloadInfo *SbcDecParser_Init (void *p_internal_buf, unsigned short magic_word);

/*****************************************************************************************|
|   Function:                                                                             |
|       SbcDecParser_Process                                                              |
|                                                                                         |
|   Description:                                                                          |
|       Parse the SBC media payload buffer                                                |
|                                                                                         |
|   Arguments:                                                                            |
|       p_handle        [I] Pointer to the SBC media payload information handle structure |
|       p_in_buf        [I] Pointer to the input SBC media payload buffer                 |
|       p_in_buf_size   [I] Pointer to the available input buffer size (unit: byte)       |
|                       [O] Pointer to the consumed input buffer size (unit: byte)        |
|       p_ou_buf        [I] Pointer to the output SBC frame bitstream buffer              |
|       p_ou_buf_size   [I] Pointer to the available output buffer size (unit: byte)      |
|                       [O] Pointer to the produced output buffer size (unit: byte)       |
|                                                                                         |
|   Reture Value:                                                                         |
|        0 : Normal case                                                                  |
|       -1 : Invalid pointer(s), including "p_handle", "p_in_buf", "p_in_buf_size",       |
|            "p_ou_buf", and / or "p_ou_buf_size"                                         |
|       -2 : Invalid sync word                                                            |
|       -3 : Invalid non-fragmented payload since the previous payload is fragmented and  |
|            not the last payload, which means that the current payload should be         |
|            fragmented                                                                   |
|       -4 : Invalid starting payload since the previous payload is fragmented and        |
|            not the last payload, which means that the current payload should not be     |
|            the starting payload                                                         |
|       -5 : Invalid fragment index since the previous payload is fragmented and          |
|            not the last payload, which means that the current payload should be         |
|            the previous fragment index - 1                                              |
|       -6 : Invalid fragment index since this payload is the last payload, which means   |
|            that the fragment index should be 1                                          |
|       -7 : Invalid number of frames since this payload is not fragmented and the        |
|            bitstream size is greater than zero, which means that the number of frames   |
|            should be greater than zero                                                  |
|*****************************************************************************************/
int SbcDecParser_Process (
    SbcDec_MediaPayloadInfo *p_handle, 
    unsigned char *p_in_buf, 
    int *p_in_buf_size, 
    unsigned char *p_ou_buf, 
    int *p_ou_buf_size);

/*****************************************************************************************|
|   Function:                                                                             |
|       SbcDec_ParseOneFrame                                                              |
|                                                                                         |
|   Description:                                                                          |
|       Parse one frame of the SBC bitstream buffer                                       |
|                                                                                         |
|   Arguments:                                                                            |
|       p_handle        [O] Pointer to the SBC decoder handle structure                   |
|       p_in_buf        [I] Pointer to the input SBC frame bitstream buffer               |
|       input_buf_size  [I] Pointer to the available input buffer size (unit: byte)       |
|                                                                                         |
|   Reture Value:                                                                         |
|      >=0 : Normal case, including insufficient input / output buffer size               |
|       -1 : SBC frame sync byte incorrect                                                |
|       -2 : SBC frame CRC incorrect                                                      |
|       -3 : SBC frame bitpool value out of bounds                                        |
|       -4 : Invalid pointer(s), including "p_handle" and / or "p_in_buf"                 |
|*****************************************************************************************/
int SbcDec_ParseOneFrame (
    SbcDec_Handle *p_handle,
    const void *p_in_buf, 
    unsigned int input_buf_size);

/*****************************************************************************************|
|   Function:                                                                             |
|       SbcDec_GetMediaPayloadSampleCount                                                 |
|                                                                                         |
|   Description:                                                                          |
|       Get SBC media payload sample count (1 byte payload header + N x SBC frames)       |
|                                                                                         |
|   Arguments:                                                                            |
|       input    [I] Pointer to the input SBC media payload buffer                        |
|       consumed [I] Pointer to the input SBC media payload buffer size (unit: byte)      |
|                [O] Pointer to the consumed SBC media payload buffer size (unit: byte)   |
|       produced [O] Pointer to the output PCM sample count of this payload               |
|                    (Note: One pair of L / R counts as 2 samples)                        |
|                                                                                         |
|   Reture Value:                                                                         |
|      >=0 : Normal case, including insufficient input buffer size                        |
|       -1 : Invalid pointer(s), including "input", "consumed" and / or "produced"        |
|       -2 : Invalid internal pointers                                                    |
|       -3 : SBC frame sync byte incorrect                                                |
|       -4 : SBC frame bitpool value out of bounds                                        |
|*****************************************************************************************/
int SbcDec_GetMediaPayloadSampleCount (
    const void *input, 
    unsigned int *consumed, 
    unsigned int *produced);

/*****************************************************************************************|
|   Function:                                                                             |
|       SbcEnc_GetSilencePayloadLength                                                    |
|                                                                                         |
|   Description:                                                                          |
|       Get MTK SBC decoder silence payload length                                        |
|                                                                                         |
|   Arguments:                                                                            |
|       smpl_cnt [I] Silence sample count (Note: One pair of L / R counts as 2 samples)   |
|                                                                                         |
|   Reture Value:                                                                         |
|       Silence payload length (unit: byte)                                               |
|*****************************************************************************************/
unsigned int SbcEnc_GetSilencePayloadLength (unsigned int smpl_cnt);

/*****************************************************************************************|
|   Function:                                                                             |
|       SbcEnc_ProduceSilencePayload                                                      |
|                                                                                         |
|   Description:                                                                          |
|       Produce MTK SBC decoder silence payload                                           |
|                                                                                         |
|   Arguments:                                                                            |
|       smpl_cnt [I] Silence sample count (Note: One pair of L / R counts as 2 samples)   |
|       output   [O] Pointer to the output SBC silence payload                            |
|       written  [I] Pointer to the available output buffer size (unit: byte)             |
|                [O] Pointer to the produced output buffer size (unit: byte)              |
|                                                                                         |
|   Reture Value:                                                                         |
|      >=0 : Normal case, including insufficient output buffer size                       |
|       -1 : Invalid pointer(s), including "output" and / or "written"                    |
|*****************************************************************************************/
int SbcEnc_ProduceSilencePayload (
    unsigned int smpl_cnt, 
    void *output, 
    unsigned int *written);

#endif // __SBC_DEC_EXP_H__
