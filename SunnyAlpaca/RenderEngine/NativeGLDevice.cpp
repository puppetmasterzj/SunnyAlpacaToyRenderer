#include "NativeGLDevice.h"
#include "../RenderObject/SkyBox.h"
#include "../RenderObject/RenderObject.h"

NativeGLDevice::NativeGLDevice()
{
}


NativeGLDevice::~NativeGLDevice()
{
}

int NativeGLDevice::WINDOW_HEIGHT = 768;
int NativeGLDevice::WINDOW_WIDTH = 1024;

void NativeGLDevice::Init()
{
	renderAPI = new OpenGLApi();
	RenderManager::GetRenderManager()->AddCamera(new Camera(Vector3(0, 0, 0), Vector3(0, 1, 0), 0.0f, 0.0f));
	for (int i = 0; i < 10; ++i)
	{
		RenderObject* obj = new RenderObject();
		Mesh* mesh = new Mesh();
		mesh->InitCube();
		obj->SetMesh(mesh);
		Material* mat = new Material();
		mat->InitMaterialFromJson("Material/SimpleTest.mtl");
		obj->SetMaterial(mat);
		obj->SetPosition(Vector3(i * 3, 0, 0));
		RenderManager::GetRenderManager()->AddRenderObject(obj);
	}
	plane = new RenderObject();
	Mesh* planMesh = new Mesh();
	planMesh->InitPlane();
	Material* postEffectMat = new Material();
	postEffectMat->InitMaterialFromJson("Material/PostEffectTest.mtl");
	plane->SetMaterial(postEffectMat);
	plane->SetMesh(planMesh);
	plane->SetPosition(Vector3(10, 1, -2));
	//RenderManager::GetRenderManager()->AddRenderObject(plane);

	SkyBox* sky = new SkyBox();
	RenderManager::GetRenderManager()->AddRenderObject(sky);

	rt = new RenderTexture();
}

void NativeGLDevice::Draw(GLFWwindow* window)
{
	RenderTexture::SetRenderTexture(rt);
	//Clear颜色缓存区，深度，模板
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	RenderManager::GetRenderManager()->DoRenderer();

	RenderTexture::SetRenderTexture(NULL);

	//Clear颜色缓存区，深度，模板
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	plane->GetMaterial()->SetTexture(mainTexture, rt);
	plane->DoRender();
	//前后缓冲区交换
	glfwSwapBuffers(window);
}

NativeGLDevice* NativeGLDevice::GetInstance()
{
	if (instance == NULL)
		instance = new NativeGLDevice();
	return instance;
}

NativeGLDevice* NativeGLDevice::instance = NULL;


