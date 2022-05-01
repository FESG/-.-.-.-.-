#include "pch.h"
#include "Controlador.h"

void Menu();

void Logo();

int main()
{
    srand(time(NULL));
    Console::SetWindowSize(110, 41);
    char tecla, opcion;

    while (1) {
        Controlador* controlador = new Controlador();
        do {
            system("cls");
            Menu();
            cin >> opcion;
            opcion = toupper(opcion);
        } while (opcion != 'M' && opcion != 'P' && opcion != 'E' && opcion != 'R');

        if (opcion == 'E')
        {
            exit(0);
        }

        switch (opcion) {
        case 'M':
            Logo();
            Console::SetCursorPosition(35, 29); cout << "\n\t\t\t\t\t\tIntegrantes";
            Console::SetCursorPosition(35, 31); cout << "\n\t\t\t\t-Lucas Coronel, Nadia Alessandra (U202120430)";
            Console::SetCursorPosition(35, 32); cout << "\n\t\t\t\t-Jarama Pe" << char(164) << "aloza, Fiorella(U202120418)";
            Console::SetCursorPosition(35, 33); cout << "\n\t\t\t\t-Santos Gonzales, Felix Eduardo (U201617450)\n\n";
            system("PAUSE");
            break;
        case 'P':
            system("cls");
            controlador->IniciarJuego();
            Logo();
            Console::SetCursorPosition(35, 32); cout << "\n\t\t\t\t\t\tGAME OVER\n\n";
            system("PAUSE");
            break;

        case 'R':
            system("cls");
            Console::SetCursorPosition(35, 9); cout << "\n\t\t\t\t\t\Reglas de Cyberninja 2088:";
            Console::SetCursorPosition(35, 11); cout << "\n\t\t\t\t- El cyberninja se movera usando las teclas W, A, S, D";
            Console::SetCursorPosition(35, 12); cout << "\n\t\t\t\t- Se generaran aleatoriamente 5 documentos ";
            Console::SetCursorPosition(35, 13); cout << "\n\t\t\t\t- Al presionar la tecla K se recoge el documento";
            Console::SetCursorPosition(35, 14); cout << "\n\t\t\t\t- El cyberninja cuenta con 4 puntos de armadura y 2 pociones ";
            Console::SetCursorPosition(35, 15); cout << "\n\t\t\t\t  de resurrecion";
            Console::SetCursorPosition(35, 16); cout << "\n\t\t\t\t- El jugador debe evitar ser impactado por las shurikens que se ";
            Console::SetCursorPosition(35, 17); cout << "\n\t\t\t\t  mueven de forma vertical, horizontal y diagonal";
            Console::SetCursorPosition(35, 18); cout << "\n\t\t\t\t- Al ser impactado por un shuriken perdera 1 punto de armadura";
            Console::SetCursorPosition(35, 19); cout << "\n\t\t\t\t- Si el jugador logra conseguir 5 documentos un ninja recolector ";
            Console::SetCursorPosition(35, 20); cout << "\n\t\t\t\t  se llevara los documentos y los almacenara";
            Console::SetCursorPosition(35, 21); cout << "\n\t\t\t\t- El juego termina cuando al jugador no le queden pociones ";
            Console::SetCursorPosition(35, 22); cout << "\n\t\t\t\t  o recolecte los 5 documentos\n\n ";
            system("PAUSE");
            break;
        }
    }
    _getch();
    return 0;
}

