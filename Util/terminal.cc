#include "terminal.hh"

#include <initializer_list>
#include <set>
#include <string>

namespace Carrot
{
    namespace Terminal
    {
        Modifier::Modifier( std::initializer_list<int> modifiers )
        {
            for ( auto mod : modifiers )
                _modifiers.insert( std::to_string( mod ) );
        }

        std::string Modifier::operator()( const bool& reset )
        {
            return operator()("", reset);
        }

        std::string Modifier::operator()( const char* text )
        {
            return operator()( std::string(text) );
        }
        
        std::string Modifier::operator()( const std::string& text, bool reset )
        {
            size_t i = 0;
            size_t size = _modifiers.size();

            std::string modString = "\033[";

            for ( auto mod : _modifiers )
            {
                modString += mod;
                if ( i < size - 1 )
                    modString += ';';
                i++;
            }

            modString += 'm' + text + ( reset ? "\033[0m" : "" );

            return modString;
        }
    }
}