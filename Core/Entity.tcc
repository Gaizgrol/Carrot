// Avoid including this file directly
#ifndef _CARROT_CORE_ENTITY_
#error Include Entity.hh instead of Entity.tcc
#endif

// Interface include
#include "Entity.hh"

// Global includes
#include <memory>
#include <string>
#include <type_traits>
#include <unordered_map>

// Project includes
#include "Serialization/type.hh"

namespace Carrot
{
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
