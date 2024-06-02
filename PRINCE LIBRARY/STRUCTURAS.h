#include <stdio.h>
#include <conio.h>

using namespace std;



struct direccion_usuario {
	string DIRECCION;
	string DISTRITO;
	string PROVINCIA;
	string CASA_DEPARTAMENTO;
};

struct USUARIO {
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