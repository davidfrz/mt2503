/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * phb_utils.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This files contains utility functions for PHB.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h" /* Task message communiction */

//#include "custom_nvram_editor_data_item.h"
#include "sim_common_enums.h"
#include "l4c_common_enum.h"
//#include "mcd_l3_inc_struct.h"
#include "l4c_utility.h" 

#include "l4c2phb_enums.h"
//#include "l4c2phb_struct.h"

//#include "ps2sim_struct.h"
#include "phb_defs.h"
//#include "phb_control_block.h"
//#include "phb_config.h"
//#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"
#include "phb_context.h"
#include "phb_utils.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "l4c2abm_struct.h"
#include "stack_config.h"
#include "ps_public_enum.h"

#if defined(__PINYIN_SORTING_ZI__)
#include "zi8api.h"
#elif  defined(__PINYIN_SORTING_KA__)
extern const signed char *GetPYString(unsigned char *HZ);
#endif 

#ifdef __PHB_USIM_SUPPORT__
#if defined(__GEMINI__) || defined(GEMINI_PLUS)
extern kal_bool is_usim_type(sim_interface_enum which_sim);
#else /* __GEMINI__ */
extern kal_bool is_usim_type(void);
#endif /* __GEMINI__ */
#endif /* __PHB_USIM_SUPPORT__ */

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_UTILS_C_

const kal_uint16 phb_default_7bit_to_ucs2_table[] = 
{
    64, 163, 36, 165, 232, 233, 249, 236, 242, 199, 10, 216, 248, 13, 197, 229,
    0x0394, 95, 0x03A6, 0x0393, 0x039B, 0x03A9, 0x03A0, 0x03A8, 0x03A3, 0x0398, 0x039E, 0x1B, 198, 230, 223, 201,
    32, 33, 34, 35, 164, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    161, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 196, 214, 209, 220, 167,
    191, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 228, 246, 241, 252, 224
};

typedef struct
{
    kal_uint16 ucs2;   /* ucs2 */
    kal_uint8 gsm;     /* 7 bit */
} phb_ucs2_7bit_map;

const phb_ucs2_7bit_map phb_default_7bit_to_ucs2_ext_table[] = 
{
    {0x5e, 0x14},
    {0x20, 0x1b},
    {0x7b, 0x28},
    {0x7d, 0x29},
    {0x5c, 0x2f},
    {0x5b, 0x3c},
    {0x7e, 0x3d},
    {0x5d, 0x3e},
    {0x7c, 0x40},
    {0x20ac, 0x65}
};


/*****************************************************************************
 * FUNCTION
 *  table_shift
 * DESCRIPTION
 *  A generic shift function that shifts content of an array by one slot.
 * PARAMETERS
 *  used_count          [IN/OUT]        Used count of the array
 *  slots               [IN/OUT]        Total slots of the array
 *  array               [IN]            The array to be shifted
 *  element_size        [IN]            Size of each element in `array'
 *  op                  [IN]            Shift down or up
 *  from                [IN]            `from', while for shift-up, shift each slot up from `from'.
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.(?)
 *****************************************************************************/
void table_shift(
        kal_uint16 *used_count,
        kal_uint16 *slots,
        void *array,
        kal_uint16 element_size,
        shift_op_enum op,
        kal_uint16 from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *table = (kal_uint8*) array;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(array != NULL);

    /* shift down */
   /**
    * []    []    [] ...   []
    * from ->  ->   ->     used_count
    */
    if (op == shift_down)
    {
        kal_uint16 i;

        if ((from >= *used_count) || (*used_count >= *slots))
        {
            return;
        }

        for (i = *used_count; (i > from); --i)
        {
            kal_mem_cpy(table + (i * element_size), (void const*)(table + ((i - 1) * element_size)), element_size);
        }
    }
    /* shift up */
   /**
    * []                []       [] ...   []
    * (from - 1) <-     from <-    <-     (used_count - 1)
    */
    else
    {
        kal_uint16 i;

        if ((from >= *used_count) || (*used_count < 1))
        {
            return;
        }

        for (i = from - 1; i < (*used_count - 1); ++i)
        {
            kal_mem_cpy(table + (i * element_size), (void const*)(table + (i + 1) * element_size), element_size);
        }
    }
}   /* end of table_shift */


/*****************************************************************************
 * FUNCTION
 *  table_range_shift
 * DESCRIPTION
 *  A generic shift function that shifts some elements of an array by one slot.
 * PARAMETERS
 *  used_count          [IN/OUT]        Used count of the array
 *  slots               [IN/OUT]        Total slots of the array
 *  array               [IN]            The array to be shifted
 *  element_size        [IN]            Size of each element in `array'
 *  op                  [IN]            Shift down or up
 *  from                [IN]            Ranges to shift
 *  to                  [IN]            Ranges to shift
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE else.(?)
 *****************************************************************************/
void table_range_shift(
        kal_uint16 *used_count,
        kal_uint16 *slots,
        void *array,
        kal_uint16 element_size,
        shift_op_enum op,
        kal_uint16 from,
        kal_uint16 to)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *table = (kal_uint8*) array;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(array != NULL);

    /* shift down */
    if (op == shift_down)
    {
        kal_uint16 i;

        for (i = to + 1; (i > from) && (i >= 1) && (i < *used_count) && (i < *slots); --i)
        {
            if (i >= (*slots - 1))
            {
                continue;
            }
            else
            {
                kal_mem_cpy(table + (i * element_size), (void const*)(table + (i - 1) * element_size), element_size);
            }
        }
    }
    /* shift up */
    else
    {
        kal_uint16 i;

        for (i = from - 1; (i < to) &&
             // amanda remove
             // (i >= 1) &&
             (i < *used_count) && (i < *slots); ++i)
        {
            if (i >= (*slots - 1))
            {
                continue;
            }
            else
            {
                kal_mem_cpy(table + (i * element_size), (void const*)(table + (i + 1) * element_size), element_size);
            }
        }
    }
}   /* end of table_range_shift */


