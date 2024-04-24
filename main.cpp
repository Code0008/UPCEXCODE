#include <iostream>
#include <ctime>
#include <string>

using namespace std;

string capture_time(int newtime){  // esta funcion nos devolvera el tipo de dato string mejor dicho una cadena de texto
    time_t ahora = time(0); // En esta parte del codigo con la libreria ctime usamos su metodo time_t y en la varibale ahora guardamos la funcion time(0) capturando el timesawp
    ahora+=newtime; // aca sumamos el valor de timesawp el nuevo valor a calcular para hallar el tiempo
    string x=ctime(&ahora); // asignamos a la variable x el texto de timeswap que pasamos la direccion de mememoria de la variable ahora pasandola y convirtiendo ese valor en texto
    return x; //devolvemos la variable x
}
void boleta_entrega(string username, string dni, string autor_del_libro, int fechas){ // lo que recibieremos sera el nombre_de_usuario, su documento de identidad, el autor del libro y pasaremos tambien la cantidad de segundos del tiempo que el usuario tomara prestado el libro
    cout << "Usuario: " << username<< endl;
    cout << "DNI: " << dni << endl;
    cout << "Autor: " << autor_del_libro  << endl;
    if (fechas>0){ //Aca podemos hacer la diferencia entre el tiempo que tomara prestado y tiempo que tomo prestado
        cout << "Fecha de pedido " << capture_time(0);
        cout << "Fecha de entrega: " << capture_time(fechas*604800); // si cumple la condicion del if al valor almacenado en fechas se le multiplicara por la cantidad de segundos de una semana para hallar el tiempo que prestara
    }else{ // si no se cumple la condicion entrara a el else
    cout << "Fecha de entrega del pedido: " << capture_time(0)<< endl; // llamamos la funcion con el numero 0 para calulcar la fecha actual que se devuelve el prodcuto
    cout << "Fecha que pediste el libro: " << capture_time(604800*fechas); // aca calculamos hace cuantas semanas pidio el libro
    }
}

int main(){
    string nombre_de_usuario, documento_de_identidad, titulo_del_libro, direccion_de_contacto,
    numero_de_contacto; // las variables string almacenaran datos en texto ya que no trataremos con ellos a la hora de trabajar la logica del programa
    unsigned short eleccion, semanas; // el unsigned short con esto declaramos que las variables eleccion y semanas no puedan recibir valores menores a 0

    cout << "[+] Ingrese nombre de usuario: "<<endl; getline(cin,nombre_de_usuario);
    cout << "[+] Ingrese su documento de identidad: "<<endl; getline(cin,documento_de_identidad);
    cout << "[+] Ingrese su direccion de contacto" << endl; getline(cin,direccion_de_contacto);
    cout << "[+] Ingrese su numero de contacto: " << endl; getline(cin,numero_de_contacto);
    cout << endl <<"[!] ingrese su seleccion \n[1] para prestar libros\n[2] Para devolver libros"<<endl;cin >> eleccion;
    switch (eleccion) {
        case 1:
            cout << "[!!!] cuantas semanas tomara prestado el libro (limite 3):";cin>>semanas;
            if(semanas>3 || semanas<0){ cout << "Numero superior al limite o incorrecto saliendo del proceso..."
            << endl; break;}
            else{cout << "Ingrese que libro retirara: "; getline(cin, titulo_del_libro);
            boleta_entrega(nombre_de_usuario, documento_de_identidad, titulo_del_libro,
                           semanas);break;}
        case 2:
            cout << "Ingrese el libro que devolvera  : "; getline(cin, titulo_del_libro);
            cout << "Ingrse hace cuantas semanas pidio el libro: ";cin>>semanas;
            if (semanas<=3){boleta_entrega(nombre_de_usuario, documento_de_identidad,
                                           titulo_del_libro,-semanas);}
            else{
                cout << "USTED SE DEMORO{" << semanas-2 <<"} DE MAS PARA ENTREGAR EL LIBRO SE LE PONDRA UNA SANSCION: "
                << endl;boleta_entrega(nombre_de_usuario, documento_de_identidad,
                                       titulo_del_libro,-semanas);
                cout << "La sancion es de 10 soles por semana que no entrego: " << 10*(semanas-2) << endl;
            }break;
        default:
            cout << "Valor incorrecto ingrsado: " << endl; break;
    }
}
