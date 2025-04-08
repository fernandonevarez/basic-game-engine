#include "engine/Input.h"

#include <iostream>
#include <GLFW/glfw3.h>

namespace engine {
    GLFWwindow *Input::s_window = nullptr;

    void Input::setWindow(GLFWwindow *window) {
        s_window = window;
    }

    bool Input::isKeyPressed(const int key) {
        if (!s_window) {
            std::cerr << "[Input] No window set!" << std::endl;
            return false;
        }

        if (const int state = glfwGetKey(s_window, key); state == GLFW_PRESS) {
            std::cout << "[Input] Key " << key << " is pressed" << std::endl;
            return true;
        }

        return false;
    }
}