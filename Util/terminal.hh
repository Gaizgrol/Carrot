#ifndef _CARROT_UTIL_TERMINAL_
#define _CARROT_UTIL_TERMINAL_

#include <initializer_list>
#include <set>
#include <string>

namespace Carrot
{
    namespace Terminal
    {
        enum Style
        {
            RESET = 0,

            BOLD_ON = 1,
            UNDERLINE_ON = 4,
            INVERSE_ON = 7,
            
            BOLD_OFF = 21,
            UNDERLINE_OFF = 24,
            INVERSE_OFF = 27,
        };

        enum Color
        {
            BLACK_TEXT = 30,
            RED_TEXT,
            GREEN_TEXT,
            YELLOW_TEXT,
            BLUE_TEXT,
            MAGENTA_TEXT,
            CYAN_TEXT,
            WHITE_TEXT,

            BLACK_BACKGROUND = 40,
            RED_BACKGROUND,
            GREEN_BACKGROUND,
            YELLOW_BACKGROUND,
            BLUE_BACKGROUND,
            MAGENTA_BACKGROUND,
            CYAN_BACKGROUND,
            WHITE_BACKGROUND,
        };
        
        class Modifier
        {
            public:
                Modifier( std::initializer_list<int> modifiers );
                
                std::string operator()( const bool& reset = false );
                std::string operator()( const char* texto );
                std::string operator()( const std::string& text, bool reset = true );
            
            private:
                std::set<std::string> _modifiers;
        };
    }
}

#endif