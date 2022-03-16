#ifndef _CARROT_CORE_WORLD_
#define _CARROT_CORE_WORLD_

#include "Application.hh"
#include "Entity.hh"

// Global includes
#include <vector>
#include <set>

namespace Carrot
{
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
