//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3TextureManager.h
// Description : V3 Texture Manager : V3 �����K�Ϻ޲z
// Author      : Ray
// Create      : 2011-01-26
// Update      : 2011-02-15
//==============================================================================

#ifndef __V3_TEXTURE_MANAGER_H__
#define __V3_TEXTURE_MANAGER_H__

#include "CUtils.h"
#include "IGTexture.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

//========== �ϥΤ覡 =========================================================================================================
// (1) �b V3Retained_InitEngine �̭��|�I�s V3TextureCollection_Init(), V3Retained_End �̭��|�I�s V3TextureCollection_Release()
//     �ҥH�{�����ݭn�_�l������K��
// (2) �@�ߥζK�ϦW�� (�ɦW) �Ӧs���K��, �W�٤��n����, ���L�t�Ψä��|�ˬd���ƦW��
// (3) V3UI ����|��J�@�Ǧ@�ζK��, �W�ٽаѦ� V3UI
// (4) �ۦ�s�W�K�ϽХ� V3TextureCollection_Add
// (5) ���o�K�ϽХ� V3TextureCollection_Get
//=============================================================================================================================

struct _V3TextureCollection
{
	CArray	*m_Textures;
};

extern struct _V3TextureCollection V3TextureCollection;

extern void V3TextureCollection_Init(void);
extern void V3TextureCollection_Add(const char *_name, unsigned char *_buf, int _keycolor);
extern void V3TextureCollection_Release(void);
extern IGTexture *V3TextureCollection_Get(const char *_name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif