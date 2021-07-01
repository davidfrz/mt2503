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
 *    CATResGenerator.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Creator of CAT 2.0 structure and symbols for MMIResource
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "CatResGenerator.h"


CATResGenerator::CATResGenerator(){
    this->reservedSymbolFile="cat_reserve_space.c";
    this->reservedSymbolName = "cat_reserve";
    this->catSectionName = "CAD_RODATA";
}
int CATResGenerator::generate(int reservedSize){
    int result = 1;
    ofstream outfile;
    createDummySymbol(this->reservedSymbolFile.c_str(), this->reservedSymbolName.c_str(),reservedSize);
    outfile.close();
    return 0;
}
void CATResGenerator::setReservedSymbolName(char * symbolName){
    this->reservedSymbolName = symbolName;
}
void CATResGenerator::setReservedSymbolFile(char * fileName){
    this->reservedSymbolFile = fileName;
}
void CATResGenerator::setCatSectionName(char * sectionName){
    this->catSectionName = sectionName;
}

const char * CATResGenerator::getReservedSymbolName(){
    return this->reservedSymbolName.c_str();
}

const char * CATResGenerator::getReservedSymbolFile(){
    return this->reservedSymbolFile.c_str();
}

int CATResGenerator::createDummySymbol(const char* fileName, const char * symbolName, int size){
    const int lineElementCounts = 16;
    ofstream oss;
    oss.open( fileName);

    oss<<"#include \"CustDataRes.h\"\n"<<endl;
    oss<<"#if ( !defined (__MTK_TARGET__) )"<<endl;
    oss<<"    #define __align(x)"<<endl;
    oss<<"#endif\n"<<endl;

    if(size >0){

        oss<<"#ifdef __MTK_TARGET__"<<endl;
        oss<<"#pragma arm section rodata = \""<< this->catSectionName<<"\""<<endl;
        oss<<"#endif//Start of CAD variable size resource\n"<<endl;

        oss<<"__align(4) const U8 "<<symbolName<<"["<<size<<"] = {"<<endl;

        for(int i =0; i < size; i++){
            if(i%lineElementCounts == 0 && i!=0){
                oss<<endl;
            }
            oss<<"0x00, ";
        }

        oss<<"};\n"<<endl;

        oss<<"#ifdef __MTK_TARGET__"<<endl;
        oss<<"#pragma arm section rodata"<<endl;
        oss<<"#endif//Start of CAD variable size resource"<<endl;
    }

    oss.close();

    return 1;
}


string* CATResGenerator::createDummySymbol(const char * symbolName, int size){
    stringstream oss;
    string * result = new string("");
    const int lineElementCounts = 16;

    oss<<"#include \"CustDataRes.h\"\n"<<endl;
    oss<<"#if ( !defined (__MTK_TARGET__) )"<<endl;
    oss<<"    #define __align(x)"<<endl;
    oss<<"#endif\n"<<endl;

    oss<<"#ifdef __MTK_TARGET__"<<endl;
    oss<<"#pragma arm section rodata = \""<< this->catSectionName<<"\""<<endl;
    oss<<"#endif//Start of CAD variable size resource\n"<<endl;

    oss<<"__align(4) const U8 "<<symbolName<<"["<<size<<"] = {"<<endl;

    for(int i =0; i < size; i++){
        if(i%lineElementCounts == 0 && i!=0){
            oss<<endl;
        }
        oss<<"0x00, ";
    }

    oss<<"};\n"<<endl;

    oss<<"#ifdef __MTK_TARGET__"<<endl;
    oss<<"#pragma arm section rodata"<<endl;
    oss<<"#endif//Start of CAD variable size resource"<<endl;(*result) = oss.str();
    return result;

}
