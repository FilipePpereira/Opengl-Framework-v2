#pragma once
#ifndef __CUBEOBJECT_H_
#define __CUBEOBJECT_H_


#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include"ShaderProgram.h"

class CubeObject
{
public:
	CubeObject();
	~CubeObject();


	void Initialized();
	void Update();
	void Draw(ShaderProgram* shader);
	void Shutdown();

	void SetPosition(float x, float y, float z);
	void SetPosition(glm::vec3 position);

	glm::vec3 GetPosition();

private:
	
	unsigned int VBO, cubeVAO, lightCubeVAO;

	glm::vec3 m_position;
};
#endif // !__CUBEOBJECT_H_
