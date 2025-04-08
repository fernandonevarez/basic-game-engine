#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

namespace engine {
    class Renderer {
    public:
        static void init();

        static void render();

        static void clear();
    };
}

#endif // ENGINE_RENDERER_H