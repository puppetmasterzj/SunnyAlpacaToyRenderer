#version 330 core



in vec3 outTexcoord;
out vec4 color;

uniform samplerCube cubemap;

void main()
{
	color = texture(cubemap, outTexcoord);
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	//color = vec4(outTexcoord.x, outTexcoord.y, 0.0f, 1.0f);
}