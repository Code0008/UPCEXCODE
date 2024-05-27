#include<iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

void promedio(unsigned short * notas, unsigned short nalumnos){
    unsigned short prom=0, maxnota=0, minnota=0, moda=0;
    for (unsigned short i=0; i<nalumnos; i++){
        cout << "Ingrese notas: "; cin>>notas[i]; cout << endl;
        prom+=notas[i];
        if (notas[i]>maxnota){
            maxnota=notas[i];
        }else if (notas[i]<maxnota){
            minnota=notas[i];
        }else{continue;}

    }
    for (int j=1; j<nalumnos; j++){
        if(notas[j-1] == notas[j]){
            moda=notas[j-1];
        }
    }
    cout << "El promedio es: " << prom/nalumnos <<endl;16:03 19/05/202416:03 19/05/202416:03 19/05/202416:03 19/05/2024
    cout << "La minima nota es: " << minnota << endl;
    cout << "La maxima nota es: " << maxnota << endl;
    cout << "La moda es: " << moda<<endl;
}


int main(){
    unsigned short nalumnos=0;
    unsigned short * notas = new unsigned short[nalumnos];
    while (true){
        cout << "Ingrese el numero de alumnos "<< endl; cin>> nalumnos;
        if(nalumnos>0){break;}
    }
    promedio(notas, nalumnos);

}
----------------------------------
void calcular(unsigned short * notas, unsigned short nalumnos){
    unsigned short obtubieron_00=0, obtuvieron_20=0, jalados=0, aprobados=0;
    for(unsigned short i=0; i<nalumnos; i++){
        cout << "Ingrese nota del alumno [" << i << "] => "; cin>>notas[i]; cout<< endl;
        switch (notas[i]) {
            case 20: obtuvieron_20++;
            case 00: obtubieron_00++;
            default:
                if(notas[i]>=13){aprobados++;}
                if(notas[i]<13){jalados++;}
        }
    }
    cout << "Alumnos aprobados: " << aprobados << endl;
    cout << "Alumnos jalados: " << jalados<< endl;
    cout << "Inteligentes: " << obtuvieron_20 << endl;
    cout << "JALARON COMO REALES BURROS: " << obtubieron_00 << endl;
}


int main(){
    unsigned short nalumnos=0;
    cout << "Ingrese la cantidad de alumnos: " << endl; cin>> nalumnos;
    unsigned short * notas =  new unsigned short[nalumnos];
    calcular(notas, nalumnos);
}
-------------------------------------
void insertionSort(int * arr, int size) { //ALGORITMO DE ORDENAMIENTO TIPO SORT
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
    for(int x=0; x<size; x++){
        cout << arr[x];
    }
}
----------------------------------------


void ingresar_datos(int * compras, int nprovedores) {
	for (int i = 0; i < nprovedores; i++) {
		cin >> compras[i];
	}
}


void promedio_compras(int* compras, int nprovedores) {
	int prom=0;
	for (int i = 0; i < nprovedores; i++) {
		prom += compras[i];
	}
	cout << "El promedio es: " << prom / nprovedores << endl;
}

void mayor_compras(int* compras, int nprovedores) {
	int mayor = 0, menor = 0;
	for (int i = 0; i < nprovedores; i++) {
		if (compras[i] > mayor) {
			mayor = compras[i];
		}else if (compras[i] < mayor) {
			menor = compras[i];
		}
	}
}

void menor_compras(int* compras, int nprovedores) { 
	int menor = INT_MAX;
	for (int i = 0; i < nprovedores; i++) {
		if (menor > compras[i]) {
			menor = compras[i];
		}
	}
	cout << "El menor numero es: "<< menor << endl;
}


void ordenas_compras(int* compras, int nprovedores) {
	for (int i = 1; i < nprovedores; i++) {
		int key = compras[i];
		int j = i - 1;
		while (j >= 0 && compras[j] > key) {
			compras[j + 1] = compras[j];
			j = j - 1;
		}
		compras[j + 1] = key;
	}
	for (int x = 0; x < nprovedores; x++) {
	
		cout << "["<< compras[x] << "]";
	}
}

