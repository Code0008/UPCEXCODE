// PROPUESTA 008 PARA SISSOFT-UPC
// 02/06/2024 18:00 INCIO
// 03/06/2024 19:10 ACTUALIZANDO

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include "INFO_DE_MENUS.h"
#include "FUNCIONALIDADES.h"
//#include "TESTS.h"
using namespace std;
int main() {
	while (true) {
		int contador_usuario = 0;
		menu_login();
		cout << "\t"; estetica(30, '*');
		cout << "\t\t\t" << capture_time() << endl;
		cout << "\t"; estetica(30, '*');
		obtener_informacion_usuario(contador_usuario);
		if (respuesta_continuar() != true) { break; }
	}

}
