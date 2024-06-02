// PROPUESTA 008 PARA SISSOFT-UPC
// 01/06/2024 22:08 INCIO
// 02/06/2024 00:16 ACTUALIZANDO

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
		int contador_usuario=0;
		menu_principal();
		cout << "\t" << capture_time();
		obtener_informacion_usuario(contador_usuario);
		if (respuesta_continuar() != true) { break;}
	}

}
