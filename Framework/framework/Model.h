#pragma once
#ifndef __MODEL_H_


#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp> 

#include"Mesh.h"

class Model
{
public:
	Model();
	~Model();


	void Initialized();
	void Draw(ShaderProgram shader);
	void ShutDown();

private:

	Mesh mesh;

};
#endif // !__MODEL_H_


