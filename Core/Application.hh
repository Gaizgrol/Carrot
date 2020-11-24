#pragma once

// Project libraries
#include "World.hh"

namespace Carrot
{
    // Forward declaration
    class Entity;

    class Application
    {
        private:
            static World* currentWorld;

        public:
            static void run();
            static void start( World* startingWorld );

            static Entity* instanceCreate( Entity* newEntity );
            static void instanceDestroy( size_t entityId );
    };
}
