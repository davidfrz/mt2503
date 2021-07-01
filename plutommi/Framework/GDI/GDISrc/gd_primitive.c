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

/*******************************************************************************
 * Filename:
 * ---------
 *  gd_primitive.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GD Primitive related.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "gd_primitive.h"

#include "kal_release.h"
#include "kal_general_types.h"
#include "lcd_sw_rnd.h"

#include "gdi_primitive.h"
#include "gdi_include.h"
#include "gdi_datatype.h"
#include "gd_include.h"

const unsigned short gd_sqrt[1025] = 
{
    1024, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
    1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
    1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
    1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023,
    1023, 1023, 1023, 1023, 1023, 1023, 1022, 1022, 1022, 1022,
    1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
    1022, 1022, 1022, 1022, 1021, 1021, 1021, 1021, 1021, 1021,
    1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1020,
    1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020,
    1020, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019,
    1019, 1019, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018,
    1018, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017,
    1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1015, 1015,
    1015, 1015, 1015, 1015, 1015, 1015, 1014, 1014, 1014, 1014,
    1014, 1014, 1014, 1013, 1013, 1013, 1013, 1013, 1013, 1013,
    1012, 1012, 1012, 1012, 1012, 1012, 1012, 1011, 1011, 1011,
    1011, 1011, 1011, 1010, 1010, 1010, 1010, 1010, 1010, 1009,
    1009, 1009, 1009, 1009, 1009, 1008, 1008, 1008, 1008, 1008,
    1008, 1007, 1007, 1007, 1007, 1007, 1006, 1006, 1006, 1006,
    1006, 1006, 1005, 1005, 1005, 1005, 1005, 1004, 1004, 1004,
    1004, 1004, 1003, 1003, 1003, 1003, 1003, 1002, 1002, 1002,
    1002, 1002, 1001, 1001, 1001, 1001, 1000, 1000, 1000, 1000,
    1000, 999, 999, 999, 999, 998, 998, 998, 998, 998,
    997, 997, 997, 997, 996, 996, 996, 996, 995, 995,
    995, 995, 994, 994, 994, 994, 994, 993, 993, 993,
    993, 992, 992, 992, 991, 991, 991, 991, 990, 990,
    990, 990, 989, 989, 989, 989, 988, 988, 988, 988,
    987, 987, 987, 986, 986, 986, 986, 985, 985, 985,
    984, 984, 984, 984, 983, 983, 983, 982, 982, 982,
    982, 981, 981, 981, 980, 980, 980, 979, 979, 979,
    979, 978, 978, 978, 977, 977, 977, 976, 976, 976,
    975, 975, 975, 974, 974, 974, 974, 973, 973, 973,
    972, 972, 972, 971, 971, 971, 970, 970, 970, 969,
    969, 969, 968, 968, 967, 967, 967, 966, 966, 966,
    965, 965, 965, 964, 964, 964, 963, 963, 963, 962,
    962, 961, 961, 961, 960, 960, 960, 959, 959, 959,
    958, 958, 957, 957, 957, 956, 956, 955, 955, 955,
    954, 954, 954, 953, 953, 952, 952, 952, 951, 951,
    950, 950, 950, 949, 949, 948, 948, 948, 947, 947,
    946, 946, 945, 945, 945, 944, 944, 943, 943, 943,
    942, 942, 941, 941, 940, 940, 940, 939, 939, 938,
    938, 937, 937, 937, 936, 936, 935, 935, 934, 934,
    933, 933, 933, 932, 932, 931, 931, 930, 930, 929,
    929, 928, 928, 927, 927, 927, 926, 926, 925, 925,
    924, 924, 923, 923, 922, 922, 921, 921, 920, 920,
    919, 919, 918, 918, 917, 917, 916, 916, 915, 915,
    914, 914, 913, 913, 912, 912, 911, 911, 910, 910,
    909, 909, 908, 908, 907, 907, 906, 906, 905, 905,
    904, 903, 903, 902, 902, 901, 901, 900, 900, 899,
    899, 898, 898, 897, 896, 896, 895, 895, 894, 894,
    893, 893, 892, 891, 891, 890, 890, 889, 889, 888,
    887, 887, 886, 886, 885, 885, 884, 883, 883, 882,
    882, 881, 880, 880, 879, 879, 878, 877, 877, 876,
    876, 875, 874, 874, 873, 873, 872, 871, 871, 870,
    870, 869, 868, 868, 867, 866, 866, 865, 865, 864,
    863, 863, 862, 861, 861, 860, 859, 859, 858, 857,
    857, 856, 855, 855, 854, 854, 853, 852, 852, 851,
    850, 850, 849, 848, 847, 847, 846, 845, 845, 844,
    843, 843, 842, 841, 841, 840, 839, 839, 838, 837,
    836, 836, 835, 834, 834, 833, 832, 831, 831, 830,
    829, 829, 828, 827, 826, 826, 825, 824, 823, 823,
    822, 821, 820, 820, 819, 818, 817, 817, 816, 815,
    814, 814, 813, 812, 811, 811, 810, 809, 808, 808,
    807, 806, 805, 804, 804, 803, 802, 801, 800, 800,
    799, 798, 797, 796, 796, 795, 794, 793, 792, 792,
    791, 790, 789, 788, 787, 787, 786, 785, 784, 783,
    782, 782, 781, 780, 779, 778, 777, 776, 776, 775,
    774, 773, 772, 771, 770, 770, 769, 768, 767, 766,
    765, 764, 763, 762, 762, 761, 760, 759, 758, 757,
    756, 755, 754, 753, 752, 752, 751, 750, 749, 748,
    747, 746, 745, 744, 743, 742, 741, 740, 739, 738,
    737, 736, 735, 734, 734, 733, 732, 731, 730, 729,
    728, 727, 726, 725, 724, 723, 722, 721, 720, 719,
    718, 717, 716, 715, 714, 712, 711, 710, 709, 708,
    707, 706, 705, 704, 703, 702, 701, 700, 699, 698,
    697, 696, 695, 693, 692, 691, 690, 689, 688, 687,
    686, 685, 684, 682, 681, 680, 679, 678, 677, 676,
    675, 673, 672, 671, 670, 669, 668, 666, 665, 664,
    663, 662, 661, 659, 658, 657, 656, 655, 653, 652,
    651, 650, 649, 647, 646, 645, 644, 642, 641, 640,
    639, 637, 636, 635, 634, 632, 631, 630, 629, 627,
    626, 625, 623, 622, 621, 619, 618, 617, 615, 614,
    613, 611, 610, 609, 607, 606, 605, 603, 602, 601,
    599, 598, 596, 595, 594, 592, 591, 589, 588, 587,
    585, 584, 582, 581, 579, 578, 576, 575, 573, 572,
    571, 569, 568, 566, 565, 563, 561, 560, 558, 557,
    555, 554, 552, 551, 549, 548, 546, 544, 543, 541,
    540, 538, 536, 535, 533, 531, 530, 528, 526, 525,
    523, 521, 520, 518, 516, 515, 513, 511, 509, 508,
    506, 504, 502, 501, 499, 497, 495, 493, 492, 490,
    488, 486, 484, 482, 480, 479, 477, 475, 473, 471,
    469, 467, 465, 463, 461, 459, 457, 455, 453, 451,
    449, 447, 445, 443, 441, 439, 437, 435, 432, 430,
    428, 426, 424, 422, 419, 417, 415, 413, 410, 408,
    406, 403, 401, 399, 396, 394, 391, 389, 387, 384,
    382, 379, 377, 374, 372, 369, 366, 364, 361, 359,
    356, 353, 350, 348, 345, 342, 339, 336, 333, 331,
    328, 325, 322, 319, 316, 312, 309, 306, 303, 300,
    296, 293, 290, 286, 283, 279, 276, 272, 269, 265,
    261, 257, 253, 250, 246, 241, 237, 233, 229, 224,
    220, 215, 211, 206, 201, 196, 191, 185, 180, 174,
    168, 162, 156, 149, 142, 135, 127, 119, 110, 101,
    90, 78, 63, 45, 0
};

const unsigned short gd_sin_table[91] = 
{
    0, 17, 35, 53, 71, 89, 107, 124, 142, 160,
    177, 195, 212, 230, 247, 265, 282, 299, 316, 333,
    350, 366, 383, 400, 416, 432, 448, 464, 480, 496,
    511, 527, 542, 557, 572, 587, 601, 616, 630, 644,
    658, 671, 685, 698, 711, 724, 736, 748, 760, 772,
    784, 795, 806, 817, 828, 838, 848, 858, 868, 877,
    886, 895, 904, 912, 920, 928, 935, 942, 949, 955,
    962, 968, 973, 979, 984, 989, 993, 997, 1001, 1005,
    1008, 1011, 1014, 1016, 1018, 1020, 1021, 1022, 1023, 1023,
    1024
};

const unsigned short gd_tan_table[91] = 
{
    0, 17, 35, 53, 71, 89, 107, 125, 143, 162,
    180, 199, 217, 236, 255, 274, 293, 313, 332, 352,
    372, 393, 413, 434, 455, 477, 499, 521, 544, 567,
    591, 615, 639, 664, 690, 717, 743, 771, 800, 829,
    859, 890, 922, 954, 988, 1023, 1060, 1098, 1137, 1177,
    1220, 1264, 1310, 1358, 1409, 1462, 1518, 1576, 1638, 1704,
    1773, 1847, 1925, 2009, 2099, 2195, 2299, 2412, 2534, 2667,
    2813, 2973, 3151, 3349, 3571, 3821, 4107, 4435, 4817, 5268,
    5807, 6465, 7286, 8339, 9742, 11704, 14643, 19539, 29323, 58664,
    0
};

const gd_draw_line_func gd_draw_line[] = 
{
    gd_draw_line16
};

const gd_draw_rect_func gd_draw_rect[] = 
{
    gd_draw_rect16
};

const gd_fill_rect_func gd_fill_rect[] = 
{
    gd_fill_rect16
};

const gd_draw_round_rect_func gd_draw_round_rect[] = 
{
    gd_draw_round_rect16
};

const gd_fill_round_rect_func gd_fill_round_rect[] = 
{
    gd_fill_round_rect16
};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
const gd_draw_ellipse_func gd_draw_ellipse[] = 
{
    gd_draw_ellipse16
};

const gd_fill_ellipse_func gd_fill_ellipse[] = 
{
    gd_fill_ellipse16
};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  gdi_atan
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sita        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gdi_atan(int sita)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int low = 0, up = 90, spec = 45, binary = 1, sitaValue = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (binary)
    {
        if (sita > gd_tan_table[spec])
        {
            up = up;
            low = spec;
        }
        else if (sita < gd_tan_table[spec])
        {
            up = spec;
            low = low;
        }
        else if (sita == gd_tan_table[spec])
        {
            sitaValue = spec;
            binary = 0;
        }

        if ((up - low) == 1)
        {
            sitaValue = low;
            binary = 0;
        }
        else
        {
            spec = ((up - low) >> 1) + low;
        }

    }
    return sitaValue;
}


/*****************************************************************************
 * FUNCTION
 *  gd_null_pointer_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gd_null_pointer_function(void)
{
    //GDI_DEBUG_ASSERT(0);
}


gdi_color gd_color_from_rgb_uyvy422(U32 A, U32 R, U32 G, U32 B)
{
    /* Only support black color */
    return 0x0080;
}



