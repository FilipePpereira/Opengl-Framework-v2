#include"LightCube.h"
#include"ShaderProgram.h"

LightCube::LightCube(): VBO(), lightCubeVAO(), m_position(glm::vec3(0.0f, 0.0f, 0.0f))
{

}

LightCube::~LightCube()
{
}

void LightCube::Initialized()
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

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
   unsigned int lightCubeVAO;
   glGenVertexArrays(1, &lightCubeVAO);
   glBindVertexArray(lightCubeVAO);

   // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
   glBindBuffer(GL_ARRAY_BUFFER, VBO);

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
   glEnableVertexAttribArray(0);


   // init shader
  // cube Object
   //ShaderProgram::Instance()->LoadShader("assets/light_cubeVertex.glsl", "assets/light_cubeFrag.glsl");

}

void LightCube::Update()
{
   /* ShaderProgram::Instance()->UsePrograma();

    ShaderProgram::Instance()->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    ShaderProgram::Instance()->setVec3("lightColor", 1.0f, 1.0f, 1.0f);*/
}

void LightCube::Draw()
{
  
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(1.0f));
    model = glm::translate(model, glm::vec3(0.0f, -1.0f, 5.0f));

    glBindVertexArray(lightCubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void LightCube::Shutdown()
{
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &VBO);
}

void LightCube::SetPosition(float x, float y, float z)
{
    m_position.x = x;
    m_position.y = y;
    m_position.z = z;
}

void LightCube::SetPosition(glm::vec3 position)
{
    m_position = position;
}

glm::vec3 LightCube::GetPosition()
{
    return m_position;
}