void Logo() {
    system("cls");
    Console::SetCursorPosition(35, 3); cout << "           .                .                    ";
    Console::SetCursorPosition(35, 4); cout << "           :\" - .      . - \":                    ";
    Console::SetCursorPosition(35, 5); cout << "           |:`.`.__..__.'.';|                    ";
    Console::SetCursorPosition(35, 6); cout << "           || :-\"      \"-; ||                    ";
    Console::SetCursorPosition(35, 7); cout << "           :;              :;                   ";
    Console::SetCursorPosition(35, 8); cout << "           /  .==.    .==.  \\                   ";
    Console::SetCursorPosition(35, 9); cout << "          :      _.--._      ;                   ";
    Console::SetCursorPosition(35, 10); cout << "          ; .--.' `--' `.--. :                   ";
    Console::SetCursorPosition(35, 11); cout << "         :   __;`      ':__   ;                  ";
    Console::SetCursorPosition(35, 12); cout << "         ;  '  '-._:;_.-'  '  :                  ";
    Console::SetCursorPosition(35, 13); cout << "          '.       `--'     .'                  ";
    Console::SetCursorPosition(35, 14); cout << "         .\" - ._          _. \".                   ";
    Console::SetCursorPosition(35, 15); cout << "       .'     \"\"------\"\"      `.                 ";
    Console::SetCursorPosition(35, 16); cout << "      /`-                     -'\\ ";
    Console::SetCursorPosition(35, 17); cout << "     /`-                       -'\\                ";
    Console::SetCursorPosition(35, 18); cout << "    /`-                         -'\\               ";
    Console::SetCursorPosition(35, 19); cout << "   :`-   .'                 `.   -';              ";
    Console::SetCursorPosition(35, 20); cout << "  ;    /                      \\    :              ";
    Console::SetCursorPosition(35, 21); cout << " :    :                       ;    ;             ";
    Console::SetCursorPosition(35, 22); cout << " ;    ;                       :    :             ";
    Console::SetCursorPosition(35, 22); cout << " ':_:.'                       '.;_;'             ";
    Console::SetCursorPosition(35, 23); cout << "   :_                            _;                ";
    Console::SetCursorPosition(35, 24); cout << "     :_          ()             _;   \"--::__. `.  ";
    Console::SetCursorPosition(35, 25); cout << "     .-\" - . - \"-.  \"\"--..____.'  ";
    Console::SetCursorPosition(35, 26); cout << "   /         .__  __.         \\         ";
    Console::SetCursorPosition(35, 27); cout << "   : / ,       / \"\" \\       . \\ :";
    Console::SetCursorPosition(35, 28); cout << "   \" - :___..--\"      \"--..___; -\"";
}

void Menu() {
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::SetCursorPosition(38, 4); cout << " _ __ ___   ___ _ __  _   _ ";
    Console::SetCursorPosition(38, 5); cout << "| '_ ` _ \\ / _ \\ '_ \\| | | |";
    Console::SetCursorPosition(38, 6); cout << "| | | | | |  __/ | | | |_| |";
    Console::SetCursorPosition(38, 7);  cout << "|_| |_| |_|\___|_| |_|\__,_|";

    Console::SetCursorPosition(38, 9); cout << "        .--'''''''''--.";
    Console::SetCursorPosition(38, 10); cout << "     .'      .---.      '.";
    Console::SetCursorPosition(38, 11); cout << "    /    .-----------.    .";
    Console::SetCursorPosition(38, 12); cout << "   /        .-----.        |";
    Console::SetCursorPosition(38, 13); cout << "   |       .-.   .-.       |";
    Console::SetCursorPosition(38, 14); cout << "   |      /   \ /   \        | ";
    Console::SetCursorPosition(38, 15); cout << "   |     | .-. | .-. |    /";
    Console::SetCursorPosition(38, 16); cout << "     '-._| | | | | | |_.-'";
    Console::SetCursorPosition(38, 17); cout << "         | '-' | '-' |   ";
    Console::SetCursorPosition(38, 18); cout << "          \___/ \___/    ";
    Console::SetCursorPosition(38, 19); cout << "       _.-'  /   \  `-._ ";
    Console::SetCursorPosition(38, 20); cout << "     .' _.--|     |--._ '.";
    Console::SetCursorPosition(38, 21); cout << "     ' _...-|     |-..._ '";
    Console::SetCursorPosition(38, 22); cout << "            |     |          ";
    Console::SetCursorPosition(38, 23); cout << "            '.___.'         ";
    Console::SetCursorPosition(38, 24); cout << "              | |        ";
    Console::SetCursorPosition(38, 25); cout << "             _| |_         ";
    Console::SetCursorPosition(38, 26); cout << "            /\( )/\.     ";
    Console::SetCursorPosition(38, 27); cout << "           /  ` '  \.     ";
    Console::SetCursorPosition(38, 28); cout << "          | |     | |     ";
    Console::SetCursorPosition(38, 29); cout << "          '-'     '-'     ";
    Console::SetCursorPosition(38, 30); cout << "          | |     | |     ";
    Console::SetCursorPosition(38, 31); cout << "          | |     | |      ";

    Console::SetCursorPosition(38, 33); cout << "-----------CYBERNINJA 2088-----------";

    Console::SetCursorPosition(38, 35); cout << "Escriba [R] si desea salir visualizar las reglas";
    Console::SetCursorPosition(38, 36); cout << "Escriba [P] si desea jugar";
    Console::SetCursorPosition(38, 37); cout << "Escriba [M] si desea ver los cr" << char(130) << "ditos";
    Console::SetCursorPosition(38, 38); cout << "Escriba [E] si desea salir";
    Console::SetCursorPosition(38, 39); cout << "-> ";
}