const kal_uint8 SubLCDSetArray[] =
{
    0x01,    // 0000 0001
    0x02,    // 0000 0010
    0x04,    // 0000 0100
    0x08,    // 0000 1000
    0x10,    // 0001 0000
    0x20,    // 0010 0000
    0x40,    // 0100 0000
    0x80,    // 1000 0000
};
const kal_uint8 SubLCDReSetArray[] =
{
    0xFE,    // 1111 1110
    0xFD,    // 1111 1101
    0xFB,    // 1111 1011
    0xF7,    // 1111 0111
    0xEF,    // 1110 1111
    0xDF,    // 1101 1111
    0xBF,    // 1011 1111
    0x7F,    // 0111 1111
};
#if defined(GDI_USE_RGB565_TO_SHOW_BW)

#define  GDI_RGB_TO_HW_1(R,G,B) ((R)==0xFF && (G)==0xFF && (B)==0xFF)?0:1 //( ((U16)(((S32)(R)+(S32)(G)+(S32)(B))/(S32)3)>=0x80)? 0:1 )
#define  GDI_HW_TO_RGB_R_1(VALUE) ( (U8)((VALUE) ? 0xFF:0x00) )
#define  GDI_HW_TO_RGB_G_1(VALUE) ( (U8)((VALUE) ? 0xFF:0x00) )
#define  GDI_HW_TO_RGB_B_1(VALUE) ( (U8)((VALUE) ? 0xFF:0x00) )
#ifdef MMI_ON_HARDWARE_P
void  GDI_GET_BUFFER_PIXEL_1(S32 X,S32 Y, U32 *VALUE)
{
    (*VALUE= ( (*((U8*)GDI_LAYER.act_buf_ptr+(((Y)*LCD_WIDTH/8)+(X)/8))) & SubLCDSetArray[(X)%8] )? 1:0);
}
void  GDI_SET_BUFFER_PIXEL_1(S32 X, S32 Y, U32 VALUE)
{   
    ((VALUE)?((*((U8*)GDI_LAYER.act_buf_ptr+(((Y)*LCD_WIDTH/8)+(X)/8)))|= SubLCDSetArray[(X)%8]): ((*((U8*)GDI_LAYER.act_buf_ptr+(((Y)*LCD_WIDTH/8) + (X)/8))) &= SubLCDReSetArray[(X)%8]));
}


