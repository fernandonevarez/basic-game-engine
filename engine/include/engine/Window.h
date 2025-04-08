#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

struct GLFWwindow;

namespace engine {
    class Window {
    public:
        Window(int width, int height, const char *title);

        ~Window();

        bool shouldClose() const;

        static void pollEvents();

        void swapBuffers() const;

    private:
        GLFWwindow *m_window;
    };
}

#endif // ENGINE_WINDOW_H
