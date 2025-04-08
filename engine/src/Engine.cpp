#include "engine/Engine.h"
#include <iostream>
#include <thread>
#include <chrono>

namespace engine {
    Engine::Engine() {
    }

    Engine::~Engine() {
    }

    void Engine::run() {
        std::cout << "Engine is running!" << std::endl;
    }
}
