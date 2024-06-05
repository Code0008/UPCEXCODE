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

#include <stdio.h>
#include <conio.h>

using namespace std;


struct LIBRO {
	int codigo_libro;
	string tipo_libro;
	string titutlo_libro;
};

struct direccion_usuario {
	string DIRECCION="void";
	string DISTRITO="void";
	string PROVINCIA="LIMA";
	string CASA_DEPARTAMENTO="void";
};

struct USUARIO {
	int userID=0;
	string DNI="void";
	string NOMBRE_APELLIDO;
	int EDAD;
	char SEXO;
	direccion_usuario direccion;
	string CELULAR="void";
	string hora_operacion="void";
	string correo="void";
	int cantidad_libros_prestado=0;
	int cantidad_libros_devueltos=0;
	LIBRO* libros_retirados = new LIBRO[100];
	LIBRO* libros_devueltos = new LIBRO[100];
};

