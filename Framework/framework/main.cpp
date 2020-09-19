// include core
#include<iostream>


#include<fstream>
#include<streambuf>
#include<sstream>
#include<string>

#include<Windows.h>


// include glad and glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include"InputManager.h"
#include"ShaderProgram.h"

#include"Plane.h"

#include"ShaderProgram.h"
#include"TextureManager.h"

#include"PlayerControl.h"

#include"LightCube.h"
#include"CubeObject.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

POINT CenterWindow(int width, int height);
void Draw();


// settings
int m_screenWidth = 800;
int m_screenHeight = 600;

int GetScreenWidth() { return m_screenWidth; };
int GetScreenHeight() { return m_screenHeight; };

float lastTime = 0.0f;
float deltaTime = 0.0f;

TextureManager* m_pTextureManager = nullptr;
PlayerControl* m_pPlayerControl = nullptr;

Plane* m_plane = nullptr;
LightCube*  m_lightCube = nullptr;
CubeObject* m_cubeObject = nullptr;


ShaderProgram* m_shaderPlane = nullptr;
ShaderProgram* m_shaderCube = nullptr;

int main()
{

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(m_screenWidth, m_screenHeight, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    ////-----------------------        init shaders        ------------------------------//


    m_shaderPlane = new ShaderProgram();
    if (!m_shaderPlane)
    {
        std::cout << "failed creat texture" << "\n";
        return -1;
    }

    m_shaderPlane->LoadShader("assets/PlaneVertex.glsl", "assets/Planefragvertex.glsl");

    m_shaderCube = new ShaderProgram();
    if (!m_shaderCube)
    {
        std::cout << "failed creat texture" << "\n";
        return -1;
    }

    m_shaderCube->LoadShader("assets/colorsVertex.glsl", "assets/colorsFrag.glsl");

    ///-----------------------        end shaders        ------------------------------//
   
    ///-----------------------        start Textures        ------------------------------//
    m_pTextureManager = new TextureManager();

    if (!m_pTextureManager)
    {
        std::cout << "failed creat texture" << "\n";
    }

    m_pTextureManager->LoadTextures("assets/textures/wall.jpg", true);

    ///-----------------------        end Textures        ------------------------------//

    m_pPlayerControl = new PlayerControl();
    m_pPlayerControl->Initialized(window);

    m_plane = new Plane();

    if (!m_plane)
    {
        std::cout << "Failed Create Triangle " << "";
    }

    m_plane->Initialized();
    m_plane->SetTexture(*m_pTextureManager);

    m_lightCube = new LightCube();
    if (!m_lightCube)
    {
        std::cout << "Failed Create Triangle " << "";
    }

    m_lightCube->Initialized();


    m_cubeObject = new CubeObject();
    if (!m_cubeObject)
    {
        std::cout << "Failed Create Triangle " << "";
    }

    // cube object
    m_cubeObject->Initialized();
    m_cubeObject->SetPosition(0.0f, 0.0f, 20.0f);


    POINT center =  CenterWindow(m_screenWidth, m_screenHeight);
    glfwSetWindowPos(window, center.x, center.y);

    

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        
        // input
        // -----
        processInput(window);
        glfwPollEvents();
        float currentFrame = (float)glfwGetTime();
        deltaTime = (float)currentFrame - lastTime;
       

       

        m_plane->Update();

        // render
       // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        Draw();
      
        // setup view matrix
        glm::mat4 trans = glm::mat4(1.0f);
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        
        
        // m_camera
        m_pPlayerControl->Update(deltaTime);
        view = m_pPlayerControl->GetCameraView();
        projection = glm::perspective(glm::radians(45.0f), (float)m_screenWidth / (float)m_screenHeight, 0.1f, 10000.0f);

      
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
        model = glm::rotate(model, glm::radians(0.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.0f));

       
        
        m_shaderPlane->UsePrograma();
        m_shaderPlane->SetMat4("model", model);
        m_shaderPlane->SetMat4("view", view);
        m_shaderPlane->SetMat4("projection", projection);
        m_plane->Draw(m_shaderPlane);
        


      
      
       
       

        
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                m_shaderCube->UsePrograma();
                glm::mat4 modelcube = glm::mat4(1.0f);
                modelcube = glm::translate(modelcube, glm::vec3(i, j, 0.0f));
                modelcube = glm::scale(modelcube, glm::vec3(0.25f));

                m_shaderCube->SetMat4("model", modelcube);
                m_shaderCube->SetMat4("view", view);
                m_shaderCube->SetMat4("projection", projection);
                /* m_lightCube->Update();*/

                m_cubeObject->Update();
                m_cubeObject->Draw(m_shaderCube);
            }

        }

        m_pTextureManager->Draw();



        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
       

        lastTime = currentFrame;
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


POINT CenterWindow(int width, int height)
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    POINT center;
    center.x = (screenWidth - width) / 2;
    center.y = (screenHeight - height) / 2;

    return center;
}

void Draw()
{
    
    /*   m_lightCube->Draw(); */
   
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


