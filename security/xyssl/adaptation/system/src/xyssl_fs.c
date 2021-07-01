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
 * xyssl_fs.c
 *
 * Project:
 * --------
 *   OpenSSL
 *
 * Description:
 * ------------
 *   This is file is used to adapt the File System APIs in OpenSSL
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
     /* KAL - RTOS Abstraction Layer */
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_api.h"

#include "stdlib.h"
#include "string.h"         /* size_t */
#include "app_str.h"        /* app string lib for ucs2 APIs */
/* trace include files */
#include "kal_trace.h"
#include "xyssl_defs.h"
#include "xyssl_fs.h"

static int xyssl_adp_getmode(const char *mode, kal_uint32 *flag);
static kal_uint8 xyssl_unicode_to_ucs2encoding(kal_wchar unicode, kal_uint8 *charLength, kal_uint8 *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 status = 1;
    kal_uint8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (arrOut != 0)
    {

        if (unicode < 256)
        {
            arrOut[index++] = *((kal_uint8*) (&unicode));
            arrOut[index] = 0;

        }
        else
        {
            arrOut[index++] = *((kal_uint8*) (&unicode));
            arrOut[index] = *(((kal_uint8*) (&unicode)) + 1);

        }
        *charLength = 2;
    }
    else
    {

        status = 0;
    }

#ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
    if (arrOut != 0)
    {

        if (unicode < 256)
        {
            arrOut[index++] = 0;    /* *((kal_uint8*)(&unicode)); */
            arrOut[index] = *((kal_uint8*) (&unicode));

        }
        else
        {
            arrOut[index++] = *(((kal_uint8*) (&unicode)) + 1);        /* *((kal_uint8*)(&unicode)); */
            arrOut[index] = *((kal_uint8*) (&unicode)); /* *(((kal_uint8*)(&unicode)) + 1); */

        }
        *charLength = 2;
    }
    else
    {

        status = 0;
    }
#endif /* __FOR_TESTING */ 

    return status;
}


static kal_uint16 xyssl_asc_str_to_ucs2_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int16 count = -1;
    kal_uint8 charLen = 0;
    kal_uint8 arrOut[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pInBuffer != '\0')
    {

        xyssl_unicode_to_ucs2encoding((kal_wchar) (*((kal_uint8 *)pInBuffer)), &charLen, arrOut);

        // #ifdef MMI_ON_WIN32
        pOutBuffer[++count] = arrOut[0];
        pOutBuffer[++count] = arrOut[1];
        pInBuffer++;
        // #endif

    #ifdef __FOR_TESTING    /* MMI_ON_HARDWARE_P */
        pOutBuffer[++count] = arrOut[1];    /* arrOut[0]; */
        pOutBuffer[++count] = arrOut[0];    /* arrOut[1]; */
        pInBuffer++;
    #endif /* __FOR_TESTING */ 

    }

    pOutBuffer[++count] = '\0';
    pOutBuffer[++count] = '\0';
    return count + 1;
}


/****************************************************************************
* EXPORT APIs
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_stat
 * DESCRIPTION
 *  This function is to adapt the stat to kal system
 * PARAMETERS
 *  *file_path        [IN]  file path to check existence
 *  *stat_t           [IN]  useless in kal porting which is used for save file 
                            attributes in UNIX system and not supported in KAL
 * RETURNS
 *    0 : file exists
 *   -1 : something wrong
 *****************************************************************************/
