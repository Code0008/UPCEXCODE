#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include "ESTRUCTURAS.h"
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
/*____________________________________*/
/*FUNCION DE ESTETICA DEL PROGRAMA*/
static void estetica(int tamaño=20, char caracter='_') {
	cout << "\t";
	for (int i = 0; i < tamaño; i++) {
		cout << caracter;
	}cout << endl;
}
/*____________________________________*/

/*FUNCION COMPLEMENTARIA CAPTURE TIME*/
extern string capture_time() {
	string tiempo_capturado;
	cout << endl;
	estetica(24, '*');
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
	int selection;
	usuarios[id_usuario].hora_operacion = capture_time();
	usuarios[id_usuario].userID = id_usuario;
	cout << "\tIngrese nombre del usuario: ";
	cin.ignore(); getline(cin, usuarios[id_usuario].NOMBRE_APELLIDO);
	cout << "\tIngrese edad del usuario: ";
	cin.ignore(); cin >> usuarios[id_usuario].EDAD;
	cout << "\tSeleccion de sexo Masculino(1)/Femenino(2)/Helicoptero apache(3): ";
	cin.ignore(); cin >> selection;
	switch (selection)
	{
	case 1: usuarios[id_usuario].SEXO = 'M'; break; case 2: usuarios[id_usuario].SEXO = 'F'; break; case 3: usuarios[id_usuario].SEXO = 'N'; break; default:break;
	}selection = 0;
	cout << "\tIngrese su distrito: "; cin.ignore(); getline(cin, usuarios[id_usuario].direccion.DISTRITO);
	cout << "\tIngrese su direccion: "; cin.ignore(); getline(cin, usuarios[id_usuario].direccion.DIRECCION);
	cout << "\tIngrese CASA(1)/DEPARTAMENTO(2): ";  cin >> selection;
	switch (selection)
	{
	case 1:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "CASA"; break; case 2:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "DEPARTAMENTO"; break; default:break;
	}
	cout << "\tIngrese su numero de celular (SIN PREFIJO): "; cin.ignore();
	getline(cin, usuarios[id_usuario].CELULAR);
}

/*_______________________________________*/
/*FUNCION COMPLEMENTARIA RECIBIR RESPUESTA*/
extern bool respuesta_continuar() {
	char respuesta;
	estetica(20, '!');
	cout << "\tdesea hacer otra operacion?: Y/N " << endl;
	cin >> respuesta; respuesta=toupper(respuesta);
	if (respuesta == 'Y') { return true; }
	else { return false; }
}

/*________________________________________*/
/*________________________________________*/

/*________________________________________*/
