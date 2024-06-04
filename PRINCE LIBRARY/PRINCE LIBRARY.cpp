
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include "INFO_DE_MENUS.h"
#include "FUNCIONALIDADES.h"
//#include "TESTS.h"
#include "COLORAMA.h"
using namespace std;
int main() {
	RESET;
	int contador_usuario = 0;
	int seleccion = 0;
	while (true) {
		menu_login();
		cout << "\t"; estetica(30, '*');
		cout << "\t\t\t" << capture_time() << endl;
		cout << "\t"; estetica(30, '*');
		obtener_informacion_usuario(contador_usuario);
		contador_usuario++;
		system("cls");

		menu_principal();
		while (true) {
			seleccion = 0;
			cout << "[+] INGRESE SELECCION: ";
			cin >> seleccion;
			if (seleccion == 1 || seleccion == 2 || seleccion == 3) { break; }
			else { cout << "\t[!]Ingrese una seleccion valida\n";   continue; }
		}
		switch (seleccion)
		{
		case 1:
			system("cls");
			menu_prestamo();
			break;
		default:
			break;
		}

		if (respuesta_continuar() != true) { break; }

		cin.ignore();
	}
	see_data(2);
	RESET;

}