/*****************************************************************************
 * FUNCTION
 *  istring_encode_to_sim
 * DESCRIPTION
 *  Encode input `istr' string to the format of alpha id stored in SIM
 *  (see 3GPP TS 11.11 SIM-ME interface Annex B)  into buffer with byte size of
 *  `buffer_len'.
 *  
 *  Currently, only CODING_AUTO is supported.
 *  
 *  This function assumes caller ensures the correctness of raw content stored in `istr', thus
 *  this function behaves in a best-effort manner. Ie, it encodes each character in `istr'
 *  one by one; once an error is encountered, returns 0. However, the returned `buffer'
 *  may not be correct.
 * PARAMETERS
 *  coding          [IN]        Will be DEFAULT_7BITS or CODING_UCS2_80.
 *  istr            [IN]        The input istring
 *  buffer_len      [IN]        Byte size of buffer
 *  buffer          [OUT]       Where decoded bytes are stored.
 * RETURNS
 *  Number of bytes encoded into buffer
 *****************************************************************************/
kal_uint8 istring_encode_to_sim(
            sim_alpha_id_coding_enum coding,
            istring_type *istr,
            kal_uint8 buffer_len,
            kal_uint8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 count;
    kal_uint8 buf_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(istr != NULL);

    if (get_0338_charset_bits(istr->charset) == CHARSET_ASCII)
    {
        kal_uint16 ch;

        for (count = 0; count < istring_len(istr); ++count)
        {
            ch = istring_char_at(istr, count);

            /* The character doesn't conform to ASCII charset */
            if (ch >= 0x80)
            {
                return 0;
            }

            /* Exceeds capacity */
            if (buf_offset >= buffer_len)
            {
                break;
            }

            buffer[buf_offset++] = (kal_uint8) ch;
        }

        /* Complement all reset bytes to 0xF */
        for (; buf_offset < buffer_len; ++buf_offset)
        {
            buffer[buf_offset] = (kal_uint8) PHB_UTILS_INVALID_VALUE;
        }

        return count;
    }
#ifdef __PHB_0x81_SUPPORT__     /* support maximum length of 0x81 UCS2 */
    /* Handle 0x81 case first */
    else if (istr->charset == CHARSET_UCS2_81 || istr->charset == CHARSET_UCS2_82)
    {

        for (count = 0; count < istr->length; ++count)
        {

            /* Exceeds capacity */
            if ((buf_offset + 1) > (buffer_len))
            {
                break;
            }

            buffer[buf_offset++] = istr->data[count];
        }

        /* Complement all rest of bytes to 0xF */
        for (; buf_offset < buffer_len; ++buf_offset)
        {
            buffer[buf_offset] = (kal_uint8) PHB_UTILS_INVALID_VALUE;
        }

        if (istr->charset == CHARSET_UCS2_81)
        {
            buffer[1] = count - 3;  /* correct the data string size of 0x81 */
        }
        else
        {
            buffer[1] = count - 4;  /* correct the data string size of 0x82 */
        }
        return count;
    }
#endif /* __PHB_0x81_SUPPORT__ */ 
    else if (get_0338_charset_bits(istr->charset) == CHARSET_UCS2)
    {
        kal_uint16 ch;

        buffer[buf_offset++] = CODING_UCS2_80;

        if (buffer_len % 2 == 0)
        {
            buffer_len--;
            buffer[buffer_len] = (kal_uint8) PHB_UTILS_INVALID_VALUE;
        }

        for (count = 0; count < istring_len(istr); ++count)
        {
            ch = istring_char_at(istr, count);

            /* Exceeds capacity */
            if ((buf_offset + 1) > (buffer_len - 1))
            {
                break;
            }

            buffer[buf_offset++] = (ch >> 8) & 0xFF;
            buffer[buf_offset++] = ch & 0xFF;
        }

        /* Complement all rest of bytes to 0xF */
        for (; buf_offset < buffer_len; ++buf_offset)
        {
            buffer[buf_offset] = (kal_uint8) PHB_UTILS_INVALID_VALUE;
        }

        return count;
    }
    else
    {
        return 0;
    }
}   /* istring_encode_to_sim */


/*****************************************************************************
 * FUNCTION
 *  istring_decode_from_sim
 * DESCRIPTION
 *  Decode raw data of alpha id stored in SIM (see 3GPP TS 11.11 SIM-ME interface Annex B)
 *  into a `istring'.
 *  
 *  This function behaves in a best-effort manner. Ie, it decodes each byte in
 *  `raw_data' one by one; once an error is encountered, returns 0.
 *  Since this is a decode function, caller can assume the returned `istring' is always
 *  correct, though it could be truncated.
 *  
 *  NOTE: Passed in istring->length must be set to the length of buffer being decoded.
 *  Before this function is returned, it will be filled with 0xFF for unused bytes.
 * PARAMETERS
 *  raw_data_len        [IN]        Length of raw data
 *  raw_data            [IN]        Raw data
 *  decoded_str         [OUT]       Caller allocated istring_type structure for storing decoded data. Note that caller shall prevent buffer overflow problem.
 * RETURNS
 *  Length of bytes actually decoded. Caller should set this value to the istring's `length' field.
 *  Returns 0 if raw data is not encoded with supported ASCII, 80, 81, 82 encoding.
 *****************************************************************************/