//废弃
/*
if (!m_GLShader->IsShaderValid())
return;
m_GLShader->UseShader();

/*if (!m_SingleColorShader->IsShaderValid())
return;
m_SingleColorShader->UseShader();


//return;
//视矩阵
Matrix4x4 viewMat = m_Camera->GetViewMatrix();
m_GLShader->SetPropertyMatrix4x4("viewMat", viewMat);

//投影矩阵
Matrix4x4 projMat = m_Camera->GetProjMatrix();
m_GLShader->SetPropertyMatrix4x4("projMat", projMat);


//设置其他Uniform变量
//m_GLShader->SetPropertyVec3("viewPos", m_Camera->m_vPosition);

////设置贴图
//m_GLShader->SetPropertyTexture2D("material.mainTex", m_Texture1, GL_TEXTURE0, 0);
//m_GLShader->SetPropertyTexture2D("material.specTex", m_Texture2, GL_TEXTURE1, 1);
////设置Material相关属性
//m_GLShader->SetPropertyFloat("material.shininess", 256.0f);
//
////设置light相关属性
//m_GLShader->SetPropertyVec3("light.direction", Vector3(0.0f, -1.0f, 0.0f));
////m_GLShader->SetPropertyVec3("light.position", Vector3(1.0f, 0.5f, 0.3f));
//m_GLShader->SetPropertyVec3("light.ambient", Vector3(0.2f, 0.2f, 0.2f));
//m_GLShader->SetPropertyVec3("light.diffuse", Vector3(0.0f, 1.0f, 1.0f));
//m_GLShader->SetPropertyVec3("light.specular", Vector3(1.0f, 1.0f, 1.0f));

glm::vec3 pointLightPositions[4] = {
	glm::vec3(0.7f,  0.2f,  2.0f),
	glm::vec3(2.3f, -3.3f, -4.0f),
	glm::vec3(-4.0f,  2.0f, -12.0f),
	glm::vec3(0.0f,  0.0f, -3.0f)
};

//设置PointLight相关属性
// point light 1
//m_GLShader->SetPropertyVec3("pointlights[0].position", pointLightPositions[0]);
//m_GLShader->SetPropertyVec3("pointlights[0].ambient", Vector3(0.05f, 0.05f, 0.05f));
//m_GLShader->SetPropertyVec3("pointlights[0].diffuse", Vector3(0.8f, 0.0f, 0.0f));
//m_GLShader->SetPropertyVec3("pointlights[0].specular", Vector3(1.0f, 1.0f, 1.0f));
//m_GLShader->SetPropertyFloat("pointlights[0].constant", 1.0f);
//m_GLShader->SetPropertyFloat("pointlights[0].linear", 0.09);
//m_GLShader->SetPropertyFloat("pointlights[0].quadratic", 0.032);
//// point light 2
//m_GLShader->SetPropertyVec3("pointlights[1].position", pointLightPositions[1]);
//m_GLShader->SetPropertyVec3("pointlights[1].ambient", Vector3(0.05f, 0.05f, 0.05f));
//m_GLShader->SetPropertyVec3("pointlights[1].diffuse", Vector3(0.0f, 0.0f, 0.8f));
//m_GLShader->SetPropertyVec3("pointlights[1].specular", Vector3(1.0f, 1.0f, 1.0f));
//m_GLShader->SetPropertyFloat("pointlights[1].constant", 1.0f);
//m_GLShader->SetPropertyFloat("pointlights[1].linear", 0.09);
//m_GLShader->SetPropertyFloat("pointlights[1].quadratic", 0.032);
//// point light 3
//m_GLShader->SetPropertyVec3("pointlights[2].position", pointLightPositions[2]);
//m_GLShader->SetPropertyVec3("pointlights[2].ambient", Vector3(0.05f, 0.05f, 0.05f));
//m_GLShader->SetPropertyVec3("pointlights[2].diffuse", Vector3(0.8f, 0.8f, 0.0f));
//m_GLShader->SetPropertyVec3("pointlights[2].specular", Vector3(1.0f, 1.0f, 1.0f));
//m_GLShader->SetPropertyFloat("pointlights[2].constant", 1.0f);
//m_GLShader->SetPropertyFloat("pointlights[2].linear", 0.09);
//m_GLShader->SetPropertyFloat("pointlights[2].quadratic", 0.032);
//// point light 4
//m_GLShader->SetPropertyVec3("pointlights[3].position", pointLightPositions[3]);
//m_GLShader->SetPropertyVec3("pointlights[3].ambient", Vector3(0.05f, 0.05f, 0.05f));
//m_GLShader->SetPropertyVec3("pointlights[3].diffuse", Vector3(0.0f, 0.8f, 0.0f));
//m_GLShader->SetPropertyVec3("pointlights[3].specular", Vector3(1.0f, 1.0f, 1.0f));
//m_GLShader->SetPropertyFloat("pointlights[3].constant", 1.0f);
//m_GLShader->SetPropertyFloat("pointlights[3].linear", 0.09);
//m_GLShader->SetPropertyFloat("pointlights[3].quadratic", 0.032);

glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
};

for (int i = 0; i < 10; i++)
{
	//模型转世界矩阵
	Matrix4x4 modelMat;
	modelMat = glm::translate(modelMat, cubePositions[i]);
	//modelMat = glm::rotate(modelMat, (GLfloat)glfwGetTime(), Vector3(1.0f, 0.0f, 0.0f));
	modelMat = glm::scale(modelMat, Vector3(0.3f, 0.3f, 0.3f));
	m_GLShader->SetPropertyMatrix4x4("modelMat", modelMat);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
*/