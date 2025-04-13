#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "engine/Entity.h"

namespace engine {
    class Renderer {
    public:
        static void init();

        static void render(const Entity &entity);

        static void clear();
    };
}

#endif // ENGINE_RENDERER_H
