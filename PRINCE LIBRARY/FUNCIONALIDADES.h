#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "STRUCTURAS.h"
#include "COLORAMA.h"
#include <string>
#include <cctype>

using namespace std;


/*CREACION DE ARREGLOS DE INVENTARIO*/

LIBRO* inventario = new LIBRO[100];

LIBRO inventario_disponible[3] = {
	{202412340, "LIBRO", "EL_QUIJOTE_DE_LA_MANCHA"},
	{202413830, "REVISTA", "NAT GEO NEW PUBLICATION"},
	{202412334, "PERIODICO", "ABEJA REPUBLICANA"}
};
/*___________________________________*/
/*CRACION DE ARREGLOS DE USUARIOS*/
USUARIO* usuarios = new USUARIO[100];

bool verif_string(string texto);
bool verif_dni(string dni);
bool verif_telefono(string telefono);
bool verif_entero(string entero);


/*________________________________________*/

static bool verif_dni(string dni) {
	if (dni.length() == 8) {
		if (verif_entero(dni)) {
			return true;
		}
		else { return false; }

	}
	else { return false; }
}

static bool verif_codigo_libro(string codigo_libro) {
	int n = sizeof(inventario_disponible) / sizeof(inventario_disponible[0]);
	if (verif_entero(codigo_libro)) {
		if (codigo_libro.length() == 9) {
			for (int i = 0; i < n; i++) {
				if (inventario_disponible[i].codigo_libro == stoi(codigo_libro)) {
					return true;
				}
			}
		}
	}
	return false;
}


static bool verif_string(string texto) { //Funcion para verificar si es netamente un string sin entrada de digitos
	for (int i = 0; i < texto.length(); i++) {
		if (isdigit(texto[i])) { return true; }
		else { continue; }
	} return false;
}

static bool verif_telefono(string telefono) {
	if (telefono.length() < 10 && telefono.length() > 1) { // Verificamos numero de telefono evitando los numeros de un string y evitando el caracter +
		bool verif = false;
		for (int i = 0; i < 9; i++) {
			if (isdigit(telefono[i])) { verif = true; }
			if (isdigit(telefono[i]) == false || telefono[i] == '+') { return false; }
		}
		return verif;
	}
	else { return false; }
}

static bool verif_entero(string verificar) { // verificamos si la cadena que ingreso es netamente un numero entero
	if (verificar.length() == 0) { return false; }
	bool verif = false;
	for (int i = 0; i < verificar.length(); i++) {
		if (isspace(verificar[i]) || !isprint(verificar[i])) { return false; }
		if (isdigit(verificar[i])) { verif = true; }
		else { return false; }
	}
	return verif;
}



/*________________________________________*/
/*FUNCION DE ESTETICA DEL PROGRAMA*/
extern void estetica(int tamano = 20, char caracter = '_') {
	cout << "\t";
	for (int i = 0; i < tamano; i++) {
		cout << caracter;
	}cout << endl;
}
/*____________________________________*/


/*____________________________________*/

/*FUNCION COMPLEMENTARIA CAPTURE TIME*/
extern string capture_time() { // tiempo actual
	string tiempo_capturado;
	tm tiempo;
	time_t timestap;
	time(&timestap);
	localtime_s(&tiempo, &timestap);
	/*_______________*/
	tiempo_capturado.append(to_string(tiempo.tm_year + 1900)); tiempo_capturado.append("/");
	tiempo_capturado.append(to_string(tiempo.tm_mon + 1)); tiempo_capturado.append("/");
	tiempo_capturado.append(to_string(tiempo.tm_mday)); tiempo_capturado.append("/ -- ");
	tiempo_capturado.append(to_string(tiempo.tm_hour)); tiempo_capturado.append("(H):");;
	tiempo_capturado.append(to_string(tiempo.tm_min)); tiempo_capturado.append("(M):");
	tiempo_capturado.append(to_string(tiempo.tm_sec)); tiempo_capturado.append("(S)");
	return tiempo_capturado;
}
/*____________________________________*/

