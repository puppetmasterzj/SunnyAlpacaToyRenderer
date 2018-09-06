/*!
 * \file ApcUtility.h
 *
 * \author zhangjian
 * \date 2017.5.28
 *
 * \公共头文件
 */
#pragma once
#define GLEW_STATIC
#include <iostream>
#include <fstream>
#include <sstream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <map>
#include <list>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#pragma  comment (lib, "glew32s.lib")
#pragma  comment (lib, "opengl32.lib")
#pragma  comment (lib, "glfw3.lib")
#pragma  comment (lib, "assimp.lib")
#pragma  comment (lib, "SOIL.lib")

using namespace rapidjson;

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;
typedef glm::vec4 Vector4;
typedef glm::mat4 Matrix4x4;

#define INVALID_VALUE -1

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

#define SerilizedString(x) ( std::string m_x; const std::string x = #x	)

#define VariableName(x) (#x)