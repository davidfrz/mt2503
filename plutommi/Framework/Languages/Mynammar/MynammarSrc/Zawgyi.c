/*****************************************************************************
* Include                                                                     
*****************************************************************************/
#include "MMI_include.h"
#include "IndicEngineGprot.h"
#include "Zawgyi.h"
#include "imc.h"

#if defined(__MMI_LANG_ZAWGYI_MYANMAR__)
/***************************************************************************** 
* Define
*****************************************************************************/

#define IRE_ZAWGYI_MYANMAR_PROPRIETRY_SHIFT 0xDF00
#define ZAWGYI_MASK_POSITION_BYTES				    0x0000F000	/*To identify positions*/
#define ZAWGYI_CONVERT_U8_U16(pCharacter) ((pCharacter)[0]|((pCharacter)[1]<<8))
#define ZAWGYI_CLUSTER_MAX_LEN 10

#define ZAWGYI_NORMAL_CONSONANT 1
#define ZAWGUI_PRE_CONSONANT_1 2
#define ZAWGUI_PRE_CONSONANT_2 4

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/
static const ire_character_info_table_struct zawgyi_get_character_info(U16 character);
static S32 zawgyi_get_index_by_code(U16 character);
static MMI_BOOL zawgyi_check_conbination_validate(
    ire_character_info_table_struct *pre_character_info, 
    S32 n, 
    char_pos_info *prev_char_state);

/*****************************************************************************
* const Global Variable
*****************************************************************************/
//in zawgyi language, consonant means that this character can put on first position in ligature.
//this table matain all zawgyi character info, which indicate the combination and position
const ire_character_info_table_struct zawgyi_character_info_table[] = 
{
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1000 */	
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1001 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1002 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1003 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1004 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1005 */	
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1006 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1007 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1008 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1009 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 100A */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 100B */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 100C */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 100D */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 100E */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 100F */	
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1010 */	
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1011 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1012 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1013 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1014 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1015 */	
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1016 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1017 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1018 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1019 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 101A */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 101B */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 101C */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 101D */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 101E */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 101F */	
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1020 */	

	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1021 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1022 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW},	/* 1023 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW|CHARACTER_POS_ABOVE},	/* 1024 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1025 */	
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1026 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1027 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1028 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW|CHARACTER_POS_ABOVE},	/* 1029 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW|CHARACTER_POS_ABOVE},	/* 102A */

	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_SPECIAL_POST_BASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_ABOVE_HALF},	/* 102B */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 102C */
	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 102D */
	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 102E */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 102F */	
    {0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1030 */	

	{ZAWGUI_PRE_CONSONANT_1, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1031 */	

	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 1032 */	
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW},	/* 1033 */	
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW},	/* 1034 */	

	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1035 */		

	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE_HALF},	/* 1036 */	
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW_HALF},	/* 1037 */	
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER_HALF},	/* 1038 */	
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 1039  halant */	
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_AND_POST_BASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW_HALF},	/* 103A */	

	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 103B */	

	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 103C */	
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 103D */	

	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 103E */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 103F */	
	
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1040 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1041 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1042 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1043 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1044 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1045 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1046 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1047 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1048 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 1049 */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 104A */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 104B */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 104C */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 104D */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 104E */
	{0, 0, 0, 0, 0, IRE_NUMERIC_DIGIT, 0, 0, 0, 0},	/* 104F */

	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1050 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1051 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1052 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1053 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1054 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1055 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1056 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1057 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1058 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1059 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_SPECIAL_POST_BASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_ABOVE},	/* 105A */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 105B */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 105C */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 105D */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 105E */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 105F */
	
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1060 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1061 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1062 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1063 */
	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 1064 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1065 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1066 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1067 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1068 */
	{0, IRE_POST_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_AND_POST_BASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW},	/* 1069 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 106A */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 106B */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 106C */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 106D */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW},	/* 106E */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER|CHARACTER_POS_BELLOW},	/* 106F */

	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1070 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1071 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1072 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1073 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1074 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1075 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1076 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1077 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1078 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1079 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 107A */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 107B */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 107C */
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 107D */

	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 107E */
	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 107F */
	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1080 */
	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1081 */
	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1082 */
	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1083 */
	{ZAWGUI_PRE_CONSONANT_2, 0, 0, 0, 0, 0, IRE_PREBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1084 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1085 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1086 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1087 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1088 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1089 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 108A */
	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 108B */
	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 108C */
	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 108D */
	{0, IRE_ABOVE_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_ABOVE_BASE_POSITION, 0, 0, CHARACTER_POS_ABOVE},	/* 108E */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 108F */
		
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1090 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1091 */
	{ZAWGYI_NORMAL_CONSONANT, 0, 0, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1092 */
	{0, IRE_BELOW_BASE_DEP_VOWEL, 0, 0, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW},	/* 1093 */
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW_HALF},	/* 1094 */
	{0, 0, 0, IRE_NORMAL_SIGN, 0, 0, IRE_BELOW_BASE_POSITION, 0, 0, CHARACTER_POS_BELLOW_HALF},	/* 1095 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1096 */
	{0, 0, IRE_INDEP_VOWEL, 0, 0, 0, IRE_POSTBASE_POSITION, 0, 0, CHARACTER_POS_CENTER},	/* 1097 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1098 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 1099 */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 109A */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 109B */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 109C */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 109D */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 109E */
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	/* 109F */
				
};

