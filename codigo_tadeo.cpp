#include <iostream>
#include <cctype>
#include <ctime>
#include <time.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
using namespace std;

struct direccion {
    string direccion_exacta;
    string distrito;
    string provincia = "Lima";
};
struct Usuarios {
    string nombre_usuario;
    int edad_usuario;
    int DNI = 0;
    char sexo;
    direccion direccion_usuario;
    string celular;
    bool sancion = false;
};
struct contenido {
    int codigo_libro; //123456
    string titulo_libro;
    bool prestado;
    char tipo;
};

bool verif_string(string texto);
bool verif_dni(string dni);
bool verif_telefono(string telefono);
bool verif_entero(string entero);
tm capture_time() {
    tm tiempo;
    time_t timestap;
    time(&timestap);
    localtime_s(&tiempo, &timestap);
    return tiempo;
}

static bool verif_dni(string dni) {
    if (dni.length() == 8) {
        if (verif_entero(dni)) {
            return true;
        }
        else { return false; }
    }else { return false; }
}

static bool verif_string(string texto) {
    bool verif = true;
    for (int i = 0; i < texto.length(); i++) {
        if (isdigit(texto[i])) { return true; }
        else { continue; }
    } return false;
}

static bool verif_telefono(string telefono) {
    if (telefono.length() < 10 && telefono.length() > 1) {
        bool verif = false;
        for (int i = 0; i < 9; i++) {
            if (isdigit(telefono[i])) { verif = true; }
            if (isdigit(telefono[i]) == false || telefono[i] == '+') { return false; }
        }return verif;
    }else { return false; }
}

static bool verif_entero(string verificar) {
    if (verificar.length() == 0) { return false; }
    bool verif = false;
    for (int i = 0; i < verificar.length(); i++) {
        if (isspace(verificar[i]) || !isprint(verificar[i])) { return false; }
        if (isdigit(verificar[i])) { verif = true; }
        else { return false; }
    }
    return verif;
}

void see_info_tratada(string** tratado) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            if (tratado[i][3] == "true") {cout << "\t";cout << tratado[i][j];}
        }
    }
}
bool verificar_codigo(contenido inventario[], string codigo) {
    for (int i = 0; i < 5; i++) {
        if (stoi(codigo) == inventario[i].codigo_libro) {inventario[i].prestado = true;return  true; break;}
    }
    return false;
}

void mirar_informacion_inventario(contenido inventario[], Usuarios* usuarios, int posicion) {
    cout << "\tCODIGO\ttitulo" << endl;
    for (int i = 0; i < 4; i++) {
        if (inventario[i].prestado == false) {cout << "\t" << inventario[i].codigo_libro << "\t" << inventario[i].titulo_libro << endl;}
    }
}

void agregar_libro(contenido inventario[], string** data_usuario, string codigo, int fecha_devlucion) {
    int indice = 0;
    for (int i = 0; i < 100; i++) {
        if (data_usuario[i][3] == "true" && data_usuario[i + 1][1] == "false") {indice = i + 1;break;}
    }
    string fecha;
    int indice_2 = 0;
    for (int i = 0; i < 4; i++) {
        if (inventario[i].codigo_libro == stoi(codigo)) {indice_2 = i; break; }
    }
   
    switch (inventario[indice_2].tipo) {case 'R': fecha = to_string(fecha_devlucion += 2);break;case 'P':fecha = to_string(fecha_devlucion += 5); break;case 'L': fecha  = to_string(fecha_devlucion += 5); break;}
    for (int j = 0; j < 4; j++) {
        switch (j) {
        case 0: data_usuario[indice][0] = codigo; break;
        case 1:data_usuario[indice][1] = "prestamo"; break;
        case 2:data_usuario[indice][2] = fecha; break;
        case 3: data_usuario[indice][3] = "true"; break;
        default:break;
        }
    }
}
void get_prestamo_data(contenido inventario[], Usuarios* usuarios, int posicion, string** data_usuario) {
    string dni;
    while (true) {
        cout << "[!] Ingrese su DNI: " << endl;
        getline(cin, dni);
        if (dni.length() == 8) { break; }
        else { continue; }
    }
    usuarios[posicion].DNI = stoi(dni);
    mirar_informacion_inventario(inventario, usuarios, posicion);
    cout << "[!] Ingrese el codigo del libro que va a prestarse:  " << endl;
    while (true) {
        string codigo; getline(cin, codigo);
        if (verificar_codigo(inventario, codigo)) { agregar_libro(inventario, data_usuario, codigo, capture_time().tm_mday);break; }
    }
    cout << "\t INVENTARIO ACTUAL DE LA BIBLIOTECA" << endl;
    mirar_informacion_inventario(inventario, usuarios, posicion);
    cout << "\t INVENTARIO ACTUAL DEL USUARIO" << endl;
    see_info_tratada(data_usuario);
    cout << endl;
}

