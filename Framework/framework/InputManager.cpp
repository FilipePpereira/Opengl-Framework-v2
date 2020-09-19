#include"InputManager.h"




InputManager* InputManager::s_pInputManager = 0;


InputManager::InputManager()
{

}


void InputManager::InputManagerCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		s_pInputManager->keyListener[key] = true;
	else if (action == GLFW_RELEASE)
		s_pInputManager->keyListener[key] = false;
}

bool InputManager::isKeyPressed(int key)
{
	return s_pInputManager->keyListener[key];
}

bool InputManager::isKeyRelease(int key)
{
	return s_pInputManager->keyListener[key];
}






