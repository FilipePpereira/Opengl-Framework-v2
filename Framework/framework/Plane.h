#pragma once
#ifndef __PLANE_H_
#define __PLANE_H_


#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include"TextureManager.h"


#include"ShaderProgram.h"

class Plane
{
public:
	Plane();
	~Plane();


	void Initialized();
	void Update();
	void Draw(ShaderProgram* shader);
	void Shutdown();

	void SetPosition(float x, float y, float z);
	void SetPosition(glm::vec3 position);

	void SetTexture(TextureManager& Texture);
	glm::vec3 GetPosition();

	TextureManager* GetTexture();
private:
	TextureManager* m_pTextureManager;
	unsigned int VBO, VAO, EBO;

	glm::vec3 m_position;
};
#endif // !__PLANE_H_
