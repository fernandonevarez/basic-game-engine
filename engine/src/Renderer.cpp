#include "engine/Renderer.h"
#include <GLFW/glfw3.h>

namespace engine {

    void Renderer::clear() {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::drawTriangle() {
        // TEMP: Draw using immediate mode (bad, but easy)
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f( 0.5f, -0.5f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f( 0.0f,  0.5f);
        glEnd();
    }

}