kal_uint8 istring_decode_from_sim(kal_uint8 raw_data_len, kal_uint8 *raw_data, istring_type *decoded_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 count, length;
    kal_uint8 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((raw_data != NULL) && (decoded_str != NULL));

    /* First byte is less than 128, coding is default 7-bits */
    if (raw_data[offset] < 0x80)
    {
        kal_uint8 ch;

        decoded_str->charset = CHARSET_ASCII;

        for (count = 0; offset < raw_data_len; ++offset, ++count)
        {
            /* Error, this character is not conformed to default 7-bits encoding. */
            if ((ch = raw_data[offset]) >= 0x80)
            {
                break;
            }

         /**
          * Should we assume a ASCII charset string is terminated by '\0' ?
          * Or, even by '\xFF' ??

         if ((ch == 0) || (ch == 0xFF))
            break; */

            decoded_str->data[count] = ch;

            /* Exceeds capacity, truncate */
            if (count > (decoded_str->length - 1))
            {
                break;
            }
        }
    }
    else if (raw_data[offset] == CODING_UCS2_80)
    {
        kal_uint8 ch1;
        kal_uint8 ch2;

        decoded_str->charset = CHARSET_UCS2;

        if (raw_data_len % 2 == 0)
        {
            raw_data_len--;
        }
        for (count = 0, ++offset; offset < raw_data_len;)
        {
            /* Exceeds capacity, truncate */
            if ((count + 1) >= decoded_str->length)
            {
                break;
            }

            ch1 = raw_data[offset++];
            ch2 = raw_data[offset++];

            if (ch1 == 0xFF && ch2 == 0xFF)
            {
                break;
            }

            decoded_str->data[count++] = ch1;
            decoded_str->data[count++] = ch2;
        }
    }
#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 and 0x82 format UCS2 */
    /*
     * For 0x81 & 0x82, Keep Original Data, Not Convert, Leave MMI to handle this part
     */
    else if (raw_data[offset] == CODING_UCS2_81)
    {
        /* kal_uint16 ch; */
        kal_uint8 specified_decoded_str_len;

        decoded_str->charset = CHARSET_UCS2_81;

        decoded_str->data[0] = raw_data[0];
        decoded_str->data[1] = raw_data[1];
        specified_decoded_str_len = raw_data[1];
        decoded_str->data[2] = raw_data[2];

        for (count = 3; count < (specified_decoded_str_len + 3); count++)
        {
            /* Exceeds capacity, truncate */
            if ((count + 1) >= decoded_str->length)
            {
                break;
            }

            decoded_str->data[count] = raw_data[count];

        }
    }
    else if (raw_data[offset] == CODING_UCS2_82)
    {
        /* kal_uint16 ch; */
        kal_uint8 specified_decoded_str_len;

        decoded_str->charset = CHARSET_UCS2_82;

        decoded_str->data[0] = raw_data[0];
        decoded_str->data[1] = raw_data[1];
        specified_decoded_str_len = raw_data[1];
        decoded_str->data[2] = raw_data[2];
        decoded_str->data[3] = raw_data[3];

        for (count = 4; count < (specified_decoded_str_len + 4); count++)
        {
            /* Exceeds capacity, truncate */
            if ((count + 1) >= decoded_str->length)
            {
                break;
            }

            decoded_str->data[count] = raw_data[count];
        }
    }
#else /* defined(__PHB_0x81_SUPPORT__) */ 
    else if (raw_data[offset] == CODING_UCS2_81)
    {
        kal_uint16 ch;

        kal_uint8 specified_decoded_str_len;
        kal_uint16 base_ptr;

        decoded_str->charset = CHARSET_UCS2;

        //if (raw_data_len % 2 == 0)
        //   raw_data_len--;

        ++offset;
        specified_decoded_str_len = raw_data[offset++];
        base_ptr = raw_data[offset++] << 7;
        for (count = 0; offset < raw_data_len;)
        {
            ch = raw_data[offset++];

            /* Exceeds capacity, truncate */
            if ((count + 1) >= decoded_str->length)
            {
                break;
            }

            /* All bytes are docoed */
            if ((count + 1) >= (specified_decoded_str_len * 2))
            {
                break;
            }

            if (ch < 0x80)
            {
                //decoded_str->data[count++] = 0x0;
                //decoded_str->data[count++] = (kal_uint8) ch;
                extern const kal_uint16 phb_default_7bit_to_ucs2_table[];
                decoded_str->data[count++] = phb_default_7bit_to_ucs2_table[ch] >> 8;
                decoded_str->data[count++] = phb_default_7bit_to_ucs2_table[ch] & 0xff;
            }
            else
            {
                ch &= 0x7F;
                ch += base_ptr;

                decoded_str->data[count++] = phb_more_significant_char(ch);
                decoded_str->data[count++] = phb_less_significant_char(ch);
            }
        }
    }
    else if (raw_data[offset] == CODING_UCS2_82)
    {
        kal_uint16 ch;

        kal_uint8 specified_decoded_str_len;
        kal_uint16 base_ptr;

        decoded_str->charset = CHARSET_UCS2;

        //if (raw_data_len % 2 == 0)
        //   raw_data_len--;

        ++offset;
        specified_decoded_str_len = raw_data[offset++];
        base_ptr = raw_data[offset++] << 8;
        base_ptr |= raw_data[offset++];
        for (count = 0; offset < raw_data_len;)
        {
            ch = raw_data[offset++];

            /* Exceeds capacity, truncate */
            if ((count + 1) >= (decoded_str->length - 1))
            {
                break;
            }

            /* All bytes are docoed */
            if ((count + 1) >= (specified_decoded_str_len * 2))
            {
                break;
            }

            if (ch < 0x80)
            {
                decoded_str->data[count++] = 0x0;
                decoded_str->data[count++] = (kal_uint8) ch;
            }
            else
            {
                ch &= 0x7F;
                ch += base_ptr;

                decoded_str->data[count++] = phb_more_significant_char(ch);
                decoded_str->data[count++] = phb_less_significant_char(ch);
            }
        }
    }
#endif /* defined(__PHB_0x81_SUPPORT__) */ 
    /* Error */
    else
    {
        return 0;
    }

    length = count;

    /* Complement all rest of bytes to 0xFF */
    for (; count < decoded_str->length; ++count)
    {
        decoded_str->data[count] = 0;
    }

    return length;
}


/*****************************************************************************
 * FUNCTION
 *  istring_decode_0x81_to_0x80
 * DESCRIPTION
 *  Decode raw data of alpha id stored in SIM in 0x81 format
 *  into a `istring'.
 * PARAMETERS
 *  raw_data_len        [IN]        Length of raw data
 *  raw_data            [IN]        Raw data
 *  decoded_str         [OUT]       Caller allocated istring_type structure for storing decoded data. Note that caller shall prevent buffer overflow problem.
 * RETURNS
 *  Length of bytes actually decoded. Caller should set this value to the istring's `length' field.
 *  Returns 0 if raw data is not encoded with supported ASCII, 80, 81, 82 encoding.
 *****************************************************************************/
