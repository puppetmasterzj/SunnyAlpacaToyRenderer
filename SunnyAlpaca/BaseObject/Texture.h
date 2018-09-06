/*!
 * \file Texture.h
 *
 * \author zhangjian
 * \date 2017.5.21
 *
 * \ÌùÍ¼»ùÀà 
 */
#pragma once
#include "../Common/ApcUtility.h"

class Texture
{
protected:
	GLuint m_GLTexture;
	GLchar* m_TextureName;
public:
	Texture();
	~Texture();

	GLuint  GetGLTexture() { return m_GLTexture; }
	GLchar* GetTextureName() { return m_TextureName; }

	virtual void InitTexture(const GLchar* name);
	virtual void UseTexture();
};

