#include "OpenGLApi.h"
#include "../Common/ApcUtility.h"

OpenGLApi::OpenGLApi()
{
}


OpenGLApi::~OpenGLApi()
{
}

void OpenGLApi::SetZWriteOption(ZWriteOption option)
{
	if (curZWriteOption == option)
		return;
	switch (option)
	{
	case ZWriteOn:
		glDepthMask(GL_TRUE);
		break;
	case ZWriteOff:
		glDepthMask(GL_FALSE);
		break;
	}
	curZWriteOption = option;
}

void OpenGLApi::SetZTestOption(ZTestOption option)
{
	if (curZTestOption == option)
		return;
	switch (option)
	{
	case ZTestLEqual:
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		break;
	case ZTestAlways:
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_ALWAYS);
		break;
	case ZTestLess:
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		break;
	case ZTestEqual:
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_EQUAL);
		break;
	case ZTestGreater:
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_GREATER);
		break;
	case ZTestGEqual:
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_GEQUAL);
		break;
	default:
		break;
	}
	curZTestOption = option;
}

void OpenGLApi::SetRasterCullMode(CullOption option)
{
	if (curCullOption == option)
		return;
	switch (option)
	{
	case CullBack:
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		break;
	case CullFront:
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		break;
	case CullOff:
		glDisable(GL_CULL_FACE);
		break;
	default:
		break;
	}
	curCullOption = option;
}


