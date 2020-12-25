#ifndef _CARROT_CORE_APPLICATION_
#define _CARROT_CORE_APPLICATION_

// Project libraries
#include "World.hh"

namespace Carrot
{
    // Forward declaration
    class Entity;

    class Application
    {
        public:
            static World* currentWorld;

            static void run();
            static void start( World* startingWorld );

            static Entity* instanceCreate( Entity* newEntity );
            static void instanceDestroy( size_t entityId );
    };
}

#endif