kal_uint8 istring_decode_0x81_to_0x80(kal_uint8 raw_data_len, kal_uint8 *raw_data, istring_type *decoded_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ch, i;

    kal_uint8 specified_decoded_str_len;
    kal_uint16 base_ptr;

    kal_uint8 count, length, escape = 0;
    kal_uint8 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    decoded_str->charset = CHARSET_UCS2;

    ++offset;
    specified_decoded_str_len = raw_data[offset++];
    base_ptr = raw_data[offset++] << 7;
    for (count = 0; offset < raw_data_len;)
    {
        ch = raw_data[offset++];

        /* Exceeds capacity, truncate */
        if ((count + 1) >= decoded_str->length)
        {
            break;
        }

        /* All bytes are docoed */
        if ((count + 1) >= (specified_decoded_str_len * 2))
        {
            break;
        }

        if (ch < 0x80)
        {
            if (ch == 0x1B)
            {
                escape = 1;
                continue;
            }
            else if (escape)
            {
                escape = 0;
                for (i = 0; i < sizeof(phb_default_7bit_to_ucs2_ext_table) / sizeof(phb_ucs2_7bit_map); i++)
                {
                    if (phb_default_7bit_to_ucs2_ext_table[i].gsm == phb_less_significant_char(ch))
                    {
                        ch = phb_default_7bit_to_ucs2_ext_table[i].ucs2;
                        break;
                    }
                }

                decoded_str->data[count++] = phb_more_significant_char(ch);
                decoded_str->data[count++] = phb_less_significant_char(ch);
            }
            else
            {
                decoded_str->data[count++] = phb_default_7bit_to_ucs2_table[ch] >> 8;
                decoded_str->data[count++] = phb_default_7bit_to_ucs2_table[ch] & 0xff;
            }
        }
        else
        {
            ch &= 0x7F;
            ch += base_ptr;

            decoded_str->data[count++] = phb_more_significant_char(ch);
            decoded_str->data[count++] = phb_less_significant_char(ch);
        }
    }

    length = count;

    /* Complement all rest of bytes to 0xFF */
    for (; count < decoded_str->length; ++count)
    {
        decoded_str->data[count] = 0;
    }

    return length;
}


/*****************************************************************************
 * FUNCTION
 *  istring_decode_0x82_to_0x80
 * DESCRIPTION
 *  Decode raw data of alpha id stored in SIM in 0x82 format
 *  into a `istring'.
 * PARAMETERS
 *  raw_data_len        [IN]        Length of raw data
 *  raw_data            [IN]        Raw data
 *  decoded_str         [OUT]       Caller allocated istring_type structure for storing decoded data. Note that caller shall prevent buffer overflow problem.
 * RETURNS
 *  Length of bytes actually decoded. Caller should set this value to the istring's `length' field.
 *  Returns 0 if raw data is not encoded with supported ASCII, 80, 81, 82 encoding.
 *****************************************************************************/
kal_uint8 istring_decode_0x82_to_0x80(kal_uint8 raw_data_len, kal_uint8 *raw_data, istring_type *decoded_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ch;

    kal_uint8 specified_decoded_str_len;
    kal_uint16 base_ptr;

    kal_uint8 count, length;
    kal_uint8 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    decoded_str->charset = CHARSET_UCS2;

    ++offset;
    specified_decoded_str_len = raw_data[offset++];
    base_ptr = raw_data[offset++] << 8;
    base_ptr |= raw_data[offset++];
    for (count = 0; offset < raw_data_len;)
    {
        ch = raw_data[offset++];

        /* Exceeds capacity, truncate */
        if ((count + 1) >= (decoded_str->length - 1))
        {
            break;
        }

        /* All bytes are docoed */
        if ((count + 1) >= (specified_decoded_str_len * 2))
        {
            break;
        }

        if (ch < 0x80)
        {
            decoded_str->data[count++] = phb_default_7bit_to_ucs2_table[ch] >> 8;
            decoded_str->data[count++] = phb_default_7bit_to_ucs2_table[ch] & 0xff;
        }
        else
        {
            ch &= 0x7F;
            ch += base_ptr;

            decoded_str->data[count++] = phb_more_significant_char(ch);
            decoded_str->data[count++] = phb_less_significant_char(ch);
        }
    }

    length = count;

    /* Complement all rest of bytes to 0xFF */
    for (; count < decoded_str->length; ++count)
    {
        decoded_str->data[count] = 0;
    }

    return length;

}


/*****************************************************************************
 * FUNCTION
 *  istring_len
 * DESCRIPTION
 *  Returns number of characters in `istring' according to its charset.
 * PARAMETERS
 *  istr        [IN]        The istring
 * RETURNS
 *  Number of characters in `istr' according to its charset.
 *****************************************************************************/
kal_uint8 istring_len(istring_type *istr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(istr != NULL);

    return (get_0338_charset_bits(istr->charset) == CHARSET_ASCII) ? istr->length : istr->length / 2;
}   /* end of get_char_len */


/*****************************************************************************
 * FUNCTION
 *  istring_char_at
 * DESCRIPTION
 *  Returns the `offset'th UCS2 character in `istr' according to its charset.
 * PARAMETERS
 *  istr        [IN]        The istring
 *  offset      [IN]        Offset
 * RETURNS
 *  The `offset'th character in `istr' according to its charset.
 *****************************************************************************/
kal_uint16 istring_char_at(istring_type *istr, kal_uint8 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error, invalid offset */
    if (offset >= istring_len(istr))
    {
        return (kal_uint16) PHB_UTILS_INVALID_VALUE;
    }

    if (get_0338_charset_bits(istr->charset) == CHARSET_ASCII)
    {
        return 0 << 8 | istr->data[offset];
    }
    else if (offset <= istring_len(istr))
    {
        return (istr->data[offset * 2] << 8 | istr->data[offset * 2 + 1]);
    }
    else
    {
        return (kal_uint16) PHB_UTILS_INVALID_VALUE;
    }
}   /* end of get_char_len */


/*****************************************************************************
 * FUNCTION
 *  is_chars_equal
 * DESCRIPTION
 *  Determines whether the two characters are equal. A ascii character is treated as equal
 *  if its corresponding UCS2 character is compared with.
 * PARAMETERS
 *  char1       [IN]        Character to compare
 *  char2       [IN]        Character to compare
 * RETURNS
 *  true if the two characters are equal, false else.
 *****************************************************************************/
