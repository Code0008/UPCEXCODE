
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "INFO_DE_MENUS.h"
#include "FUNCIONALIDADES.h"
#include "funcionalidades_prestamo.h"
#include "funcionalidades_devolucion.h"
#include <string>
//#include "TESTS.h"
#include "COLORAMA.h"
using namespace std;
int main() {
	RESET;
	int  id_usuario = 0;
	string seleccion;
	menu_login();
	switch (select())
	{
	default:
		break;
	}
	obtener_informacion_usuario(id_usuario);
	generar_matris();
	while (true) {
		system("cls");
		menu_principal(); cin.ignore(); cout << endl;
		while (true) {
			cout << "[+] INGRESE SELECCION: ";
			getline(cin, seleccion);
			if (verif_entero(seleccion)) { if (stoi(seleccion) == 1 || stoi(seleccion) == 2 || stoi(seleccion) == 3) { break; } else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese una opcion valida!\n" << RESET; continue; } }
			else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese una opcion valida!\n" << RESET; }
		}
		switch (stoi(seleccion))
		{
		case 1:
			if (verif_sancion()) {
				menu_de_sancion();
				break;
			}
			system("cls");
			menu_prestamo();
			obtener_informacion_prestamo(id_usuario);
			boleta_prestamo();
			break;
		case 2:
			menu_devulocion();
			obtener_informacion_devolucion();
			boleta_devolucion();
			break;
		default:
			break;
		}
		if (respuesta_continuar() != true) { break; }
	}
	system("cls");
	RESET;

	return 0;
}

// CODIGO PENDEJO DE PENDEJOS ECHO PARA PENDEJOS
