#ifndef _CARROT_CORE_WORLD_
#define _CARROT_CORE_WORLD_

// Global libraries
#include <vector>
#include <set>

// Project libraries
#include "Entity.hh"

namespace Carrot
{
    // Forward declaration
    class Application;

    class World
    {
        private:
            friend class Application;

            std::vector<Entity*> toBeCreated;
            std::vector<Entity*> stepEntities;
            std::set<size_t> toBeDestroyed;

            void handleEntityCreation();
            void handleEntityDestruction();
            
            Entity* instanceCreate( Entity* newEntity );
            void instanceDestroy( size_t entityId );

            void run();
            void step();

        public:
            ~World();
    };
}

#endif