#define GDI_GET_BUFFER_PIXEL_EXT_1(X,Y,VALUE,BUF,PITCH)		(VALUE= ( (*((U8*)BUF+(((Y)/8)*PITCH+(X)/8))) & SubLCDSetArray[(X)%8] )?0x0000:0xFFFF)
#define GDI_SET_BUFFER_PIXEL_EXT_1(X,Y,VALUE,BUF,PITCH)		(((VALUE)<=0)?((*((U8*)BUF+(((Y)/8)*PITCH+X)))|= SubLCDSetArray[(X)%8]): ((*((U8*)BUF+(((Y)/8)*PITCH+(X)/8))) &= SubLCDReSetArray[(X)%8]))


#else
#define  GDI_GET_BUFFER_PIXEL_1(X,Y,VALUE) (VALUE= ((*((U8*)GDI_LAYER.act_buf_ptr+(((Y)/8)+X*(LCD_HEIGHT/8)))) &SubLCDSetArray[(Y)%8] )?0xFFFF:0x00)
#define  GDI_SET_BUFFER_PIXEL_1(X,Y,VALUE)(((VALUE)<=0)?((*((U8*)GDI_LAYER.act_buf_ptr+(((Y)/8)+X*(LCD_HEIGHT/8))))|=SubLCDSetArray[(Y)%8]):((*((U8*)GDI_LAYER.act_buf_ptr+((Y/8)+(LCD_HEIGHT/8)*X))) &=SubLCDReSetArray[(Y)%8]))
#define GDI_GET_BUFFER_PIXEL_EXT_1(X,Y,VALUE,BUF,PITCH)		(VALUE= ((*((U8*)BUF+(((Y)/8)+X*(PITCH/8)))) &SubLCDSetArray[(Y)%8] )?0xFFFF:0x00)
#define GDI_SET_BUFFER_PIXEL_EXT_1(X,Y,VALUE,BUF,PITCH)		(((VALUE)<=0)?((*((U8*)BUF+(((Y)/8)+X*(PITCH/8))))|=SubLCDSetArray[(Y)%8]):((*((U8*)BUF+((Y/8)+(PITCH/8)*X))) &=SubLCDReSetArray[(Y)%8]))

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define gd_replace_src_key_1 gd_null_pointer_function
#define gd_resize_bitblt_1 gd_null_pointer_function
#define gd_bitblt_1 gd_null_pointer_function
#define gd_memset_1 gd_null_pointer_function
#define gd_fill_dot_rect_1 gd_null_pointer_function
#define gd_image_bits_draw_1 gd_null_pointer_function


/*****************************************************************************
 * FUNCTION
 *  gd_color_from_rgb_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  A       [IN]        
 *  R       [IN]        
 *  G       [IN]        
 *  B       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_color_from_rgb_1(U32 A, U32 R, U32 G, U32 B)
{
    return (GDI_RGB_TO_HW_1(R, G, B));
}


/*****************************************************************************
 * FUNCTION
 *  gd_color_to_rgb_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  A       [?]         
 *  R       [?]         
 *  G       [?]         
 *  B       [?]         
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_color_to_rgb_1(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{
    *A = 0xFF;
    *R = GDI_HW_TO_RGB_R_1(c);
    *G = GDI_HW_TO_RGB_G_1(c);
    *B = GDI_HW_TO_RGB_B_1(c);
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_pixel_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_get_pixel_1(int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_BUFFER_PIXEL_1(x, y, &c);
    return c;
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_pixel_1(int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_SET_BUFFER_PIXEL_1(x, y, c);
}

/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_to_layer_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_pixel_to_layer_1(gdi_handle layer_handle, int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(0);
}

/*****************************************************************************
 * FUNCTION
 *  gd_get_buf_pixel_1
 *****************************************************************************/
