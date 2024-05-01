#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main();
unsigned short veces_ejecutada = 0, veces_prestado = 0, veces_devuelto = 0; string nombre_usuario, codigo_empleado;

void estetica(){
    for(unsigned short x=0; x<20;x++){
        cout << '-';
    }
}
void boleta_devolver(string nombre_usuario, string codigo_empleado, string codigo) {
    int dia, mes, prestado_dia, prestado_mes, sancion_economica = 0;
    do{
        do {
        cout << "\n\t";estetica();cout << "\t[+] Ingrese el dia: ";cin >> dia;cout << endl << "\t";estetica();
        cout << "\t[+] Ingrese el mes actual: ";cin >> mes;
        cout << endl << "\t";estetica();cout << "\t[!] Ingrese el dia pidio prestado el libro: ";
        cin >> prestado_dia;cout << endl << "\t";estetica();
        cout << "\t[!] Ingrese el mes que presto el libro: ";cin >> prestado_mes;cout << endl << "\t";estetica();
        }while(dia>30 || prestado_dia>30 || mes>=12 || prestado_mes>=12);
        if (mes>prestado_mes) { sancion_economica=(30*(mes-prestado_mes)-prestado_dia)-(30-dia);
            sancion_economica-14>14 ? sancion_economica= sancion_economica*2 : sancion_economica=0 ; }
    }while(mes<prestado_mes);
    if (sancion_economica == 0) { cout << "\tEXCELENTE GRACIAS POR DEVOLVER A TIEMPO" << endl; }
    else {cout << "USTED TIENE UN SANCION DE " << sancion_economica << endl;}
}

void boleta_prestar(string nombre_usuario, string codigo_empleado, string codigo) {
    unsigned short dia, mes, prestado;
    do {
        cout << "Ingrese el dia: "  << endl; cin >> dia;
        cout << "Ingrese el mes actual: "<<endl; cin >> mes;
    }while(dia<0 && dia>31 || mes<0&& mes>12);
    do {
        if (prestado>14) {cout << "Cantidad incorrecta ingrese denuevo" << endl;}
        cout << "Ingrese la cantidad de dias que tomara prestado el libro (Limite 14): " << endl;cin >> prestado;
    } while(prestado>14);
        cout << "Usuario " << nombre_usuario << endl << "con el codigo" << codigo_empleado <<
             endl << " Registro un prestamo de: " << prestado << " dias" << endl << " Se espera recibir el dia: ";
        dia + prestado < 30 ? prestado = prestado + dia : prestado = (prestado + dia) - 30;cout <<prestado <<" Del mes";
        dia + prestado < 30 ? mes = mes : mes++;cout << mes;
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
void menu() {
    char seleccion; string codigo_libro_num;
        do{
        cout << "Codigo de libro (Ej: 123456): "<< endl; cin>> codigo_libro_num;
        }while(verif(codigo_libro_num)!=true || codigo_libro_num.length()>=7);
        cout << "[+] Seleccione prestar(P)/ devolver(D)" << endl; cin >> seleccion;
        switch (toupper(seleccion)) {
            case 'D':  boleta_devolver(nombre_usuario, codigo_empleado, codigo_libro_num);veces_devuelto++;break;
            case 'P':  boleta_prestar(nombre_usuario, codigo_empleado, codigo_libro_num);veces_prestado++; break;
            case 'E':
            default:  break;
        }
}
int main() {
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

