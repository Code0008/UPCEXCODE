#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "STRUCTURAS.h"
#include "COLORAMA.h"
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
	if (telefono.length() <10 && telefono.length()>1) {
		bool verif=false;
		for (int i = 0; i < 9; i++) {
			if (isdigit(telefono[i])) { verif = true; }
			if (isdigit(telefono[i]) == false || telefono[i] == '+') { return false; }
		}
		return verif;
	}
	else { return false; }
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
		cout << LGREEN <<"\t[+]Ingrese nombre del usuario: "<<RESET; getline(cin, usuarios[id_usuario].NOMBRE_APELLIDO);
		if (verif_string(usuarios[id_usuario].NOMBRE_APELLIDO)) { cout <<RED<<"\t[!]"<<RESET <<ORANGE<<"INGRESE BIEN EL NOMBRE\n"<<RESET;}else {break; }
	}
	while (true){
		cout << LGREEN<<"\t[+]Ingrese edad del usuario: "<<RESET;  cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { usuarios[id_usuario].EDAD = stoi(ingreso_jugar); break; }
		else { cout << RED <<"\t[!]"<<RESET <<ORANGE<<" Ingrese bien su edad!\n"<<RESET; } 
	}
	while (true) {
		cout<< LGREEN << "\t[+]Seleccion de sexo:\n\t->(1)Masculino\n\t->(2)Femenino\n\t->(3)Helicoptero apache\n--> "<< RESET; cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) { break; }
		else { cout << RED <<"\t[!]" << RESET<< ORANGE <<"Ingrese un valor correcto!\n "<< RESET; }
	}
	switch (stoi(ingreso_jugar))
	{case 1: usuarios[id_usuario].SEXO = 'M'; break; case 2: usuarios[id_usuario].SEXO = 'F'; break; case 3: usuarios[id_usuario].SEXO = 'N'; break; default:break;}
	while (true) {
		cout << LGREEN<<"\t[+]Ingrese su distrito: "<<RESET; cin.ignore();  getline(cin, usuarios[id_usuario].direccion.DISTRITO);
		if (verif_string(usuarios[id_usuario].direccion.DISTRITO)) { cout << RED<<"\t[!]" << RESET<<ORANGE <<"Ingrese bien los datos!\n"<< RESET; }
		else { break; }
	}
	cout << LGREEN<<"\t[+]Ingrese su direccion: "<< RESET;  getline(cin, usuarios[id_usuario].direccion.DIRECCION);
	while (true) {
		cout << LGREEN<<"\t[+]Seleccione:\n\t-->(1)Casa\n\t-->(2)Departamento\n "<<RESET;cin >> ingreso_jugar;
		if (verif_entero(ingreso_jugar)) {if(stoi(ingreso_jugar)<3 && stoi(ingreso_jugar)>0) break; }
		else { cout << RED<<"\t[!]" << RESET<< ORANGE<<"Ingrese un valor correcto!\n "<< RESET; }
	}
	switch (stoi(ingreso_jugar))
	{case 1:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "CASA"; break; case 2:  usuarios[id_usuario].direccion.CASA_DEPARTAMENTO = "DEPARTAMENTO"; break; default:break;	}
	while (true) {
		cout << LGREEN << "\t[+]Ingrese su numero de celular (SIN PREFIJO): " << RESET; cin.ignore();  cin>> ingreso_jugar;
		if (verif_telefono(ingreso_jugar) == false) { ingreso_jugar = " "; cout << RED << "\t[!]" << RESET << ORANGE << " Ingreso de forma erronea el numero telefnoico\n" << RESET; }
		else { usuarios[id_usuario].CELULAR=ingreso_jugar; break; }
	}
}

/*FUNCION COMPLEMENTARIA RECIBIR RESPUESTA*/
extern bool respuesta_continuar() {
	char respuesta;
	cout << endl;
	cout << RED; estetica(20, '!'); cout  << RESET;
	cout << LBLUE<<"\t[!]desea hacer otra operacion?:<<"<<RESET << RED" Y/N " << RESET<< endl;
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

extern void see_data(int contador) {
	for (int i = 0; i < contador; i++) {
		cout << "\t" << usuarios[i].userID << endl;
		cout << "\t" << usuarios[i].DNI << endl;
		cout << "\t" << usuarios[i].NOMBRE_APELLIDO<< endl;
		cout << "\t" << usuarios[i].EDAD<< endl;
		cout << "\t" << usuarios[i].SEXO<< endl;
		cout << "\t" << usuarios[i].direccion.CASA_DEPARTAMENTO << endl;
		cout << "\t" << usuarios[i].direccion.DIRECCION<< endl;
		cout << "\t" << usuarios[i].direccion.DISTRITO<< endl;
		cout << "\t" << usuarios[i].direccion.PROVINCIA << endl;
		cout << "\t" << usuarios[i].CELULAR<< endl;
		cout << "\t" << usuarios[i].hora_operacion << endl;
	}
}
