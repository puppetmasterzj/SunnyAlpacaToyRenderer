#include "FBO.h"



FBO::FBO()
{
	Create();
}


FBO::~FBO()
{
	Destory();
}

void FBO::Create()
{
	glGenFramebuffers(1, &fboID);
	glBindFramebuffer(GL_FRAMEBUFFER, fboID);
	GenColorAttachment();
	GenDepthAttachment();
	//check
	if (!glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
		std::cout << "Crate Frame Buffer Erroer" << std::endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FBO::Destory()
{
	glDeleteFramebuffers(1, &fboID);
}

void FBO::GenColorAttachment()
{
	glGenTextures(1, &colorTexID);
	glBindTexture(GL_TEXTURE_2D, colorTexID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexID, 0);
}

void FBO::GenDepthAttachment()
{
	glGenTextures(1, &depthTexID);
	glBindTexture(GL_TEXTURE_2D, depthTexID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, 800, 600, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, depthTexID, 0);
}

void FBO::BindFrameBuffer(FBO* fbo)
{
	if (fbo == NULL)
	{
		if (currentFBOID != 0)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			currentFBOID = 0;
		}
	}
	else if (currentFBOID != fbo->fboID)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, fbo->fboID);
		currentFBOID = fbo->fboID;
	}
}

unsigned int FBO::currentFBOID = 0;
