#include "../RenderEngine/RenderManager.h"
#include "../BaseObject/Camera.h"
#include "../RenderEngine/NativeGLDevice.h"
#include "../RenderObject/RenderObject.h"

float Camera::DefalutMoveSpeed = 80.0f;
float Camera::DefalutMouseSpeed = 0.2f;
float Camera::DefalutZoom = 45.0f;

Camera::Camera(Vector3 camPos, Vector3 camUpDir, GLfloat yaw, GLfloat pitch)
	: m_vFront(Vector3(0.0f, 0.0f, 1.0f))
	, m_vWorldUp(0.0f, 1.0f, 0.0f)
	, m_fMouseSpeed(DefalutMouseSpeed)
	, m_fMoveSpeed(DefalutMoveSpeed)
	, m_fZoom(DefalutZoom)
	, m_fNearClip(0.1f)
	, m_fFarClip(100.0f)
{
	m_vPosition = camPos;
	m_vUp = camUpDir;
	m_fYaw = yaw;
	m_fPitch = pitch;
}


Camera::~Camera()
{

}

void Camera::UpdateCamera()
{
	Vector3 front;
	front.x = cos(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
	front.y = sin(glm::radians(m_fPitch));
	front.z = sin(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
	m_vFront = glm::normalize(front);
	m_vRight = glm::normalize(glm::cross(m_vFront, m_vWorldUp));
	m_vUp = glm::normalize(glm::cross(m_vRight, m_vFront));
}

Matrix4x4 Camera::GetViewMatrix()
{
	//m_vPosition = Vector3(0, 0, 0);
	//UpdateCamera();
	return glm::lookAt(m_vPosition, m_vPosition + m_vFront, m_vUp);
}

Matrix4x4 Camera::GetProjMatrix()
{
	float width = NativeGLDevice::GetWindowWidth();
	float height = NativeGLDevice::GetWindowHeight();
	return glm::perspective(m_fZoom, width / height, m_fNearClip, m_fFarClip);
}

void Camera::ProcessMouseMove(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
	xoffset *= m_fMouseSpeed;
	yoffset *= m_fMouseSpeed;

	m_fYaw += xoffset;
	m_fPitch += yoffset;

	if (constrainPitch)
	{
		if (m_fPitch > 89.0f)
			m_fPitch = 89.0f;
		if (m_fPitch < -89.0f)
			m_fPitch = -89.0f;
	}
	//重新计算Camera相关属性
	UpdateCamera();
}

void Camera::ProcessKeyBoard(Camera_Movement direction, GLfloat deltaTime)
{
	//UpdateCamera();
	GLfloat velocity = m_fMoveSpeed * deltaTime;
	if (direction == FORWARD)
		m_vPosition += m_vFront * velocity;
	if (direction == BACKWARD)
		m_vPosition -= m_vFront * velocity;
	if (direction == LEFT)
		m_vPosition -= m_vRight * velocity;
	if (direction == RIGHT)
		m_vPosition += m_vRight * velocity;
	UpdateCamera();
}

void Camera::ProcessMouseScroll(GLfloat yoffset)
{
	if (m_fZoom >= 1.0f && m_fZoom <= 45.0f)
		m_fZoom -= yoffset;
	if (m_fZoom <= 1.0f)
		m_fZoom = 1.0f;
	if (m_fZoom >= 45.0f)
		m_fZoom = 45.0f;
	UpdateCamera();
}

void Camera::Render()
{


	RenderObjList* list = RenderManager::GetRenderManager()->GetRenderObjectList();
	for (RenderObjList::iterator it = (*list).begin(); it != (*list).end(); ++it)
	{
		RenderObject* renderer = (*it);
		renderer->DoRender();
	}
	
}

