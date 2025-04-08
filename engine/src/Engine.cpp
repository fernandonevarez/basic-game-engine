#include "engine/Engine.h"
#include "engine/Renderer.h"
#include <thread>
#include <chrono>

namespace engine {
    Engine::Engine() {}

    Engine::~Engine() {
        delete m_window;
    }

    void Engine::run() {
        m_window = new Window(800, 600, "Basic Engine");

        Renderer::init();

        while (!m_window->shouldClose()) {
            engine::Window::pollEvents();

            Renderer::clear();
            Renderer::render();

            m_window->swapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }

        delete m_window;
    }
}