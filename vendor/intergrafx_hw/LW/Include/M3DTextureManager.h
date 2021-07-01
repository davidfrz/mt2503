//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3D_LW_Lib
// File        : M3DTextureManager.h
// Description : M3D Texture Manager : 
// Author      : Ray
// Create      : 2011-08-03
// Update      : 2011-08-03
//==============================================================================

#ifndef __M3D_TEXTURE_MANAGER_H__
#define __M3D_TEXTURE_MANAGER_H__

#include "M3DUtils.h"
#include "IGV5Texture.h"
#include "IGV5DataCache.h"

#include "Shaders\IGV5UVDisplacementShader.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

//========== �ϥΤ覡 = �o��n���g =================================================================================================
// (1) �b V3Retained_InitEngine �̭��|�I�s V3TextureCollection_Init(), V3Retained_End �̭��|�I�s V3TextureCollection_Release()
//     �ҥH�{�����ݭn�_�l������K��
// (2) �@�ߥζK�ϦW�� (�ɦW) �Ӧs���K��, �W�٤��n����, ���L�t�Ψä��|�ˬd���ƦW��
// (3) V3UI ����|��J�@�Ǧ@�ζK��, �W�ٽаѦ� V3UI
// (4) �ۦ�s�W�K�ϽХ� V3TextureCollection_Add
// (5) ���o�K�ϽХ� V3TextureCollection_Get
//=============================================================================================================================

struct _M3DTextureCollection
{
	void		*m_rr;		//M3DRenderer
	M3DArray		*m_Textures;
	M3DArray		*m_TexturesNormal;
	M3DArray		*m_TexturesAlpha;
	M3DArray		*m_TexturesUVAnim;
	float			m_UVAnimTimeFactorU;
	float			m_UVAnimTimeFactorV;
	
	IGV5UVDisplacementShaderProgram* uvDisplacementShader;
};

typedef struct _M3DTextureCollection M3DTextureCollection;

extern void M3DTextureCollection_Init(M3DTextureCollection *_this, void *_rr);
extern void M3DTextureCollection_Add(M3DTextureCollection *_this, char *_tex_name, unsigned char const *_data, unsigned char const *_data_n, unsigned char const *_data_a);
extern void M3DTextureCollection_AddFromFile(M3DTextureCollection *_this, char *_tex_name, char *_filepath);
extern void M3DTextureCollection_AddFromMem(M3DTextureCollection *_this, char *_tex_name, unsigned char const *_data);
extern void M3DTextureCollection_Map(M3DTextureCollection *_this, char *_tex_name, char *_normal_tex_name, char *_alpha_tex_name);
extern void M3DTextureCollection_MapAlpha(M3DTextureCollection *_this, char *_tex_name, char *_alpha_tex_name);
extern void M3DTextureCollection_AddUVAnim(M3DTextureCollection *_this, char *_tex_name);
extern int  M3DTextureCollection_IsUVAnim(M3DTextureCollection *_this, char *_tex_name);

extern void M3DTextureCollection_AddFromFile_old(M3DTextureCollection *_this, char *_filename, int _bNormal, int _bAlpha);
extern void M3DTextureCollection_AddFromFiles(M3DTextureCollection *_this, M3DSplitString *_filenames);
extern void M3DTextureCollection_Remove(M3DTextureCollection *_this, const char *_tex_name);
extern void M3DTextureCollection_Release(M3DTextureCollection *_this);
extern IGV5Texture *M3DTextureCollection_Get(M3DTextureCollection *_this, const char *_name);
extern void M3DTextureCollection_GetByNames(M3DTextureCollection *_this, M3DSplitString *_names, IGV5NameCache *_cache);
extern void M3DTextureCollection_Bind(M3DTextureCollection *_this, const char *_name);

extern void M3DTextureCollection_SetUVAnimTimeFactor(M3DTextureCollection *_this, float _time_factor_u, float _time_factor_v);

//CY: quick way to reduce texture size by 25%
extern void M3DTextureCollection_SetMipLevelStart(int iL);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif