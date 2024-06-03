#include <stdio.h>
#include <conio.h>

using namespace std;



struct direccion_usuario {
	string DIRECCION;
	string DISTRITO;
	string PROVINCIA="LIMA";
	string CASA_DEPARTAMENTO;
};

struct USUARIO {
	int userID;
	string DNI;
	string NOMBRE_APELLIDO;
	int EDAD;
	char SEXO;
	direccion_usuario direccion;
	string CELULAR;
	string hora_operacion;
};


struct LIBRO {
	int codigo_libro;
	string tipo_libro;
	string titutlo_libro;
};

