#pragma once
#ifndef __GAME_H_
#define __GAME_H_

// core window
#include<Windows.h>
#include<iostream>
#include<string>

// include glad 
#include <glad\glad.h>

// include glfw 
#include<GLFW/glfw3.h>
#include<GLFW/glfw3native.h>

// include glad and glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include"InputManager.h"
#include"ShaderProgram.h"

#include"Plane.h"

#include"ShaderProgram.h"
#include"TextureManager.h"

#include"PlayerControl.h"

#include"LightCube.h"
#include"CubeObject.h"


class Game
{
public:
	Game();
	~Game();

	bool Initialized(std::string title, int with, int height);
	void Run();
	void Update();
	void Draw();
	void Shutdown();



	int GetScreenWidth() { return m_screenWidth; };
	int GetScreenHeight() { return m_screenHeight; };

private:

	bool InitShaders();
	void InitializedGameObjects();
	void InitializedTextures();
	void UpdateShader();
	void UpdateGameObjects();

	void processInput(GLFWwindow* window);


private:

	TextureManager*  m_pTextureManager;
	PlayerControl*   m_pPlayerControl;

	Plane*            m_plane;
	LightCube*        m_lightCube;
	CubeObject*       m_cubeObject;
	ShaderProgram*    m_shaderPlane;
	ShaderProgram*    m_shaderCube;

private:

	GLFWwindow* m_pWindow;

	int m_screenWidth;
	int m_screenHeight;

	float lastTime;
	float deltaTime;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	POINT CenterWindow(int width, int height);
};
#endif // !__GAME_H_