gdi_color gd_get_buf_pixel_1(U8 *buf_ptr, U32 buf_width, int x, int y)
{
    gdi_color color;
    
    GDI_GET_BUFFER_PIXEL_EXT_1(x, y, color, buf_ptr, buf_width);
    return color;
}

/*****************************************************************************
 * FUNCTION
 *  gd_put_buf_pixel_1
 *****************************************************************************/
void gd_put_buf_pixel_1(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c)
{
    GDI_SET_BUFFER_PIXEL_EXT_1(x, y, c, buf_ptr, buf_width);
}
#endif


#if GDI_MAINLCD_BIT_PER_PIXEL == 1 || !defined(GDI_USING_LAYER)


/*****************************************************************************
 * FUNCTION
 *  gd_color_from_rgb_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  A       [IN]        
 *  R       [IN]        
 *  G       [IN]        
 *  B       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_color_from_rgb_main(U32 A, U32 R, U32 G, U32 B)
{
    return (DRV_RGB_TO_HW(R, G, B));
}


/*****************************************************************************
 * FUNCTION
 *  gd_color_to_rgb_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  A       [?]         
 *  R       [?]         
 *  G       [?]         
 *  B       [?]         
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_color_to_rgb_main(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{
    *A = 0xFF;
    *R = DRV_HW_TO_RGB_R(c);
    *G = DRV_HW_TO_RGB_G(c);
    *B = DRV_HW_TO_RGB_B(c);
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_pixel_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_get_pixel_main(int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRV_MAINLCD_GET_BUFFER_PIXEL(x, y, c);
    return c;
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_pixel_main(int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRV_MAINLCD_SET_BUFFER_PIXEL(x, y, c);
}

/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_to_layer_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_pixel_to_layer_main(gdi_handle layer_handle, int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_DEBUG_ASSERT(0);
}

/*****************************************************************************
 * FUNCTION
 *  gd_get_buf_pixel_main
 *****************************************************************************/
gdi_color gd_get_buf_pixel_main(U8 *buf_ptr, U32 buf_width, int x, int y)
{
    gdi_color color;
    
    DRV_MAINLCD_GET_BUFFER_PIXEL_EXT(x, y, color, buf_ptr, buf_width);
    return color;
}

/*****************************************************************************
 * FUNCTION
 *  gd_put_buf_pixel_main
 *****************************************************************************/
void gd_put_buf_pixel_main(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c)
{
    DRV_MAINLCD_SET_BUFFER_PIXEL_EXT(x, y, c, buf_ptr, buf_width);
}

#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
#define gd_color_from_rgb_main      GD_FUNC_16(gd_color_from_rgb)
#define gd_color_to_rgb_main        GD_FUNC_16(gd_color_to_rgb)
#define gd_get_pixel_main           GD_FUNC_16(gd_get_pixel)
#define gd_put_pixel_main           GD_FUNC_16(gd_put_pixel)
#define gd_put_pixel_to_layer_main  GD_FUNC_16(gd_put_pixel_to_layer)
#define gd_get_buf_pixel_main       GD_FUNC_16(gd_get_buf_pixel)
#define gd_put_buf_pixel_main       GD_FUNC_16(gd_get_buf_pixel)
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
#define gd_color_from_rgb_main      GD_FUNC_24(gd_color_from_rgb)
#define gd_color_to_rgb_main        GD_FUNC_24(gd_color_to_rgb)
#define gd_get_pixel_main           GD_FUNC_24(gd_get_pixel)
#define gd_put_pixel_main           GD_FUNC_24(gd_put_pixel)
#define gd_put_pixel_to_layer_main  GD_FUNC_24(gd_put_pixel_to_layer)
#define gd_get_buf_pixel_main       GD_FUNC_24(gd_get_buf_pixel)
#define gd_put_buf_pixel_main       GD_FUNC_24(gd_get_buf_pixel)
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
#define gd_color_from_rgb_main      GD_FUNC_32(gd_color_from_rgb)
#define gd_color_to_rgb_main        GD_FUNC_32(gd_color_to_rgb)
#define gd_get_pixel_main           GD_FUNC_32(gd_get_pixel)
#define gd_put_pixel_main           GD_FUNC_32(gd_put_pixel)
#define gd_put_pixel_to_layer_main  GD_FUNC_32(gd_put_pixel_to_layer)
#define gd_get_buf_pixel_main       GD_FUNC_32(gd_get_buf_pixel)
#define gd_put_buf_pixel_main       GD_FUNC_32(gd_get_buf_pixel)
#endif 

#ifndef __MMI_SUBLCD__
#define gd_color_from_rgb_sub       gd_null_pointer_function
#define gd_color_to_rgb_sub         gd_null_pointer_function
#define gd_get_pixel_sub            gd_null_pointer_function
#define gd_put_pixel_sub            gd_null_pointer_function
#define gd_put_pixel_to_layer_sub   gd_null_pointer_function
#define gd_get_buf_pixel_sub        gd_null_pointer_function
#define gd_put_buf_pixel_sub        gd_null_pointer_function
#elif GDI_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gd_color_from_rgb_sub
 * DESCRIPTION
 *****************************************************************************/
