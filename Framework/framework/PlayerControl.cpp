#include "PlayerControl.h"
#include"InputManager.h"

// include glad and glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>





PlayerControl::PlayerControl(): deltaTime(0.0f), lastTime(0.0f), m_camera(nullptr)
{
}

PlayerControl::~PlayerControl()
{
}

void PlayerControl::Initialized(GLFWwindow* window)
{

    m_camera = new Camera();
  
    glfwSetKeyCallback(window, InputManager::InputManagerCallback);

}

void PlayerControl::Update(float deltaTime)
{
    glm::vec3 cameraPosition = m_camera->GetCameraPosition();

    float speed = 1.0f;

    
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_W))
    {
        cameraPosition.z += speed * deltaTime * m_camera->GetCameraFront().z;
        std::cout << "Move Z: " << cameraPosition.z << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_S))
    {
        cameraPosition.z -= m_camera->GetCameraFront().z * deltaTime;
        std::cout << "Move Z: " << -cameraPosition.z << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_A))
    {
        cameraPosition.x -= speed * deltaTime;
        std::cout << "Move -X: " << -cameraPosition.x << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_D))
    {
        cameraPosition.x += speed * deltaTime;
        std::cout << "Move X: " << cameraPosition.x << "\n";
    }

    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_SPACE))
    {
        cameraPosition.y += speed * deltaTime;
        std::cout << "Move Y: " << cameraPosition.y << "\n";
    }
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_Z))
    {
        cameraPosition.y -= speed * deltaTime;
        std::cout << "Move -Y: " << -cameraPosition.y << "\n";
    }

    
    m_camera->SetPosition(cameraPosition);


    bool wireframe = false;
    if (InputManager::Instance()->isKeyPressed(GLFW_KEY_1))
    {
        wireframe = !wireframe;

        if (wireframe)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
       
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

  

}

glm::vec3 PlayerControl::GetCameraPosition()
{
    return m_camera->GetCameraPosition();
}

glm::mat4 PlayerControl::GetCameraView()
{
    return m_camera->GetViewMatrix();
}