#ifdef __CUSTOMER_REQUIREMENT__
const UI_character_type default_zawgyi_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', ZAWGYI_CS_HA_U, ZAWGYI_CS_HA_UU, ZAWGYI_DV_VIRAMA_JHA, ZAWGYI_DV_VIRAMA_KA, ZAWGYI_DV_VIRAMA_KHA, ZAWGYI_DV_VIRAMA_CA, ZAWGYI_DV_VIRAMA_TA_2, ZAWGYI_DV_VIRAMA_THA_1, ZAWGYI_DV_VIRAMA_PA, ZAWGYI_DV_VIRAMA_BHA_1, ZAWGYI_DV_VIRAMA_MA, ZAWGYI_D_ZERO, '0', '\0'},  /* key 0 */
    {'.', '?', '!', ',', '@', ':', ';', '\'', '-', '\\',  '/', '%', '&', '(', ')', '[', ']', '{', '}', '<', '>', '"', '$', '+', '=', '#', '*', '_', '~', ZAWGYI_D_ONE, '1', '\0'},        /* key 1 */
    {ZAWGYI_C_KA, ZAWGYI_C_KHA, ZAWGYI_C_GA, ZAWGYI_C_GHA, ZAWGYI_C_NGA, ZAWGYI_C_CA, ZAWGYI_C_CHA, ZAWGYI_D_TWO, '2', '\0'},        /* key 2 */
    {ZAWGYI_C_JA, ZAWGYI_C_JHA, ZAWGYI_C_NNYA, ZAWGYI_C_TTA, ZAWGYI_C_TTHA, ZAWGYI_C_DDA, ZAWGYI_C_DDHA, ZAWGYI_D_THREE, '3', '\0'},  /* key 3 */
    {ZAWGYI_C_NNA, ZAWGYI_C_TA, ZAWGYI_C_THA, ZAWGYI_C_DA, ZAWGYI_C_DHA, ZAWGYI_C_NA, ZAWGYI_C_PA, ZAWGYI_D_FOUR, '4', '\0'},        /* key 4 */
    {ZAWGYI_C_PHA, ZAWGYI_C_BA, ZAWGYI_C_BHA, ZAWGYI_C_MA, ZAWGYI_C_YA, ZAWGYI_C_RA, ZAWGYI_C_LA, ZAWGYI_D_FIVE, '5', '\0'},        /* key 5 */
    {ZAWGYI_C_WA, ZAWGYI_C_SA, ZAWGYI_C_HA, 	ZAWGYI_C_LLA, 	ZAWGYI_IV_A, ZAWGYI_IV_U, ZAWGYI_C_NYA, ZAWGYI_D_SIX, '6', '\0'},       /* key 6 */
    {ZAWGYI_DV_TAA, ZAWGYI_DV_AA, ZAWGYI_DV_I, ZAWGYI_DV_II, ZAWGYI_DV_U, ZAWGYI_DV_UU, ZAWGYI_DV_E, ZAWGYI_DV_AI, ZAWGYI_DV_U_L, ZAWGYI_DV_UU_L, ZAWGYI_CS_RA_2, ZAWGYI_CS_RA_4, ZAWGYI_D_SEVEN, '7', '\0'}, /* key 7 */
    {ZAWGYI_CS_RA, ZAWGYI_CS_RA_3, ZAWGYI_CS_YA, ZAWGYI_S_ANUSVARA, ZAWGYI_S_DOT, ZAWGYI_S_VISARGA, ZAWGYI_DV_VIRAMA_NA, ZAWGYI_S_ASAT, ZAWGYI_CS_WA, ZAWGYI_CS_HA, ZAWGYI_S_LITTLE_SECTION, ZAWGYI_S_SECTION, ZAWGYI_D_EIGHT, '8',  '\0'},        /* key 8 */
    {ZAWGYI_C_GREAT_SA, ZAWGYI_S_LOCATIVE, ZAWGYI_S_COMPLETED, ZAWGYI_S_AFOREMENTONED, ZAWGYI_IV_II, ZAWGYI_S_GENITIVE, ZAWGYI_IV_AU, 	ZAWGYI_S_TAA_ASAT, ZAWGYI_IV_E, ZAWGYI_DV_NGA_ASAT_VIRAMA, ZAWGYI_CS_WA_HA, ZAWGYI_C_NNA_VIRAMA_NNA, ZAWGYI_D_NINE, '9', '\0'},                        /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif

