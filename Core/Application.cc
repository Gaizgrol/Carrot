// Interface include
#include "Application.hh"

// Global includes
#include <chrono>
#include <thread>

// Project includes
#include "World.hh"

namespace Carrot
{
    // Referencing static symbols
    World* Application::currentWorld = nullptr;

    Entity* Application::instanceCreate( Entity* newEntity )
    {
        currentWorld->instanceCreate( newEntity );
    }

    void Application::instanceDestroy( size_t entityId )
    {
        currentWorld->instanceDestroy( entityId );
    }
    
    void Application::run()
    {
        while ( true )
        {
            std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
            currentWorld->run();
        }
    }

    void Application::start( World* startingWorld )
    {
        currentWorld = startingWorld;
        run();
    }
}
