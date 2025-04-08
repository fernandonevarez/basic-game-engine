#include "engine/Window.h"
#include <GLFW/glfw3.h>
#include <iostream>

namespace engine {
    Window::Window(int width, int height, const char *title) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW\n";
            std::exit(EXIT_FAILURE);
        }

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!m_window) {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            std::exit(EXIT_FAILURE);
        }

        // allows the ability to use the ESC button to quit
        glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int, int action, int) {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);
        });


        glfwMakeContextCurrent(m_window);
    }

    Window::~Window() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(m_window);
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(m_window);
    }
}