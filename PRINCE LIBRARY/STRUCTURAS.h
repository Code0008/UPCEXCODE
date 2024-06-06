
#include <stdio.h>
#include <conio.h>

using namespace std;


struct LIBRO {
	int codigo_libro;
	string tipo_libro;
	string titutlo_libro;
};

struct direccion_usuario {
	string DIRECCION = "void";
	string DISTRITO = "void";
	string PROVINCIA = "LIMA";
	string CASA_DEPARTAMENTO = "void";
};

struct USUARIO {
	int userID = 0;
	string DNI = "void";
	string NOMBRE_APELLIDO;
	int EDAD;
	char SEXO;
	direccion_usuario direccion;
	string CELULAR = "void";
	string hora_operacion = "void";
	string correo = "void";
	string** libros_tratados = new string*[100];

	/*
		| codigo | hora_tratado | operacion que se realizo(P/D) | Verificador_coompleto_operacion |
		1 fila  3 columnas

	*/
};