extern void obtener_informacion_usuario(int id_usuario) {
	string ingreso_jugar;
	usuarios[id_usuario].hora_operacion = capture_time();
	usuarios[id_usuario].userID = id_usuario;
	while (true) {
		cout << LGREEN << "\t[+]Ingrese nombre del usuario: " << RESET; getline(cin, usuarios[id_usuario].NOMBRE_APELLIDO);
		if (verif_string(usuarios[id_usuario].NOMBRE_APELLIDO)) { cout << RED << "\t[!]" << RESET << ORANGE << "INGRESE BIEN EL NOMBRE\n" << RESET; }
		else { break; }
	}
	while (true) {
		cout << LGREEN << "\t[+]Ingrese edad del usuario: " << RESET;  cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { usuarios[id_usuario].EDAD = stoi(ingreso_jugar); break; }
		else { cout << RED << "\t[!]" << RESET << ORANGE << " Ingrese bien su edad!\n" << RESET; }
	}
	while (true) {
		cout << LGREEN << "\t[+]Seleccion de sexo:\n\t->(1)Masculino\n\t->(2)Femenino\n\t->(3)Cabrini\n\t--> " << RESET; cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { break; }
		else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese un valor correcto!\n " << RESET; }
	}
	switch (stoi(ingreso_jugar))
	{
	case 1: usuarios[id_usuario].SEXO = 'M'; break; case 2: usuarios[id_usuario].SEXO = 'F'; break; case 3: usuarios[id_usuario].SEXO = 'N'; break; default:break;
	}
	while (true) {
		cout << LGREEN << "\t[+]Ingrese su distrito: " << RESET; cin.ignore();  getline(cin, usuarios[id_usuario].direccion.DISTRITO);
		if (verif_string(usuarios[id_usuario].direccion.DISTRITO)) { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese bien los datos!\n" << RESET; }
		else { break; }
	}
	cout << LGREEN << "\t[+]Ingrese su direccion: " << RESET;  getline(cin, usuarios[id_usuario].direccion.DIRECCION);
	while (true) {
		cout << LGREEN << "\t[+]Seleccione:\n\t-->(1)Casa\n\t-->(2)Departamento\n " << RESET; cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { if (stoi(ingreso_jugar) < 3 && stoi(ingreso_jugar) > 0) break; }
		else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese un valor correcto!\n " << RESET; }
	}
	switch (stoi(ingreso_jugar))
	{
	case 1:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "CASA"; break; case 2:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "DEPARTAMENTO"; break; default:break;
	}
	while (true) {
		cout << LGREEN << "\t[+]Ingrese su numero de celular (SIN PREFIJO): " << RESET; cin.ignore();  cin >> ingreso_jugar;
		if (verif_telefono(ingreso_jugar) == false) { ingreso_jugar = " "; cout << RED << "\t[!]" << RESET << ORANGE << " Ingreso de forma erronea el numero telefnoico\n" << RESET; }
		else { usuarios[id_usuario].CELULAR = ingreso_jugar; break; }
	}
}

/*FUNCION COMPLEMENTARIA RECIBIR RESPUESTA*/
extern bool respuesta_continuar() {
	char respuesta;
	cout << endl;
	cout << RED; estetica(20, '!'); cout << RESET;
	cout << LBLUE << "\t[!]desea hacer otra operacion?:<<" << RESET << RED" Y/N " << RESET << endl;
	cin >> respuesta; respuesta = toupper(respuesta);
	if (respuesta == 'Y') { return true; }
	else { return false; }
}
/*_______________________________________*/
/*FUNCION COMPLEMENTARIA GENERAR CODIGO ALEATORIO*/
extern int codigo_aleatorio(int inicio, int fin) {
	int gen;
	srand(time(NULL));
	gen = inicio + rand() % (fin + 1 - inicio);
	return gen;
}
/*___________________________________________________________________________________________________________________________________________________________________________*/


static  string calculo_dia_devolucion() {
	int end_days[] = { 31, 29, 31, 30, 31, 30 };
	int n = sizeof(end_days) / sizeof(end_days[0]);
	int moth_end_day = 0;
	string tiempo_capturado;
	tm tiempo;
	time_t timestap;
	time(&timestap);
	localtime_s(&tiempo, &timestap);
	tiempo_capturado.append(to_string(tiempo.tm_year + 1900)); tiempo_capturado.append("/");
	for (int i = 0; i < n; i++) {
		moth_end_day = end_days[tiempo.tm_mon];
	}
	if (tiempo.tm_mday > tiempo.tm_mday + 5) {tiempo_capturado.append(to_string(tiempo.tm_mon+2)); tiempo_capturado.append("/");}
	else {tiempo_capturado.append(to_string(tiempo.tm_mon+1));}
	tiempo_capturado.append(to_string(tiempo.tm_mday+5)); 
	return tiempo_capturado;
}




extern void generar_matris(int usuario_id=0) {
	for (int i = 0; i < 50; i++) {
		usuarios[usuario_id].libros_tratados[i] = new string[4];
	}
	for (int i = 0; i < 50; i++) {
		usuarios[usuario_id].libros_tratados[i][3] = "void";
	}
}

extern void append_libro(int usuario_id = 0, int fila=0, string libro="void") {
	for (int j = 0; j < 4; j++) {
		if (j == 0) {
			usuarios[usuario_id].libros_tratados[fila][j] = libro;
		}
		if (j == 1) {
			usuarios[usuario_id].libros_tratados[fila][j] = capture_time();
		}
		if(j==2){
			usuarios[usuario_id].libros_tratados[fila][j] = "P";
		}
		if (j == 3) {
			usuarios[usuario_id].libros_tratados[fila][j] = "true";
		}
	}
}


extern  void see_matris(int usuario_id = 0) {
	for (int i = 0; i < 50; i++) {
		if (usuarios[usuario_id].libros_tratados[i][3] == "true") {
			for (int j = 0; j < 4; j++) {
				cout << usuarios[usuario_id].libros_tratados[i][j] << "|";
			}
		}
	}
}


extern void obtener_informacion_prestamo(int usuario_id = 0) {
	int contador_posicion_libro=0; 
	string var_to_game;
	if (usuarios[usuario_id].DNI=="void") {
		while (true) {
			cout << "\n\t[+]Ingrese su numero de DNI: "; getline(cin, var_to_game);
			if (verif_dni(var_to_game)) {
				usuarios[usuario_id].DNI = var_to_game; break;
			}
			else { cout << RED << "\t[!]" << RESET << ORANGE << " Ingrese bien su DNI!\n" << RESET; }
		}
	}
	while (true) {
		var_to_game = "";
		cout << "\n\t[+]Ingrese el codigo del libro: "; getline(cin, var_to_game);
		if (verif_codigo_libro(var_to_game)) {
			contador_posicion_libro++;
			break;}
		else {
			cout << RED << "\t[!]" << RESET << ORANGE << " Ingrese de forma valida su codigo!\n" << RESET;
		}
	}
	append_libro(usuario_id, contador_posicion_libro, var_to_game);
	cout << "\t[!] El dia maximo para devolver es: " << calculo_dia_devolucion() << endl;
}

static void boleta_prestamo(int usuario_id = 0) {
	estetica(100, '_');
	cout << "\t" << usuarios[usuario_id].userID << endl;
	cout << "\t" << usuarios[usuario_id].DNI << endl;
	cout << "\t" << usuarios[usuario_id].NOMBRE_APELLIDO << endl;
	cout << "\t" << usuarios[usuario_id].EDAD << endl;
	cout << "\t" << usuarios[usuario_id].SEXO << endl;
	cout << "\t" << usuarios[usuario_id].direccion.CASA_DEPARTAMENTO << endl;
	cout << "\t" << usuarios[usuario_id].direccion.DIRECCION << endl;
	cout << "\t" << usuarios[usuario_id].direccion.DISTRITO << endl;
	cout << "\t" << usuarios[usuario_id].direccion.PROVINCIA << endl;
	cout << "\t" << usuarios[usuario_id].CELULAR << endl;
	cout << "\t" << usuarios[usuario_id].hora_operacion << endl;
	estetica(100, '_');
	see_matris(usuario_id);

}
