#pragma once
#include "../Common/ApcUtility.h"
#include "../BaseObject/Camera.h"
#include "../RenderObject/RenderObject.h"
#include <list>

typedef std::list<Camera*> CameraList;
typedef std::list<RenderObject*> RenderObjList;

class RenderManager
{
private:
	CameraList m_CameraList;
	Camera* m_CurrentCamera;
	RenderObjList m_RenderObjectList;
	static RenderManager* gRenderManager;
public:
	RenderManager();
	~RenderManager();

	void AddCamera(Camera* cam);
	void RemoveCamera(Camera* cam);

	Camera* GetCurrentCamera() { return m_CurrentCamera; }
	void SetCurrentCamera(Camera* cam) { m_CurrentCamera = cam; }

	void DoRenderer();

	void AddRenderObject(RenderObject* obj);
	void RemoveRenderObject(RenderObject* obj);
	RenderObjList* GetRenderObjectList() { return &m_RenderObjectList; }

	static RenderManager* GetRenderManager();
};




