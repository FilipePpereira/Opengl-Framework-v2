#include "ShaderProgram.h"


ShaderProgram* ShaderProgram::s_pShaderProgram = nullptr;


ShaderProgram::ShaderProgram(): shaderProgram()
{
}

ShaderProgram::~ShaderProgram()
{
    delete s_pShaderProgram;
    s_pShaderProgram = nullptr;
}



void ShaderProgram::LoadShader(const char* shaderVertex, const char* shaderFragment)
{
    int sucess;
    char infoLog[512];


    //-----------------------        init shaders        ------------------------------//

  // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string vertexshaderfile = LoadShaders(shaderVertex);
    const GLchar* vertShader = vertexshaderfile.c_str();
    glShaderSource(vertexShader, 1, &vertShader, NULL);
    glCompileShader(vertexShader);

    // status compiler shader

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &sucess);
    if (!sucess)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR width vertex shader comp.::" << std::endl << infoLog << std::endl << "\n";

    }

    // Fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fragmentShaderfile = LoadShaders(shaderFragment);
    const GLchar* fragmentfile = fragmentShaderfile.c_str();
    glShaderSource(fragmentShader, 1, &fragmentfile, NULL);
    glCompileShader(fragmentShader);

    // status compiler shader

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &sucess);
    if (!sucess)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR width vertex shader comp.::" << std::endl << infoLog << std::endl << "\n";

    }
    //-----------------------        end shaders        ------------------------------//

    shaderProgram = glCreateProgram();
    // vertex shader
    glAttachShader(shaderProgram, vertexShader);
    // fragment shader
    glAttachShader(shaderProgram, fragmentShader);

    // gl link programa
    glLinkProgram(shaderProgram);

    // check status do program
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &sucess);
    if (!sucess)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR Link program" << std::endl << infoLog << std::endl << "\n";
    }

   
    DeleteShaders(vertexShader, fragmentShader);
}

std::string ShaderProgram::LoadShaders(const char* filename)
{
    std::ifstream file;
    std::stringstream buf;
    std::string name = "";

    file.open(filename);
    if (file.is_open())
    {
        buf << file.rdbuf();
        name = buf.str();
    }
    else
    {
        std::cout << "Could not Open" << filename << "\n";
    }

    file.close();
    return name;
}


void ShaderProgram::UsePrograma()
{
	glUseProgram(shaderProgram);
}

void ShaderProgram::DeleteShaders(unsigned int vertexShader, unsigned int fragmentShader)
{
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


void ShaderProgram::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
}

void ShaderProgram::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void ShaderProgram::SetFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void ShaderProgram::SetFloat4f(const std::string& name, float v1, float v2, float v3, float v4) const
{

    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), v1, v2, v3, v4);
}

void ShaderProgram::setVec2(const std::string& name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, glm::value_ptr(value));
}

void ShaderProgram::setVec2(const std::string& name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(shaderProgram, name.c_str()), x, y);
}

void ShaderProgram::setVec3(const std::string& name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, glm::value_ptr(value));
}

void ShaderProgram::setVec3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z);
}

void ShaderProgram::setVec4(const std::string& name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, glm::value_ptr(value));
}

void ShaderProgram::setVec4(const std::string& name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z, w);
}

void ShaderProgram::setMat2(const std::string& name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderProgram::setMat3(const std::string& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderProgram::SetMat4(const std::string& name, glm::mat4 value) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}


















