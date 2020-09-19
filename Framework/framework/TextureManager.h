#pragma once
#ifndef __TEXTUREMANAGER_H_
#define __TEXTUREMANAGER_H_


#include<iostream>
#include<string>

#include<glad/glad.h>
#include<GLFW/glfw3.h>




class TextureManager
{
public:

	//static TextureManager* Instance()
	//{
	//	if (s_pTextureManager == nullptr)
	//	{
	//		s_pTextureManager = new TextureManager();

	//		return s_pTextureManager;
	//	}
	//	return s_pTextureManager;
	//}


	TextureManager();


	void LoadTextures(std::string filename, bool isFlip);
	void Update();
	void Draw();

	unsigned int GetTexture();

private:
	~TextureManager();
	void Generate();
	unsigned int texture;

	static TextureManager* s_pTextureManager;
};

#endif // !__TEXTUREMANAGER_H_









