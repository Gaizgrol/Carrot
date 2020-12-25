// Global libraries
#include <type_traits>
#include <unordered_map>

// Project libraries
#include "Entity.hh"
#include "Serialization/type.hh"

namespace Carrot
{
    // Referencing static symbols
    size_t Entity::lastId = 0;

    Entity::Entity()
    {
        id = lastId++;
        isActive = true;
        isDestroyed = false;
        layer = 0;
        position[0] = 0;
        position[1] = 0;
    }

    Entity::~Entity()
    {
        components.clear();
    }

    size_t Entity::getId()
    {
        return id;
    }
}