kal_bool is_chars_equal(kal_uint16 char1, kal_uint16 char2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* try UCS2 matching */
    if (char1 == char2)
    {
        return KAL_TRUE;
    }
    /* if not, try ASCII case-insensitive matching */
    else if ((char1 < 0x007E) && (char2 < 0x007E))
    {
        if ((char1 <= 0x007b) && (char1 >= 0x0061))
        {
            char1 -= 0x20;
        }
        if ((char2 <= 0x007b) && (char2 >= 0x0061))
        {
            char2 -= 0x20;
        }

        if (char1 == char2)
        {
            return KAL_TRUE;
        }
    }
    /* no match */
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  compare_chars
 * DESCRIPTION
 *  Determines whether the two characters are equal. A ascii character is treated as equal
 *  if its corresponding UCS2 character is compared with.
 * PARAMETERS
 *  char1       [IN]        Character to compare
 *  char2       [IN]        Character to compare
 * RETURNS
 *  true if the two characters are equal, false else.
 *****************************************************************************/
kal_int32 compare_chars(kal_uint16 char1, kal_uint16 char2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* try UCS2 matching */
    if (char1 == char2)
    {
        return 0;
    }

    /* if not, try ASCII case-insensitive matching */
    else if ((char1 < 0x007E) && (char2 < 0x007E))
    {
        if ((char1 <= 0x007b) && (char1 >= 0x0061))
        {
            char1 -= 0x20;
        }
        if ((char2 <= 0x007b) && (char2 >= 0x0061))
        {
            char2 -= 0x20;
        }

        return char1 - char2;
    }
    /* no match */
   /**
    * Return value must be wide enough.
    * If width is signed 16 bits,
    * consider a char greater than 0x8000 minus 0x0000 could become
    * negative number, which leads to char1 less than char2.
    */
    return char1 - char2;
}


/*****************************************************************************
 * FUNCTION
 *  bcd2string
 * DESCRIPTION
 *  Converts BCD digits to character array representation.
 *  eg,
 *  from 0x123456
 *  to "123456"
 * PARAMETERS
 *  length          [IN]        Length of `tel_number'
 *  tel_number      [IN]        Input BCD digits
 *  bcd_array       [IN]        Caller provided buffer where the converted BCD digits stored. Size should be 2 * (length of `tel_number') + 1. Null terminated string.
 * RETURNS
 *  Total characters in bcd_array.
 *****************************************************************************/
kal_uint16 bcd2string(kal_uint8 length, kal_uint8 *tel_number, char *bcd_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, k = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < length; ++i)
    {
        for (k = 0; k < 2; ++k)
        {
            char bcd;

            bcd = (k == 0) ? (tel_number[i] >> 4) & 0x0F : tel_number[i] & 0x0F;
            if (bcd > 0x0a)
            {
                bcd_array[k++] = bcd;
            }
            else
            {
                bcd_array[k++] = bcd | 0x30;
            }
        }
    }
    bcd_array[k] = '\0';
    return k;
}   /* end of bcd2string */


/*****************************************************************************
 * FUNCTION
 *  bcd2char
 * DESCRIPTION
 *  Converts a single BCD digit to character representation.
 *  eg,
 *  from 0x01
 *  to '1'
 * PARAMETERS
 *  bcd                 [IN]        
 *  tel_number(?)       [IN]        Input BCD digit
 * RETURNS
 *  character.
 *****************************************************************************/
kal_uint8 bcd2char(kal_uint8 bcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (bcd < 0x0A) ? bcd | 0x30 : bcd;
}   /* end of bcd2char */


/*****************************************************************************
 * FUNCTION
 *  get_next_bcd_digit
 * DESCRIPTION
 *  Get next bcd digit in first byte of bcd_array.
 *  
 *  A typical usage:
 *  
 *  kal_uint16 offset;
 *  kal_bool flag = KAL_FALSE;
 *  kal_uint8 digit;
 *  
 *  while (offset < length of bcd_array) {
 *  offset = get_next_bcd_digit(bcd_array, offset, &flag, &digit);
 *  do_something_using_the_digit(digit);
 *  }
 * PARAMETERS
 *  bcd_array       [IN]        Bcd_array
 *  offset          [IN]        
 *  is_first        [IN]        Get first digit in `bcd_byte' or second digit. This flag is a toggle. It will be toggled when returned.
 *  digit           [OUT]       The converted digit.
 * RETURNS
 *  Next offset that contains the next BCD digit.
 *****************************************************************************/
kal_uint16 get_next_bcd_digit(kal_uint8 *bcd_array, kal_uint16 offset, kal_bool *is_first, kal_uint8 *digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Second BCD, more significant half */
    if (*is_first == KAL_FALSE)
    {
        *digit = (bcd_array[offset] >> 4) & 0x0F;
        *is_first = KAL_TRUE;
        return ++offset;
    }
    /* First BCD, less significant half */
    else
    {
        *digit = bcd_array[offset] & 0x0F;
        *is_first = KAL_FALSE;
        return offset;
    }
}   /* end of get_next_bcd_digit */


/*****************************************************************************
 * FUNCTION
 *  compare_n_string_bcd
 * DESCRIPTION
 *  Compare not more than `n' character or length of `istr', each character
 *  of which is 8-bits char, and digit in `bcd_array', each digit of which is
 *  a 4-bits BCD digit.
 * PARAMETERS
 *  str             [IN]        
 *  bcd_array       [IN]        BCD digit array
 *  n               [IN]        Compare at most n elements.
 *  istr(?)         [IN]        Char array
 * RETURNS
 *  An 8-bits integer greater than, equal to, or less than 0, according as istr is greater than,
 *  equal to, or less than bcd_array.
 *****************************************************************************/
kal_int8 compare_n_string_bcd(char const *str, kal_uint8 *bcd_array, kal_uint16 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char c1 = '\0';
    unsigned char c2 = '\0';
    kal_bool flag = KAL_TRUE;
    kal_uint16 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n > 0)
    {
        c1 = (unsigned char)*str++;
        offset = get_next_bcd_digit(bcd_array, offset, &flag, &c2);
        c2 = bcd2char(c2);

        if (c1 == '\0' || c1 != c2)
        {
            return c1 - c2;
        }
        n--;
    }

    return c1 - c2;
}


