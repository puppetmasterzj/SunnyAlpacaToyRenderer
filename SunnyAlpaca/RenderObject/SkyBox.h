
#pragma once
#include "../Common/ApcUtility.h"
#include "RenderObject.h"
#include "../BaseObject/TextureCube.h"

class SkyBox : public RenderObject
{
private:
	Material* mat;
	Mesh* mesh;
	Texture* cubeMap;
public:
	SkyBox();
	~SkyBox();

	virtual void DoRender();
};

