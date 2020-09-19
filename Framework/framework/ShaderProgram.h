#pragma once
#ifndef __SHADERPROGRAM_H_
#define __SHADERPROGRAM_H_

// core 
#include<iostream>
#include<fstream>
#include<streambuf>
#include<sstream>
#include<string>

// include glad and glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// include GLM
#include<glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glm/gtc/matrix_transform.hpp>




class ShaderProgram
{
public:
	//
	//static ShaderProgram* Instance()
	//{
	//	if (s_pShaderProgram == nullptr)
	//	{
	//		s_pShaderProgram = new ShaderProgram();

	//		return s_pShaderProgram;
	//	}
	//	return s_pShaderProgram;
	//}

	ShaderProgram();
	~ShaderProgram();

	void LoadShader(const char* shaderVertex, const char* shaderFragment);
	void UsePrograma();
	
	void SetBool(const std::string& name, bool value) const;

	void SetInt(const std::string& name, int value) const;

	void SetFloat(const std::string& name, float value) const;

	void SetFloat4f(const std::string& name, float v1, float v2, float v3, float v4) const;

	void setVec2(const std::string& name, const glm::vec2& value) const;
	
	void setVec2(const std::string& name, float x, float y) const;

	void setVec3(const std::string& name, const glm::vec3& value) const;

	void setVec3(const std::string& name, float x, float y, float z) const;

	void setVec4(const std::string& name, const glm::vec4& value) const;
	
	void setMat2(const std::string& name, const glm::mat2& mat) const;
	
	void setMat3(const std::string& name, const glm::mat3& mat) const;
	
	void setVec4(const std::string& name, float x, float y, float z, float w);

	void SetMat4(const std::string& name, glm::mat4 value) const;

private:
	std::string LoadShaders(const char* filename);
	void DeleteShaders(unsigned int vertexShader, unsigned int fragmentShader);
	unsigned int shaderProgram;


private:

	static ShaderProgram* s_pShaderProgram;
	
};
#endif // !__SHADERPROGRAM_H_

