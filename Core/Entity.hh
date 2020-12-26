#ifndef _CARROT_CORE_ENTITY_
#define _CARROT_CORE_ENTITY_

// Global includes
#include <memory>
#include <string>
#include <unordered_map>

namespace Carrot
{
    // Forward declaration
    class Component;

    class Entity
    {
        public:
            Entity();
            ~Entity();

            template<typename T, typename... Args>
            std::shared_ptr<T> addComponent( Args... args );
            
            template<typename T>
            std::shared_ptr<T> getComponent();

            size_t getId();
            
            template<typename T>
            bool hasComponent();
            
            template<typename T>
            std::shared_ptr<T> removeComponent();

        private:
            static size_t lastId;

            std::unordered_map<std::string, std::shared_ptr<Component>> components;
            size_t id;
            bool isActive;
            bool isDestroyed;
            size_t layer;
            float position[2];
    };
}

// Template implementation
#include "Entity.tcc"

#endif
