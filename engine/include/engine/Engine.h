#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Window.h"

namespace engine {
    class Engine {
    private:
        Window *m_window = nullptr;

    public:
        Engine();

        ~Engine();

        void run();
    };
}

#endif // ENGINE_ENGINE_H