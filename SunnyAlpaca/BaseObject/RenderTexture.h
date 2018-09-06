#pragma once
#include "Texture.h"
#include "FBO.h"

class RenderTexture : public Texture
{
private:
	FBO* fbo;
public:
	RenderTexture();
	virtual ~RenderTexture();

	virtual void UseTexture();

	static void SetRenderTexture(RenderTexture* rt);
};

