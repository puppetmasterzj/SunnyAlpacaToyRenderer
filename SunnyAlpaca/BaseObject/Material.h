#pragma once
#include "../Common/ApcUtility.h"
#include "Texture.h"
#include "Shader.h"
#include "../RenderObject/RenderObject.h"
#include "../RenderEngine/RenderDefine.h"

class RenderObject;

struct MaterialTextureInfo
{
public:
	std::string texturePath;
	Texture* texture;
};
typedef std::map<std::string, MaterialTextureInfo> MaterialTexMap;

class Material
{
private:
	Shader* m_Shader;
	std::string VertShaderName;
	std::string FragShaderName;
	MaterialTexMap TextureMap;
	int m_RenderQueue;
	ZTestOption ZTestOp;
	ZWriteOption ZWriteOp;
	CullOption CullOp;	
public:
	Material();
	virtual ~Material();

	void Use(RenderObject* renderer);
	void SetCommonProperty();
	void SetRenderState();
	void InitMaterialFromJson(char* fileName);
	void SetTexture(std::string slotName, Texture* texture);
};