int xyssl_adp_stat(char *file_path, char* stat_t)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    kal_wchar *ucs2_file;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_file = get_ctrl_buffer((XYSSL_ADP_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    memset(ucs2_file, 0, (XYSSL_ADP_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    xyssl_asc_str_to_ucs2_str((kal_int8*)ucs2_file, (kal_int8*)file_path);

    /* try to check the specified file */
    ret = FS_GetAttributes((const kal_wchar*)ucs2_file);
    free_ctrl_buffer(ucs2_file);
    if (ret < FS_NO_ERROR)
    {
        return -1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fopen
 * DESCRIPTION
 *  opens the file whose name is the string pointed to by filename 
 *  and associates a file handle with it
 * PARAMETERS
 *  *filename      [IN]  the name of the file to open/create
 *  *mode          [IN]  points to a string beginning with one of the following
                         sequences
        "r"  Open text file for reading.
        "w"  Truncate file to zero length or create text file for writing.
        "b"  means binary file, either as a last character or as a character 
             between the characters in any of the two-character strings 
             described above. 
 * RETURNS
 *   >= 0 : file handle
 *   < 0 : open failed
 *****************************************************************************/
FS_HANDLE xyssl_adp_fopen(const char *filename, const char *mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file;
    kal_uint32 flag = 0;
    kal_wchar *ucs2_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check filename and mode first */
    if (filename == NULL || (!xyssl_adp_getmode(mode, &flag)))
    {
        return (FS_HANDLE)-1;
    }

    ucs2_file = get_ctrl_buffer((XYSSL_ADP_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    memset(ucs2_file, 0, (XYSSL_ADP_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    xyssl_asc_str_to_ucs2_str((kal_int8*)ucs2_file, (kal_int8*)filename);

    file = FS_Open((const WCHAR *)ucs2_file, flag);
    free_ctrl_buffer(ucs2_file);
    if (file < 0)
    {
        return (FS_HANDLE)-1;
    }
    return file;
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fclose
 * DESCRIPTION
 *  closes an open file
 * PARAMETERS
 *  *file      [IN]  Must have been assigned in a previous successful call to 
 *                   FS_Open.
 * RETURNS
 *  FS_NO_ERROR : close success
 *   < 0        : close failed
 *****************************************************************************/
int xyssl_adp_fclose(FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR == FS_Close(file))
        return 1;
    return 0;    
}


/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fread
 * DESCRIPTION
 *  reads file data
 * PARAMETERS
 *  *outptr     [IN/OUT]    buffer pointer for storing read data
 *  size        [IN]        identify the size bytes of nitems.
 *  nitems      [IN]        reads nitems objects, each size bytes long
 *  file        [IN]        specified file to read
 * RETURNS
 *   > 0 : number of objects read
 *   < 0 : FS error
 *****************************************************************************/
int xyssl_adp_fread(void *outptr, size_t size, size_t nitems, FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  read;
    kal_int32   ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (( ret = FS_Read(file, outptr, (size * nitems), &read))!= FS_NO_ERROR)
    {
        return ret;
    }
    return (int)read;
}


/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fwrite
 * DESCRIPTION
 *  writes file data
 * PARAMETERS
 *  *intptr     [IN/OUT]    buffer pointer for storing read data
 *  size        [IN]        identify the size bytes of nitems.
 *  nitems      [IN]        writes nitems objects, each size bytes long
 *  file        [IN]        specified file to write
 * RETURNS
 *   > 0 : number of objects write
 *   < 0 : FS error
 *****************************************************************************/
int xyssl_adp_fwrite(const void *inptr, size_t nitems, size_t size, FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  written;
    kal_int32   ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (( ret = FS_Write(file, (void*)inptr, (size * nitems), &written))!= FS_NO_ERROR)
    {
        return ret;
    }
    return (int)written;
}


/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fseek
 * DESCRIPTION
 *  Repositions a file pointer and possibly extends a file.
 *  The new position, measured in bytes, is obtained by adding offset bytes 
 *  to the position specified by whence.
 * PARAMETERS
 *  file        [IN]    specified file to seek
 *  offset      [IN]    adding bytes
 *  whence      [IN]    start position
 * RETURNS
 *   > 0 : number of objects write
 *   < 0 : FS error
 *****************************************************************************/
int xyssl_adp_fseek(FS_HANDLE file, long offset, int whence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 _whence;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (whence)
    {
        case 0:
            _whence = FS_FILE_BEGIN;
            break;			
        case 1:
            _whence = FS_FILE_CURRENT;
            break;
        case 2:
            _whence = FS_FILE_END;
			break;
        default:
            return -1;
    }

    if (FS_Seek(file, (int)offset, _whence) < FS_NO_ERROR)
    {
        return -1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_feof
 * DESCRIPTION
 *  to test the file pointer at eof or not
 * PARAMETERS
 *  file        [IN]    specified file to test eof
 * RETURNS
 *   1 : yes or error happened
 *   0 : otherwise
 *****************************************************************************/
int xyssl_adp_feof(FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  position, size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* query and compare current file position and file size */
    FS_GetFilePosition(file, &position);
    FS_GetFileSize(file, &size);

    if (position >= size)
    {
        return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fsize
 * DESCRIPTION
 *  to get the file size
 * PARAMETERS
 *  file        [IN]    specified file to query size
 * RETURNS
 *   file size
 *****************************************************************************/
int xyssl_adp_fsize(FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* query and compare current file position and file size */   
    FS_GetFileSize(file, &size);
    return (int)size;
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_ftell
 * DESCRIPTION
 *  to get the current value of file position of given file
 * PARAMETERS
 *  file        [IN]    specified file to tell
 * RETURNS
 *   file position
 *****************************************************************************/
long xyssl_adp_ftell(FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     kal_uint32  position;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/    
     FS_GetFilePosition(file, &position);    
     return (long)position;
}


/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fflush
 * DESCRIPTION
 *  forces a write of all buffered data for the given output
 * PARAMETERS
 *  file        [IN]    specified file to flush
 * RETURNS
 *   0  :   success
 *   -1 :   error case
 *****************************************************************************/
int xyssl_adp_fflush(FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_Commit(file) == FS_NO_ERROR)
    {
        return 0;
    }
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_fgets
 * DESCRIPTION
 *  reads in at most one less than size characters from file and stores them 
 *  into the buffer pointed to by buf. 
 *  Reading stops after an EOF or a newline. If a newline is read, 
 *  it is stored into the buffer. A '\0' is stored after the last character 
 *  in the buffer.
 * PARAMETERS
 *  buf     [IN/OUT]    provided buffer
 *  size    [IN]        specified size to get data
 *  file    [IN]        specified file to get data
 * RETURNS
 *   buf  :   success
 *   NULL :   error case or start from EOF
 *****************************************************************************/
char* xyssl_adp_fgets(char *buf, int size, FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  read;
    kal_int32   ret = 0;
    kal_char    *p = buf;
    kal_char    c = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check parameters */
    if (xyssl_adp_feof(file) || buf == NULL || size <= 0)
    {
        return NULL;
    }

    /* size until n-1, read until EOF or error */
    while ( --size > 0 &&
            ((ret = FS_Read(file, &c, 1, &read)) == FS_NO_ERROR) && 
            read == 1)
    {
        /* newline char read */
        if((*p++ = c) == '\n')
        {
            break;
        }        
    }

    if (ret < 0 ||      /* file error */
        (read != 1 && p == buf))    /* start from EOF */
    {
        return NULL;
    }    
    *p = '\0';
    return buf;
}

/****************************************************************************
* STATIC APIs
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_getmode
 * DESCRIPTION
 *  convert the given file mode string into FS flag
 * PARAMETERS
 *  *mode      [IN]     file mode string
 *  *flag      [IN\OUT] flag to save the mode settings 
 * RETURNS
 *   1 : convert process success
 *   0 : convert process failed
 ******************************************************************************/
int xyssl_adp_getmode(const char *mode, kal_uint32 *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mode == NULL || flag == NULL)
    {
        goto badmode;
    }
    memset(flag, 0, sizeof(*flag));

    /* handle the mode settings (max currently: wb) */
    for (i = 0; i < 2; i++, mode++)
    {
        switch(*mode)
        {
            /* mode end */
            case '\0':       
              break;
            /* ignore currently */
            case 'b':       
              continue;
            case 'w':
              *flag = (FS_READ_WRITE | FS_CREATE_ALWAYS);
              continue;
            case 'r':
              *flag = FS_READ_ONLY;
              continue;
            default:
              goto badmode;
        }
    }
    /* without read or write flag... --> error setting */
    if (!((*flag) & FS_READ_ONLY) && !((*flag) & FS_CREATE_ALWAYS))
    {
        goto badmode;
    }
    return 1;

badmode:
    return 0;
}
