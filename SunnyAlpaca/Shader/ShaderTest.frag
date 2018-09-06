#version 330 core
#pragma optimize(off)

//材质结构体
uniform struct Material
{
	sampler2D mainTex;
	sampler2D specTex;
	float shininess;
};

//灯光结构体
uniform struct PointLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};
#define POINT_LIGHT_COUNT 4

uniform struct DirectionLight
{
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 outNormal;
in vec3 outWorldPos;
in vec2 outTexcoord;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;
uniform DirectionLight light;
uniform PointLight pointlights[POINT_LIGHT_COUNT];

//计算方向光源的光照函数
vec3 CalculateDirLight(DirectionLight light, vec3 normal, vec3 viewDir)
{
	//diffuse 
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(normal, lightDir), 0.0f);
	
	//specular
	vec3 reflDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflDir), 0.0f), material.shininess);
	
	//ambient + diffuse + specular
	vec3 ambient = light.ambient * vec3(texture(material.mainTex, outTexcoord));
	vec3 diffuse = light.diffuse * vec3(texture(material.mainTex, outTexcoord)) * diff;
	vec3 specular = light.specular * vec3(texture(material.specTex, outTexcoord)) * spec;
	return ambient + diffuse + specular;
}

//计算点光源的光照函数
vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 worldPos, vec3 viewDir)
{
	//衰减
	float distance = length(light.position - worldPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	//diffuse
	vec3 lightDir = normalize(light.position - worldPos);
	float diff = max(dot(normal, lightDir), 0.0f);
	
	//specular
	vec3 reflDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflDir), 0.0f), material.shininess);
	
	//ambient + diffuse + specular
	vec3 ambient = light.ambient * vec3(texture(material.mainTex, outTexcoord));
	vec3 diffuse = light.diffuse * vec3(texture(material.mainTex, outTexcoord)) * diff;
	vec3 specular = light.specular * vec3(texture(material.specTex, outTexcoord)) * spec;
	return (diffuse + ambient + specular) * attenuation;
}

void main()
{
	vec3 normal = normalize(outNormal);
	vec3 viewDir = normalize(viewPos - outWorldPos);
	
	vec3 outColor = CalculateDirLight(light, normal, viewDir);
	for(int i = 0; i < POINT_LIGHT_COUNT; i++)
	{
		outColor += CalculatePointLight(pointlights[i], normal, outWorldPos, viewDir);
	}
	color = vec4(outColor, 1.0f);
}