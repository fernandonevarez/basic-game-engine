#include "engine/Entity.h"
#include <iostream>

namespace engine {

    Entity::Entity()
        : position(0.0f), velocity(0.0f) {}

    void Entity::update(const float dt) {
        position += velocity * dt;
    }

    void Entity::draw() const {
        // Placeholder
        std::cout << "Entity at (" << position.x << ", " << position.y << ")\n";
    }

}