void get_user_data(Usuarios* usuarios, int posicion) {
    while (true) {
        cout << "\tIngrese el nombre de usuario: " << endl;getline(cin, usuarios[posicion].nombre_usuario);
        if (verif_string(usuarios[posicion].nombre_usuario)) {cout << "\t INGRESO MAL EL NOMBRE DE USUARIO" << endl; }
        else { break; }
    }
    string validar;
    while (true) {
        cout << "\t[+]Ingrese edad del usuario: "; cin >> validar;
        if (verif_entero(validar)) { usuarios[posicion].edad_usuario = stoi(validar); break; }
        else { cout <<"\t[!] Ingrese bien su edad!\n"; }
    }

    while (true) {
        cout << "\tIngrese su sexo: " << endl;
        usuarios[posicion].sexo = _getch();
        if (usuarios[posicion].sexo == 'M' || usuarios[posicion].sexo == 'F') {
            break;
        }
        else {
            cout << "\t ingrse su sexo de forma correcta" << endl;
        }
    
    }
    while (true){  cin.ignore();
        cout << "\tIngrese su direccion: " << endl;
        getline(cin, usuarios[posicion].direccion_usuario.direccion_exacta);
        cout << "\tIngrese su distrito: " << endl;
        getline(cin, usuarios[posicion].direccion_usuario.distrito);
        if (verif_string(usuarios[posicion].direccion_usuario.direccion_exacta) != true && verif_string(usuarios[posicion].direccion_usuario.distrito) != true && usuarios[posicion].direccion_usuario.distrito.length() >= 5)  { break; 
        }else{ cout << "\t ALGUNO DE LOS DATOS MAL INGRESAO" << endl;}
    }
    while(true){
        cout << "\tIngrese su celular: " << endl;
        getline(cin, usuarios[posicion].celular);
        if (verif_telefono(usuarios[posicion].celular)) {break; }else { cout << "\t INGRESE CORRECTAMENTE SU TELEFONO" << endl; }
    }
}

bool mensaje_continuar() {
    char respuesta;
    cout << "Ingrese su respuesta ";
    respuesta = _getch();
    if (toupper(respuesta) == 'N') { exit(0);}
    else {  return true;}
}

void make_matriz(string** matriz) {
    for (int i = 0; i < 100; i++) {
        matriz[i] = new string[4];
        matriz[i][3] = "false";
    }
}

void get_devolucion_data(contenido* inventario, string** infotratada, Usuarios* usuarios, int posicion) {
    cin.ignore();
    if (usuarios[posicion].DNI == 0) {
        string dni;
        while (true) {
            cout << "[!] Ingrese su DNI: " << endl; getline(cin, dni);
            if (dni.length() == 8) { break;} else { continue; }
        }
        usuarios[posicion].DNI = stoi(dni);
    }
    string codigo;
    while (true) {
        cout << "\nINGRESE EL CODIGO DEL LIBRO: ";getline(cin, codigo);
        if (codigo.length()>= 5) {
            agregar_libro(inventario, infotratada, codigo, 0);
            break;}
        else { continue; }
    }
    char tipo_libro;
    int dia_que_paso;
    while(true){
        cout << "\nINGRESE TIPO DE LIBRO: ";
        tipo_libro = _getch(); cout << endl;
        tipo_libro = toupper(tipo_libro);
        if (tipo_libro == 'R' || tipo_libro == 'L' || tipo_libro == 'P') {switch (tipo_libro){case 'R':dia_que_paso = 5;break;case 'L':dia_que_paso = 5; break;case 'P':dia_que_paso = 2;break; }break; }
    }
    string mes;
    int mes_i;
    int dia_i;
    while (true) {
        cout << "\nINGRESE EL MES QUE PRESTO ";
        cin >> mes;
        if (verif_entero(mes)) {
            if (stoi(mes) >= capture_time().tm_mon + 1) {
                mes_i = stoi(mes);
                break;
            }
            else {
                cout << "\t INGRESO MAL MES" << endl;
            }
            
        }else {
            cout << "\t INGRESO MAL EL MES" << endl;
        }
    }
    while (true) {
        cout << "\nINGRESE EL DIA QUE PRESTO ";
        cin >> mes;
        if (verif_entero(mes)) {
            if (stoi(mes) <= capture_time().tm_yday) {
                dia_i = stoi(mes);
                break;
            }
            else {
                cout << "\t INGRESO MAL EL DIA" << endl;
            }
        }
        else {
            cout << "\t INGRESO MAL EL DIA" << endl;
        }
    }
    int total = (mes_i*6)-(30-dia_i);
    if (capture_time().tm_yday >= total+dia_que_paso) {
        cout << "\t GRACIAS POR DEVOLVER A TIEMPO!" << endl;
        
    }
    else {
        usuarios[posicion].sancion;
        cout << "\t TIENES SANCION MARRON!" << endl;

    }

    see_info_tratada(infotratada);
    cout << endl;
    
}

int main(){
    contenido inventario[4]{{202412, "Eltinling", false, 'R'},{202411, "Ananim", false, 'L'},{202416, "Perukistano", false, 'P'},{202415, "Pivano", false, 'R'},};
    Usuarios* usuarios = new Usuarios[100];
    string** informacion_tratada = new string * [100];
    make_matriz(informacion_tratada);
    int posicion = 0;char selec;
    while (true) {
        get_user_data(usuarios, posicion);
        cout << "\t [A] Prestamo" << endl;
        cout << "\t [B] Devolucion" << endl;
        cout << "Ingrese procesoa ejecutar:"; cin >> selec;
        switch (selec){
        case 'A':cin.ignore(); get_prestamo_data(inventario, usuarios, posicion, informacion_tratada);break;
        case 'B':
            if (usuarios[posicion].sancion != true) {get_devolucion_data(inventario, informacion_tratada, usuarios, posicion);}
            else { break; }break;
        }
        if (mensaje_continuar()) {
            cin.ignore();
            cout << endl;continue;}
    }
}