/*****************************************************************************
 * FUNCTION
 *  compare_n_bcd
 * DESCRIPTION
 *  Compare not more than `n' digits, or length of `first_bcd_array' (ie,
 *  number of digits before first 0xF is encountered), for `first_bcd_array'
 *  and `second_bcd_array', each digit is a 4-bits BCD digit.
 * PARAMETERS
 *  first_bcd_array         [?]         
 *  second_bcd_array        [?]         
 *  n                       [IN]        Compare at most n elements.
 *  bcd_array(?)            [IN]        BCD digit array
 *  istr(?)                 [IN]        Char array
 * RETURNS
 *  An 8-bits integer greater than, equal to, or less than 0, according as istr is greater than,
 *  equal to, or less than bcd_array.
 *****************************************************************************/
kal_int8 compare_n_bcd(kal_uint8 *first_bcd_array, kal_uint8 *second_bcd_array, kal_uint16 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 c1 = 0;
    kal_uint8 c2 = 0;

    kal_bool first_flag = KAL_TRUE;
    kal_uint16 first_offset = 0;

    kal_bool second_flag = KAL_TRUE;
    kal_uint16 second_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n > 0)
    {
        first_offset = get_next_bcd_digit(first_bcd_array, first_offset, &first_flag, &c1);
        second_offset = get_next_bcd_digit(second_bcd_array, second_offset, &second_flag, &c2);

        if (c1 == 0x0F || c1 != c2)
        {
            return c1 - c2;
        }
        n--;
    }

    return c1 - c2;
}


/*****************************************************************************
 * FUNCTION
 *  compare_n_bcd_for_wild_char
 * DESCRIPTION
 *  Compare not more than `n' digits, or length of `first_bcd_array' (ie,
 *  number of digits before first 0xF is encountered), for `first_bcd_array'
 *  and `second_bcd_array', each digit is a 4-bits BCD digit.
 * PARAMETERS
 *  first_bcd_array         [?]         
 *  second_bcd_array        [?]         
 *  n                       [IN]        Compare at most n elements.
 *  bcd_array(?)            [IN]        BCD digit array
 *  istr(?)                 [IN]        Char array
 * RETURNS
 *  An 8-bits integer greater than, equal to, or less than 0, according as istr is greater than,
 *  equal to, or less than bcd_array.
 *****************************************************************************/
kal_int8 compare_n_bcd_for_wild_char(kal_uint8 *first_bcd_array, kal_uint8 *second_bcd_array, kal_uint16 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 c1 = 0;
    kal_uint8 c2 = 0;

    kal_bool first_flag = KAL_TRUE;
    kal_uint16 first_offset = 0;

    kal_bool second_flag = KAL_TRUE;
    kal_uint16 second_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n > 0)
    {
        first_offset = get_next_bcd_digit(first_bcd_array, first_offset, &first_flag, &c1);
        second_offset = get_next_bcd_digit(second_bcd_array, second_offset, &second_flag, &c2);

        if (c1 == 0x0D)
        {
            if (c2 == 0x0F)
            {
                break;
            }
            else
            {
                n--;
                continue;
            }
        }
        if (c1 == 0x0F || c1 != c2)
        {
            return c1 - c2;
        }
        n--;
    }

    if (c1 == 0x0D && c2 != 0x0F)
        return 0;

    return c1 - c2;
}

/*****************************************************************************
 * FUNCTION
 *  phb_compare_bcd_for_wild_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length1     [IN]        
 *  length2     [IN]        
 *  bcd1        [?]         
 *  bcd2        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool phb_compare_bcd_for_wild_char(kal_uint8 length1, kal_uint8 length2, kal_uint8 *bcd1, kal_uint8 *bcd2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i;
    kal_int16 j, match = 0, min_len;
    kal_int16 len1, len2;
    kal_uint8 temp1[MAX_CC_ADDR_LEN * 2], temp2[MAX_CC_ADDR_LEN * 2];
    kal_uint8 *temp1_number;
    kal_uint8 *temp2_number;
#ifndef __PHB_NUM_EXACT_MATCH__
    kal_uint8 condition;
#endif /* __PHB_NUM_EXACT_MATCH__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_COMPARE_BCD_FOR_WILD_CHAR);

    len1 = convert_to_digit(&bcd1[1], temp1);
    len2 = convert_to_digit(&bcd2[1], temp2);

    temp1_number = (kal_uint8*) temp1;
    temp2_number = (kal_uint8*) temp2;

#ifdef __PHB_NUM_EXACT_MATCH__

    if ((length1 != length2) || (len1 != len2))
    {
        return KAL_FALSE;
    }

    for (i = 0; i < len1; i++)
    {
        if ((temp1_number[i] != temp2_number[i]) && temp1_number[i] != 0x0D && temp2_number[i] != 0x0D)
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;

#else /* __PHB_NUM_EXACT_MATCH__ */ 
    /* Ignore *31# and #31# case */
    while (((temp1_number[0] == '*') || (temp1_number[0] == '#')) &&
           (temp1_number[1] == '3') && (temp1_number[2] == '1') && (temp1_number[3] == '#'))
    {
        temp1_number += 4;
        len1 -= 4;
    }
    while (((temp2_number[0] == '*') || (temp2_number[0] == '#')) &&
           (temp2_number[1] == '3') && (temp2_number[2] == '1') && (temp2_number[3] == '#'))
    {
        temp2_number += 4;
        len2 -= 4;
    }

    if (phb_ptr->compare_digit < 6 || phb_ptr->compare_digit > (MAX_CC_ADDR_LEN - 1))
    {
        condition = 6;
    }
    else
    {
        condition = phb_ptr->compare_digit;
    }

    if (len1 > len2)
    {
        min_len = len2;
    }
    else
    {
        min_len = len1;
    }

    for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (temp1_number[i] == temp2_number[j])
        {
            match++;
        }
        else
        {
            break;
        }
    }
    if (match >= condition || (match == min_len && len1 == len2))
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;

#endif /* __PHB_NUM_EXACT_MATCH__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  bcd_len
 * DESCRIPTION
 *  Calculate number of digits of 0xF terminated bcd_array.
 *  Scan not more than n bytes.
 * PARAMETERS
 *  bcd_array       [IN]        BCD digit array
 *  n               [IN]        Compare at most n elements.
 * RETURNS
 *  An 8-bits integer greater than, equal to, or less than 0, according as istr is greater than,
 *  equal to, or less than bcd_array.
 *****************************************************************************/
