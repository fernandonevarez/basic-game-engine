#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include "glm/glm.hpp"

namespace engine {
    class Entity {
    public:
        Entity();

        void update(float dt);

        void draw() const;

        glm::vec2 position;

        glm::vec2 velocity;
    };
}

#endif // ENGINE_ENTITY_H