// key mapping array
#if defined(__MMI_MULTITAP_MYANMAR__)
const UI_character_type default_zawgyi_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', ZAWGYI_DV_NGA_ASAT_VIRAMA,  ZAWGYI_S_NGA_ASAT_VIRAMA_I,  ZAWGYI_S_NGA_ASAT_VIRAMA_II,  ZAWGYI_S_NGA_ASAT_VIRAMA_ANUSVARA,  ZAWGYI_S_I_ANUSVARA,  ZAWGYI_DV_VIRAMA_KA,  ZAWGYI_DV_VIRAMA_KHA,  ZAWGYI_DV_VIRAMA_GA,  ZAWGYI_DV_VIRAMA_GHA,  ZAWGYI_DV_VIRAMA_CA,  ZAWGYI_DV_VIRAMA_CHA_1,  ZAWGYI_DV_VIRAMA_CHA_2,  ZAWGYI_DV_VIRAMA_JA,  ZAWGYI_DV_VIRAMA_JHA,  ZAWGYI_DV_VIRAMA_TTA,  ZAWGYI_DV_VIRAMA_TTHA,  ZAWGYI_DV_VIRAMA_LA,  ZAWGYI_D_ZERO, '0', '\0'},  /* key 0 */
    {ZAWGYI_C_KA,  ZAWGYI_C_KHA,  ZAWGYI_C_GA,  ZAWGYI_C_GHA,  ZAWGYI_C_NGA,  ZAWGYI_C_CA,  ZAWGYI_C_CHA,  ZAWGYI_D_ONE, '1', '\0'},  /* key 1 */
    {ZAWGYI_C_JA,  ZAWGYI_C_JHA,  ZAWGYI_C_NNYA,  ZAWGYI_C_TTA,  ZAWGYI_C_TTHA,  ZAWGYI_C_DDA,  ZAWGYI_C_DDHA,  ZAWGYI_D_TWO, '2', '\0'},  /* key 2 */
    {ZAWGYI_C_NNA,  ZAWGYI_C_TA,  ZAWGYI_C_THA,  ZAWGYI_C_DA,  ZAWGYI_C_DHA,  ZAWGYI_C_NA,  ZAWGYI_C_PA,  ZAWGYI_D_THREE, '3', '\0'},  /* key 3 */
    {ZAWGYI_C_PHA,  ZAWGYI_C_BA,  ZAWGYI_C_BHA,  ZAWGYI_C_MA,  ZAWGYI_C_YA,  ZAWGYI_C_RA,  ZAWGYI_C_LA,  ZAWGYI_D_FOUR, '4', '\0'},  /* key 4 */
    {ZAWGYI_C_WA,  ZAWGYI_C_SA,  ZAWGYI_C_HA,  ZAWGYI_C_LLA,  ZAWGYI_IV_A,  ZAWGYI_IV_U,  ZAWGYI_IV_UU,  ZAWGYI_IV_E,  ZAWGYI_C_NYA,  ZAWGYI_C_NYA_2,  ZAWGYI_C_NNYA_2,  ZAWGYI_D_FIVE, '5', '\0'},  /* key 5 */
    {ZAWGYI_DV_TAA,  ZAWGYI_DV_AA,  ZAWGYI_DV_I,  ZAWGYI_DV_II,  ZAWGYI_DV_U,  ZAWGYI_DV_UU,  ZAWGYI_DV_E,  ZAWGYI_DV_AI,  ZAWGYI_DV_U_L,  ZAWGYI_DV_UU_L,  ZAWGYI_CS_HA,  ZAWGYI_CS_HA_S,  ZAWGYI_CS_HA_U,  ZAWGYI_CS_HA_UU,  ZAWGYI_S_LITTLE_SECTION,  ZAWGYI_S_SECTION,  ZAWGYI_D_SIX, '6', '\0'},  /* key 6 */
    {ZAWGYI_CS_RA,  ZAWGYI_CS_RA_3,  ZAWGYI_CS_RA_2,  ZAWGYI_CS_RA_4,  ZAWGYI_CS_RA_5,  ZAWGYI_CS_RA_6,  ZAWGYI_CS_RA_7,  ZAWGYI_CS_RA_8,  ZAWGYI_CS_YA,  ZAWGYI_S_ANUSVARA,  ZAWGYI_S_DOT,  ZAWGYI_S_VISARGA,  ZAWGYI_S_ASAT,  ZAWGYI_CS_WA,  ZAWGYI_DV_VIRAMA_NA_2,  ZAWGYI_CS_YA_2,  ZAWGYI_D_SEVEN, '7', '\0'},  /* key 7 */
    {ZAWGYI_IV_I,  ZAWGYI_IV_II,  ZAWGYI_IV_O,  ZAWGYI_IV_AU,  ZAWGYI_S_LOCATIVE,  ZAWGYI_S_COMPLETED,  ZAWGYI_S_AFOREMENTONED,  ZAWGYI_S_GENITIVE,  ZAWGYI_C_GREAT_SA,  ZAWGYI_DV_VIRAMA_NA,  ZAWGYI_C_RA_2,  ZAWGYI_C_NNA_VIRAMA_NNA,  ZAWGYI_C_LLA_2,  ZAWGYI_S_MON_II_ANUSVARA,  ZAWGYI_C_TTA_VIRAMA_TTA,  ZAWGYI_C_DDA_VIRAMA_DDA,  ZAWGYI_C_UNKNOW_CONBINATION,  ZAWGYI_D_EIGHT, '8', '\0'},  /* key 8 */
    {ZAWGYI_DV_VIRAMA_NNA,  ZAWGYI_DV_VIRAMA_TA_1,  ZAWGYI_DV_VIRAMA_TA_2,  ZAWGYI_DV_VIRAMA_THA_1,  ZAWGYI_DV_VIRAMA_THA_2,  ZAWGYI_DV_VIRAMA_DA,  ZAWGYI_DV_VIRAMA_DHA,  ZAWGYI_DV_VIRAMA_PA,  ZAWGYI_DV_VIRAMA_PHA,  ZAWGYI_DV_VIRAMA_BA,  ZAWGYI_DV_VIRAMA_BHA_1,  ZAWGYI_DV_VIRAMA_MA,  ZAWGYI_S_DOT_SHIFT,  ZAWGYI_S_DOT_POST,  ZAWGYI_CS_WA_HA,  ZAWGYI_S_TAA_ASAT,  ZAWGYI_D_NINE, '9', '\0'},  /* key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + zawgyi internal funciton
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  zawgyi_check_and_update_current_state
 * DESCRIPTION          
 *  this api used to update the cluster state.
 * PARAMETERS
 *  start_character     [IN]   UCS code for character  
 *  pre_len    [IN]  
 *  current_character    [IN]  
 *  current_char_state    [IN]  
 *  RETURNS
 *  U16 : 
 *****************************************************************************/
