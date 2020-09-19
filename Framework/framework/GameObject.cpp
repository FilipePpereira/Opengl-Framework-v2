#include "GameObject.h"

GameObject::GameObject() : m_position(0.0f, 0.0f, 0.0f),
						   m_rotation(0.0f, 0.0f, 0.0f),
						   m_scale(1.0f, 1.0f, 1.0f),
						   m_velocity(0.0f, 0.0f, 0.0f),
						   m_width(1),
	                       m_height(1)
{
}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(glm::vec3 position)
{
	m_position = position;
}

void GameObject::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void GameObject::SetRotation(glm::vec3 rotation)
{
	m_rotation = rotation;
}

void GameObject::SetRotation(float x, float y, float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

void GameObject::SetScale(glm::vec3 scale)
{
	m_scale = scale;
}

void GameObject::SetScale(float x, float y, float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}

void GameObject::SetVelocity(glm::vec3 velocity)
{
	m_velocity = velocity;
}

void GameObject::SetVelocity(float x, float y, float z)
{
	m_velocity.x = x;
	m_velocity.y = y;
	m_velocity.z = z;
}

void GameObject::SetWidth(int width)
{
	m_width = width;
}

void GameObject::SetHeight(int height)
{
	m_height = height;
}

glm::vec3 GameObject::GetPosition() const
{
	return m_position;
}

glm::vec3 GameObject::GetRotation() const
{
	return m_rotation;
}

glm::vec3 GameObject::GetScale() const
{
	return m_scale;
}

glm::vec3 GameObject::GetVelocity() const
{
	return m_velocity;
}

int GameObject::GetWidth() const
{
	return m_width;
}

int GameObject::GetHeight() const
{
	return m_height;
}
