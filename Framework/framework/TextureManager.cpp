#include"TextureManager.h"

#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"

//
//TextureManager* TextureManager::s_pTextureManager = nullptr;

TextureManager::TextureManager(): texture()
{
	
}

TextureManager::~TextureManager()
{
}

void TextureManager::LoadTextures(std::string filename, bool isFlip)
{
	
	int nrChannels;
	int width, height;

	unsigned char* data = data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
	stbi_set_flip_vertically_on_load(isFlip);


	GLenum colorMode = GL_RGB;
	switch (nrChannels) {
	case 1:
		colorMode = GL_RED;
		break;
	case 4:
		colorMode = GL_RGBA;
		break;
	};
	
	if (data)
	{
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, colorMode, width, height, 0, colorMode, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);


		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	

	stbi_image_free(data);

}


void TextureManager::Draw()
{
	glActiveTexture(GL_TEXTURE0);
	Generate();
	glBindTexture(GL_TEXTURE_2D, texture);
}

unsigned int TextureManager::GetTexture()
{
	return texture;
}


void TextureManager::Generate()
{
	glGenTextures(1, &texture);
}