MMI_BOOL zawgyi_check_and_update_current_state(PU8 start_character, S32 pre_len, U16 current_character, char_pos_info *current_char_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ire_character_info_table_struct pre_character_info[ZAWGYI_CLUSTER_MAX_LEN] = {0};
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pre_len)
    {
        // first character, always return ture.
        *current_char_state = (char_pos_info) zawgyi_get_character_info(current_character).lang_specific;
        return MMI_TRUE;
    }

    if (pre_len >= ZAWGYI_CLUSTER_MAX_LEN)
    {
        // should not exceed the max len of one cluster.
        return MMI_FALSE;
    }
    
    for (i = 0; i < pre_len; i++, start_character += 2)
    {
        pre_character_info[i] = zawgyi_get_character_info(ZAWGYI_CONVERT_U8_U16(start_character));
    }

    pre_character_info[i] = zawgyi_get_character_info(current_character);

    if(zawgyi_check_conbination_validate(pre_character_info, i+1, current_char_state))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

static MMI_BOOL zawgyi_check_conbination_validate(
    ire_character_info_table_struct *pre_character_info, 
    S32 n, 
    char_pos_info *prev_char_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    char_pos_info curr_char_state = (char_pos_info) pre_character_info[n-1].lang_specific;  //trick, used language_specific for zawgyi rule.
    char_pos_info overlap_check;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(n > 0 && n <= ZAWGYI_CLUSTER_MAX_LEN);

    overlap_check = curr_char_state & (*prev_char_state);

    if (!(pre_character_info[0].consonant))
    {
        ret = MMI_FALSE;
    }
    // pos center will be handle specially.
    if (overlap_check & (CHARACTER_POS_ABOVE|CHARACTER_POS_BELLOW|CHARACTER_POS_POST|CHARACTER_POS_PRE|CHARACTER_POS_CENTER_HALF))
    {
        ret = MMI_FALSE;
    }
    //handle center pos.
    {
        S32 i, pre_consonant_1 = 0,pre_consonant_2 = 0, consonant_count = 0, dep_cen_vowel = 0, cen_sign = 0;
        
        for (i = 0; i < n; i++)
        {
            if (pre_character_info[i].digit || pre_character_info[i].indep_vowel)
            {
                ret = MMI_FALSE;
            }
            else if (pre_character_info[i].consonant == ZAWGYI_NORMAL_CONSONANT)
            {
                consonant_count++;
            }
            else if (pre_character_info[i].consonant == ZAWGUI_PRE_CONSONANT_2)
            {
                pre_consonant_2++;
                if (consonant_count)
                {
                    ret = MMI_FALSE;    // preconsonant 2 should be input before consonant and preconsonant 1.
                }
            }
            else if (pre_character_info[i].consonant == ZAWGUI_PRE_CONSONANT_1)
            {
                pre_consonant_1++;
                if (consonant_count || pre_consonant_2)
                {
                    ret = MMI_FALSE;    // preconsonant 1 should be input before consonant.
                }
            }
            else if (pre_character_info[i].dep_vowel == IRE_POST_BASE_DEP_VOWEL)
            {
                dep_cen_vowel++;
            }
            else if (pre_character_info[i].dep_vowel && (!consonant_count))
            {
                ret = MMI_FALSE;
            }
            else if (pre_character_info[i].sign && (pre_character_info[i].lang_specific & CHARACTER_POS_CENTER))
            {
                cen_sign++;
            }
        }
        if ( pre_consonant_1 > 1 || pre_consonant_2 > 1 || consonant_count > 1 || dep_cen_vowel > 1 || cen_sign > 1)
        {
            ret = MMI_FALSE;
        }
    }

    //update char state
    if (*prev_char_state & curr_char_state & CHARACTER_POS_ABOVE_HALF)
    {
        *prev_char_state |= CHARACTER_POS_ABOVE;
    }
    if (*prev_char_state & curr_char_state & CHARACTER_POS_BELLOW_HALF)
    {
        *prev_char_state |= CHARACTER_POS_BELLOW;
    }
    *prev_char_state |= 
        (curr_char_state & (CHARACTER_POS_CENTER
        |CHARACTER_POS_ABOVE
        |CHARACTER_POS_BELLOW
        |CHARACTER_POS_POST
        |CHARACTER_POS_PRE
        |CHARACTER_POS_ABOVE_HALF
        |CHARACTER_POS_BELLOW_HALF
        |CHARACTER_POS_CENTER_HALF));
    if (curr_char_state & CHARACTER_POS_POST)
    {
        *prev_char_state |= (CHARACTER_POS_ABOVE|CHARACTER_POS_BELLOW);
        if (curr_char_state & CHARACTER_POS_ABOVE)
        {
            *prev_char_state &= ~CHARACTER_POS_ABOVE;
        }
        if (curr_char_state & CHARACTER_POS_BELLOW)
        {
            *prev_char_state &= ~CHARACTER_POS_BELLOW;
        }
    }

    return ret;
}

