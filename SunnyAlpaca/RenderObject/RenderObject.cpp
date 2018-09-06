#include "RenderObject.h"



RenderObject::RenderObject()
{
	worldPosition = Vector3(0, 0, 0);
	worldScale = Vector3(1, 1, 1);
}


RenderObject::~RenderObject()
{
}

void RenderObject::DoRender()
{
	m_Material->Use(this);
	m_Mesh->Render();
}

Matrix4x4 RenderObject::GenerateWorldMatrix() 
{
	Matrix4x4 matrix;
	matrix = glm::translate(matrix, worldPosition);
	matrix = glm::scale(matrix, worldScale);
	//TODO: Rotation & avoid Copy Constructor?
	return matrix;
}

void RenderObject::SetCommonShaderParam()
{

}


