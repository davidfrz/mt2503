/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_bytestream.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Bytestream. Abstract file and memory data source.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "kal_trace.h"
#include "kal_release.h"
#include "kal_general_types.h"
#include "MMI_fw_trc.h"
#include "gdi_trc.h"
#include "setjmp.h"
#include "string.h"
#include "fs_errcode.h"
#include "fs_type.h"

#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "gdi_bytestream.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_lfs.h"
#include "gdi_primitive.h"

#if defined(__MTK_TARGET__)
#pragma arm section zidata = "CACHEDZI",  rwdata = "CACHEDRW" 
#endif

/* Function pointer */
/* will point to different function depends on bytestream source */
U8(*gdi_bytestream_get_byte) (void);
U8(*gdi_bytestream_peek_byte) (void);
U8(*gdi_bytestream_peek_byte_n) (int index);
U16(*gdi_bytestream_get_word) (void);
U32(*gdi_bytestream_get_3bytes) (void);
U32(*gdi_bytestream_get_dword) (void);
void (*gdi_bytestream_get_array) (U8 *array, U32 size);
void (*gdi_bytestream_flush) (U32 count);
void (*gdi_bytestream_seek) (S32 offset);

S32(*gdi_bytestream_tell) (void);
U32(*gdi_bytestream_get_size) (void);
BOOL(*gdi_bytestream_is_eof) (void);    /* Deprecated. We use longjmp() to handle truncated data source. */

/* following used when source is from memory */
static U8 *gdi_bytestream_cache_buf_ptr;
static U32 gdi_bytestream_cache_size;
static U32 gdi_bytestream_cache_offset;

/* following used when source is from file */
int gdi_bytestream_file_size;
int gdi_bytestream_handle;

int gdi_bytestream_buffer_content_size;
int gdi_bytestream_file_offset;
U8 *gdi_bytestream_buffer_reader;

/* Common bytestream data */
typedef enum
{
    GDI_BYTESTREAM_TYPE_NONE,
    GDI_BYTESTREAM_TYPE_MEM,
    GDI_BYTESTREAM_TYPE_FILE
} gdi_bytestream_type_enum;

gdi_bytestream_type_enum gdi_bytestream_source_type = GDI_BYTESTREAM_TYPE_NONE;

/* buffer and buffer size */
/* This buffer could be assigned by gdi_bytestream_create_file_ext() or use default buf(gdi_bytestream_buffer[]) */
U8 *gdi_bytestream_buffer_ptr;
U32 gdi_bytestream_buffer_ptr_size;

#if defined(__MTK_TARGET__)
#pragma arm section zidata, rwdata
#endif



/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_free
 * DESCRIPTION
 *  free a bytestream
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_bytestream_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_source_type == GDI_BYTESTREAM_TYPE_FILE)
    {
        gdi_free_ext_mem((void **)&gdi_bytestream_buffer_ptr);
        gdi_lfs_close(gdi_bytestream_handle);
    }
    else
    {
        GDI_ASSERT(gdi_bytestream_source_type == GDI_BYTESTREAM_TYPE_MEM);
    }

    gdi_bytestream_source_type = GDI_BYTESTREAM_TYPE_NONE;

    return GDI_SUCCEED;
}

/* Start of internal RAM */
#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE"
#endif 


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_byte_mem
 * DESCRIPTION
 *  get a byte from memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U8, return value get from bytestream
 *****************************************************************************/
static U8 gdi_bytestream_get_byte_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 v = (U8) gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_cache_offset <= gdi_bytestream_cache_size)
    {
        return v;
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_30,//"GDI_RAISE gdi_bytestream_get_byte_mem %d/%d",
                            gdi_bytestream_cache_offset,gdi_bytestream_cache_size);
        GDI_RAISE(1);
        return 0;   /* Unreached */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_peek_byte_mem
 * DESCRIPTION
 *  peek a byte from memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U8, return value get from bytestream, 0 if fail
 *****************************************************************************/
