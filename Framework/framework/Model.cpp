#include "Model.h"

Model::Model(): mesh()
{
}

Model::~Model()
{
}

void Model::Initialized()
{
	
}

void Model::Draw(ShaderProgram shader)
{
	mesh.Draw(shader);
}

void Model::ShutDown()
{
	mesh.Shutdown();
}
