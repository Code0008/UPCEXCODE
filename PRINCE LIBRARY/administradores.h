#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "STRUCTURAS.h"
#include "COLORAMA.h"
#include "FUNCIONALIDADES.h"
#include <string>
#include <cctype>


static string verif_password(string password) {
    char* caracteres = new char[26];
    char* caracteres_dos = new char[26];
    int caracter_inicio = 65;
    int caracter_dos = 97;

    for (int i = 0; i < 26; i++) {
        caracteres[i] = caracter_inicio;
        caracter_inicio++;
    }
    for (int i = 0; i < 26; i++) {
        caracteres_dos[i] = caracter_dos;
        caracter_dos++;
    }

    cout << "ORIGINAL" << password << endl;
    string new_pasword;
    for (int i = 0; i < password.length(); i++) {
        if (!isalpha(password[i])) {
            return false;
        }
        char caracter_encriptado;
        for (int j = 0; j < 25; j++) {
            if (password[i] == caracteres[j]) {
                caracter_encriptado = caracteres[(j + 5) % 26];
                break;
            }
            else if (password[i] == caracteres_dos[j]) {
                caracter_encriptado = caracteres_dos[(j + 5) % 26];
                break;
            }
        }
        new_pasword += caracter_encriptado;
    }

    return new_pasword;
}




ADMINISTRADOR administradores[2] = {
	{"EnzoFavito", "MtqfRzsit", capture_time(), "enzofavito@biblio.com", true, true},
	{"RalphSito", "Xmfnijq", capture_time(), "ralphxshaiel@teamoshaiel.com", true, false}
};


