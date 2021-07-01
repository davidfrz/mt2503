#ifndef ZAWGYI_H
#define ZAWGYI_H

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"

#define IRE_ZAWGYI_MYANMAR_LANG_START_RANGE 0x1000
#define IRE_ZAWGYI_MYANMAR_LANG_END_RANGE 0x109F
#define IRE_ZAWGYI_MYANMAR_PROPRIETRY_START_RANGE 0xEF00
#define IRE_ZAWGYI_MYANMAR_PROPRIETRY_END_RANGE 0xEF9F
#define IS_ZAWGYI_MYANMAR_RANG(character) ((character >= 0x1000 && character <= 0x109F) || (character >= 0xEF00 && character <= 0xEF9F))

typedef enum
{
    ZAWGYI_C_KA = 0x1000,
    ZAWGYI_C_KHA = 0x1001,
    ZAWGYI_C_GA = 0x1002,
    ZAWGYI_C_GHA = 0x1003,
    ZAWGYI_C_NGA = 0x1004,
    ZAWGYI_C_CA = 0x1005,
    ZAWGYI_C_CHA = 0x1006,
    ZAWGYI_C_JA = 0x1007,
    ZAWGYI_C_JHA = 0x1008,
    ZAWGYI_C_NYA = 0x1009,
    ZAWGYI_C_NNYA = 0x100A,
    ZAWGYI_C_TTA = 0x100B,
    ZAWGYI_C_TTHA = 0x100C,
    ZAWGYI_C_DDA = 0x100D,
    ZAWGYI_C_DDHA = 0x100E,
    ZAWGYI_C_NNA = 0x100F,
    ZAWGYI_C_TA = 0x1010,
    ZAWGYI_C_THA = 0x1011,
    ZAWGYI_C_DA = 0x1012,
    ZAWGYI_C_DHA = 0x1013,
    ZAWGYI_C_NA = 0x1014,
    ZAWGYI_C_PA = 0x1015,
    ZAWGYI_C_PHA = 0x1016,
    ZAWGYI_C_BA = 0x1017,
    ZAWGYI_C_BHA = 0x1018,
    ZAWGYI_C_MA = 0x1019,
    ZAWGYI_C_YA = 0x101A,
    ZAWGYI_C_RA = 0x101B,
    ZAWGYI_C_LA = 0x101C,
    ZAWGYI_C_WA = 0x101D,
    ZAWGYI_C_SA = 0x101E,
    ZAWGYI_C_HA = 0x101F,	
    ZAWGYI_C_LLA = 0x1020,	
	
    ZAWGYI_IV_A = 0x1021,
    // 0x1022,
    ZAWGYI_IV_I = 0x1023,
    ZAWGYI_IV_II = 0x1024,
    ZAWGYI_IV_U = 0x1025,
    ZAWGYI_IV_UU = 0x1026,
    ZAWGYI_IV_E = 0x1027,
    // 0x1028,
    ZAWGYI_IV_O = 0x1029,
    ZAWGYI_IV_AU = 0x102A,	

	ZAWGYI_DV_TAA = 0x102B,
    ZAWGYI_DV_AA = 0x102C,
    ZAWGYI_DV_I = 0x102D,
    ZAWGYI_DV_II = 0x102E,
    ZAWGYI_DV_U = 0x102F,
    ZAWGYI_DV_UU = 0x1030,
    ZAWGYI_DV_E = 0x1031,
    ZAWGYI_DV_AI = 0x1032,
    
    ZAWGYI_DV_U_L = 0x1033,
    ZAWGYI_DV_UU_L = 0x1034,
    // 0x1035,

	
    ZAWGYI_S_ANUSVARA = 0x1036,
    ZAWGYI_S_DOT = 0x1037,
    ZAWGYI_S_VISARGA = 0x1038,
    ZAWGYI_S_ASAT = 0x1039,
    
    ZAWGYI_CS_YA = 0x103A,
    ZAWGYI_CS_RA = 0x103B,
    ZAWGYI_CS_WA = 0x103C,
    ZAWGYI_CS_HA = 0x103D,
    // 0x103E,
    // 0x103F,

    ZAWGYI_D_ZERO = 0x1040, /* ZAWGYI digital 0 */
    ZAWGYI_D_ONE = 0x1041, /* ZAWGYI digital 1 */
    ZAWGYI_D_TWO = 0x1042, /* ZAWGYI digital 2 */
    ZAWGYI_D_THREE = 0x1043, /* ZAWGYI digital 3 */
    ZAWGYI_D_FOUR = 0x1044, /* ZAWGYI digital 4 */
    ZAWGYI_D_FIVE = 0x1045, /* ZAWGYI digital 5 */
    ZAWGYI_D_SIX = 0x1046, /* ZAWGYI digital 6 */
    ZAWGYI_D_SEVEN = 0x1047, /* ZAWGYI digital 7 */
    ZAWGYI_D_EIGHT = 0x1048, /* ZAWGYI digital 8 */
    ZAWGYI_D_NINE = 0x1049, /* ZAWGYI digital 9 */

    ZAWGYI_S_LITTLE_SECTION = 0x104A,
    ZAWGYI_S_SECTION = 0x104B,
    
    ZAWGYI_S_LOCATIVE = 0x104C,
    ZAWGYI_S_COMPLETED = 0x104D,
    ZAWGYI_S_AFOREMENTONED = 0x104E,
    ZAWGYI_S_GENITIVE = 0x104F,
    
    // 0x1050,
    // 0x1051,
    // 0x1052,
    // 0x1053,
    // 0x1054,
    // 0x1055,
    // 0x1056,
    // 0x1057,
    // 0x1058,
    // 0x1059,
    
    ZAWGYI_S_TAA_ASAT = 0x105A,
    // 0x105B,
    // 0x105C,
    // 0x105D,
    // 0x105E,
    // 0x105F,
    
    ZAWGYI_DV_VIRAMA_KA = 0x1060,
    ZAWGYI_DV_VIRAMA_KHA = 0x1061,
    ZAWGYI_DV_VIRAMA_GA = 0x1062,
    ZAWGYI_DV_VIRAMA_GHA = 0x1063,
    ZAWGYI_DV_NGA_ASAT_VIRAMA = 0x1064,
    ZAWGYI_DV_VIRAMA_CA = 0x1065,
    ZAWGYI_DV_VIRAMA_CHA_1 = 0x1066,
    ZAWGYI_DV_VIRAMA_CHA_2 = 0x1067,
    ZAWGYI_DV_VIRAMA_JA = 0x1068, 
    ZAWGYI_DV_VIRAMA_JHA = 0x1069,
    ZAWGYI_C_NYA_2 = 0x106A, 
    ZAWGYI_C_NNYA_2 = 0x106B, 
    ZAWGYI_DV_VIRAMA_TTA = 0x106C, 
    ZAWGYI_DV_VIRAMA_TTHA = 0x106D, 
    ZAWGYI_C_DDA_VIRAMA_DDA = 0x106E, 
    
    ZAWGYI_C_UNKNOW_CONBINATION = 0x106F,  // havn't got the shapping rule.
    
    ZAWGYI_DV_VIRAMA_NNA = 0x1070,
    ZAWGYI_DV_VIRAMA_TA_1 = 0x1071, 
    ZAWGYI_DV_VIRAMA_TA_2 = 0x1072, 
    ZAWGYI_DV_VIRAMA_THA_1 = 0x1073, 
    ZAWGYI_DV_VIRAMA_THA_2 = 0x1074, 
    ZAWGYI_DV_VIRAMA_DA = 0x1075,
    ZAWGYI_DV_VIRAMA_DHA = 0x1076,
    ZAWGYI_DV_VIRAMA_NA_2 = 0x1077,
    ZAWGYI_DV_VIRAMA_PA = 0x1078,
    ZAWGYI_DV_VIRAMA_PHA = 0x1079,
    ZAWGYI_DV_VIRAMA_BA = 0x107A,
    ZAWGYI_DV_VIRAMA_BHA_1 = 0x107B,
    ZAWGYI_DV_VIRAMA_MA = 0x107C,
    ZAWGYI_CS_YA_2 = 0x107D,
    ZAWGYI_CS_RA_2 = 0x107E,
    ZAWGYI_CS_RA_3 = 0x107F,
    ZAWGYI_CS_RA_4 = 0x1080,
    ZAWGYI_CS_RA_5 = 0x1081,
    ZAWGYI_CS_RA_6 = 0x1082, 
    ZAWGYI_CS_RA_7 = 0x1083, 
    ZAWGYI_CS_RA_8 = 0x1084,
    ZAWGYI_DV_VIRAMA_LA = 0x1085, 
    ZAWGYI_C_GREAT_SA = 0x1086, 
    ZAWGYI_CS_HA_S = 0x1087, 
    ZAWGYI_CS_HA_U = 0x1088, 
    ZAWGYI_CS_HA_UU = 0x1089, 
    ZAWGYI_CS_WA_HA = 0x108A, 
    ZAWGYI_S_NGA_ASAT_VIRAMA_I = 0x108B, 
    ZAWGYI_S_NGA_ASAT_VIRAMA_II = 0x108C, 
    ZAWGYI_S_NGA_ASAT_VIRAMA_ANUSVARA = 0x108D, 
    ZAWGYI_S_I_ANUSVARA = 0x108E, 
    ZAWGYI_DV_VIRAMA_NA = 0x108F,     
    ZAWGYI_C_RA_2 = 0x1090, 
    ZAWGYI_C_NNA_VIRAMA_NNA = 0x1091, 
    ZAWGYI_C_LLA_2 = 0x1092, 
    ZAWGYI_DV_VIRAMA_BHA_2 = 0x1093, 
    ZAWGYI_S_DOT_SHIFT = 0x1094, 
    ZAWGYI_S_DOT_POST = 0x1095, 
    ZAWGYI_S_MON_II_ANUSVARA = 0x1096, 
    ZAWGYI_C_TTA_VIRAMA_TTA = 0x1097, 

    // 0x1098, 
    // 0x1099, 
    // 0x109A, 
    // 0x109B,
    // 0x109C,
    // 0x109D,
    // 0x109E,
    // 0x109F
    
}zawgyi_characters_enum;


typedef enum 
{
    CHARACTER_POS_NON = 0,
    CHARACTER_POS_CENTER = 0x0001,
    CHARACTER_POS_ABOVE = 0x0002,
    CHARACTER_POS_BELLOW = 0x0004,
    CHARACTER_POS_PRE = 0x0008,
    CHARACTER_POS_POST = 0x0010,
    CHARACTER_POS_ABOVE_HALF = 0x0020,
    CHARACTER_POS_BELLOW_HALF = 0x0040,
    CHARACTER_POS_CENTER_HALF = 0x0080,
} char_pos_info;

extern MMI_BOOL zawgyi_check_and_update_current_state(
    PU8 start_character, 
    S32 pre_len, 
    U16 current_character, 
    char_pos_info *current_char_state);

extern UI_string_type get_zawgyi_multitap_string(S32 index);

extern U16 zawgyi_convert_logic_encoding_to_rendering_encoding(U16 character);

extern U16 zawgyi_convert_rendering_encoding_to_logic_encoding(U16 character);

extern S32 zawgyi_get_character_shift_direction(U16 character);

#endif /* ZAWGYI_H */ 
