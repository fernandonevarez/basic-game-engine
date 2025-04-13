#include "engine/Shader.h"

#include <string>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace engine {
    Shader::Shader(const char *vertexSrc, const char *fragmentSrc) {
        const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
        glCompileShader(vertexShader);

        GLint success;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            std::cerr << "[Shader] Vertex shader compilation failed!" << std::endl;
        }

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            std::cerr << "[Shader] Fragment shader compilation failed!" << std::endl;
        }

        m_programID = glCreateProgram();
        glAttachShader(m_programID, vertexShader);
        glAttachShader(m_programID, fragmentShader);
        glLinkProgram(m_programID);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::~Shader() {
        glDeleteProgram(m_programID);
    }

    void Shader::bind() const {
        glUseProgram(m_programID);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }

    void Shader::setVec2(const std::string &name, const glm::vec2 &value) const {
        const GLint location = glGetUniformLocation(m_programID, name.c_str());
        glUniform2fv(location, 1, glm::value_ptr(value));
    }
}
