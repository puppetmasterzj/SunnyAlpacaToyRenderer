#include "Model.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Model::Model()
{
}


Model::~Model()
{
}

void Model::LoadModel(const GLchar* path)
{
	/*Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}

	ProcessNode(scene->mRootNode, scene);*/
}

void Model::ProcessNode(aiNode* node, const aiScene* scene)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(ProcessMesh(mesh, scene));
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
	//std::vector<Vertex> vertices;
	//std::vector<unsigned int> indices;

	//for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	//{
	//	Vertex vertex;
	//	Vector3 vector;
	//	//position
	//	vector.x = mesh->mVertices[i].x;
	//	vector.y = mesh->mVertices[i].y;
	//	vector.z = mesh->mVertices[i].z;
	//	vertex.position = vector;
	//	//normal
	//	vector.x = mesh->mNormals[i].x;
	//	vector.y = mesh->mNormals[i].y;
	//	vector.z = mesh->mNormals[i].z;
	//	vertex.normal = vector;
	//	//texcoord
	//	if (mesh->mTextureCoords[0])
	//	{
	//		Vector2 vec;
	//		vec.x = mesh->mTextureCoords[0][i].x;
	//		vec.y = mesh->mTextureCoords[0][i].y;
	//		vertex.texcoord = vec;
	//	}
	//	else
	//	{
	//		vertex.texcoord = Vector2(0.0f, 0.0f);
	//	}
	//	//tangent
	//	vector.x = mesh->mTangents[i].x;
	//	vector.y = mesh->mTangents[i].y;
	//	vector.z = mesh->mTangents[i].z;
	//	vertex.tangent = vector;
	//	//bitangent
	//	vector.x = mesh->mBitangents[i].x;
	//	vector.y = mesh->mBitangents[i].y;
	//	vector.z = mesh->mBitangents[i].z;
	//	vertex.bitangent = vector;
	//	vertices.push_back(vertex);
	//}
 //   //index
	//for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	//{
	//	aiFace face = mesh->mFaces[i];
	//	for (unsigned int j = 0; j < face.mNumIndices; j++)
	//		indices.push_back(face.mIndices[j]);
	//}
	return Mesh();
}
