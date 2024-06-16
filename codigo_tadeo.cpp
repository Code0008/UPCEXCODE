// ProyectoPagado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
#include <cctype>
#include <ctime>
#include <time.h>
#include <string>
#include <stdio.h>
#include <iomanip>
using namespace std;


struct direccion {
    string direccion_exacta;
    string distrito;
    string provincia="Lima";
};
struct Usuarios {
    string nombre_usuario;
    int edad_usuario;
    int DNI=0;
    char sexo;
    direccion direccion_usuario;
    string celular;
    bool sancion=false;
};

struct contenido {
    int codigo_libro; //123456
    string titulo_libro;
    bool prestado;
    char tipo;
};


void see_info_tratada(string** tratado) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            if (tratado[i][3] == "true") {
                cout << "\t";
                cout << tratado[i][j];
            }
        }
    }
}
bool verificar_codigo(contenido inventario[], string codigo) {
    for (int i = 0; i < 5; i++) {
        if (stoi(codigo) == inventario[i].codigo_libro) {
            inventario[i].prestado = true;
            return  true;
            break;
        }
    }
    return false;
}

void mirar_informacion_inventario(contenido inventario[], Usuarios * usuarios, int posicion) {
    cout << "\tCODIGO\ttitulo" << endl;
    for (int i = 0; i < 4; i++){
        if (inventario[i].prestado == false) {
            cout << "\t" << inventario[i].codigo_libro << "\t" << inventario[i].titulo_libro << endl;
        }
    }
}

void agregar_libro(string ** data_usuario, string codigo, string fecha_devlucion) {
    int indice = 0;
    for (int i = 0; i < 100; i++) {
        if (data_usuario[i][3] == "true" && data_usuario[i + 1][1] == "false") {
            indice = i + 1;
            break;
        }
    }
    for (int j = 0; j < 4; j++) {
        switch (j){
        case 0: data_usuario[indice][0] = codigo; break;
        case 1:data_usuario[indice][1] = "prestamo"; break;
        case 2:data_usuario[indice][2] = fecha_devlucion;break;
        case 3: data_usuario[indice][3] = "true"; break;
        default:break; }
    }
}


void get_prestamo_data(contenido inventario[], Usuarios* usuarios, int posicion, string ** data_usuario) {
    string dni;
    while (true) {
        cout << "[!] Ingrese su DNI: " << endl;
        getline(cin, dni);
        if (dni.length() == 8) {  break;}
        else { continue; }
    }
    usuarios[posicion].DNI = stoi(dni);
    mirar_informacion_inventario(inventario, usuarios, posicion);
    cout << "[!] Ingrese el codigo del libro que va a prestarse:  " << endl;
    while (true)
    {
        string codigo;
        getline(cin, codigo); 
        if (verificar_codigo(inventario, codigo)) {
            agregar_libro(data_usuario, codigo, "hoy ");
            break;
        }
    }
    cout << "\t INVENTARIO ACTUAL DE LA BIBLIOTECA" << endl;
    mirar_informacion_inventario(inventario, usuarios, posicion);
    cout << "\t INVENTARIO ACTUAL DEL USUARIO" << endl;
    see_info_tratada(data_usuario);
    cout << endl;
}


void get_user_data(Usuarios* usuarios, int posicion) {
    cout << "\tIngrese el nombre de usuario: " << endl;
    getline(cin, usuarios[posicion].nombre_usuario);
    cout << "\tIngrese la edad del usuario: " << endl;
    cin >> usuarios[posicion].edad_usuario;
    cout << "\tIngrese su sexo: " << endl;
    cin >> usuarios[posicion].sexo;
    cin.ignore();
    cout << "\tIngrese su direccion: " << endl;
    getline(cin,usuarios[posicion].direccion_usuario.direccion_exacta);
    cout << "\tIngrese su distrito: " << endl;
    getline(cin, usuarios[posicion].direccion_usuario.distrito); 
    cout << "\tIngrese su celular: " << endl;
    getline(cin, usuarios[posicion].celular); 
}

bool mensaje_continuar() {
    char respuesta;
    cout << "Ingrese su respuesta ";
    cin >> respuesta;
    if (toupper(respuesta) == 'N') {
       exit(0);
    }
    else {
        return true;
    }
    
}

void make_matriz(string  **  matriz) { 
    for (int i = 0; i < 100; i++) {
    
        matriz[i] = new string[4];
    }
    for (int i = 0; i < 100; i++) {
        matriz[i][3] = "false";
    }
    /*
    0       1       2       3
    codigo  proceso fecha   verificador

    */
}

void get_devolucion_data(string** infotratada, Usuarios* usuarios, int posicion ) {
    if (usuarios[posicion].DNI==0) {
        string dni;
        while (true) {
            cout << "[!] Ingrese su DNI: " << endl;
            getline(cin, dni);
            if (dni.length() == 8) {
                break;
            }
            else { continue; }
        }
        usuarios[posicion].DNI = stoi(dni);
    }
    string codigo;
    while (true) {
        cout << "\nINGRESE EL CODIGO DEL LIBRO: ";
        getline(cin, codigo);
        if (codigo.length() == 5) {
            break;
        }
        else { continue; }
    }
   
}

int main()
{
    contenido inventario[4]{
    {202412, "Eltinling", false, 'R'},
    {202411, "Ananim", false, 'R'},
    {202416, "Perukistano", false, 'R'},
    {202415, "Pivano", false, 'R'},
    };
    Usuarios* usuarios = new Usuarios[100];

    string** informacion_tratada = new string * [100];
    make_matriz(informacion_tratada);
    int posicion = 0; 
    char selec;
    while (true) {
        get_user_data(usuarios, posicion);
        cout << "\t [A] Prestamo" << endl;
        cout << "\t [B] Devolucion" << endl;
        cout << "Ingrese procesoa ejecutar:"; cin >> selec;
        switch (selec)
        {
        case 'A': 
            cin.ignore();
            get_prestamo_data(inventario, usuarios, posicion, informacion_tratada);
            break;
        case 'B': 
            if (usuarios[posicion].sancion != true) {
                get_devolucion_data(informacion_tratada, usuarios, posicion);
            }
            else { break; }
            break;
        default:
            break;
        }
        if (mensaje_continuar()) {
            continue;
        }
    }

}
