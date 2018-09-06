#include "RenderManager.h"



RenderManager::RenderManager()
{

}


RenderManager::~RenderManager()
{

}

void RenderManager::AddCamera(Camera* cam)
{
	m_CameraList.push_back(cam);
}

void RenderManager::RemoveCamera(Camera* cam)
{
	m_CameraList.remove(cam);
}

void RenderManager::AddRenderObject(RenderObject* obj)
{
	m_RenderObjectList.push_back(obj);
}

void RenderManager::RemoveRenderObject(RenderObject* obj)
{
	m_RenderObjectList.remove(obj);
}

void RenderManager::DoRenderer()
{
	for (CameraList::iterator i = m_CameraList.begin(); i != m_CameraList.end(); i++)
	{
		Camera* cam = *i;
		SetCurrentCamera(cam);
		cam->Render();
	}
}

RenderManager* RenderManager::gRenderManager = NULL;

RenderManager* RenderManager::GetRenderManager()
{
	if (gRenderManager == NULL)
		gRenderManager = new RenderManager();
	return gRenderManager;
}



