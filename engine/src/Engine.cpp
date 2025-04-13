#include "engine/Engine.h"
#include "engine/Window.h"
#include "engine/Renderer.h"
#include "engine/Input.h"
#include "engine/Entity.h"

#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>

namespace engine {
    Engine::Engine() = default;

    Engine::~Engine() {
        delete m_window;
    }

    void Engine::run() {
        m_window = new Window(800, 600, "Basic Engine");

        Renderer::init();

        std::vector<Entity> entities;
        entities.emplace_back();

        // FPS tracking
        double lastTime = glfwGetTime();
        int frames = 0;

        while (!m_window->shouldClose()) {
            engine::Window::pollEvents();

            glm::vec2 direction = {0.0f, 0.0f};

            if (Input::isKeyPressed(GLFW_KEY_W)) direction.y += 1.0f;
            if (Input::isKeyPressed(GLFW_KEY_S)) direction.y -= 1.0f;
            if (Input::isKeyPressed(GLFW_KEY_A)) direction.x -= 1.0f;
            if (Input::isKeyPressed(GLFW_KEY_D)) direction.x += 1.0f;

            if (length(direction) > 0.0f)
                direction = normalize(direction);

            entities[0].velocity = direction * 100.0f;

            for (auto &entity: entities) {
                entity.update(0.016f);
                std::cout << "Entity Y: " << entity.position.y << std::endl;
            }

            Renderer::clear();
            Renderer::render(entities[0]);
            m_window->swapBuffers();

            frames++;
            if (const double currentTime = glfwGetTime(); currentTime - lastTime >= 1.0) {
                std::string title = "Game Engine [FPS: " + std::to_string(frames) + "]";
                glfwSetWindowTitle(m_window->getNativeWindow(), title.c_str());
                frames = 0;
                lastTime = currentTime;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }
    }
}