kal_int16 bcd_len(kal_uint8 *bcd_array, kal_uint16 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (len = 0; n > 0; --n)
    {
        if (phb_less_significant_nibble(*bcd_array) != 0x0F)
        {
            ++len;
        }
        else
        {
            break;
        }

        if (phb_more_significant_nibble(*bcd_array) != 0x0F)
        {
            ++len;
        }
        else
        {
            break;
        }

        ++bcd_array;
    }
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  bcd_exact_len
 * DESCRIPTION
 *  Calculate number of digits of 0xF terminated bcd_array.
 *  Scan not more than n bytes and stop until 0xF.
 * PARAMETERS
 *  bcd_array       [IN]        BCD digit array
 *  n               [IN]        Compare at most n elements.
 * RETURNS
 *  An 8-bits integer greater than, equal to, or less than 0, according as istr is greater than,
 *  equal to, or less than bcd_array.
 *****************************************************************************/
kal_int16 bcd_exact_len(kal_uint8 *bcd_array, kal_uint16 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (len = 0; n > 0; --n)
    {
        if (phb_less_significant_nibble(*bcd_array) != 0x0F)
        {
            ++len;
        }
        else
        {
            return len;
        }

        if (phb_more_significant_nibble(*bcd_array) != 0x0F)
        {
            ++len;
        }
        else
        {
           return len;
        }

        ++bcd_array;
    }
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  is_empty
 * DESCRIPTION
 *  Tests for a sequence of bytes is empty.
 *  For empty means that all bytes are 0x0F.
 * PARAMETERS
 *  ptr     [IN]        The byte sequence to test
 *  len     [IN]        Length of ptr
 * RETURNS
 *  KAL_TRUE if empty, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool is_empty(kal_uint8 *ptr, kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; ++i)
        if (*ptr++ != 0xFF)
        {
            return KAL_FALSE;
        }

    return KAL_TRUE;
}   /* end of is_empty */


/*****************************************************************************
 * FUNCTION
 *  phb_abs
 * DESCRIPTION
 *  Returns absolute value
 * PARAMETERS
 *  val     [IN]        The value to calculate its absolute value.
 * RETURNS
 *  Absolute value
 *****************************************************************************/
kal_uint32 phb_abs(kal_int32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (val < 0) ? ~val + 1 : val;
}   /* end of phb_abs */


/*****************************************************************************
 * FUNCTION
 *  binary_search
 * DESCRIPTION
 *  The generic binary search function.
 * PARAMETERS
 *  collection          [?]         
 *  low                 [IN]        
 *  high                [IN]        
 *  key                 [?]         
 *  compare_func        [IN]        
 * RETURNS
 *  If found, hit index to collection is returned;
 *  otherwise -1 is returned.
 *****************************************************************************/
int binary_search(void *collection[], int low, int high, void *key, bin_search_cmp_func_type compare_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;
    int mid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(compare_func != NULL);

    while (low <= high)
    {
        mid = (low + high) / 2;
        i = compare_func(collection, mid, key);
        if (i < 0)
        {
            low = mid + 1;
        }
        else if (i > 0)
        {
            high = mid - 1;
        }
        else
        {
            return (kal_uint16) mid;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  find_pinying_str_for_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2_code       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *find_pinying_str_for_ucs2(kal_uint16 ucs2_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}

/* MTK 2003-12-30 Wilson, For PinYin Sort and Search */


/*****************************************************************************
 * FUNCTION
 *  find_pinyin_str_for_ucs2_with_tone
 * DESCRIPTION
 *  Convert input Chinese Character to PinYin spelling, including tone.
 * PARAMETERS
 *  inputString         [?]     
 *  outputString        [?]     
 * RETURNS
 *  Return True if converted, else False.
 *****************************************************************************/
kal_bool find_pinyin_str_for_ucs2_with_tone(kal_uint8 *inputString, kal_uint8 *outputString)
{
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 in, out, i, flag;

#if defined(__PINYIN_SORTING_ZI__)
    kal_uint16 code;
    kal_uint8 pCharInfoBuffer[PHB_ALPHA_ID_DEPTH * 2];
#elif defined(__PINYIN_SORTING_KA__)
    kal_uint8 code[2];
    const kal_int8 *pCharInfoBuffer;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(outputString, 0, PHB_ALPHA_ID_DEPTH);
    flag = in = out = 0;

    while ((out < PHB_ALPHA_ID_DEPTH) && (in < PHB_ALPHA_ID_DEPTH) &&
           !((*inputString == 0) && (*(inputString + 1) == 0)))
    {
    #if defined(__PINYIN_SORTING_ZI__)
        code = *((kal_uint16*) inputString);
        code = (code << 8) | (code >> 8);

        if ((code >= 0x4e00) && (code <= 0x9fa5) &&
            Zi8GetCharInfo(code, (kal_uint16*) pCharInfoBuffer, PHB_ALPHA_ID_DEPTH * 2, 1))
    #elif defined(__PINYIN_SORTING_KA__)

        code[0] = inputString[1];
        code[1] = inputString[0];

        if ((pCharInfoBuffer = GetPYString(code)) != NULL)
    #endif 

        {
            i = 0;
            while ((pCharInfoBuffer[i] != 0x00) && (out < PHB_ALPHA_ID_DEPTH) && (i < PHB_ALPHA_ID_DEPTH * 2))
            {
                outputString[out] = pCharInfoBuffer[i];
                out++;
            #if defined(__PINYIN_SORTING_ZI__)
                i = i + 2;
            #elif defined(__PINYIN_SORTING_KA__)
                i = i + 1;
            #endif 
            }
            /* Add space between convert result for KA */
        #if defined(__PINYIN_SORTING_KA__)
            outputString[out++] = 0x20;
        #endif 
            flag = 1;
        }
        else    // if(*inputString == 0)    /*NOT a Chinese character, Is a ASCII character. Ex. 'A' "0x0041"*/
        {
            outputString[out] = *(inputString + 1);
            out++;
            /* Add space between convert result for KA */
        #if defined(__PINYIN_SORTING_KA__)
            outputString[out++] = 0x20;
        #endif 
        }

        in += 2;
        inputString += 2;

    }

    if (flag)
    {
        return KAL_TRUE;
    }
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 
    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  find_pinyin_str_for_ucs2_without_tone
 * DESCRIPTION
 *  Convert input Chinese Character to PinYin spelling, ignore tone.
 * PARAMETERS
 *  inputString         [?]     
 *  outputString        [?]     
 * RETURNS
 *  Return True if converted, else False.
 *****************************************************************************/
kal_bool find_pinyin_str_for_ucs2_without_tone(kal_uint8 *inputString, kal_uint8 *outputString)
{
#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 in, out, i, flag;

#if defined(__PINYIN_SORTING_ZI__)
    kal_uint16 code;
    kal_uint8 pCharInfoBuffer[PHB_ALPHA_ID_DEPTH * 2];
#elif defined(__PINYIN_SORTING_KA__)
    kal_uint8 code[2];
    const kal_int8 *pCharInfoBuffer;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(outputString, 0, PHB_ALPHA_ID_DEPTH);
    flag = in = out = 0;

    while ((out < PHB_ALPHA_ID_DEPTH) && (in < PHB_ALPHA_ID_DEPTH) &&
           !((*inputString == 0) && (*(inputString + 1) == 0)))
    {
    #if defined(__PINYIN_SORTING_ZI__)
        code = *((kal_uint16*) inputString);
        code = (code << 8) | (code >> 8);

        if ((code >= 0x4e00) && (code <= 0x9fa5) &&
            Zi8GetCharInfo(code, (kal_uint16*) pCharInfoBuffer, PHB_ALPHA_ID_DEPTH * 2, 1))
    #elif defined(__PINYIN_SORTING_KA__)

        code[0] = inputString[1];
        code[1] = inputString[0];

        if ((pCharInfoBuffer = GetPYString(code)) != NULL)
    #endif 
        {
            i = 0;
            while ((pCharInfoBuffer[i] != 0x00) && (out < PHB_ALPHA_ID_DEPTH) &&
                   (i < PHB_ALPHA_ID_DEPTH * 2) &&
                   pCharInfoBuffer[i] != '1' && pCharInfoBuffer[i] != '2' &&
                   pCharInfoBuffer[i] != '3' && pCharInfoBuffer[i] != '4' && pCharInfoBuffer[i] != '5')
            {
                outputString[out] = pCharInfoBuffer[i];
                out++;
            #if defined(__PINYIN_SORTING_ZI__)
                i = i + 2;
            #elif defined(__PINYIN_SORTING_KA__)
                i = i + 1;
            #endif 
            }
            /* Add space between convert result for KA */
        #if defined(__PINYIN_SORTING_KA__)
            outputString[out++] = 0x20;
        #endif 
            flag = 1;
        }
        else    // if(*inputString == 0)    /*NOT a Chinese character, Is a ASCII character. Ex. 'A' "0x0041"*/
        {
            outputString[out] = *(inputString + 1);
            out++;
            /* Add space between convert result for KA */
        #if defined(__PINYIN_SORTING_KA__)
            outputString[out++] = 0x20;
        #endif 
        }

        in += 2;
        inputString += 2;
    }

    if (flag)
    {
        return KAL_TRUE;
    }
#endif /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */ 
    return KAL_FALSE;

}

/* END of MTK 2003-12-30 Wilson */


/*****************************************************************************
 * FUNCTION
 *  phb_is_prefix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  target          [?]     
 *  candidate       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool phb_is_prefix(alpha_id_type *target, alpha_id_type *candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_uint8 compare_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (target->length > candidate->length)
    {
        compare_length = candidate->length; /* candidate->length should be 1 */
    }
    else
    {
        compare_length = target->length;
    }
    for (i = 0; i < compare_length; i++)
        if (target->data[i] != candidate->data[i])
        {
            return KAL_FALSE;
        }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_which_sim_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 phb_which_sim_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__GEMINI__) || defined(GEMINI_PLUS)
    return (phb_current_mod - MOD_PHB);
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  phb_which_sim_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  
 *****************************************************************************/
phb_storage_enum phb_which_sim_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__GEMINI__) || defined(GEMINI_PLUS)
    switch (phb_current_mod)
    {
    #if defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3)
        case MOD_PHB_3:
            return PHB_STORAGE_SIM3;
    
    #if defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4)
        case MOD_PHB_4:
            return PHB_STORAGE_SIM4;
    #endif
    #endif
    
    #ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
    #endif
    
        case MOD_PHB:
        default:
            return PHB_STORAGE_SIM;
    }
#else
    return PHB_STORAGE_SIM;
#endif /* __GEMINI__ */
}


/*****************************************************************************
 * FUNCTION
 *  phb_util_is_usim
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 phb_util_is_usim(kal_uint8 sim_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PHB_USIM_SUPPORT__
    {
    #if defined(__GEMINI__) || defined(GEMINI_PLUS)
        return is_usim_type((sim_interface_enum)sim_num);
    #else
        return is_usim_type();
    #endif /* __GEMINI__ */
    }
#else
    {
        return KAL_FALSE;
    }
#endif /* __PHB_USIM_SUPPORT__ */
}
phb_type_enum phb_util_get_type(kal_uint16 file_idx)
{
    switch (file_idx)
    {
        case FILE_ECC_IDX:
        case FILE_U_ECC_IDX:
            return PHB_ECC;

        case FILE_FDN_IDX:
        case FILE_U_FDN_IDX:
            return PHB_FDN;

        case FILE_BDN_IDX:
        case FILE_U_BDN_IDX:
            return PHB_BDN;
            
        case FILE_MSISDN_IDX:
        case FILE_U_MSISDN_IDX:
            return PHB_MSISDN;

        case FILE_SDN_IDX:
        case FILE_U_SDN_IDX:
            return PHB_SDN;


        case FILE_ADN_IDX:
        case FILE_G_ADN_IDX:
        case FILE_U_ADN_IDX:
            return PHB_PHONEBOOK;
            
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_AAS_IDX:
        case FILE_U_AAS_IDX:
            return PHB_AAS;
            
        case FILE_G_GAS_IDX:
        case FILE_U_GAS_IDX:
            return PHB_GAS;
    #endif
        default:
            return PHB_NONE;

    }
}

