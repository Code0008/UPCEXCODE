// ProyectoPagado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

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
    int DNI;
    char sexo;
    direccion direccion_usuario;
    string celular;

    
};

struct contenido {
    int codigo_libro; //123456
    string titulo_libro;
    bool prestado;
    char tipo;
};


bool verificar_codigo(contenido inventario[], string codigo) {
    for (int i = 0; i < 4; i++) {
        if (stoi(codigo) == inventario[i].codigo_libro) {
            inventario[i].prestado = true;
            return  true;
        }
    }
    return false;
}

void mirar_informacion_inventario(contenido inventario[], Usuarios * usuarios, int posicion) {

    for (int i = 0; i < 4; i++) {
        if (inventario[i].prestado == false) {
            cout << inventario[i].codigo_libro << setw(5);
            cout << inventario[i].titulo_libro << endl;
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
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            switch (j)
            {
            case 0:
                data_usuario[i][0] = codigo;
                break;
            case 1:
                data_usuario[i][1] = "prestamo";
                break;
            case 3:
                data_usuario[i][2] =
            default:
                break;
            }
        }
    }
}


void get_prestamo_data(contenido inventario[], Usuarios* usuarios, int posicion, string ** data_usuario) {
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
    mirar_informacion_inventario(inventario, usuarios, posicion);
    cout << "[!] Ingrese el codigo del libro que va a prestarse:  " << endl;
    while (true)
    {
        string codigo;
        getline(cin, codigo); cin.ignore();
        if (verificar_codigo(inventario, codigo)) {
            break;
        }
    }
    mirar_informacion_inventario(inventario, usuarios, posicion);

    
}


void get_user_data(Usuarios* usuarios, int posicion) {
    cout << "Ingrese el nombre de usuario: " << endl;
    getline(cin, usuarios[posicion].nombre_usuario);
    cout << "Ingrese la edad del usuario: " << endl;
    cin >> usuarios[posicion].edad_usuario;
    cout << "Ingrese su sexo: " << endl;
    cin >> usuarios[posicion].sexo;
    cout << "Ingrese su direccion: " << endl;
    cin.ignore();
    getline(cin,usuarios[posicion].direccion_usuario.direccion_exacta);
    cout << "Ingrese su distrito: " << endl;
    getline(cin, usuarios[posicion].direccion_usuario.distrito); cin.ignore();
    cout << "Ingrese su celular: " << endl;
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


int main()
{
    contenido inventario[4]{
    {202412, "Eltinling", false, 'R'},
    {202411, "Ananim", true, 'R'},
    {202416, "Perukistano", true, 'R'},
    {202415, "Pivano", false, 'R'},
    };
    Usuarios* usuarios = new Usuarios[100];

    string** informacion_tratada = new string * [100];
    make_matriz(informacion_tratada);
    int posicion = 0; 
    char selec;
    while (true) {
        get_user_data(usuarios, posicion);
        
        cout << "Ingrese procesoa ejecutar:"; cin >> selec;

        switch (selec)
        {
        case 'A': 
            get_prestamo_data(inventario, usuarios, posicion, informacion_tratada);
            break;
        default:
            break;
        }
        if (mensaje_continuar()) {
            continue;
        }
    }

}




