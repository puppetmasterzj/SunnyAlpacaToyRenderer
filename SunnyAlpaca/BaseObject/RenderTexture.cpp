#include "RenderTexture.h"
#include "FBO.h"


RenderTexture::RenderTexture()
{
	fbo = new FBO();
}


RenderTexture::~RenderTexture()
{
}

void RenderTexture::UseTexture()
{
	unsigned int colorTexID = fbo->GetColorAttachmentID();
	glBindTexture(GL_TEXTURE_2D, colorTexID);
}

void RenderTexture::SetRenderTexture(RenderTexture* rt)
{
	if (rt == NULL)
		FBO::BindFrameBuffer(NULL);
	else
		FBO::BindFrameBuffer(rt->fbo);
}
