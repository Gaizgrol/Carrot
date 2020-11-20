#pragma once

// Global libraries
#include <string>
#include <vector>

// Project libraries
#include "Component.hh"

namespace Carrot
{
    class Entity
    {
        private:
            static size_t lastId;

            size_t id;
            std::vector<Component*> components;
            bool active;

        public:
            Entity();

            void onStep();
    };
}
