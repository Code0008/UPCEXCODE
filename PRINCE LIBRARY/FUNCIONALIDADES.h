#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "STRUCTURAS.h"
#include <string>
using namespace std;


/*________________________________________*/

static bool verif_string(string texto) {
	for (int i = 0; i < texto.length(); i++) {
		if (isdigit(texto[i])) { return true; }
		else { continue; }
	} return false;
}

static bool verif_telefono(string telefono) {
	cout << telefono.length();
	if (telefono.length() <10) {
		bool verif=false;
		for (int i = 0; i < 9; i++) {
			if (telefono[i] == '+') { return false; }
			if (isdigit(telefono[i])) { verif = true; }
		}
		return verif;
	}
	else { return false; }
}

static bool verif_entero(string verificar) {
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
/*____________________________________*/

/*FUNCION COMPLEMENTARIA CAPTURE TIME*/
extern string capture_time() {
	string tiempo_capturado;
	tm tiempo;
	time_t timestap;
	time(&timestap);
	localtime_s(&tiempo, &timestap);
	/*_______________*/
	tiempo_capturado.append(to_string(tiempo.tm_year + 1900)); tiempo_capturado.append("/");
	tiempo_capturado.append(to_string(tiempo.tm_mon+1)); tiempo_capturado.append("/");
	tiempo_capturado.append(to_string(tiempo.tm_mday)); 
	return tiempo_capturado;
}
/*____________________________________*/

extern void obtener_informacion_usuario(int id_usuario) {
	string ingreso_jugar;
	usuarios[id_usuario].hora_operacion = capture_time();
	usuarios[id_usuario].userID = id_usuario;
	while (true) {
		cout << "\tIngrese nombre del usuario: ";
		getline(cin, usuarios[id_usuario].NOMBRE_APELLIDO);
		if (verif_string(usuarios[id_usuario].NOMBRE_APELLIDO)) { cout << "\t [!]INGRESE BIEN EL NOMBRE\n";}
		else {break; }
	}

	while (true){
		cout << "\tIngrese edad del usuario: ";  cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { usuarios[id_usuario].EDAD = stoi(ingreso_jugar); break; }
		else { cout << "\t[!] Ingrese bien su edad!\n"; } 
	}
	while (true) {
		cout << "\tSeleccion de sexo Masculino(1)/Femenino(2)/Helicoptero apache(3): "; cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { break; }
		else { cout << "\t[!]Ingrese un valor correcto!\n "; }
	}
	switch (stoi(ingreso_jugar))
	{case 1: usuarios[id_usuario].SEXO = 'M'; break; case 2: usuarios[id_usuario].SEXO = 'F'; break; case 3: usuarios[id_usuario].SEXO = 'N'; break; default:break;}

	while (true) {
		cout << "\tIngrese su distrito: "; cin.ignore();  getline(cin, usuarios[id_usuario].direccion.DISTRITO);
		if (verif_string(usuarios[id_usuario].direccion.DISTRITO)) { cout << "\t[!] Ingrese bien los datos!\n"; }
		else { break; }
	}
	cout << "\tIngrese su direccion: "; cin.ignore(); getline(cin, usuarios[id_usuario].direccion.DIRECCION);
	while (true) {
		cout << "\tIngrese CASA(1)/DEPARTAMENTO(2): ";  cin>> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { break; }
		else { cout << "\t[!]Ingrese un valor correcto!\n "; }
	}
	switch (stoi(ingreso_jugar))
	{case 1:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "CASA"; break; case 2:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "DEPARTAMENTO"; break; default:break;	}
	while (true) {
		cout << "\tIngrese su numero de celular (SIN PREFIJO): "; cin.ignore();getline(cin, usuarios[id_usuario].CELULAR);
		if (verif_telefono(usuarios[id_usuario].CELULAR) == false) { cout << "\t[!] Ingreso de forma erronea el numero telefnoico\n"; }
		else {  break; }

	}
}

/*FUNCION COMPLEMENTARIA RECIBIR RESPUESTA*/
extern bool respuesta_continuar() {
	char respuesta;
	estetica(20, '!');
	cout << "\tdesea hacer otra operacion?: Y/N " << endl;
	cin >> respuesta; respuesta=toupper(respuesta);
	if (respuesta == 'Y') { return true; }
	else { return false; }
}
/*_______________________________________*/
/*FUNCION COMPLEMENTARIA GENERAR CODIGO ALEATORIO*/
extern int codigo_aleatorio(int inicio, int fin) {
	int gen;
	srand(time(NULL));
    gen = inicio + rand()%(fin+1-inicio);
    return gen;
}
/*_______________________________________*/

