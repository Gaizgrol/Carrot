// Global libraries
#include <iostream>

// Project libraries
#include "Entity.hh"

namespace Carrot
{
    // Referencing static symbols
    size_t Entity::lastId = 0;

    Entity::Entity()
    {
        id = lastId++;
        active = true;
        std::cout << id << std::endl;
    }

    void Entity::onStep()
    {
        std::cout << id << ": step()" << std::endl;
    }
}
