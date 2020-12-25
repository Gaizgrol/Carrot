// Global libraries
#include <iostream>

// Project libraries
#include "World.hh"

namespace Carrot
{
    World::~World()
    {
        // Mark every instance for destruction
        for ( const auto& entity : stepEntities )
            instanceDestroy( entity->getId() );
        
        // Destroy everything
        handleEntityDestruction();
    }

    /**
     *  Triggered before step event: all entities queued
     *  for creation are added in the step list
     */
    void World::handleEntityCreation()
    {
        if ( toBeCreated.size() > 0 )
        {
            // Push all entities on creation queue on step list
            for ( const auto& entity : toBeCreated )
                stepEntities.push_back( entity );
            
            // Clear creation queue
            toBeCreated.clear();
        }
    }

    /**
     *  Triggered after step event: all entities marked
     *  for destruction are deleted and removed from the
     *  step list
     */
    void World::handleEntityDestruction()
    {
        if ( toBeDestroyed.size() > 0 )
        {
            std::vector<size_t> indexes;

            // Find all entities marked for deletion
            for ( size_t i = 0; i < stepEntities.size(); i++ )
                if ( toBeDestroyed.find( stepEntities[i]->getId() ) != toBeDestroyed.end() )
                    indexes.push_back( i );

            // Clear destruction set
            toBeDestroyed.clear();

            // Deallocate entity memory and remove from step list
            for ( const auto& i : indexes )
            {
                delete stepEntities[i];
                stepEntities.erase( stepEntities.begin() + i );
            }
        }
    }

    Entity* World::instanceCreate( Entity* newEntity )
    {
        // Place entity on creation queue
        toBeCreated.push_back( newEntity );
        return newEntity;
    }

    void World::instanceDestroy( size_t instanceId )
    {
        toBeDestroyed.insert( instanceId );
    }

    void World::run()
    {
        // World lifecycle
        handleEntityCreation();
        step();
        handleEntityDestruction();
    }

    void World::step()
    {
        
    }
}
