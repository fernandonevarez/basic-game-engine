#include "engine/Renderer.h"
#include "engine/Shader.h"
#include "engine/Entity.h"

#include <glad/glad.h>
#include <iostream>

namespace engine {
    static GLuint vao = 0, vbo = 0;
    static Shader *shader = nullptr;

    static auto vertexSrc = R"(
    #version 330 core
    layout(location = 0) in vec2 aPos;

    uniform vec2 u_Position;

    void main() {
        gl_Position = vec4(aPos + u_Position, 0.0, 1.0);
    }
)";


    static auto fragmentSrc = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(0.2, 0.6, 1.0, 1.0);
    }
)";

    void Renderer::init() {
        std::cout << "[Renderer] Initializing" << std::endl;

        constexpr float scale = 0.25f; // 25% size

        constexpr float vertices[] = {
            -0.5f * scale, -0.5f * scale,
            0.5f * scale, -0.5f * scale,
            0.0f * scale, 0.5f * scale
        };


        std::cout << "Generating VAO..." << std::endl;
        glGenVertexArrays(1, &vao);
        std::cout << "VAO ID: " << vao << std::endl;

        std::cout << "Generating VBO..." << std::endl;
        glGenBuffers(1, &vbo);
        std::cout << "VBO ID: " << vbo << std::endl;

        std::cout << "Binding VAO..." << std::endl;
        glBindVertexArray(vao);

        std::cout << "Binding VBO..." << std::endl;
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        std::cout << "Uploading buffer data..." << std::endl;
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        std::cout << "Setting vertex attrib pointer..." << std::endl;
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), static_cast<void *>(nullptr));
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        std::cout << "Creating shader..." << std::endl;
        shader = new Shader(vertexSrc, fragmentSrc);

        std::cout << "[Renderer] Initialization complete" << std::endl;
    }


    void Renderer::clear() {
        glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::render(const Entity &entity) {
        if (!shader || vao == 0) {
            std::cerr << "[Renderer] Attempted to render before initialization!" << std::endl;
            return;
        }

        shader->bind();
        shader->setVec2("u_Position", entity.position);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        Shader::unbind();
    }
}
