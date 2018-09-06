/*!
* \file FBO.h
*
* \author zhangjian
* \date 2017.12.24
*
* \Frame Buffer Object, OpenGL
*/
#pragma once
#include "../Common/ApcUtility.h"
class FBO
{
private:
	unsigned int fboID;
	unsigned int colorTexID;
	unsigned int depthTexID;

	static unsigned int currentFBOID;
public:
	FBO();
	~FBO();

	void Create();
	void Destory();

	void GenColorAttachment();
	void GenDepthAttachment();

	static void BindFrameBuffer(FBO* fbo);

	unsigned int GetColorAttachmentID() { return colorTexID; }
	unsigned int GetDepthAttachmentID() { return depthTexID; }
};

