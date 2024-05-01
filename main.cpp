#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;
int main();void banner();void menu();bool verif(string codigo);

unsigned short veces_ejecutada = 0, veces_prestado = 0, veces_devuelto = 0; string nombre_usuario, codigo_empleado;

int main() {
    banner();
    char continu;
    cout << "Ingrese su nombre del trabajor(sin espacios): " << endl;getline(cin,nombre_usuario);
    do{cout << "Ingrese su codigo de usuario: " << endl; cin >> codigo_empleado;}
    while(verif(codigo_empleado)!=true|| codigo_empleado.length()>=9);
    do {
        veces_ejecutada++;
        menu();
        cout << endl << "Desea continuar? S/N: "; cin >> continu;
    } while (toupper(continu) != 'N');
    cout << "VECES EJECUTADO: " << veces_ejecutada << endl;
    cout << "VECES DEVUELTO: " << veces_devuelto << endl;
    cout << "VECES PRESTADO: " << veces_prestado << endl;
    return 0;
}
bool verif(string codigo){
    bool ver = true;
    for(unsigned short x=0; x<codigo.length(); x++){
        if(isdigit(codigo[x])){ ver=true; continue; }
        else{ver=false; break;}
    }
    if (ver!=true){ return false;}
    else{return true;}
}
void estetica(unsigned short longitud){
    cout <<"|  ";
    for(unsigned short x=0; x<longitud;x++){
        cout << '-';
    }
}
void boleta_prestar() {
    char dia1[2], mes[2];int diai, mesi,prestado;
    do {cout << "\n\t";estetica(20);cout << "[+]Ingrese el diai: "; cin >> dia1;
        if (atoi(dia1)>0){diai= atoi(dia1);break;}else{cout<<"Valor incorrewcto"<<endl;}
    } while (true);
    do {cout << "\n\t";estetica(20);cout << "[+]Ingrese el mes actual: ";cin >> mes;
        if (atoi(mes)>0){mesi= atoi(mes); break;}
    } while(true);
    do {
        if (prestado>14){cout << "\n";estetica(20);cout << "Cantidad incorrecta ingrese denuevo" << endl;}
        cout <<"\n\t";estetica(20);cout<<"Ingrese la cantidad de diais que tomara prestado el libro (Limite 14):"
                ;cin >> prestado;
    } while(prestado>14);
    cout <<"\n";estetica(60);
    cout<<"\n\t";estetica(20);cout<<"[-]Usuario: "<<nombre_usuario;cout<<"\n\t";estetica(20);
    cout<<"[-]con el codigo: "<< codigo_empleado;cout<<"\n\t";estetica(20);
    cout<<"[!]Registro un prestamo que durara: "<< prestado; cout<<"\n\t";estetica(20);
    cout<<"[!]Se espera recibir el dia: ";diai + prestado < 30 ? prestado = prestado+diai:prestado=(prestado+diai)-30;
    cout <<prestado; cout<<"\n\t";estetica(20); cout<<"[!]Del mes";
    diai + prestado < 30 ? mesi = mesi : mesi++;cout << mes;
}
void boleta_devolver() {
    int diai, mes, prestado_diai, prestado_mes, sancion_economica = 0, diais_pasados;
    do{
        estetica(100);
        do {
            cout<<"\n\t";estetica(20);cout << "\t[+] Ingrese el diai: ";cin >> diai;cout << endl << "\t";
            estetica(20);cout<<"\t[+] Ingrese el mes actual: ";cin >> mes;
            cout<<endl << "\t";estetica(20);cout << "\t[!] Ingrese el diai pidio prestado el libro: ";
            cin >>prestado_diai;cout << endl << "\t";estetica(20);
            cout<<"\t[!] Ingrese el mes que presto el libro: ";cin >> prestado_mes;
        }while(diai>30 || prestado_diai>30 || mes>=12 || prestado_mes>=12);
        if (mes>prestado_mes) {diais_pasados=(30*mes)-(30*prestado_mes)-(prestado_diai);
            diais_pasados>14? sancion_economica=diais_pasados : sancion_economica=0;}
    }while(mes<prestado_mes);

    if (sancion_economica == 0) { estetica(20);cout << "\tSE GENERO LA DEVOLUCION DEL LIBRO" << endl; }
    else { cout<<"\n\t";estetica(20);cout << "SE DEBE APLICAR UNA SANCION DE:" << sancion_economica << endl;}
}

