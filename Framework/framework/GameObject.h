#pragma once
#ifndef __GAMEOBJECT_H_
#define __GAMEOBJECT_H_

#include<glm/vec3.hpp>


class GameObject
{
public:
	GameObject();
	~GameObject();


	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetPosition(glm::vec3 position);
	void SetPosition(float x, float y, float z);

	void SetRotation(glm::vec3 rotation);
	void SetRotation(float x, float y, float z);


	void SetScale(glm::vec3 scale);
	void SetScale(float x, float y, float z);


	void SetVelocity(glm::vec3 velocity);
	void SetVelocity(float x, float y, float z);

	void SetWidth(int width);
	void SetHeight(int height);

	glm::vec3 GetPosition() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;
	glm::vec3 GetVelocity() const;
	int GetWidth() const;
	int GetHeight() const;



private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;

	int m_width;
	int m_height;


	glm::vec3 m_velocity;



};
#endif // !__GAMEOBJECT_H_

