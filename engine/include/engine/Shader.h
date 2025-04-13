#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include <glm/glm.hpp>
#include <glad/glad.h>

namespace engine {
    class Shader {
    private:
        GLuint m_programID;
    public:
        Shader(const char *vertexSrc, const char *fragmentSrc);

        ~Shader();

        void bind() const;

        static void unbind();

        void setVec2(const std::string &name, const glm::vec2 &value) const;


    };
}

#endif // ENGINE_SHADER_H
