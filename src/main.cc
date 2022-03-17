#include <iostream>
#include <vector>

#include "Util/terminal.hh"

int main( int argc, char** argv )
{
    using namespace Carrot::Terminal;
    using Carrot::Terminal::Color;
    using Carrot::Terminal::Style;
    using std::cout;
    
    Modifier banner({ WHITE_BACKGROUND, BLACK_TEXT });
    Modifier carrotStyle({ BOLD_ON, BLUE_BACKGROUND, YELLOW_TEXT });
    Modifier warn({ YELLOW_BACKGROUND, BLACK_TEXT });
    
    cout << banner("=====================================================") << "\n\n";
    cout << "\t\t " << carrotStyle("🥕 Carrot 2D 🥕") << "\n\n";
    cout << '\t' << warn(" Versão de desenvolvimento v0.1 ") << "\n\n";
    cout << Modifier{BOLD_ON}() << "Responsabilidades do motor:" << Modifier{RESET}() << "\n\n";
    for ( const auto& item : std::vector<std::string>{
        "🟥 Lógica de atualização",
        "🟥 Controle de janela e monitores",
        "🟥 Desenho",
        "🟥 Interação com dispositivos de entrada",
        "🟥 Serialização",
        "🟥 Sons",
        "🟥 Física"
    }) cout << item << '\n';
    cout << "\nLegenda - 🟢: Feito 🔶: Em andamento 🟥: Não iniciado" << "\n\n";
    cout << banner("=====================================================") << "\n\n";

    return 0;
}
