#include "Mesh.h"


std::vector<Vertex> Vertex::GenerateList(float* vertices, int numberVertices)
{
	std::vector<Vertex> ret(numberVertices);

	int stride = sizeof(Vertex) / sizeof(float);


	for (int i = 0; i < numberVertices; i++)
	{
		ret[i].pos = glm::vec3(
			vertices[i * stride + 0],
			vertices[i * stride + 1],
			vertices[i * stride + 2]);

		ret[i].texturesCoords = glm::vec2
		(
			vertices[i * stride + 3],
			vertices[i * stride + 4]
		);
	}


	return ret;
}


Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<TextureManager> textures):
	vertices(vertices), indices(indices), textures(textures)
{
}

Mesh::~Mesh()
{
}

void Mesh::Initialized()
{
	// first, configure the cube's VAO (and VBO)

	glGenVertexArrays(1, &VAO); // vertex array
	glGenBuffers(1, &VBO); // vertex buffer
	glGenBuffers(1, &EBO); // element

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);



	// position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	

	//// colors attribute
	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	

	// textures attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texturesCoords));
	

	glBindVertexArray(0);
}

void Mesh::Draw(ShaderProgram shader)
{
	/*for (int i = 0; i < textures.size(); i++)
	{
		shader.SetInt(textures[i]., textures[i].Draw());
		textures[i].Update();
		glBindTexture(GL_TEXTURE_2D, textures[i].GetTexture());
	}*/

	// Vertex array
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0,vertices.size());

}
void Mesh::Shutdown()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

