/*!
 * \file Camera.h
 *
 * \author zhangjian
 * \date 2017.5.29
 *
 * \…„œÒª˙¿‡
 */
#pragma once
#include "../Common/ApcUtility.h"

class Camera
{
private:
	Vector3 m_vFront;
	Vector3 m_vUp;
	Vector3 m_vRight;
	Vector3 m_vWorldUp;

	GLfloat m_fYaw;
	GLfloat m_fPitch;

	GLfloat m_fMoveSpeed;
	GLfloat m_fMouseSpeed;
	GLfloat m_fZoom;
	GLfloat m_fNearClip;
	GLfloat m_fFarClip;
public:
	Vector3 m_vPosition;
	static float DefalutMoveSpeed;
	static float DefalutMouseSpeed;
	static float DefalutZoom;

	Camera(Vector3 camPos, Vector3 camUpDir, GLfloat yaw, GLfloat pitch);
	~Camera();

	void ProcessMouseMove(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);
	void ProcessKeyBoard(Camera_Movement direction, GLfloat deltaTime);
	void ProcessMouseScroll(GLfloat yoffset);
	void UpdateCamera();
	Matrix4x4 GetViewMatrix();
	Matrix4x4 GetProjMatrix();

	void Render();
	
};

