#include "Shader.h"

Shader::Shader()
	: m_ShaderProgram(INVALID_VALUE)
{
	
}


Shader::~Shader()
{
}

void Shader::InitShader(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath)
{
	//从文件读取shader到字符串
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		vShaderFile.open(vertexShaderPath);
		std::stringstream vShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		vShaderFile.close();
		vertexCode = vShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "Load Vertex Shader File Failed:" << std::endl;
	}

	try
	{
		fShaderFile.open(fragmentShaderPath);
		std::stringstream fShaderStream;
		fShaderStream << fShaderFile.rdbuf();
		fShaderFile.close();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "Load Fragment Shader File Failed:" << std::endl;
	}
	
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();

	GLint success;
	GLchar infoLog[512];
	//创建并编译vertex shader
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);
	
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Compile Vertex Shader Failed:" << infoLog << std::endl;
		return;
	}

	//创建并编译fragment shader
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Compile Fragment Shader Failed:" << infoLog << std::endl;
		return;
	}

	//创建shader program并链接
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Link Shader Program Failed:" << infoLog << std::endl;
		return;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	m_ShaderProgram = shaderProgram;
}

void Shader::UseShader()
{
	if (m_ShaderProgram)
	{
		glUseProgram(m_ShaderProgram);
	}
}

void Shader::SetPropertyVec4(const GLchar* propertyName, Vector4& vec)
{
	GLint location = glGetUniformLocation(m_ShaderProgram, propertyName);
	if (location == INVALID_VALUE)
	{
		//std::cout << "shader doesn't have property: " << propertyName << std::endl;
		return;
	}
	glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}

void Shader::SetPropertyVec3(const GLchar* propertyName, Vector3& vec)
{
	GLint location = glGetUniformLocation(m_ShaderProgram, propertyName);
	if (location == INVALID_VALUE)
	{
		//std::cout << "shader doesn't have property: " << propertyName << std::endl;
		return;
	}
	glUseProgram(m_ShaderProgram);
	glUniform3f(location, vec.x, vec.y, vec.z);
}

void Shader::SetPropertyMatrix4x4(const GLchar* propertyName, Matrix4x4& mat)
{
	GLint location = glGetUniformLocation(m_ShaderProgram, propertyName);
	if (location == INVALID_VALUE)
	{
		//std::cout << "shader doesn't have property: " << propertyName << std::endl;
		return;
	}
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetPropertyFloat(const GLchar* propertyName, float value)
{
	GLint location = glGetUniformLocation(m_ShaderProgram, propertyName);
	if (location == INVALID_VALUE)
	{
		//std::cout << "shader doesn't have property: " << propertyName << std::endl;
		return;
	}
	glUniform1f(location, value);
}

void Shader::SetPropertyTexture(const GLchar* propertyName, Texture* texture, int id)
{
	GLint location = glGetUniformLocation(m_ShaderProgram, propertyName);
	if (location == INVALID_VALUE)
	{
		//std::cout << "shader doesn't have property: " << propertyName << std::endl;
		return;
	}
	glActiveTexture(ShaderTextureSlotHelper(id));
	texture->UseTexture();
	glUniform1i(location, id);
}

//为了方便，先这么干吧。。。。
GLenum Shader::ShaderTextureSlotHelper(int id)
{
	switch (id)
	{
	case 0: return GL_TEXTURE0;
	case 1: return GL_TEXTURE1;
	case 2: return GL_TEXTURE2;
	case 3: return GL_TEXTURE3;
	case 4: return GL_TEXTURE4;
	case 5: return GL_TEXTURE5;
	case 6: return GL_TEXTURE6;
	case 7: return GL_TEXTURE7;
	case 8: return GL_TEXTURE8;
	case 9: return GL_TEXTURE9;
	case 10: return GL_TEXTURE10;
	case 11: return GL_TEXTURE11;
	case 12: return GL_TEXTURE12;
	case 13: return GL_TEXTURE13;
	case 14: return GL_TEXTURE14;
	case 15: return GL_TEXTURE15;
	case 16: return GL_TEXTURE16;
	case 17: return GL_TEXTURE17;
	case 18: return GL_TEXTURE18;
	case 19: return GL_TEXTURE19;
	case 20: return GL_TEXTURE20;
	case 21: return GL_TEXTURE21;
	case 22: return GL_TEXTURE22;
	case 23: return GL_TEXTURE23;
	case 24: return GL_TEXTURE24;
	case 25: return GL_TEXTURE25;
	case 26: return GL_TEXTURE26;
	case 27: return GL_TEXTURE27;
	case 28: return GL_TEXTURE28;
	case 29: return GL_TEXTURE29;
	case 30: return GL_TEXTURE30;
	case 31: return GL_TEXTURE31;
	}
}
