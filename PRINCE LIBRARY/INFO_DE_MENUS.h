#pragma once
#include <iostream>
#include "FUNCIONALIDADES.h"
#include "COLORAMA.h"
using namespace std;


extern void menu_login() {
    cout <<
        BG_BLACK << MAGENTA <<
        "\t\t$$$$$$$\\ $$$$$$\\$$$$$$$$\\$$\\   $$\\$$\\    $$\\$$$$$$$$\\$$\\   $$\\$$$$$$\\$$$$$$$\\  $$$$$$\\  \n"
        "\t\t$$  __$$\\\\_$$  _$$  _____$$$\\  $$ $$ |   $$ $$  _____$$$\\  $$ \\_$$  _$$  __$$\\$$  __$$\\ \n"
        "\t\t$$ |  $$ | $$ | $$ |     $$$$\\ $$ $$ |   $$ $$ |     $$$$\\ $$ | $$ | $$ |  $$ $$ /  $$ |\n"
        "\t\t$$$$$$$\\ | $$ | $$$$$\\   $$ $$\\$$ \\$$\\  $$  $$$$$\\   $$ $$\\$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t$$  __$$\\  $$ | $$  __|  $$ \\$$$$ |\\$$\\$$  /$$  __|  $$ \\$$$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t$$ |  $$ | $$ | $$ |     $$ |\\$$$ | \\$$$  / $$ |     $$ |\\$$$ | $$ | $$ |  $$ $$ |  $$ |\n"
        "\t\t$$$$$$$  $$$$$$\\$$$$$$$$\\$$ | \\$$ |  \\$  /  $$$$$$$$\\$$ | \\$$ $$$$$$\\$$$$$$$  |$$$$$$  |\n"
        "\t\t\\_______/\\______\\________\\__|  \\__|   \\_/   \\________\\__|  \\__\\______\\_______/ \\______/ \n" << RESET;
    cout << BG_BLACK << "\t"; estetica(88, ' ');
    cout << BG_GREEN<< BLUE;  estetica(100, '_'); cout << RESET;
    cout << BG_GREEN << BLUE;  estetica(100, ' '); cout << RESET;
    cout << BG_GREEN << WHITE << "\t\t\t" << capture_time() << RESET << BG_GREEN << BLACK << " -INGRESE INFORMACION BASICA DE USUARIO-\t\t\t" << RESET << endl;
    cout << BG_GREEN << BLUE;  estetica(100, ' '); cout << RESET;
    cout << BG_GREEN<< BLUE;  estetica(100, '-'); cout << RESET << "\n";
}


