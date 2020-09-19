#pragma once
#ifndef __INPUTMANAGER_H
#define __INPUTMANAGER_H

#include<glfw/glfw3.h>
#include<iostream>




class InputManager
{
public:
	
	static InputManager* Instance()
	{
		if (s_pInputManager == nullptr)
		{
			s_pInputManager = new InputManager();
			return s_pInputManager;
		}

		return s_pInputManager;
	}


	static void InputManagerCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	bool isKeyPressed(int key);
	bool isKeyRelease(int key);


	
	

private:

	InputManager();
	~InputManager() {};

	bool keyListener[256];

	static InputManager* s_pInputManager;

};

typedef InputManager TheInputManager;
#endif // !__INPUTMANAGER_H