UI_string_type get_zawgyi_multitap_string(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (UI_character_type*) default_zawgyi_multitap_strings[index];
}

/*****************************************************************************
 * FUNCTION
 *  zawgyi_convert_rendering_encoding_to_logic_encoding
 * DESCRIPTION			
 *  this api used to convert  logic code to rendering code.
 * PARAMETERS
 *  character     [IN]   UCS code for character  
 *  RETURNS
 *  U16 : 
 *****************************************************************************/
U16 zawgyi_convert_logic_encoding_to_rendering_encoding(U16 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return zawgyi_get_index_by_code(character) + IRE_ZAWGYI_MYANMAR_PROPRIETRY_START_RANGE;
}


/*****************************************************************************
 * FUNCTION
 *  zawgyi_convert_rendering_encoding_to_logic_encoding
 * DESCRIPTION			
 *  this api used to convert rendering code to logic code.
 * PARAMETERS
 *  character     [IN]   UCS code for character  
 *  RETURNS
 *  U16 : the code save in memory 
 *****************************************************************************/
U16 zawgyi_convert_rendering_encoding_to_logic_encoding(U16 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return zawgyi_get_index_by_code(character) + IRE_ZAWGYI_MYANMAR_LANG_START_RANGE;
}

/*****************************************************************************
 * FUNCTION
 *  zawgyi_get_character_shift_direction
 * DESCRIPTION			
 *  This method will tell us the character should move to left or right, if return MMI_TURE, means should move to left.
 *  and copy the output buffer i.e glyphoutput
 * PARAMETERS
 *  character     [IN]   UCS code for character  
 *  RETURNS
 *  S32 
 *****************************************************************************/
