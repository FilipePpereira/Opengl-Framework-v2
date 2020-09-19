#pragma once
#ifndef __MESH_H_
#define __MESH_H_

#include<vector>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<glm/glm.hpp>
#include"ShaderProgram.h"
#include"TextureManager.h"


struct Vertex
{
	glm::vec3 pos;
	glm::vec3 normals;
	glm::vec2 texturesCoords;

	std::vector<Vertex> GenerateList(float* vertices, int numberVertices);
};



class Mesh
{

public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<TextureManager> textures);
	~Mesh();


	virtual void Initialized();
	virtual void Draw(ShaderProgram shader);
	virtual void Shutdown();

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<TextureManager> textures;



private:

	unsigned int VBO, VAO, EBO;


};
#endif // !__MESH_H_