U8 gdi_bytestream_peek_byte_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_cache_offset + 1 <= gdi_bytestream_cache_size)
    {
        return (U8) gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset];
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_31,//"GDI_RAISE gdi_bytestream_peek_byte_mem %d/%d",
                   gdi_bytestream_cache_offset+1,gdi_bytestream_cache_size);

        GDI_RAISE(1);
        return 0;   /* Unreached */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_peek_byte_n_mem
 * DESCRIPTION
 *  peek one byte after n bytes
 * PARAMETERS
 *  index       [IN]    index of the byte want to peek, reference to current position
 * RETURNS
 *  U8, return value get from bytestream, 0 if fail
 *****************************************************************************/
U8 gdi_bytestream_peek_byte_n_mem(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int offset = gdi_bytestream_cache_offset + index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (offset + 1 <= (int)gdi_bytestream_cache_size)
    {
        return (U8) gdi_bytestream_cache_buf_ptr[offset];
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_32,//"GDI_RAISE gdi_bytestream_peek_byte_n_mem %d/%d",
                                            offset+1,gdi_bytestream_cache_size);
        
        GDI_RAISE(1);
        return 0;   /* Unreached */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_word_mem
 * DESCRIPTION
 *  peek a word from memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U16, return value get from bytestream, 0 if fail
 *****************************************************************************/
U16 gdi_bytestream_get_word_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 byte0;
    U32 byte1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte0 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];
    byte1 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];

    if (gdi_bytestream_cache_offset <= gdi_bytestream_cache_size)
    {
        return ((U16) ((byte1 << 8) | byte0));
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_33,//"GDI_RAISE gdi_bytestream_get_word_mem %d/%d",
                            gdi_bytestream_cache_offset,gdi_bytestream_cache_size);
  
        GDI_RAISE(1);
        return 0;   /* Unreached */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_3bytes_mem
 * DESCRIPTION
 *  peek a word from memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U16, return value get from bytestream, 0 if fail
 *****************************************************************************/
U32 gdi_bytestream_get_3bytes_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 byte0;
    U32 byte1;
    U32 byte2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte0 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];
    byte1 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];
    byte2 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];

    if (gdi_bytestream_cache_offset <= gdi_bytestream_cache_size)
    {
        return ((U32) ((byte2 << 16) | (byte1 << 8) | byte0));
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_34,//"GDI_RAISE gdi_bytestream_get_3bytes_mem %d/%d",
                            gdi_bytestream_cache_offset,gdi_bytestream_cache_size);
  
        GDI_RAISE(1);
        return 0;   /* Unreached */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_dword_mem
 * DESCRIPTION
 *  peek a U32 from memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U32, return value get from bytestream, 0 if fail
 *****************************************************************************/
U32 gdi_bytestream_get_dword_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 byte0;
    U32 byte1;
    U32 byte2;
    U32 byte3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte0 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];
    byte1 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];
    byte2 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];
    byte3 = gdi_bytestream_cache_buf_ptr[gdi_bytestream_cache_offset++];

    if (gdi_bytestream_cache_offset <= gdi_bytestream_cache_size)
    {
        return ((U32) (byte3 << 24)) | ((U32) (byte2 << 16)) | ((U32) (byte1 << 8)) | (U32) (byte0);
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_35,//"GDI_RAISE gdi_bytestream_get_dword_mem %d/%d",
                            gdi_bytestream_cache_offset,gdi_bytestream_cache_size);
  
        GDI_RAISE(1);
        return 0;   /* Unreached code */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_array_mem
 * DESCRIPTION
 *  read to array
 * PARAMETERS
 *  array       [IN]   read data to this array      
 *  size        [IN]   size need to read     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_bytestream_get_array_mem(U8 *array, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_cache_offset + size <= gdi_bytestream_cache_size)
    {
        memcpy(array, gdi_bytestream_cache_buf_ptr + gdi_bytestream_cache_offset, size);
        gdi_bytestream_cache_offset += size;
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_36,//"GDI_RAISE gdi_bytestream_get_array_mem %d/%d",
                            gdi_bytestream_cache_offset+size,gdi_bytestream_cache_size);
  
        GDI_RAISE(1);
        return; /* Unreached code */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_is_eof_mem
 * DESCRIPTION
 *  chcek if is eof
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL, return true if it's eof of mem, false if not
 *****************************************************************************/