S32 zawgyi_get_character_shift_direction(U16 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 move_style = 0;
    ire_character_position_info_enum character_pos = (ire_character_position_info_enum) zawgyi_get_character_info(character).char_position;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (character_pos)
    {
       	case IRE_PREBASE_POSITION:
            move_style = 1;
            break;
    	case IRE_ABOVE_BASE_POSITION:
    	case IRE_BELOW_BASE_POSITION:
    	case IRE_SPECIAL_POST_BASE_POSITION:
    	case IRE_BELOW_AND_POST_BASE_POSITION:
            move_style = -1;
            break;
        case IRE_POSTBASE_POSITION:
        case IRE_CENTER_BASE_POSITION:
        default:
            move_style = 0;
            break;
    }
    return move_style;
}


/*****************************************************************************
 * FUNCTION
 *  zawgyi_get_character_info
 * DESCRIPTION			
 *  used to get character info.
 * PARAMETERS
 *  character     [IN]   UCS code     
 *  RETURNS
 *  character info
 *****************************************************************************/
static const ire_character_info_table_struct zawgyi_get_character_info(U16 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return zawgyi_character_info_table[zawgyi_get_index_by_code(character)];
}


/*****************************************************************************
 * FUNCTION
 *  zawgyi_get_index_by_code
 * DESCRIPTION			
 *  used to get relate index of character info array.
 * PARAMETERS
 *  character     [IN]   UCS code for zawgyi character.    
 *  RETURNS
 *  relate index in character info array
 *****************************************************************************/
static S32 zawgyi_get_index_by_code(U16 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    if (character >= IRE_ZAWGYI_MYANMAR_LANG_START_RANGE && character <= IRE_ZAWGYI_MYANMAR_LANG_END_RANGE)
    {
        return character - IRE_ZAWGYI_MYANMAR_LANG_START_RANGE;
    }
    else if (character >= IRE_ZAWGYI_MYANMAR_PROPRIETRY_START_RANGE && character <= IRE_ZAWGYI_MYANMAR_PROPRIETRY_END_RANGE)
    {
        return character - IRE_ZAWGYI_MYANMAR_PROPRIETRY_START_RANGE;
    }
    else
    {
        MMI_ASSERT(0);
    }
}
#endif