gdi_color gd_color_from_rgb_sub(U32 A, U32 R, U32 G, U32 B)
{
    return (SUBMMI_RGB_TO_HW_FORMAT(R, G, B));
}


/*****************************************************************************
 * FUNCTION
 *  gd_color_to_rgb_sub
 * DESCRIPTION
 *****************************************************************************/
void gd_color_to_rgb_sub(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{
    *A = 0xFF;
    *R = HW_FORMAT_TO_SUBMMI_R(c);
    *G = HW_FORMAT_TO_SUBMMI_G(c);
    *B = HW_FORMAT_TO_SUBMMI_B(c);
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_pixel_sub
 * DESCRIPTION
 *****************************************************************************/
gdi_color gd_get_pixel_sub(int x, int y)
{
    gdi_color c;
    DRV_SUBLCD_GET_BUFFER_PIXEL(x, y, c);
    return c;
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_sub
 *****************************************************************************/
void gd_put_pixel_sub(int x, int y, gdi_color c)
{
    DRV_SUBLCD_SET_BUFFER_PIXEL(x, y, c);
}

/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_sub
 *****************************************************************************/
void gd_put_pixel_to_layer_sub(gdi_handle layer_handle, int x, int y, gdi_color c)
{
    GDI_DEBUG_ASSERT(0);
}

/*****************************************************************************
 * FUNCTION
 *  gd_get_buf_pixel_sub
 *****************************************************************************/
gdi_color gd_get_buf_pixel_sub(U8 *buf_ptr, U32 buf_width, int x, int y)
{
    gdi_color color;
    
    DRV_SUBLCD_GET_BUFFER_PIXEL_EXT(x, y, color, buf_ptr, buf_width);
    return color;
}

/*****************************************************************************
 * FUNCTION
 *  gd_put_buf_pixel_sub
 *****************************************************************************/
void gd_put_buf_pixel_sub(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c)
{
    DRV_SUBLCD_SET_BUFFER_PIXEL_EXT(x, y, c, buf_ptr, buf_width);
}


#elif GDI_SUBLCD_BIT_PER_PIXEL == 16
#define gd_color_from_rgb_sub       GD_FUNC_16(gd_color_from_rgb)
#define gd_color_to_rgb_sub         GD_FUNC_16(gd_color_to_rgb)
#define gd_get_pixel_sub            GD_FUNC_16(gd_get_pixel)
#define gd_put_pixel_sub            GD_FUNC_16(gd_put_pixel)
#define gd_put_pixel_to_layer_sub   GD_FUNC_16(gd_put_pixel_to_layer)
#define gd_get_buf_pixel_sub        GD_FUNC_16(gd_get_buf_pixel)
#define gd_put_buf_pixel_sub        GD_FUNC_16(gd_put_buf_pixel)
#elif GDI_SUBLCD_BIT_PER_PIXEL == 24
#define gd_color_from_rgb_sub       GD_FUNC_24(gd_color_from_rgb)
#define gd_color_to_rgb_sub         GD_FUNC_24(gd_color_to_rgb)
#define gd_get_pixel_sub            GD_FUNC_24(gd_get_pixel)
#define gd_put_pixel_sub            GD_FUNC_24(gd_put_pixel)
#define gd_put_pixel_to_layer_sub   GD_FUNC_24(gd_put_pixel_to_layer)
#define gd_get_buf_pixel_sub        GD_FUNC_24(gd_get_buf_pixel)
#define gd_put_buf_pixel_sub        GD_FUNC_24(gd_put_buf_pixel)
#elif GDI_SUBLCD_BIT_PER_PIXEL == 32
#define gd_color_from_rgb_sub       GD_FUNC_32(gd_color_from_rgb)
#define gd_color_to_rgb_sub         GD_FUNC_32(gd_color_to_rgb)
#define gd_get_pixel_sub            GD_FUNC_32(gd_get_pixel)
#define gd_put_pixel_sub            GD_FUNC_32(gd_put_pixel)
#define gd_put_pixel_to_layer_sub   GD_FUNC_32(gd_put_pixel_to_layer)
#define gd_get_buf_pixel_sub        GD_FUNC_32(gd_get_buf_pixel)
#define gd_put_buf_pixel_sub        GD_FUNC_32(gd_put_buf_pixel)
#endif 

///////////////////////////////////////////////////////////////////////////////////
// define the default main func
///////////////////////////////////////////////////////////////////////////////////
#if GDI_MAINLCD_BIT_PER_PIXEL == 1 || !defined(GDI_USING_LAYER)
    #define GD_FUNC_MAIN(NAME)       (NAME##_func) gd_null_pointer_function    
#elif GDI_MAINLCD_BIT_PER_PIXEL == 8
    #define GD_FUNC_MAIN(NAME)       GD_FUNC_8(NAME)
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
    #define GD_FUNC_MAIN(NAME)       GD_FUNC_16(NAME)
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
    #define GD_FUNC_MAIN(NAME)       GD_FUNC_24(NAME)
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
    #define GD_FUNC_MAIN(NAME)       GD_FUNC_32(NAME)
#else
    #error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif

///////////////////////////////////////////////////////////////////////////////////
// define the default sub func
///////////////////////////////////////////////////////////////////////////////////
#if !defined(__MMI_SUBLCD__) || GDI_SUBLCD_BIT_PER_PIXEL == 1 || !defined(GDI_USING_LAYER)
    #define GD_FUNC_SUB(NAME)       (NAME##_func) gd_null_pointer_function
#elif GDI_SUBLCD_BIT_PER_PIXEL == 8
    #define GD_FUNC_SUB(NAME)       GD_FUNC_8(NAME)
#elif GDI_SUBLCD_BIT_PER_PIXEL == 16
    #define GD_FUNC_SUB(NAME)       GD_FUNC_16(NAME)
#elif GDI_SUBLCD_BIT_PER_PIXEL == 24
    #define GD_FUNC_SUB(NAME)       GD_FUNC_24(NAME)
#elif GDI_SUBLCD_BIT_PER_PIXEL == 32
    #define GD_FUNC_SUB(NAME)       GD_FUNC_32(NAME)
#else
    #error "Unknown SUBLCD_BIT_PER_PIXEL"
#endif

///////////////////////////////////////////////////////////////////////////////////
// define the default color format function
///////////////////////////////////////////////////////////////////////////////////
#if defined(GDI_USE_RGB565_TO_SHOW_BW)
#define GD_FUNC_1(NAME)         (NAME##_func) NAME##_1 //gd_null_pointer_function
#else
#define GD_FUNC_1(NAME)         (NAME##_func) gd_null_pointer_function
#endif
#define GD_FUNC_8(NAME)         (NAME##_func) NAME##_8
#define GD_FUNC_16(NAME)        (NAME##_func) NAME##_16
#define GD_FUNC_24(NAME)        (NAME##_func) NAME##_24
#define GD_FUNC_32(NAME)        (NAME##_func) NAME##_32
#define GD_FUNC_32PARGB(NAME)   (NAME##_func) NAME##_32PARGB
#define GD_FUNC_UYVY422(NAME)   (NAME##_func) gd_null_pointer_function
#define GD_FUNC_A8(NAME)        (NAME##_func) NAME##_8

#ifdef GDI_LAYER_PARGB6666_SUPPORT
#define GD_FUNC_PARGB6666(NAME) (NAME##_func) NAME##_PARGB6666
#else
#define GD_FUNC_PARGB6666(NAME) (NAME##_func) gd_null_pointer_function
#endif

/* Venus requires 32-bit layer support even without HW support. */
#if !defined(GDI_USING_LAYER_COLOR_FORMAT) && !defined(__VENUS_UI_ENGINE__)
    //#if GDI_MAINLCD_BIT_PER_PIXEL != 8 && GDI_SUBLCD_BIT_PER_PIXEL != 8
    //#undef  GD_FUNC_8
    //#define GD_FUNC_8(NAME)         (NAME##_func) gd_null_pointer_function
    //#endif
    //#if GDI_MAINLCD_BIT_PER_PIXEL != 16 && GDI_SUBLCD_BIT_PER_PIXEL != 16
    //#undef  GD_FUNC_16
    //#define GD_FUNC_16(NAME)        (NAME##_func) gd_null_pointer_function
    //#endif
    #if GDI_MAINLCD_BIT_PER_PIXEL != 24 && (!defined(GDI_SUBLCD_BIT_PER_PIXEL) || (GDI_SUBLCD_BIT_PER_PIXEL != 24))
    #undef  GD_FUNC_24
    #define GD_FUNC_24(NAME)        (NAME##_func) gd_null_pointer_function
    #endif
    #if GDI_MAINLCD_BIT_PER_PIXEL != 32 && (!defined(GDI_SUBLCD_BIT_PER_PIXEL) || (GDI_SUBLCD_BIT_PER_PIXEL != 32))
    #undef  GD_FUNC_32
    #define GD_FUNC_32(NAME)        (NAME##_func) gd_null_pointer_function
    #endif

    #undef  GD_FUNC_32PARGB
    #define GD_FUNC_32PARGB(NAME)   (NAME##_func) gd_null_pointer_function
    
#endif /* !defined(GDI_USING_LAYER_COLOR_FORMAT) && !defined(__VENUS_UI_ENGINE__) */

/* Convert color from ARGB8888 */
const gd_color_from_rgb_func gd_color_from_rgb[] = 
{
    GD_FUNC_1       (gd_color_from_rgb),            /* 1 */
    GD_FUNC_8       (gd_color_from_rgb),            /* 8 */
    GD_FUNC_16      (gd_color_from_rgb),            /* 16 */
    GD_FUNC_24      (gd_color_from_rgb),            /* 24 */
    GD_FUNC_32      (gd_color_from_rgb),            /* 32 */
    GD_FUNC_32PARGB (gd_color_from_rgb),            /* 32PARGB */
    gd_color_from_rgb_uyvy422,                      /* UYVY422 work around for gdi_layer_clear */
    GD_FUNC_A8      (gd_color_from_rgb),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_color_from_rgb),
#endif
    (gd_color_from_rgb_func)gd_color_from_rgb_main, /* main */
    (gd_color_from_rgb_func)gd_color_from_rgb_sub   /* sub */
};

/* Convert color to ARGB8888 */
const gd_color_to_rgb_func gd_color_to_rgb[] = 
{
    GD_FUNC_1       (gd_color_to_rgb),          /* 1 */
    GD_FUNC_8       (gd_color_to_rgb),          /* 8 */
    GD_FUNC_16      (gd_color_to_rgb),          /* 16 */
    GD_FUNC_24      (gd_color_to_rgb),          /* 24 */
    GD_FUNC_32      (gd_color_to_rgb),          /* 32 */
    GD_FUNC_32PARGB (gd_color_to_rgb),          /* 32PARGB */
    GD_FUNC_UYVY422 (gd_color_to_rgb),          /* UYVY422 */
    GD_FUNC_A8      (gd_color_to_rgb),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_color_to_rgb),
#endif
    (gd_color_to_rgb_func)gd_color_to_rgb_main, /* main */
    (gd_color_to_rgb_func)gd_color_to_rgb_sub   /* sub */
};

const gd_get_pixel_func gd_get_pixel[] = 
{
    GD_FUNC_1       (gd_get_pixel),         /* 1 */
    GD_FUNC_8       (gd_get_pixel),         /* 8 */
    GD_FUNC_16      (gd_get_pixel),         /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_get_pixel_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_get_pixel),         /* 24 */
    #endif
    GD_FUNC_32      (gd_get_pixel),         /* 32 */
    GD_FUNC_32PARGB (gd_get_pixel),         /* 32PARGB */
    GD_FUNC_UYVY422 (gd_get_pixel),         /* UYVY422 */
    GD_FUNC_A8      (gd_get_pixel),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_get_pixel),
