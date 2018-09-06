#include "TextureCube.h"



TextureCube::TextureCube()
{
}


TextureCube::~TextureCube()
{
}

void TextureCube::InitTexture(const GLchar* name)
{
	glGenTextures(1, &m_GLTexture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_GLTexture);
	int width, height, channel;
	for (unsigned int i = 0; i < 6; i++)
	{
		unsigned char* image = SOIL_load_image((std::string(name) + std::string(texNameArray[i]) + ".jpg").c_str(), &width, &height, &channel, 0);
		if (image != nullptr)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		}
		else
		{
			std::cout << "Load Cube Image Error" << name << std::endl;
		}
		SOIL_free_image_data(image);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	}
}

void TextureCube::UseTexture()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_GLTexture);
}
