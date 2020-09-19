#pragma once
#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_


#include<glad/glad.h>
#include<GLFW/glfw3.h>


class Triangle
{
public: 
	Triangle();
	~Triangle();


	void Initialized();
	void Update();
	void Draw();
	void Shutdown();


private:
	
	
	unsigned int VBO, VAO, EBO;
};
#endif // !__TRIANGLE_H_