#endif
    (gd_get_pixel_func)gd_get_pixel_main,   /* main */
    (gd_get_pixel_func)gd_get_pixel_sub     /* sub */
};

const gd_put_pixel_func gd_put_pixel[] = 
{
    GD_FUNC_1       (gd_put_pixel),         /* 1 */
    GD_FUNC_8       (gd_put_pixel),         /* 8 */
    GD_FUNC_16      (gd_put_pixel),         /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_put_pixel_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_put_pixel),         /* 24 */
    #endif
    GD_FUNC_32      (gd_put_pixel),         /* 32 */
    GD_FUNC_32PARGB (gd_put_pixel),         /* 32PARGB */
    GD_FUNC_UYVY422 (gd_put_pixel),         /* UYVY422 */
    GD_FUNC_A8      (gd_put_pixel),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_put_pixel),
#endif
    (gd_put_pixel_func)gd_put_pixel_main,   /* main */
    (gd_put_pixel_func)gd_put_pixel_sub     /* sub */
};

const gd_put_pixel_to_layer_func gd_put_pixel_to_layer[] = 
{
    GD_FUNC_1   (gd_put_pixel_to_layer),        /* 1 */
    GD_FUNC_8   (gd_put_pixel_to_layer),        /* 8 */
    GD_FUNC_16  (gd_put_pixel_to_layer),        /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_put_pixel_to_layer_func)gd_null_pointer_function,
    #else
    GD_FUNC_24  (gd_put_pixel_to_layer),        /* 24 */
    #endif
    GD_FUNC_32  (gd_put_pixel_to_layer),        /* 32 */
    GD_FUNC_32PARGB  (gd_put_pixel_to_layer),   /* 32PARGB */
    GD_FUNC_UYVY422  (gd_put_pixel_to_layer),   /* UYVY422 */
    GD_FUNC_A8      (gd_put_pixel_to_layer),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_put_pixel_to_layer),
