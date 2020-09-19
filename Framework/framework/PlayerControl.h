#pragma once
#ifndef __PLAYERCONTROL_H
#define __PLAYERCONTROL_H

#include"Plane.h"
#include"Camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"Camera.h"


class PlayerControl
{
public:
	PlayerControl();
	~PlayerControl();

	void Initialized(GLFWwindow* window);
	void Update(float deltaTime);

	glm::vec3 GetCameraPosition();
	glm::mat4 GetCameraView();
private:

	
	float   deltaTime;
	float   lastTime;
	Camera* m_camera;



};
#endif // !__PLAYERCONTROL_H


