
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "INFO_DE_MENUS.h"
#include "FUNCIONALIDADES.h"
#include <string>
//#include "TESTS.h"
#include "COLORAMA.h"
using namespace std;
int main() {
	RESET;
	int  id_usuario = 0;
	string seleccion;
	menu_login();
	obtener_informacion_usuario(id_usuario);
	id_usuario++;
	while (true) {
		system("cls");
		menu_principal(); cin.ignore();
		while (true) {
			cout << "[+] INGRESE SELECCION: ";
			getline(cin, seleccion);
			if (verif_entero(seleccion)) { if (stoi(seleccion) == 1 || stoi(seleccion) == 2 || stoi(seleccion) == 3) { break; } else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese una opcion valida!\n" << RESET; continue; } }
			else { cout << RED << "\t[!]" << RESET << ORANGE << "Ingrese una opcion valida!\n" << RESET; }
		}
		switch (stoi(seleccion))
		{
		case 1:
			system("cls");
			menu_prestamo();
			generar_matris();
			obtener_informacion_prestamo();
			boleta_prestamo();
			break;
		default:
			break;
		}

		if (respuesta_continuar() != true) { break; }

	}
	system("cls");
	RESET;

}
