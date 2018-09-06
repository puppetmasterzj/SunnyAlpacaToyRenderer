/*!
 * \file NativeGLDevice.h
 *
 * \author zhangjian
 * \date 2017.5.14
 *
 * \OpenGLAPI²ãµÄ·â×°
 */
#pragma once
#include "../Common/ApcUtility.h"
#include "../BaseObject/Shader.h"
#include "../Baseobject/Texture.h"
#include "../BaseObject/Camera.h"
#include "../Baseobject/FBO.h"
#include "../BaseObject/RenderTexture.h"
#include "RenderManager.h"
#include "OpenGLApi.h"
#include "../RenderObject/RenderObject.h"


class NativeGLDevice
{
private:
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;
	static NativeGLDevice* instance;
	OpenGLApi* renderAPI;
	RenderObject* plane;
	RenderTexture* rt;
public:
	NativeGLDevice();
	~NativeGLDevice();

	static NativeGLDevice* GetInstance();

	void Init();
	void Draw(GLFWwindow* window);

	static int GetWindowHeight() { return WINDOW_HEIGHT; }
	static int GetWindowWidth() { return WINDOW_WIDTH; }

	Camera* GetCurrentCamera() { return RenderManager::GetRenderManager()->GetCurrentCamera(); }
	OpenGLApi* GetRenderAPI() { return renderAPI; }
};

