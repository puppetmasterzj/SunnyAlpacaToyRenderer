#include "Mesh.h"

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::InitMesh(std::vector<Vertex> vert, std::vector<unsigned int> index)
{
	this->vertices = vert;
	this->indices = index;

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	//pos
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	//normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	//texcoord
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));

	glBindVertexArray(0);
}

void Mesh::InitCube()
{
	
	Vertex v1, v2, v3, v4, v5, v6, v7, v8;
	v1.position = Vector3(-1,  1, -1); v1.normal = Vector3(-1,  1, -1); v1.texcoord = Vector2(0, 0);
	v2.position = Vector3(-1,  1,  1); v2.normal = Vector3(-1,  1,  1); v2.texcoord = Vector2(0, 1);
	v3.position = Vector3( 1,  1,  1); v3.normal = Vector3( 1,  1,  1); v3.texcoord = Vector2(1, 1);
	v4.position = Vector3( 1,  1, -1); v4.normal = Vector3( 1,  1, -1); v4.texcoord = Vector2(1, 0);
	v5.position = Vector3( 1, -1, -1); v5.normal = Vector3( 1, -1, -1); v5.texcoord = Vector2(1, 1);
	v6.position = Vector3(-1, -1, -1); v6.normal = Vector3(-1, -1, -1); v6.texcoord = Vector2(0, 0);
	v7.position = Vector3(-1, -1,  1); v7.normal = Vector3(-1, -1,  1); v7.texcoord = Vector2(0, 1);
	v8.position = Vector3( 1, -1,  1); v8.normal = Vector3( 1, -1,  1); v8.texcoord = Vector2(1, 1);

	std::vector<Vertex> vertex = { v1, v2, v3, v4, v5, v6, v7, v8 };

	std::vector<unsigned int> index = {
		0, 1, 2,  2, 3, 0,//up
		0, 3, 4,  4, 5, 0,//behind
		0, 5, 1,  1, 5, 6,//left
		6, 7, 2,  2, 1, 6,//beyond
		6, 5, 7,  7, 5, 4,//buttom
		4, 3, 2,  2, 7, 4,//right
	};
	InitMesh(vertex, index);
	

	//Vertex v1, v2, v3, v4, v5, v6, v7, v8;
	//v1.position = Vector3(-1, -1,  1); v1.texcoord = Vector2(0, 1);www
	//v2.position = Vector3( 1, -1,  1); v2.texcoord = Vector2(0, 1);
	//v3.position = Vector3( 1,  1,  1);
	//v4.position = Vector3(-1,  1,  1);
	//v5.position = Vector3(-1, -1, -1);
	//v6.position = Vector3(-1,  1, -1);
	//v7.position = Vector3( 1,  1, -1);
	//v8.position = Vector3( 1, -1, -1);

}

void Mesh::InitPlane()
{
	//vertex
	Vertex v1, v2, v3, v4;
	v1.position = Vector3(-1, -1, 0); v1.normal = Vector3(0, 0, -1); v1.texcoord = Vector2(0, 0);
	v2.position = Vector3(-1, 1, 0); v2.normal = Vector3(0, 0, -1); v2.texcoord = Vector2(0, 1);
	v3.position = Vector3(1, 1, 0); v3.normal = Vector3(0, 0, -1); v3.texcoord = Vector2(1, 1);
	v4.position = Vector3(1, -1, 0); v4.normal = Vector3(0, 0, -1); v4.texcoord = Vector2(1, 0);
	std::vector<Vertex> vertex = { v1, v2, v3, v4 };

	//index
	std::vector<unsigned int> index = { 0, 1, 2, 0, 2, 3 };

	InitMesh(vertex, index);
}

void Mesh::Use()
{
	
}

void Mesh::Render()
{
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