void menu() {
    char seleccion; string codigo_libro_num;
    do{
        cout << "Codigo de libro (Ej: 123456): "<< endl; cin>> codigo_libro_num;
    }while(verif(codigo_libro_num)!=true || codigo_libro_num.length()>=7);
    cout << "[+] Seleccione prestar(P)/ devolver(D)" << endl; cin >> seleccion;
    switch (toupper(seleccion)) {
        case 'D':  boleta_devolver();veces_devuelto++;break;
        case 'P':  boleta_prestar();veces_prestado++; break;
        case 'B': banner(); break;
        default:  break;
    }
}

void banner(){
          cout <<
                  "                             SOMOS TODOS UN PANOLI                                        \n"
                  "            -====-                     .....                                              \n"
                  "          =+******+++:             ::...........                                          \n"
                  "        -+**#####*****+:         ::::...    ........                                      \n"
                  "        +###****#####***+.     ::.... .-----.  .........                                  \n"
                  "        +###+=####*####**:     ::. .  .-===-----.   ....:::::::.       ..                 \n"
                  "        =#####++##*###**#**:   ::.......:=====----...........    ........:.               \n"
                  "        +############= :###:   --:::::..........:-=====-....   .:+#***#**=-               \n"
                  "          *##########-   +#- ++--:::::::.::.:.........::.....:-+#*****##*=-               \n"
                  "            +#*****+    .+#*+++::::.:::::::::::::::::.::::::-+######*###*+-               \n"
                  "                       :#=---++:::...-=++=+==-=====-::::::-=+*###*****###+-               \n"
                  "                       :#+=--++:::...--===========+=::::--+==+**#****####*-               \n"
                  "                       :#*+==++::..:...............:::----:---=+*######**=:               \n"
                  "                       :#**++**--..:::::::::::---:::----::::--===*###***+                 \n"
                  "                       :#****##-:===*######===-=======:::::===*####***+--                 \n"
                  "                       :#****#*--+++#%%%%%%+++===+=----:::-=++*###**+=-                   \n"
                  "                     .-=#****#+=+%%%%%%%%%%%%%+====+==-----#%%%%%#*--                     \n"
                  "                 .===+***##**#**+=--%@@%##*===-------------*##%@@+:                       \n"
                  "                 .##********###**:::%@@%*#+::::::::::::::::**#%@@:                        \n"
                  "                  -=**+****##+=**. .#%%#++= ..::...........+++%@@:                        \n"
                  "                    :=**#**##-:**...*##+==- ...............+++###:                        \n"
                  "                     .:::+###--**:..=++-:::................+++-::                         \n"
                  "                         =###=-**=-::::---=++=......-++-...:-=-::                         \n"
                  "                         =###****==--::.:-=**+......=**=:...:=+:.                         \n"
                  "                         +#######++==--::-=+**+++****#*=....:-+-:                         \n"
                  "                         +#######%#++=-::-=+***********+:::-==+=-                         \n"
                  "                         +#****####%#+=:--=+**+++******+--=+#*+=-                         \n"
                  "                         +#****######%%%#####%######%#.    -##**+.                        \n"
                  "                       :*****###########*+++*#****+*##+=                                  \n"
                  "                       :#****##########*+=--+#******##**+=                                \n"
                  "                      .-#****########%%%%%%%*+=-::--++-=#*.                               \n"
                  "                     -##***##########**##%##*++++=**==*#%#*=.                             \n"
                  "                    :=##*########*+=----+####*********%%%#*+=:                            \n"
                  "                   :##*####+=*###++===++*#%%####=-::*###%%**+-                            \n"
                  "                   .=======  -=##+=:---=*%##****=---+***###**=:.                          \n"
                  "                               *#==:-+=:+#*=--:::-==:::-=+##+*#-                          \n"
                  "                               ##*+=+%#=*%#+++++++**+++++*%#*##-                          \n"
                  "                               :-*###%%##%%%%%=-*%##%%%%%%%%%+-.                          \n"
                  "                                 :-===+%%##*##: +%##**#*-----.                            \n"
                  "                                      :%#*+-+*. +%**++=:                                  \n"
                  "                                       :+##**#. .:*###*-                                  \n"
                  "                                        .::::.    .::::.                                  \n"
                  "                                                                                          "
                  "\n"
                  "\t  _____  _____  _____ _   _  _____ ______ \n"
                  "\t |  __ \\|  __ \\|_   _| \\ | |/ ____|  ____|\n"
                  "\t | |__) | |__) | | | |  \\| | |    | |__   \n"
                  "\t |  ___/|  _  /  | | | . ` | |    |  __|  \n"
                  "\t | |    | | \\ \\ _| |_| |\\  | |____| |____ \n"
                  "\t |_|    |_|  \\_\\_____|_| \\_|\\_____|______|\n"
                  "\t                                          \n";
}
