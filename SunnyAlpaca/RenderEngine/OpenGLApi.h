#pragma once
#include "RenderDefine.h"

class OpenGLApi
{
private:
	CullOption curCullOption;
	ZTestOption curZTestOption;
	ZWriteOption curZWriteOption;
public:
	OpenGLApi();
	~OpenGLApi();

	void SetRasterCullMode(CullOption option);
	void SetZTestOption(ZTestOption option);
	void SetZWriteOption(ZWriteOption option);
	void SetBlendOption() {};
};

