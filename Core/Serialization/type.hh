#ifndef _CARROT_CORE_SERIALIZATION_TYPE_
#define _CARROT_CORE_SERIALIZATION_TYPE_

#include <string>

namespace Carrot
{
    template<typename T>
    const std::string type();
}

// Template implementation
#include "type.cc"

#endif
