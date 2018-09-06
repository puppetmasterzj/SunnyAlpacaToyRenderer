#include "Material.h"
#include "../RenderEngine/RenderManager.h"
#include "../RenderEngine/OpenGLApi.h"
#include "../RenderEngine/NativeGLDevice.h"

Material::Material()
{
	//InitMaterialFromJson("Material/SimpleTest.mtl");
}


Material::~Material()
{
}

void Material::InitMaterialFromJson(char* fileName)
{
	//从文件读取shader到字符串
	std::string jsonText;
	std::ifstream fileStream;
	fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		fileStream.open(fileName);
		std::stringstream stringStream;
		stringStream << fileStream.rdbuf();
		fileStream.close();
		jsonText = stringStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "Init Material From Json Failed" << fileName << std::endl;
	}
	Document document;
	if (!document.Parse(jsonText.c_str()).HasParseError())
	{
		VertShaderName = std::string(document[VariableName(VertShaderName)].GetString());
		FragShaderName = std::string(document[VariableName(FragShaderName)].GetString());
		ZTestOp = (ZTestOption)document[VariableName(ZTestOp)].GetInt();
		ZWriteOp = (ZWriteOption)document[VariableName(ZWriteOp)].GetInt();
		CullOp = (CullOption)document[VariableName(CullOp)].GetInt();
		if (document.HasMember(VariableName(TextureMap)))
		{
			Value& texArray = document[VariableName(TextureMap)];
			if (texArray.IsArray())
			{
				for (unsigned int i = 0; i < texArray.Size(); ++i)
				{
					Value& v = texArray[i];
					if (v.IsObject())
					{
						std::string slotName;
						std::string texPath;
						if (v.HasMember("SlotName"))
						{
							slotName = v["SlotName"].GetString();
						}
						if (v.HasMember("TexPath"))
						{
							texPath = v["TexPath"].GetString();
						}
						Texture* tex = new Texture();
						tex->InitTexture(texPath.c_str());
						MaterialTextureInfo info;
						info.texturePath = texPath;
						info.texture = tex;
						TextureMap[slotName] = info;
					}
				}
			}
		}
	}

	//初始化shader
	m_Shader = new Shader();
	m_Shader->InitShader(VertShaderName.c_str(), FragShaderName.c_str());
}

void Material::SetRenderState()
{
	OpenGLApi* api = NativeGLDevice::GetInstance()->GetRenderAPI();
	api->SetRasterCullMode(CullOp);
	api->SetZTestOption(ZTestOp);
	api->SetZWriteOption(ZWriteOp);
}

void Material::Use(RenderObject* renderer)
{
	SetRenderState();

	m_Shader->UseShader();
	Camera* cam = RenderManager::GetRenderManager()->GetCurrentCamera();
	
	//view矩阵
	Matrix4x4 viewMat = cam->GetViewMatrix();
	m_Shader->SetPropertyMatrix4x4(viewMatrix, viewMat);

	//投影矩阵
	Matrix4x4 projMat = cam->GetProjMatrix();
	m_Shader->SetPropertyMatrix4x4(projMatrix, projMat);

	//Model矩阵
	m_Shader->SetPropertyMatrix4x4(modelMatrix, renderer->GenerateWorldMatrix());

	//设置其他Uniform变量
	//m_GLShader->SetPropertyVec3("viewPos", m_Camera->m_vPosition);
	int index = 0;
	for (MaterialTexMap::iterator it = TextureMap.begin(); it != TextureMap.end(); ++it)
	{
		m_Shader->SetPropertyTexture(it->first.c_str(), it->second.texture, index++);
	}
	////设置贴图
	//m_Shader->SetPropertyTexture2D("material.mainTex", m_Texture1, GL_TEXTURE0, 0);
	//m_GLShader->SetPropertyTexture2D("material.specTex", m_Texture2, GL_TEXTURE1, 1);

}

void Material::SetCommonProperty()
{

}

void Material::SetTexture(std::string slotName, Texture* texture)
{
	MaterialTextureInfo info;
	info.texturePath = "";
	info.texture = texture;
	TextureMap[slotName] = info;
}