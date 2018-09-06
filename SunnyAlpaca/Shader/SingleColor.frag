#version 330 core

//材质结构体
uniform struct Material
{
	sampler2D mainTex;
	sampler2D specTex;
	float shininess;
};


in vec2 outTexcoord;
out vec4 color;

uniform Material material;

void main()
{
	color = texture(material.mainTex, outTexcoord);
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	//color = vec4(outTexcoord.x, outTexcoord.y, 0.0f, 1.0f);
}