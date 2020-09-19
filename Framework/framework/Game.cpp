#include "Game.h"


Game::Game() : m_pWindow(nullptr),
lastTime(0.0f),
deltaTime(0.0f),
m_screenWidth(0),
m_screenHeight(0),
m_pTextureManager(nullptr),
m_pPlayerControl(nullptr),
m_plane(nullptr),
m_lightCube(nullptr),
m_cubeObject(nullptr),
m_shaderPlane(nullptr),
m_shaderCube(nullptr)

{
}

Game::~Game()
{
}

bool Game::InitShaders()
{
    m_shaderPlane = new ShaderProgram();
    if (!m_shaderPlane)
    {
        std::cout << "failed creat texture" << "\n";
        return false;
    }

    m_shaderPlane->LoadShader("assets/PlaneVertex.glsl", "assets/Planefragvertex.glsl");

    m_shaderCube = new ShaderProgram();
    if (!m_shaderCube)
    {
        std::cout << "failed creat texture" << "\n";
        return false;
    }

    m_shaderCube->LoadShader("assets/colorsVertex.glsl", "assets/colorsFrag.glsl");

    ///-----------------------        end shaders       
}

void Game::InitializedTextures()
{
    ///-----------------------        start Textures        ------------------------------//
    m_pTextureManager = new TextureManager();

    if (!m_pTextureManager)
    {
        std::cout << "failed creat texture" << "\n";
    }

    m_pTextureManager->LoadTextures("assets/textures/wall.jpg", true);

    ///-----------------------        end Textures        ------------------------------//

}


void Game::InitializedGameObjects()
{
    m_pPlayerControl = new PlayerControl();
    m_pPlayerControl->Initialized(m_pWindow);

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

}

bool Game::Initialized(std::string title, int with, int height)
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
    m_pWindow = glfwCreateWindow(m_screenWidth, m_screenHeight, "LearnOpenGL", NULL, NULL);
    if (m_pWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_pWindow);
    glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    POINT center = CenterWindow(m_screenWidth, m_screenHeight);
    glfwSetWindowPos(m_pWindow, center.x, center.y);

    InitShaders();
    InitializedGameObjects();
    InitializedTextures();

    return false;
}

void Game::UpdateShader()
{
    // setup view matrix
    glm::mat4 trans = glm::mat4(1.0f);
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);



    // m_camera
    

    // m_camera

    view = m_pPlayerControl->GetCameraView();
    projection = glm::perspective(glm::radians(45.0f), (float)m_screenWidth / (float)m_screenHeight, 0.1f, 10000.0f);

    

  

    trans = glm::translate(trans, glm::vec3(m_pPlayerControl->GetCameraPosition()));
    model = glm::translate(trans, glm::vec3(0.0f, 0.0f, -3.0f));

    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f));


   // setup program compiler
    m_shaderPlane->UsePrograma();
    m_shaderPlane->SetMat4("model", model);
    m_shaderPlane->SetMat4("view", view);
    m_shaderPlane->SetMat4("projection", projection);


    m_shaderCube->UsePrograma();

    glm::mat4 modelcube = glm::mat4(1.0f);
    modelcube = glm::translate(trans, glm::vec3(0.0f, 0.0f, -3.0f));
    modelcube = glm::rotate(modelcube, glm::radians(0.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
    modelcube = glm::scale(modelcube, glm::vec3(0.25f));
    m_shaderCube->SetMat4("model", modelcube);
    m_shaderCube->SetMat4("view", view);
    m_shaderCube->SetMat4("projection", projection);

}

void Game::UpdateGameObjects()
{
    m_pPlayerControl->Update(deltaTime);

    m_plane->Update();

    m_cubeObject->Update();
}

void Game::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Game::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

POINT Game::CenterWindow(int width, int height)
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    POINT center;
    center.x = (screenWidth - width) / 2;
    center.y = (screenHeight - height) / 2;

    return center;
}

void Game::Run()
{
    while (!glfwWindowShouldClose(m_pWindow))
    {
        Update();

        Draw();
    }

    Shutdown();
}

void Game::Update()
{
    float currentFrame = (float)glfwGetTime();
    deltaTime = (float)currentFrame - lastTime;
   
   UpdateShader();

   processInput(m_pWindow);

    UpdateGameObjects();
  
    UpdateGameObjects();
    
    glfwPollEvents();
    
    glfwSwapBuffers(m_pWindow);

    lastTime = currentFrame;
}

void Game::Draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    m_cubeObject->Draw(m_shaderCube);

    m_plane->Draw(m_shaderPlane);
    
    m_pTextureManager->Draw();

    /*   m_lightCube->Draw(); */

}

void Game::Shutdown()
{
    glfwDestroyWindow(m_pWindow);
    glfwTerminate();
}


