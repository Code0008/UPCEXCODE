// PROPUESTA 008 PARA SISSOFT-UPC
// 01/06/2024 15:42 COMENZANDO PROYECTO

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;



struct direccion_usuario {
	string DIRECCION;
	string DISTRITO;
	string PROVINCIA;
	string CASA_DEPARTAMENTO;
};

struct USUARIO{
	string DNI;
	string nombre_apellido;
	int EDAD;
	char SEXO;	
	direccion_usuario direccion;
	string celular;
};


struct LIBRO {
	int codigo_libro;
	string tipo_libro;
	string titutlo_libro;
};



void capture_time() {
	tm tiempo;
	time_t timestap;
	time(&timestap);
	localtime_s(&tiempo, &timestap);
	cout << tiempo.tm_year+1900;
	cout <<"/"<< tiempo.tm_mon;
	cout << "/" << tiempo.tm_mday+5;		
}




int main() {
	//capture_time();

}