#endif
    (gd_put_pixel_to_layer_func)gd_put_pixel_to_layer_main,   /* main */
    (gd_put_pixel_to_layer_func)gd_put_pixel_to_layer_sub     /* sub */
};

const gd_get_buf_pixel_func gd_get_buf_pixel[] = 
{
    GD_FUNC_1       (gd_get_buf_pixel),   /* 1 */
    GD_FUNC_8       (gd_get_buf_pixel),   /* 8 */
    GD_FUNC_16      (gd_get_buf_pixel),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_get_buf_pixel_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_get_buf_pixel),   /* 24 */
    #endif
    GD_FUNC_32      (gd_get_buf_pixel),   /* 32 */
    GD_FUNC_32PARGB (gd_get_buf_pixel),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_get_buf_pixel),   /* UYVY422 */
    GD_FUNC_A8      (gd_get_buf_pixel),
    
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_get_buf_pixel),
    #endif
    (gd_get_buf_pixel_func)gd_get_buf_pixel_main, /* main */
    (gd_get_buf_pixel_func)gd_get_buf_pixel_sub   /* sub */
};

const gd_put_buf_pixel_func gd_put_buf_pixel[] = 
{
    GD_FUNC_1       (gd_put_buf_pixel),   /* 1 */
    GD_FUNC_8       (gd_put_buf_pixel),   /* 8 */
    GD_FUNC_16      (gd_put_buf_pixel),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_put_buf_pixel_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_put_buf_pixel),   /* 24 */
    #endif
    GD_FUNC_32      (gd_put_buf_pixel),   /* 32 */
    GD_FUNC_32PARGB (gd_put_buf_pixel),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_put_buf_pixel),   /* UYVY422 */
    GD_FUNC_A8      (gd_put_buf_pixel),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_put_buf_pixel),
#endif
    (gd_put_buf_pixel_func)gd_put_buf_pixel_main, /* main */
    (gd_put_buf_pixel_func)gd_put_buf_pixel_sub   /* sub */
};

const gd_replace_src_key_func gd_replace_src_key[] = 
{
    GD_FUNC_1       (gd_replace_src_key),   /* 1 */
    GD_FUNC_8       (gd_replace_src_key),   /* 8 */
    GD_FUNC_16      (gd_replace_src_key),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_replace_src_key_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_replace_src_key),   /* 24 */
    #endif
    GD_FUNC_32      (gd_replace_src_key),   /* 32 */
    GD_FUNC_32PARGB (gd_replace_src_key),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_replace_src_key),   /* UYVY422 */
    (gd_bitblt_func)gd_null_pointer_function, /* A8 */
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_replace_src_key),
#endif    
    GD_FUNC_MAIN    (gd_replace_src_key),   /* main */
    GD_FUNC_SUB     (gd_replace_src_key)    /* sub */
};

#define gd_resize_bitblt_func gd_bitblt_func
const gd_bitblt_func gd_resize_bitblt[] = 
{
    GD_FUNC_1       (gd_resize_bitblt),   /* 1 */
    GD_FUNC_8       (gd_resize_bitblt),   /* 8 */
    GD_FUNC_16      (gd_resize_bitblt),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_bitblt_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_resize_bitblt),   /* 24 */
    #endif
    GD_FUNC_32      (gd_resize_bitblt),   /* 32 */
    GD_FUNC_32PARGB (gd_resize_bitblt),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_resize_bitblt),   /* UYVY422 */
    GD_FUNC_A8      (gd_resize_bitblt),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_resize_bitblt),
