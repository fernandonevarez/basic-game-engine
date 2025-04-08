#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "engine/Window.h"
#include "engine/Input.h"
#include <iostream>

namespace engine {
    Window::Window(const int width, const int height, const char *title): m_window(nullptr) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW\n";
            std::exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // required for macOS
#endif

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!m_window) {
            std::cerr << "[Window] Failed to create GLFW window" << std::endl;
            glfwTerminate();
            std::exit(EXIT_FAILURE);
        }

        Input::setWindow(m_window);

        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cerr << "[Window] Failed to initialize GLAD" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        std::cout << "[Window] GLAD initialized successfully" << std::endl;

        std::cout << "[Window] OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

        // allows the ability to use the ESC button to quit
        glfwSetKeyCallback(m_window, [](GLFWwindow *window, const int key, int, const int action, int) {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, true);
            }
        });
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

    void Window::swapBuffers() const {
        glfwSwapBuffers(m_window);
    }
}
