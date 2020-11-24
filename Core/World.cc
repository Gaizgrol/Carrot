// Global libraries
#include <iostream>

// Project libraries
#include "World.hh"

namespace Carrot
{
    World::World()
    {
        stepEntities.push_back( new Entity() );
    }

    World::~World()
    {
        Entity* v = stepEntities[0];
        stepEntities.pop_back();
        instanceDestroy( v->getId() );
    }

    void World::handleCreation()
    {
    }

    void World::handleDestruction()
    {
    }

    Entity* World::instanceCreate( Entity* newEntity )
    {
        return newEntity;
    }

    void World::instanceDestroy( size_t instanceId )
    {
        toBeDestroyed.insert( instanceId );
    }

    void World::run()
    {
        std::cout << "World running..." << std::endl;

        handleCreation();
        step();
        handleDestruction();
    }

    void World::step()
    {
        for ( const auto& entity : stepEntities )
        {
            entity->onStep();
        }
    }
}
