#pragma once

#include <iostream>
#include <string>
#include <ctype.h>


static bool verificar_string(string texto) {
	for (int i = 0; i < texto.length(); i++) {
		if (isdigit(texto[i])) { return true; }
	} 
}


void test_string() {
	string nombre;
	while (true) {
		cout << "ingresew nombre: " << endl;
		cin.ignore(); getline(cin, nombre);
		if (verificar_string(nombre) == true) {
			cout << "Ingrese bien el dato: " << endl;
		}else { break; }
	}
}




using namespace std;

string verif_date(string date_string) {
    bool verife = false;
    string year = "";
    string moth = "";
    string day = "";
    int end_days[] = { 31, 29, 31, 30, 31, 30 };

    for (int i = 0; i < date_string.length(); i++) {
        if (date_string[i] == '-') {
            i += 1;
        }
        if (i < 4) {
            if (isdigit(date_string[i])) {
                year += date_string[i];
            }
            else {
                break;
            }
        }
        if (i < 7 && i >= 5) {

            if (isdigit(date_string[i])) {
                moth += date_string[i];
            }
            else {
                break;
            }
        }
        if (i >= 8 && i <= 9) {
            if (isdigit(date_string[i])) {
                day += date_string[i];
            }
            else {
                break;
            }
        }
    }
    string fecha_real;
    string current = "";
    for (int i = 0; i < moth.length(); i++) {
        if (moth[i] != '0') {
            current += moth[i];
        }
    }

    fecha_real += year;
    fecha_real += current;
    fecha_real += day;
    return fecha_real;
}

int main() {
    string fecha_actua;
    //  0123456789
    string date_string = "2024-06-5";
    time_t timepo;
    tm timestamp;
    time(&timepo);
    localtime_s(&timestamp, &timepo);
    fecha_actua += to_string(timestamp.tm_year + 1900);
    fecha_actua += to_string(timestamp.tm_mon + 1);
    fecha_actua += to_string(timestamp.tm_mday);

    string x = verif_date(date_string);
    if (fecha_actua == x) {
        cout << "Misma fecha";
    }
    else { cout << "pene"; }
}



