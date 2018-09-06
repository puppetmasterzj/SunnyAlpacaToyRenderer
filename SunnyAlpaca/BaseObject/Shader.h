/*!
 * \file Shader.h
 *
 * \author zhangjian
 * \date 2017.5.14
 *
 * \shader加载创建控制器
 */
#pragma once
#include "../Common/ApcUtility.h"
#include "Texture.h"

class Shader
{
private:
	GLuint m_ShaderProgram;
	GLchar* m_ShaderName;

	//将texture index与TextureEnum对应起来
	GLenum ShaderTextureSlotHelper(int id);
public:
	Shader();
	~Shader();

	GLuint GetShaderProgram() { return m_ShaderProgram; }

	GLchar* GetShaderName() { return m_ShaderName; }
	void SetShaderName(GLchar* name) { m_ShaderName = name; }

	void InitShader(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath);
	void UseShader();
	bool IsShaderValid() { return m_ShaderProgram != INVALID_VALUE; }

	void SetPropertyVec4(const GLchar* propertyName, Vector4& vec);
	void SetPropertyVec3(const GLchar* propertyName, Vector3& vec);
	void SetPropertyMatrix4x4(const GLchar* propertyName, Matrix4x4& mat);
	void SetPropertyFloat(const GLchar* propertyName, float value);
	void SetPropertyTexture(const GLchar* propertyName, Texture* texture, int id);
};


