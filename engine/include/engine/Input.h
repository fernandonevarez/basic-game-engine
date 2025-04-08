#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H

struct GLFWwindow;

namespace engine {

    class Input {
    public:
        static void setWindow(GLFWwindow* window);
        static bool isKeyPressed(int key);
    private:
        static GLFWwindow* s_window;
    };

}

#endif // ENGINE_INPUT_H