#pragma once
#ifndef __LIGHTCUBE_H_
#define __LIGHTCUBE_H_


#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include"ShaderProgram.h"

class LightCube
{
public:
	LightCube();
	~LightCube();


	void Initialized();
	void Update();
	void Draw();
	void Shutdown();

	void SetPosition(float x, float y, float z);
	void SetPosition(glm::vec3 position);

	glm::vec3 GetPosition();
private:

	unsigned int VBO, lightCubeVAO;
	glm::vec3 m_position;
};
#endif // !__LIGHTCUBE_H_
