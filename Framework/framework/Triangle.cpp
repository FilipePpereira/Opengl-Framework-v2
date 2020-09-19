#include "Triangle.h"
#include"ShaderProgram.h"





Triangle::Triangle():VBO(), VAO()
{
}

Triangle::~Triangle()
{
}

void Triangle::Initialized()
{

    ///-----------------------        init shaders        ------------------------------//

    //ShaderProgram::Instance()->LoadShader("assets/vertex_core.glsl", "assets/fragvertex_core.glsl");


    float vertices[]=
    {

       -0.5f,  -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
        0.5f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
        0.0f,   0.5f, 0.0f,  0.0f, 0.0f, 1.0f

    };

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //-----------------------        end model        ------------------------------//

}

void Triangle::Update()
{
    //float colorTime = glfwGetTime();
    //float colorRand = (std::sin(colorTime) / 2.0f) + 0.5f;


    //int randcolor = rand() % 25 + (int)colorRand;
    //ShaderProgram::Instance()->SetFloat4f("RColor", randcolor, colorRand, 0.5f, 1.0f);

    //ShaderProgram::Instance()->UsePrograma();
}

void Triangle::Draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Triangle::Shutdown()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
