/*!
* \file Texture.h
*
* \author zhangjian
* \date 2017.12.26
*
* \Cube Map
*/
#pragma once
#include "Texture.h"
class TextureCube : public Texture
{
private:
	const char* texNameArray[6] = { "right", "left", "top", "bottom", "back", "front"};
public:
	TextureCube();
	~TextureCube();
	
	virtual void InitTexture(const GLchar* name);
	virtual void UseTexture();
};

