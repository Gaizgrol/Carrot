#ifndef _CARROT_CORE_APPLICATION_
#define _CARROT_CORE_APPLICATION_

#include <cstddef>

namespace Carrot
{
    // Forward declaration
    class Entity;
    class World;

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
