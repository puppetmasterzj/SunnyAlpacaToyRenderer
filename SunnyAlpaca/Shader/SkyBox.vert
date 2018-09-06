#version 330 core
layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;

//out vec3 ourColor;
out vec3 outNormal;
out vec3 outWorldPos;
out vec3 outTexcoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

void main()
{
	//gl_Position = vec4(position, 1.0f);
    gl_Position = projMat * viewMat * vec4(position, 1.0f);
	gl_Position.z = gl_Position.w;
    outTexcoord = position;
	
}