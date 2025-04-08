#include "engine/Engine.h"
#include <thread>
#include <chrono>

namespace engine {
    Engine::Engine() {
    }

    Engine::~Engine() {
        delete m_window;
    }

    void Engine::run() {
        m_window = new Window(800, 600, "Basic Engine");

        while (!m_window->shouldClose()) {
            m_window->pollEvents();
            m_window->swapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }
    }
}