extern void menu_principal() {
    cout << "\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*+++++*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
        "\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+=---======--:-=+*%@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%\n"
        "\t%%%%%%%%%%%%%%%%%%%%%%%%@%=-+*%@@@@%+=--=================--:=#%#+=-=+#@@%@@@%%@@@%@@%@%%@@\n"
        "\t%=**:..........-+-=-::.:@@+=:  :+*=-========================-..:-===*#@%#%%@*=@**+@@@@@@@@\n"
        "\t%#%%**************#*****@@*===-.:-============+===========++++*++=++#*@##%#@*=-==--@@+*%==\n"
        "\t%#%***%+***%+**@*%*#*%*%@@%+==+============================++++=+==+*+*##%#@*-:==--:==+*:-\n"
        "\t%@%%%%%%%%%%%%%%%%%%%%%@@@@%++==+=========================+##++=*+-=====*##@*=-++==-=+==-=\n"
        "\t%==---------------==#**#@@@%+=++============+**+============##*++===+++==+@@@@@@@@@@@@@@@@\n"
        "\t%+=================+#**#@@#.-++=========+*%@@@@@@%#+=========#*#*+=+++++=+%#######%%%%%%%#\n"
        "\t%#%@%%%@%@%%%%%%%@@@@@@@@#.:====+=====*%@@@@@@@@@@@@@%*+======++@+-=+===++%%#%%%%%+++++%%%\n"
        "\t%%%%#%%%%@%%%%%%%@@@@@@@#.:==+======*@@@@@@@@@@@@@@@@@@@@#+=====+%%##****%%%#%%%%%%%%%%#%%\n"
        "\t%+*=++==+=@=+=+=++*+++*%..========*@@@@@@@@@@@@@@@@@@@@@@@@%*=====****@@+===**+**+*#%%%#+*\n"
        "\t%@%@@@@@@@@@@@@@@@@@@%#..===*===*@@@@@@@@%##%#####%@@@%@@@@@@@#+===+*%%%----+-:::--:::.=--\n"
        "\t%%%%%#%%%##%#%%@%@@@@%:.==+===+%@@@@@@%#%##########%#%####%%@@@%*========.--+====++=+***=+\n"
        "\t%%%%@%%%@%%%%%%%%%@@%:.======#@@@@@%%%#############*.*########@@@*=======-.+*==------==*:=\n"
        "\t%##%%#%%%%#%%%%%#%@%:.=====+%@@@#%%+-%#*#%**#######*.:++#####*###@#=======:.*%%%%%%%%%%%##\n"
        "\t%*#%%%%%%%%%%%%%%%%:.=====#@@%###%#:.-*+*#######**#=   ::=*####**%%#=======:.=========*@##\n"
        "\t%%@@%%%@%@%%%%@@@%-.====+@@@%#####+.-====+#%##*****.:+#@@@%%@@#**##@%*======:.#%%%%%%%%%%=\n"
        "\t@@@@@@@@@@@@@@@@@-.-===#@@@@@###%%%#*%@@@#-=###***- -+%%%%*:+#**###%#@@%*====::%%#%%##@@@*\n"
        "\t%%#%%##%%%%%%%@@= -==*@@@%#@%%####*::#+**+.  :-+**:  :----..:+**###%#%@@@@#+==:-%@%@%%@%@%\n"
        "\t##%##%##%##%#%@= -=+%@@@@%#%%%%#**.:.::::.     ==::.   .::..=*#*##%##%@@@@@@%+=.-%%%%%%##%\n"
        "\t%####%%%@%@@%%* :=*@@@@%@@##%#%%##*:....      ..       ...-+##*#%%%%#%@%@@@@@@%=.#@@@%@**#\n"
        "\t#*##*#%@@@@@@%# =*@@@@@@%@%##%##%%##=-:.       :       .:-=*%#*#@%@%#@%@@@@@@@@*=@@@%%@**+\n"
        "\t%%%%%%%%%%%%@%@=+@@@@@@@@@@@%#%%#@@%+.             .    ..-%###%@@%#@%%%@@@@@*==%@@@#%*=*+\n"
        "\t@@@@@@@@@@%@@%@@+*%@@@@%*#%@@@%@@@%@@+.     .    .       =@@##%@@%###***%@@#+=**%##%-:=-*+\n"
        "\t@@@@@@@@@@@@@%@@@#==+##%****#%%@%%@@@@%+:             .+@@@##%@@@#******@@+++++==+=+======\n"
        "\t%@#%@%%%%%%%#%@#@%%#++=+#*****####%%%@@@@@*=.      .=#@@@@%@@%%%##*****%#*#%%%%%%@%%##%###\n"
        "\t@@#*@@@@@@@%%@@@@@#*#%%%@***#%@%######@@@@@@@@#+-=#@%*@@@@@@####%@%****@%%%#*#@@@@%@%***++\n"
        "\t@@%%**#%@@@@@%#+***####%%####*#@%%%##@@@@@@@#%@@@@#+==%@@@@#*#%%%%####%#######*+*##*+==---\n"
        "\t@@#%@#=::=++==*###*#%%@@@@*=*++%%%@@@@@%%@@@+=+**+=-::*%@@%@@@%%@*+#++@@@@@%#####*=++*=---\n"
        "\t@@+:.-*%@%*+*#####%@@@@@@%---+=*%#%%#%#####+====-.   :####%%%%%%*=+===*@@@@@@%###*#%#%#*#%\n"
        "\t#--#@@%###*####%@@@@@@@@@*== -=+%#%%%######:...     :#######%%#%+=- -==%@%@@@@@@%#########\n"
        "\t#@%@###%@##*##%%##@@%*=%@++*-+++%%%%%######*..     :#######%%%%%+++-*+=@#===*%@@@@@%###*##\n"
        "\t@@#*###@%########%%-:=++@%*%****%%%@@=+#####- ::   *#####*=#@%%%**++##*@*=++-:-#@%%%%%###%\n"
        "\t%%-###%########%%@=-=*==#@@@%@##%@@@%=--=+###+==++*###*=---#@@@@##@%@@@@+======-@@%%###%##\n"
        "\t#:*######%###%%%##:==++==@@@@@%%@@@@++===--=*#-==*#+=-:==+**#@@@%%@@@@@*=======-*%%%%%####\n"
        "\t+:#%####%###@%##*--====+=%@@@@@@@######*++=--=###+--=+#########@@@@@@@+==========@@@%%%###\n"
        "\t+-#%####%###@@%%%.=+=====+#%%%%%%###########**#%#######**###**%%%%%%#+===========@@@@@@%%#\n"
        "\t*:#%#%%%%%%%@@@@#.=**=++==*######%#*###########**###********#%#######++=======+=+%@@@%%%##\n"
        "\t##*#%#%%%@%#@@%#*==**+=**=*@@@@#++@#****#####%%##%%####*****%@+*@@@@@=======+==#=#@@@%@%##\n"
        "\t%%##%###%@%#@%#**==+*+==*%*@@@++==*%%#####%%###%%##%%#####%@@+==*@@@@+=======+*%-+%@@%%##@\n"
        "\t%%%%%%##%%%%@%###===*+===*@@#+++====%@%%%%#*###*#####%@%%%#*#*==++#%@*=======*%*-:%@@@##@@\n"
        "\t%%%%%%##%%%%%%%%%=+==*++=+%#==+======**%#**#*##=***##*##*====+**+++#@#*+====+*++=.*%%%%%@@\n"
        "\t@@@@@@@##%*@@@@%*+=+==*##%*===========*#****###=+#*******=======+****#+=====+====.#@@###@@\n"
        "\t@@@@@@@@##@%@@@++*=====*#+===========#*****##%*=+*#*****#*========+++**=========-.+@@%##%*";
    cout << endl;
    estetica(50, '_');
    cout << "\n\t---> SELECCION PRESTAMO(1)\n""\t---> SELECCION DEVOLUCION(2)\n""\t--->(3)INGRESAR A REPORTES";

}


extern void menu_prestamo() {
    cout << "\n"
        "  _____  _____  ______  _____ _______       __  __  ____  \n"
        " |  __ \\|  __ \\|  ____|/ ____|__   __|/\\   |  \\/  |/ __ \\ \n"
        " | |__) | |__) | |__  | (___    | |  /  \\  | \\  / | |  | |\n"
        " |  ___/|  _  /|  __|  \\___ \\   | | / /\\ \\ | |\\/| | |  | |\n"
        " | |    | | \\ \\| |____ ____) |  | |/ ____ \\| |  | | |__| |\n"
        " |_|    |_|  \\_\\______|_____/   |_/_/    \\_\\_|  |_|\\____/ \n"
        "                                                          ";
}


extern void menu_devulocion() {





}


