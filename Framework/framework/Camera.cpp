#include "Camera.h"

Camera::Camera(): cameraPosition(0.0f, 0.0f, 3.0f),
				  cameraUp(glm::vec3(0.0f, 1.0f, 0.0f)),
	              worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
				  cameraRight(glm::vec3(0.0f, 0.0f, 0.0f)),
				  cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
				  cameraRotation(glm::vec3(0.0f, 0.0f, 0.0f)),
	              yaw(-90.0f), pitch(0.0f), speed(1.0f), sensitivity(1.0f), zoom(45.0f)
{

	UpdateCameraVectors();

}

Camera::~Camera()
{
}

void Camera::UpdateCameraDirection(float directionX, float directionY)
{
	yaw += directionX;
	pitch += directionY;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}

	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	UpdateCameraVectors();
}

void Camera::UpdateCameraPosition(float deltaTime)
{
	//// calcul velocity

	//float velocity = (float)deltaTime * speed;

	//// trigger fr direction
	//CameraDirection direction = {};
	//switch (direction)
	//{
	//case CameraDirection::NONE:
	//	break;
	//case CameraDirection::FORWARD:
	//	cameraPosition += cameraFront * velocity;
	//	break;
	//case CameraDirection::BACK:
	//	cameraPosition -= cameraFront * velocity;
	//	break;
	//case CameraDirection::LEFTH:
	//	cameraPosition -= cameraRight * velocity;
	//	break;
	//case CameraDirection::RIGHT:
	//	cameraPosition += cameraRight * velocity;
	//	break;
	//case CameraDirection::UP:
	//	cameraPosition += cameraUp * velocity;
	//	break;
	//case CameraDirection::DOWN:
	//	cameraPosition -= cameraUp * velocity;
	//	break;
	//default:
	//	break;
	//}
}

void Camera::UpdateCameraZoom(float dy)
{
	if (zoom >= 1.0f && zoom <= 45.0f)
	{
		zoom -= dy;
	}
	else if (zoom < 1.0f)
	{
		zoom = 1.0f;
	}
	else
	{
		zoom = 45.0f;
	}
}

void Camera::UpdateCameraVectors()
{
	glm::vec3 direction;

	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	cameraFront = glm::normalize(direction);
	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
	cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}

void Camera::SetCameraType(CameraType type)
{
	cameraType = type;
}

void Camera::SetPosition(glm::vec3 position)
{
	cameraPosition = position;

	UpdateCameraVectors();
}

void Camera::SetRotation(glm::vec3 rotation)
{
	cameraRotation = rotation;
}

glm::vec3 Camera::GetCameraPosition()
{
	return cameraPosition;
}

glm::vec3 Camera::GetCameraUp()
{
	return cameraUp;
}

glm::vec3 Camera::GetCameraRight()
{
	return cameraRight;
}

glm::vec3 Camera::GetCameraFront()
{
	return cameraFront;
}

glm::vec3 Camera::GetRotation()
{
	return cameraRotation;
}

glm::mat4 Camera::GetViewMatrix()
{
	return view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}

CameraType Camera::GetCameraType()
{
	return cameraType;
}
