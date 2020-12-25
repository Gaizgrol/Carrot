#ifndef _CARROT_CORE_ENTITY_
#define _CARROT_CORE_ENTITY_

// Global libraries
#include <memory>
#include <string>
#include <type_traits>
#include <unordered_map>

#include "Serialization/type.hh"

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

    template<typename T, typename... Args>
    std::shared_ptr<T> Entity::addComponent( Args... args )
    {
        if ( std::is_base_of<Component, T>::value && !hasComponent<T>() )
        {
            auto newComponent = std::shared_ptr<T>( new T(args...) );
            components.insert({ type<T>(), newComponent });
            return newComponent;
        }

        return std::shared_ptr<T>( nullptr );
    }
    
    template<typename T>
    std::shared_ptr<T> Entity::getComponent()
    {
        auto component = components.find( type<T>() );
        if ( component != components.cend() )
            return std::static_pointer_cast<T>( component->second );
        return std::shared_ptr<T>( nullptr );
    }

    template<typename T>
    bool Entity::hasComponent()
    {
        auto component = components.find( type<T>() );
        return component != components.cend();
    }
    
    template<typename T>
    std::shared_ptr<T> Entity::removeComponent()
    {
        if ( std::is_base_of<Component, T>::value )
        {
            auto k = getComponent<T>();
            components.erase( type<T>() );
            return k;
        }
        return std::shared_ptr<T>( nullptr );
    }
}

#endif
