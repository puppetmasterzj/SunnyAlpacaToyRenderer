/*!
* \file ApcCamera.h
*
* \author zhangjian
* \date 2017.8.13
*
* \Model类，负责调用Assimp加载Model，可能包含多个子Mesh
*/
#pragma once
#include "../Common/ApcUtility.h"
#include "Mesh.h"

class Model
{
private:
	std::vector<Mesh> meshes;
	GLchar* modelPath;
public:
	Model();
	virtual ~Model();

	void LoadModel(const GLchar* path);
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
};

