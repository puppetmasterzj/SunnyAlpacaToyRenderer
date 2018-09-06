#version 330 core
layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;

//out vec3 ourColor;
out vec3 outNormal;
out vec3 outWorldPos;
out vec2 outTexcoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
	//gl_Position = vec4(position, 1.0f);
    gl_Position = projMat * viewMat * modelMat * vec4(position, 1.0f);
    outNormal = mat3(transpose(inverse(modelMat))) * normal;
	outWorldPos = vec3(modelMat * vec4(position, 1.0f));
	//ourColor = color;
	outTexcoord = vec2(texcoord.x, 1 - texcoord.y);
}