#include <string>
#include <typeinfo>

#ifdef __GNUG__
// g++ implementation

#include <cxxabi.h>

namespace Carrot
{
    template<typename T>
    const std::string type()
    {
        // Discover mangled/truncated name
        const char* typeName = typeid( T ).name();
        
        // Transforms the truncated name into the original name
        int status = 1;
        char* abiDemangle = abi::__cxa_demangle( typeName, nullptr, nullptr, &status );

        // If the transformation was successful, use the original name. Otherwise, use the truncated one
        const char* demangledName = ( status == 0 ) ? abiDemangle : typeName;
        
        // Return the original name as a string
        std::string unmangled( demangledName );
        free( abiDemangle );
        
        return unmangled;
    }
}

#else
// g++ is not the compiler. Return truncated name

namespace Carrot
{
    template<typename T>
    const std::string type()
    {
        // Retorna o nome truncado do tipo  
        std::string originalName( typeid( T ).name() );
        return originalName;
    }
}

#endif