BOOL gdi_bytestream_is_eof_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (BOOL) (gdi_bytestream_cache_offset >= gdi_bytestream_cache_size);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_flush_mem
 * DESCRIPTION
 *  flush memory
 * PARAMETERS
 *  count       [IN]    size to flush
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_bytestream_flush_mem(U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* It allows to stop at the end of stream plus one byte */
    if ((gdi_bytestream_cache_offset += count) > gdi_bytestream_cache_size)
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_37,//"GDI_RAISE gdi_bytestream_flush_mem %d/%d",
                            gdi_bytestream_cache_offset,gdi_bytestream_cache_size);
  
        GDI_RAISE(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_seek_mem
 * DESCRIPTION
 *  seek memory
 * PARAMETERS
 *  offset      [IN]    seek to this position in memory    
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_bytestream_seek_mem(S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* It allows to stop at the end of stream plus one byte */
    if (offset <= (S32) gdi_bytestream_cache_size)
    {
        gdi_bytestream_cache_offset = offset;
    }
    else
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_38,//"GDI_RAISE gdi_bytestream_seek_mem %d/%d",
                            offset,gdi_bytestream_cache_size);
  
        GDI_RAISE(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_tell_mem
 * DESCRIPTION
 *  get the current position to read
 * PARAMETERS
 *  void
 * RETURNS
 *  S32, return current position
 *****************************************************************************/
S32 gdi_bytestream_tell_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_bytestream_cache_offset;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_size_mem
 * DESCRIPTION
 *  get size of memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U32, return size of memory
 *****************************************************************************/
U32 gdi_bytestream_get_size_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_bytestream_cache_size;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_buffer_load_file
 * DESCRIPTION
 *  read data from file to buffer
 * PARAMETERS
 *  at_least        [IN]    the size of read data must larger than this value
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_bytestream_buffer_load_file(int at_least)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = gdi_bytestream_buffer_content_size;
    if (offset)
    {
        memcpy(gdi_bytestream_buffer_ptr, gdi_bytestream_buffer_reader, gdi_bytestream_buffer_content_size);
    }

    if ((gdi_lfs_read(
            gdi_bytestream_handle,
            gdi_bytestream_buffer_ptr + offset,
            gdi_bytestream_buffer_ptr_size - offset,
            (U32*) & gdi_bytestream_buffer_content_size) == FS_NO_ERROR)
        && gdi_bytestream_buffer_content_size > 0)
    {
        gdi_bytestream_buffer_reader = gdi_bytestream_buffer_ptr;
        gdi_bytestream_buffer_content_size += offset;

        if (gdi_bytestream_buffer_content_size >= at_least)
        {
            return;
        }
    }
    GDI_TRACE(GDI_TRC, GDI_TRC_39,//"GDI_RAISE gdi_bytestream_buffer_load_file %d/%d",
                        gdi_bytestream_buffer_content_size,at_least);

    GDI_RAISE(1);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_buffer_load_file_widthout_exception
 * DESCRIPTION
 *  read data from file to buffer
 * PARAMETERS
 *  at_least        [IN]    the size of read data must larger than this value
 * RETURNS
 *  BOOL, return TRUE if succeed, FALSE if fail
 *****************************************************************************/
BOOL gdi_bytestream_buffer_load_file_widthout_exception(int at_least)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = gdi_bytestream_buffer_content_size;
    if (offset)
    {
        memcpy(gdi_bytestream_buffer_ptr, gdi_bytestream_buffer_reader, gdi_bytestream_buffer_content_size);
    }

    if ((gdi_lfs_read(
            gdi_bytestream_handle,
            gdi_bytestream_buffer_ptr + offset,
            gdi_bytestream_buffer_ptr_size - offset,
            (U32*) & gdi_bytestream_buffer_content_size) == FS_NO_ERROR)
        && gdi_bytestream_buffer_content_size > 0)
    {
        gdi_bytestream_buffer_reader = gdi_bytestream_buffer_ptr;
        gdi_bytestream_buffer_content_size += offset;

        if (gdi_bytestream_buffer_content_size >= at_least)
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_byte_file
 * DESCRIPTION
 *  get a byte from file
 * PARAMETERS
 *  void
 * RETURNS
 *  U8, return value get from bytestream
 *****************************************************************************/
U8 gdi_bytestream_get_byte_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(gdi_bytestream_buffer_content_size))
    {
        gdi_bytestream_buffer_load_file(1);
    }

    gdi_bytestream_buffer_content_size--;

    gdi_bytestream_file_offset++;

    return *gdi_bytestream_buffer_reader++;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_peek_byte_file
 * DESCRIPTION
 *  peek a byte from file
 * PARAMETERS
 *  void
 * RETURNS
 *  U8, return value get from bytestream
 *****************************************************************************/
U8 gdi_bytestream_peek_byte_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gdi_bytestream_buffer_content_size)
    {
        gdi_bytestream_buffer_load_file(1);
    }

    return *gdi_bytestream_buffer_reader;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_peek_byte_n_file
 * DESCRIPTION
 *  peek n byte from file
 * PARAMETERS
 *  index       [IN]    index of the byte want to peek, reference to current position
 * RETURNS
 *  U8, return value get from bytestream
 *****************************************************************************/
U8 gdi_bytestream_peek_byte_n_file(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_buffer_content_size < index)
    {
        gdi_bytestream_buffer_load_file(index);
    }

    return gdi_bytestream_buffer_reader[index];
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_word_file
 * DESCRIPTION
 *  peek a word from file (16 bit)
 * PARAMETERS
 *  void
 * RETURNS
 *  U16, return value get from bytestream
 *****************************************************************************/
U16 gdi_bytestream_get_word_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_buffer_content_size < 2)
    {
        gdi_bytestream_buffer_load_file(2);
    }

    gdi_bytestream_buffer_content_size -= 2;
    gdi_bytestream_file_offset += 2;

    result = *gdi_bytestream_buffer_reader++;
    result |= (*gdi_bytestream_buffer_reader++) << 8;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_3bytes_file
 * DESCRIPTION
 *  peek a word from file (16 bit)
 * PARAMETERS
 *  void
 * RETURNS
 *  U16, return value get from bytestream
 *****************************************************************************/
