#version 330 core

in vec2 outTexcoord;
out vec4 color;

uniform sampler2D _MainTex;

void main()
{
	color = texture(_MainTex, outTexcoord);
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	//color = vec4(outTexcoord.x, outTexcoord.y, 0.0f, 1.0f);
}