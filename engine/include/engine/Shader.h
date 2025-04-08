#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <glad/glad.h>

namespace engine {
    class Shader {
    public:
        Shader(const char *vertexSrc, const char *fragmentSrc);

        ~Shader();

        void bind() const;

        void unbind() const;

    private:
        GLuint m_programID;
    };
}

#endif // ENGINE_SHADER_H