#pragma once

// Global libraries
#include <vector>

// Project libraries
#include "Entity.hh"

namespace Carrot
{
    class World
    {
        private:
            std::vector<Entity*> toBeCreated;
            std::vector<Entity*> stepEntities;
            std::vector<size_t> toBeDestroyed;

        public:
            static const World* getActiveWorld();
            
            World();
            ~World();

            void handleCreation();
            void handleDestruction();
            void run();
            void step();
    };
}
