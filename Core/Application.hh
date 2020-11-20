#pragma once

// Project libraries
#include "World.hh"

namespace Carrot
{
    class Application
    {
        private:
            static World* currentWorld;

        public:
            static World* getCurrentWorld();
            static void run();
            static void start( World* startingWorld );
    };
}
