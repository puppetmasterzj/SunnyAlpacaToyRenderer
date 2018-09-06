#pragma once

#include "../BaseObject/Material.h"
#include "../BaseObject/Mesh.h"
#include "../Common/ApcUtility.h"

class Material;
class RenderObject
{
protected:
	Material* m_Material;
	Mesh* m_Mesh;
	Vector3 worldPosition;
	Vector3 worldRotation;
	Vector3 worldScale;

public:
	RenderObject();
	virtual ~RenderObject();

	Matrix4x4 GenerateWorldMatrix();

	void SetMaterial(Material* mat) { m_Material = mat; }
	Material* GetMaterial() { return m_Material; }

	void SetMesh(Mesh* mesh) { m_Mesh = mesh; }
	Mesh* GetMesh() { return m_Mesh; }

	void SetPosition(Vector3 pos) { worldPosition = pos; }
	Vector3 GetPosition() { return worldPosition; }

	void SetScale(Vector3 scale) { worldScale = scale; }
	Vector3 GetScale() { return worldScale; }

	void SetCommonShaderParam();
	virtual void DoRender();
};