#endif
    GD_FUNC_MAIN    (gd_resize_bitblt),   /* main */
    GD_FUNC_SUB     (gd_resize_bitblt)    /* sub */
};

const gd_bitblt_func gd_bitblt[] = 
{
    GD_FUNC_1       (gd_bitblt),   /* 1 */
    GD_FUNC_8       (gd_bitblt),   /* 8 */
    GD_FUNC_16      (gd_bitblt),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_bitblt_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_bitblt),   /* 24 */
    #endif
    GD_FUNC_32      (gd_bitblt),   /* 32 */
    GD_FUNC_32PARGB (gd_bitblt),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_bitblt),   /* UYVY422 */
    GD_FUNC_A8      (gd_bitblt),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_bitblt),
#endif    
    GD_FUNC_MAIN    (gd_bitblt),   /* main */
    GD_FUNC_SUB     (gd_bitblt)    /* sub */
};

const gd_memset_func gd_memset[] = 
{
    GD_FUNC_1       (gd_memset),   /* 1 */
    GD_FUNC_8       (gd_memset),   /* 8 */
    GD_FUNC_16      (gd_memset),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_memset_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_memset),   /* 24 */
    #endif
    GD_FUNC_32      (gd_memset),   /* 32 */
    GD_FUNC_32PARGB (gd_memset),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_memset),   /* UYVY422 */
    GD_FUNC_A8      (gd_memset),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)    
    GD_FUNC_PARGB6666(gd_memset),
#endif
    GD_FUNC_MAIN    (gd_memset),   /* main */
    GD_FUNC_SUB     (gd_memset)    /* sub */
};

const gd_fill_dot_rect_func gd_fill_dot_rect[] =
{
    GD_FUNC_1       (gd_fill_dot_rect),   /* 1 */
    GD_FUNC_8       (gd_fill_dot_rect),   /* 8 */
    GD_FUNC_16      (gd_fill_dot_rect),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_fill_dot_rect_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_fill_dot_rect),   /* 24 */
    #endif
    GD_FUNC_32      (gd_fill_dot_rect),   /* 32 */
    GD_FUNC_32PARGB (gd_fill_dot_rect),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_fill_dot_rect),   /* UYVY422 */
    GD_FUNC_A8      (gd_fill_dot_rect),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_fill_dot_rect),
#endif    
    GD_FUNC_MAIN    (gd_fill_dot_rect),   /* main */
    GD_FUNC_SUB     (gd_fill_dot_rect)    /* sub */
};

const gd_image_bits_draw_func gd_image_bits_draw[] =
{
    GD_FUNC_1       (gd_image_bits_draw),   /* 1 */
    GD_FUNC_8       (gd_image_bits_draw),   /* 8 */
    GD_FUNC_16      (gd_image_bits_draw),   /* 16 */
    #if defined(GDI_SLIM_COLOR_FORMAT)
    (gd_image_bits_draw_func)gd_null_pointer_function,
    #else
    GD_FUNC_24      (gd_image_bits_draw),   /* 24 */
    #endif
    GD_FUNC_32      (gd_image_bits_draw),   /* 32 */
    GD_FUNC_32PARGB (gd_image_bits_draw),   /* 32PARGB */
    GD_FUNC_UYVY422 (gd_image_bits_draw),   /* UYVY422 */
    GD_FUNC_A8      (gd_image_bits_draw),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)    
    GD_FUNC_PARGB6666(gd_image_bits_draw),
#endif
    GD_FUNC_MAIN    (gd_image_bits_draw),   /* main */
    GD_FUNC_SUB     (gd_image_bits_draw)    /* sub */
};


#if defined(GDI_USE_RGB565_TO_SHOW_BW)
/*****************************************************************************
 * FUNCTION
 *  gdi_layer_copy_1_to_16
 * DESCRIPTION
 *  copy main base layer(1bpp) to copy layer(16bpp) for color lcd blt
 * PARAMETERS
 *  src_handle : main base layer
 *  dst_handle : copy layer
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_copy_1_to_16(gdi_handle src_handle, gdi_handle dst_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *src_layer = (gdi_layer_struct *)src_handle;
	gdi_layer_struct *dst_layer = (gdi_layer_struct *)dst_handle;
    U8 *dst_ptr;
	gdi_color src_color, dst_color;
    S32 i, j, dst_pitch;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_handle == GDI_NULL_HANDLE ||
		dst_handle == GDI_NULL_HANDLE ||
		src_layer->vcf != GDI_COLOR_FORMAT_1 || 
		dst_layer->vcf != GDI_COLOR_FORMAT_16 ||
		src_layer->width != dst_layer->width ||
		src_layer->height != dst_layer->height)
	{
    	return GDI_FAILED;
	}
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_copy_1_to_16)
	dst_ptr = (U8*)dst_layer->buf_ptr;
    dst_pitch   = dst_layer->width * (dst_layer->bits_per_pixel >> 3);
	
    for (j = 0; j < dst_layer->height; j++)
    {
        U16 *dst_line_ptr = (U16*)dst_ptr;
        for (i = 0; i < dst_layer->width; i++)
        {
            GDI_GET_BUFFER_PIXEL_1(i, j, &dst_color);
		
            *dst_line_ptr = dst_color? 0x0:0xFFFF;
			dst_line_ptr++;			
        }
        dst_ptr += dst_pitch;            
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_copy_1_to_16)
        
	return GDI_SUCCEED;
}

#endif

