#include "engine/Input.h"

#include <iostream>
#include <GLFW/glfw3.h>

namespace engine {
    GLFWwindow *Input::s_window = nullptr;

    static std::unordered_map<int, std::string> keyNames = {
        {GLFW_KEY_W, "W"},
        {GLFW_KEY_A, "A"},
        {GLFW_KEY_S, "S"},
        {GLFW_KEY_D, "D"},
        {GLFW_KEY_ESCAPE, "Escape"},
        {GLFW_KEY_SPACE, "Space"},
        {GLFW_KEY_ENTER, "Enter"},
        {GLFW_KEY_LEFT, "Left Arrow"},
        {GLFW_KEY_RIGHT, "Right Arrow"},
        {GLFW_KEY_UP, "Up Arrow"},
        {GLFW_KEY_DOWN, "Down Arrow"}
    };

    void Input::setWindow(GLFWwindow *window) {
        s_window = window;
    }

    bool Input::isKeyPressed(const int key) {
        if (!s_window) {
            std::cerr << "[Input] No window set!" << std::endl;
            return false;
        }

        if (const int state = glfwGetKey(s_window, key); state == GLFW_PRESS) {
            auto it = keyNames.find(key);
            if (it != keyNames.end()) {
                std::cout << "[Input] Key '" << it->second << "' is pressed" << std::endl;
            } else {
                std::cout << "[Input] Key " << key << " is pressed (unmapped)" << std::endl;
            }
            return true;
        }

        return false;
    }
}
