#include"CubeObject.h"
#include"ShaderProgram.h"

CubeObject::CubeObject(): VBO(), cubeVAO(), lightCubeVAO()
{

}

CubeObject::~CubeObject()
{
}

void CubeObject::Initialized()
{
  

    float vertices[] = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    };


    // first, configure the cube's VAO (and VBO)
  
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    //// init shader
    //  // cube Object
    //ShaderProgram::Instance()->LoadShader("assets/colorsVertex.glsl", "assets/colorsFrag.glsl");






}

void CubeObject::Update()
{
    //ShaderProgram::Instance()->UsePrograma();
   
    //ShaderProgram::Instance()->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    //ShaderProgram::Instance()->setVec3("lightColor", 1.0f, 1.0f, 1.0f);


}

void CubeObject::Draw(ShaderProgram* shader)
{
    shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);

    glBindVertexArray(cubeVAO);
  
    glDrawArrays(GL_TRIANGLES, 0, 36);

   /* glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);*/
}

void CubeObject::Shutdown()
{
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteBuffers(1, &VBO);
}

void CubeObject::SetPosition(float x, float y, float z)
{
    m_position.x = x;
    m_position.y = y;
    m_position.z = z;
}

void CubeObject::SetPosition(glm::vec3 position)
{
    m_position = position;
}

glm::vec3 CubeObject::GetPosition()
{
    return m_position;
}



