// Interface include
#include "util.hh"

// Global includes
#include <iostream>

// Project includes
#include "../Util/terminal.hh"

void testsUtil()
{
    using namespace std;
    using namespace Carrot::Terminal;
    
    Modifier emojiBG({ Color::BLUE_BACKGROUND, Color::WHITE_TEXT, Style::BOLD_ON });
    Modifier boldGreenWhite({
        Color::GREEN_BACKGROUND,
        Color::WHITE_TEXT,
        Style::UNDERLINE_ON
    });
    Modifier underlineWhiteBlack({
        Color::WHITE_BACKGROUND,
        Color::BLACK_TEXT,
        Style::BOLD_ON,
    });
    Modifier reset({ Style::RESET });
    Modifier custom({ Color::RED_BACKGROUND, Color::WHITE_TEXT });

    cout << emojiBG("🥕 Carrot Test Start 🥕") << endl << endl;

    cout << boldGreenWhite() << "Underline" << endl;
    cout << underlineWhiteBlack() << "Underline + Bold" << endl;
    cout << reset() << "Reset! " << custom("UEPAAA!") << " Normal again!" << endl;

    cout << endl << emojiBG("🥕  Carrot Test End  🥕") << endl;
}