U32 gdi_bytestream_get_3bytes_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_buffer_content_size < 3)
    {
        gdi_bytestream_buffer_load_file(3);
    }

    gdi_bytestream_buffer_content_size -= 3;
    gdi_bytestream_file_offset += 3;

    result = *gdi_bytestream_buffer_reader++;
    result |= (*gdi_bytestream_buffer_reader++) << 8;
    result |= (*gdi_bytestream_buffer_reader++) << 16;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_dword_file
 * DESCRIPTION
 *  get a U32 from file (32 bit)
 * PARAMETERS
 *  void
 * RETURNS
 *  U32, return value get from bytestream
 *****************************************************************************/
U32 gdi_bytestream_get_dword_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_buffer_content_size < 4)
    {
        gdi_bytestream_buffer_load_file(4);
    }

    gdi_bytestream_buffer_content_size -= 4;
    gdi_bytestream_file_offset += 4;

    result = *gdi_bytestream_buffer_reader++;
    result |= (*gdi_bytestream_buffer_reader++) << 8;
    result |= (*gdi_bytestream_buffer_reader++) << 16;
    result |= (*gdi_bytestream_buffer_reader++) << 24;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_array_file
 * DESCRIPTION
 *  get a kal_uint32 from file (32 bit)
 * PARAMETERS
 *  array       [IN]   read data to this array      
 *  size        [IN]   size need to read
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_bytestream_get_array_file(U8 *array, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (size > 0)
    {
        int n;

        if (gdi_bytestream_buffer_content_size == 0)
        {
            gdi_bytestream_buffer_load_file(1);
        }

        n = GDI_MIN((int)size, gdi_bytestream_buffer_content_size);
        memcpy(array, gdi_bytestream_buffer_reader, n);
        array += n;
        gdi_bytestream_buffer_content_size -= n;
        size -= n;
        gdi_bytestream_file_offset += n;
        gdi_bytestream_buffer_reader += n;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_is_eof_file
 * DESCRIPTION
 *  check is eof
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL, return TRUE if it's eof of mem, FALSE if not
 *****************************************************************************/
BOOL gdi_bytestream_is_eof_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_bytestream_buffer_content_size)
    {
        return FALSE;
    }

    if (gdi_bytestream_buffer_load_file_widthout_exception(1))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_seek_file
 * DESCRIPTION
 *  seek file bytestream
 * PARAMETERS
 *  offset      [IN]    seek to this position in memory
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_bytestream_seek_file(S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_lfs_seek(gdi_bytestream_handle, offset, FS_FILE_BEGIN);
    gdi_bytestream_buffer_content_size = 0;
    gdi_bytestream_file_offset = offset;

    if ((ret < 0) || (ret != (int)offset))
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_40,//"GDI_RAISE gdi_bytestream_seek_file %d/%d",
                            ret,offset);
  
        GDI_RAISE(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_flush_file
 * DESCRIPTION
 *  flush file bytestream
 * PARAMETERS
 *  count       [IN]    size to flush
 * RETURNS
 *  void
 *****************************************************************************/
/* Note: FSAL does not check the availability of data until issuing read/write operations */
void gdi_bytestream_flush_file(U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_bytestream_file_offset += count;
    if (count >= gdi_bytestream_buffer_ptr_size)
    {
        gdi_bytestream_seek_file(gdi_bytestream_file_offset);
        return;
    }
    while (count)
    {
        if (gdi_bytestream_buffer_content_size < (int)count)
        {
            count -= gdi_bytestream_buffer_content_size;
            gdi_bytestream_buffer_content_size = 0;
            gdi_bytestream_buffer_load_file(1);
        }
        else
        {
            gdi_bytestream_buffer_content_size -= count;
            gdi_bytestream_buffer_reader += count;
            count = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_tell_file
 * DESCRIPTION
 *  tell file bytestream
 * PARAMETERS
 *  void
 * RETURNS
 *  S32, return current position
 *****************************************************************************/
S32 gdi_bytestream_tell_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_bytestream_file_offset;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_get_size_file
 * DESCRIPTION
 *  get size of file bytestream
 * PARAMETERS
 *  void
 * RETURNS
 *  U32, return file size
 *****************************************************************************/
U32 gdi_bytestream_get_size_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_bytestream_file_size;
}

/* End of Internal SRAM */
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_create
 * DESCRIPTION
 *  create a memory bytestream
 * PARAMETERS
 *  buf_ptr         [IN]    the memory pointer want to bind to bytestream
 *  buf_size        [IN]    size of the memory
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *              GDI_BYTESTREAM_ERR_OPEN_BUFFER_FAILED if false
 *****************************************************************************/
GDI_RESULT gdi_bytestream_create(U8 *buf_ptr, U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if someone didnt free bytestream correctly */
    GDI_ASSERT(gdi_bytestream_source_type == GDI_BYTESTREAM_TYPE_NONE);

    if (buf_ptr == NULL)
    {
        return GDI_BYTESTREAM_ERR_OPEN_BUFFER_FAILED;
    }

    gdi_bytestream_cache_size = buf_size;
    gdi_bytestream_cache_offset = 0;
    gdi_bytestream_cache_buf_ptr = buf_ptr;

    gdi_bytestream_get_byte = gdi_bytestream_get_byte_mem;
    gdi_bytestream_peek_byte = gdi_bytestream_peek_byte_mem;
    gdi_bytestream_peek_byte_n = gdi_bytestream_peek_byte_n_mem;
    gdi_bytestream_get_word = gdi_bytestream_get_word_mem;
    gdi_bytestream_get_3bytes = gdi_bytestream_get_3bytes_mem;
    gdi_bytestream_get_dword = gdi_bytestream_get_dword_mem;
    gdi_bytestream_get_array = gdi_bytestream_get_array_mem;
    gdi_bytestream_flush = gdi_bytestream_flush_mem;
    gdi_bytestream_is_eof = gdi_bytestream_is_eof_mem;
    gdi_bytestream_seek = gdi_bytestream_seek_mem;
    gdi_bytestream_tell = gdi_bytestream_tell_mem;
    gdi_bytestream_get_size = gdi_bytestream_get_size_mem;

    /* flag to check if someone didnt call free */
    gdi_bytestream_source_type = GDI_BYTESTREAM_TYPE_MEM;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_create_file_ext
 * DESCRIPTION
 *  create a file bytestream
 * PARAMETERS
 *  file_name       [IN]    the file name of file want to bind to bytestream
 *  file_buf        [IN]    buffer to store data read frome file
 *  file_buf_size   [IN]    size of file_buf
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *              GDI_BYTESTREAM_ERR_OPEN_BUFFER_FAILED if false
 *****************************************************************************/
GDI_RESULT gdi_bytestream_create_file_ext(
            const S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if someone didnt free bytestream correctly */
    GDI_ASSERT(gdi_bytestream_source_type == GDI_BYTESTREAM_TYPE_NONE);

    if (file_name == NULL)
    {
        return GDI_BYTESTREAM_ERR_OPEN_FILE_FAILED;
    }

    gdi_bytestream_handle = gdi_lfs_open(gdi_lfs_handle,(U16*) file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, 0);
    if (gdi_bytestream_handle < 0)
    {
        return GDI_BYTESTREAM_ERR_OPEN_FILE_FAILED;
    }
    gdi_bytestream_handle = gdi_lfs_handle;

    gdi_bytestream_buffer_ptr_size = BYTESTREAM_BUFFER_SIZE;
    gdi_bytestream_buffer_ptr = gdi_alloc_ext_mem_cacheable(gdi_bytestream_buffer_ptr_size);
    if (gdi_bytestream_buffer_ptr == NULL)
    {
            return GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH;
    }
    
    gdi_bytestream_buffer_reader = gdi_bytestream_buffer_ptr;
    gdi_bytestream_buffer_content_size = 0;
    gdi_bytestream_file_offset = 0;
    if (gdi_lfs_file_size(gdi_bytestream_handle, (U32*) & gdi_bytestream_file_size) < 0)
    {
        gdi_bytestream_file_size = 0;
    }

    gdi_bytestream_get_byte = gdi_bytestream_get_byte_file;
    gdi_bytestream_peek_byte = gdi_bytestream_peek_byte_file;
    gdi_bytestream_peek_byte_n = gdi_bytestream_peek_byte_n_file;
    gdi_bytestream_get_word = gdi_bytestream_get_word_file;
    gdi_bytestream_get_3bytes = gdi_bytestream_get_3bytes_file;
    gdi_bytestream_get_dword = gdi_bytestream_get_dword_file;
    gdi_bytestream_get_array = gdi_bytestream_get_array_file;
    gdi_bytestream_flush = gdi_bytestream_flush_file;
    gdi_bytestream_is_eof = gdi_bytestream_is_eof_file;
    gdi_bytestream_seek = gdi_bytestream_seek_file;
    gdi_bytestream_tell = gdi_bytestream_tell_file;
    gdi_bytestream_get_size = gdi_bytestream_get_size_file;

    /* flag to check if someone didnt call free */
    gdi_bytestream_source_type = GDI_BYTESTREAM_TYPE_FILE;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_bytestream_create_file
 * DESCRIPTION
 *  create a file bytestream
 * PARAMETERS
 *  file_name       [IN]    the file name of file want to bind to bytestream
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *              GDI_BYTESTREAM_ERR_OPEN_BUFFER_FAILED if false
 *****************************************************************************/
GDI_RESULT gdi_bytestream_create_file(const S8 *file_name)
{
    return gdi_bytestream_create_file_ext(file_name);
}



