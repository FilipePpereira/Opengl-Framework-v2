#pragma once
#ifndef __CAMERA_H_
#define __CAMERA_H_

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

enum CameraType
{
	DEFAULT,
	ORBIT,
	FIRSTPERSON,
	THIRTHPERSON
};

enum class CameraDirection
{
	NONE,
	FORWARD,
	BACK,
	LEFTH,
	RIGHT,
	UP, 
	DOWN

};


class Camera
{
public:
	Camera();
	~Camera();
	void UpdateCameraDirection(float directionX, float directionY);
	void UpdateCameraPosition(float deltaTime);
	void UpdateCameraZoom(float dy);
	

	// setters
	void SetCameraType(CameraType type);
	void SetPosition(glm::vec3 position);
	void SetRotation(glm::vec3 position);

	// getters
	glm::vec3 GetCameraPosition();
	glm::vec3 GetCameraUp();
	
	glm::vec3 GetCameraRight();
	glm::vec3 GetCameraFront();

	glm::vec3 GetRotation();
	glm::mat4 GetViewMatrix();

	CameraType GetCameraType();

private:
	
	void UpdateCameraVectors();

private:

	glm::vec3 cameraPosition;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;
	glm::vec3 cameraFront;
	glm::vec3 cameraRotation;
	glm::vec3 worldUp;

	glm::mat4 view;


	float yaw;    // cos x / h = cos x / 1 = cos x
	float pitch; // sin y / h = sin y / 1 = sin y.
	float speed;
	float sensitivity;
	float zoom;

	// Camera Types
	CameraType cameraType;

};
#endif // !__CAMERA_H_

