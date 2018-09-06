#include "SkyBox.h"

SkyBox::SkyBox()
{
	mat = new Material();
	mat->InitMaterialFromJson("Material/Skybox.mtl");
	SetMaterial(mat);

	mesh = new Mesh();
	mesh->InitCube();
	SetMesh(mesh);

	cubeMap = new TextureCube();
	cubeMap->InitTexture("Texture/skybox1");
}


SkyBox::~SkyBox()
{
}

void SkyBox::DoRender()
{
	mat->SetTexture("cubemap", cubeMap);
	mat->Use(this);
	mesh->Render();
}