int main() {
	int nprovedores=4;
	int* compras = new int[nprovedores];
	ingresar_datos(compras, nprovedores);
	promedio_compras(compras, nprovedores);
	menor_compras(compras, nprovedores);
	ordenas_compras(compras, nprovedores);
}
----------------------------------------------------------------
#include <iostream>
#include <stdio.h>
#include "modulo_ralp.h"
#include <string>
#include <conio.h>
using namespace std;


struct direccion {
	string direccion;
	string distrito;
	string provincia;
};

int ntrabajadores, promedio = 0;
struct trabajador {
	string nombre;
	int edad;
	char sexo;
	direccion inforacion_direccion;
	int venta;
} trabajadores[100]; 



void registrar_trabajador() {
	for (int i = 0; i < ntrabajadores; i++) {
		cout << "Registrar Nombre: " << endl; getline(cin, trabajadores[i].nombre); cin.ignore(); 
		cout << "Registrar edad: " << endl; cin >> trabajadores[i].edad; cin.ignore();
		cout << "Registrar sexo: " << endl; cin >> trabajadores[i].sexo; cin.ignore();
		cout << "Registrar direccion: " << endl; getline(cin, trabajadores[i].inforacion_direccion.direccion);  cin.ignore();
		cout << "Registrar distrito: " << endl; getline(cin, trabajadores[i].inforacion_direccion.distrito); cin.ignore();
		cout << "Registrar provincia: " << endl; getline(cin, trabajadores[i].inforacion_direccion.provincia);  cin.ignore();
		cout << "Registrar venta: " << endl; cin >> trabajadores[i].venta; cin.ignore();
		promedio += trabajadores[i].venta;
	}
}

void venta_promedio() {
	cout << "El promedio: " << promedio / ntrabajadores << endl;
}

void venta_mayor() {
	int mayor = 0, indice=0;
	for (int i = 0; i < ntrabajadores; i++) {
		if (trabajadores[i].venta > mayor) {
			mayor = trabajadores[i].venta;
			indice = i;
		}
	}
	cout << "EL QUE TIENE LA MAYOR VENTA ES: " << trabajadores[indice].nombre; 
}

void venta_menor() {
	int menor = INT_MAX, indice = 0;
	for (int i = 0; i < ntrabajadores; i++) {
		if (trabajadores[i].venta < menor) {
			menor = trabajadores[i].venta;
			indice = i;
		}
	}
	cout << "EL QUE TIENE LA menor VENTA ES: " << trabajadores[indice].nombre;
}

void ordenar_edad() {
	int* edades = new int[ntrabajadores];

	for (int i = 0; i < ntrabajadores; i++) {
		edades[i] = trabajadores[i].edad;
	}

	int current = 0;
	int j;
	for (int i = 0; i < ntrabajadores; i++) {
		current = edades[i];
		j = i - 1;

		while (j >= 0 && edades[j] > current) {
			edades[j + 1] = edades[j];
			j -= 1;
		}

		edades[j + 1] = current;
	}

	for (int i = ntrabajadores-1; i > 0; i--) {
		cout << " [" << edades[i] << "] ";
	}
}

void mostrar_datos() {
	cout << endl;
	for (int i = 0; i < ntrabajadores; i++) {
		cout << "-----TRABAJADOR: "<<i+1<< "-----"<< endl;
		cout << "Nombre: "<< trabajadores[i].nombre << endl;
		cout << "Edad: " << trabajadores[i].edad << endl;
		cout << "Sexo: " << trabajadores[i].sexo << endl;
		cout << "Direccion: " << trabajadores[i].inforacion_direccion.direccion << endl;
		cout << "distrito: " << trabajadores[i].inforacion_direccion.distrito << endl;
		cout << "provincia: " << trabajadores[i].inforacion_direccion.provincia << endl;
		cout << "Venta: " << trabajadores[i].venta << endl;
	}
}


int main() {
	cout << "Ingrese el numero de trabajadores: "; cin >> ntrabajadores; cin.ignore(); cout << endl;
	registrar_trabajador();cout << endl;
	venta_promedio();cout << endl;
	venta_mayor();cout << endl;
	venta_menor(); cout << endl;
	ordenar_edad();cout << endl;
	mostrar_datos();
	return 0;
}
