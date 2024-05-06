Ejercicio1:
---------------
int main(){
double importe=0, importetoal=0,numero_clientes=0, count=0; char selec;
        cout << "Ingrese el numero total de clientes: "<< endl; cin>> numero_clientes;
        while (count!=numero_clientes) {
            count++;
            cout <<endl<< "Ingrese el impote: ";cin >> importe;
            cout << endl << "Porfavor elija un color de bolita R/A/B: ";cin >> selec;
            switch (toupper(selec)) {
                case 'R': importe= importe-(importe*0.40); importetoal=+importe; cout << "GANANCIAS POR EL MOMENTO: "<< importetoal<<endl; break;
                case 'A': importe= importe-(importe*0.25); importetoal=+importe; cout << "GANANCIAS POR EL MOMENTO: "<< importetoal<<endl; break;
                case 'B': cout<< "No se apliara ningun descuento"<<endl; break;
                default:
                    cout << "Ingrese datos correcto"<< endl;
            }
        }
        cout << "GANANCIAS: " << importetoal<<endl;
        cout <<"CLientes: "<< numero_clientes;
    retun 0
}
-----------------
ejercicio 2: revertir numero
    int e,p=0;
    cin>>e;
    while(e!=0){
        p= p*10 +e%10;
        e/=10;
    }
    cout << p;
---------------
#include <iostream>
using namespace std;

int oultursagan=0, cruzdelsurgan=0, lineagan=0, co=0, cc=0,cl=0, hotel30usd=0;

char get_transporte(){
    char transport;
    while (true) {
        cout << "Ingrese transporte (B) Buscama /(V) Vip " << endl;cin >> transport;
        if (transport == 'B' || transport == 'V' || transport=='F') {break;} else{cout <<" Ingrese dato correcto: "<< endl;}
    }
    return toupper(transport);
}

char get_empresa (){
    char empresasel;
    while (true){
        cout << "Ingrese la empresa O/C/L: " << endl; cin>>empresasel;
        toupper(empresasel);
        if (empresasel=='O' || empresasel=='C' || empresasel== 'L') {break;}
    }
    return toupper(empresasel);
}

char get_hotel(){
    char hotel;
    while (true){
        cout << "Ingrese su hotel Pinos/Emperador/Cañaveral: " << endl;cin >> hotel;
        toupper(hotel);
        if (hotel=='P'||hotel=='E'||hotel=='C') {break;}
    }
    return toupper(hotel);
}

int main(){

    char transporte, empresa,hotel;int dias_viaje=0, precio=0;;
    while (true) {
        transporte = get_transporte();
        if (transporte=='F'){break;}
        empresa = get_empresa();
        hotel = get_hotel();
        do{
        cout << "Ingrese dias de viaje: " << endl;cin >> dias_viaje;
        } while (dias_viaje<=3);
       switch (empresa){
           case 'O': co++; if(transporte=='B'){ precio=150; oultursagan+=precio;}else if(transporte=='V'){precio=230;oultursagan+=precio;}
               break;
           case 'C':cc++; if(transporte=='B'){ precio=200; cruzdelsurgan+=precio;}else if (transporte=='V'){precio=300; cruzdelsurgan+=precio;}
               break;
           case 'L':cl++; if(transporte=='B'){ precio=100; lineagan+precio;}
               break;
       }
       if(hotel=='E'||hotel=='C') {hotel30usd++;}
    }
    int ganmax=0;
    cout << "Ganancias oultura: " << oultursagan << endl;
    cout << "Cantos usaron oulrsa: " << co<< endl;
    cout << "Ganancias Cruz del sur: "<< cruzdelsurgan << endl;
    cout << "Cantos usaron cruz del sur: " << cc<< endl;
    cout << "Ganancias Linea: " << lineagan<<endl;
    cout << "Cantos usaron linea:" << cl<< endl;
    ganmax=max(lineagan, max(oultursagan, cruzdelsurgan));
    cout << "La que mas ganacias tuvo: "<<endl;
    if (ganmax==lineagan){ cout << "LINEA"; } 
    if (ganmax==oultursagan) {cout << "OULTURSA";}
    if (ganmax==cruzdelsurgan) {cout<< "CRUZ DEL SUR";}
}

----------------------
#include <iostream>

using namespace std;

unsigned short origenN=0, origenI=0, emerE=0,emerS=0,emerR=0, horamadru=0, horamañana=0,horatarde=0,horanoche=0;
char tipo_emergencia(){
    char tipo_emer;
    while(true){
        cout <<"ingrese el tipo de emergencia E/S/R: " << endl; cin>> tipo_emer;tipo_emer=toupper(tipo_emer);
        if (tipo_emer=='E'|| tipo_emer=='S' ||tipo_emer=='R' || tipo_emer=='F'){break;}
    }
    return tipo_emer;
}

unsigned  short hora_ocurrida(){
    unsigned short hora;
    while (true){
        cout << "Ingrese la hora que ocurrio: " << endl; cin>> hora;
        if (hora>=0 && hora<=23) {break;}
    }
    return hora;
}

char tipo_origen(){
    char origen;
    while (true){
        cout << "Ingrese el origen N/I: " << endl; cin>>origen;origen=toupper(origen);

        if (origen=='N' || origen=='I') {break;}
    }
    return origen;
}


int main(){
    unsigned short hora, maxemer; char tipoemer, origen;
    while (true) {
        tipoemer = tipo_emergencia(); if (tipoemer=='F') {break;}
        switch (tipoemer) {
            case 'E':emerE++;break;
            case 'S':emerS++;break;
            case 'R':emerR++;break;default:break;
        }
        hora = hora_ocurrida();
        hora <= 5 && hora >= 0 ?  horamadru++ : hora <= 12 && hora >= 6 ? horamañana++ : hora >= 13 &&hora <= 17? horatarde++: horanoche++;
        origen = tipo_origen();
        switch (origen) {
            case 'N':origenN++;break;
            case 'I':origenI++;break;
            default:break;
        }
    }
    cout<< "Emergencia ecologica: " << emerE << endl<< "Emer sanitaria: " << emerS<< endl<< "Emergencia radioactiva: "
    << emerR << endl; maxemer= max(horamadru,max(horamañana, max(horatarde, horanoche)));
    if (maxemer==horamadru){ cout << "madrugada";}if (maxemer==horamañana){cout << "hora mañana";}
    if (maxemer==horanoche){cout << "hora noche";}if (maxemer==horatarde){cout << "Hora tarde";}
    return 0;
}
-------------------------------------------
ejercicio 1
int main() {
    char codigo[6], digito;
    int codigoi=0;
    unsigned  short  ufv=0,upc=0,ucato=0,ulima=0,uch=0, unsm=0;
    while (true) {
        cout <<endl<< "Ingrese el codigo: " << endl;
        cin >> codigo;
        codigoi = atoi(codigo);
        if (codigoi> 100000 && codigoi < 999999) { digito = codigo[0];
            if (digito == '1' || digito == '2') { cout << "UPCEX"; upc++; }
            else if (digito == '3' || digito == '4') { cout << "CATITO"; ucato++;}
            else{ switch (digito) {
                case '5':cout << "UNMSM"; unsm++;break;
                    case '6':cout << "UNFV";ufv++;break;
                    case '7':cout << "ULIMA";ulima++;break;
                    case '8':cout << "UCH";uch++;break;
                    default:cout << "Ninguna universidad";break;
                }
            }
        }else{ continue;}
        cout <<endl<< "Desea continuar?: S/N ";cin>>digito;
        if (toupper(digito)=='N') {break;}else{ continue;}
    }
    cout << "narcos: " << unsm<< endl<< "upcex: " << upc<<endl<<"CATO "<< ucato<< endl<< "ulima: "<< ulima<<endl<< "uch: "<< uch<< endl << "unfv: "<< ufv;
}
-----------------------------------
ejercicio 2
int main() {
    char categoria; short edad=0, precio=0, preciofin=0;
    while (true){
        cout << "Ingrese la edad del asistente: " << endl; cin>> edad; if (edad<0){break;}
        cout << "Ingrese el precio de asciento: " << endl; cin>>precio;
        edad>=5 && edad<=14 ? categoria=1 : edad>=15 && edad<=19 ? categoria=2 : edad>=20 && edad<=45 ?
                categoria=3 : edad>=46 && edad<=65 ? categoria=4 : categoria=5;
        switch (categoria) {
            case 1: preciofin+= precio-(precio*0.35);break;
            case 2: preciofin+= precio-(precio*0.25); break;
            case 3: preciofin+= precio-(precio*0.10); break;
            case 4: preciofin+= precio-(precio*0.25); break;
            case 5: preciofin+= precio-(precio*0.35); break;
        }
    }
    cout <<"Ganancias: " << preciofin;
}
-------------------------------
ejercicio 6
-------------------------------
int Factorial(int numero)
{
    int producto = 1;

    if (numero == 0)
        producto = 1; //0! = 1
    else
    {
        for (int i = numero; i > 0; i--)
        {
            producto = i * producto;
        }
    }

    return producto;
}

int main(){
    float a; int exponente; float resultado=0;
    cin>>a;//a;
    cin>>exponente;//k;
    for(int count=1; count<=exponente; count++){
        resultado+= pow(a, count) / Factorial(count);
    }
    cout << "Resultado: " << 1+resultado;

}
------------------------------------------------
ejercicio 4
-----------------------------------------------

int main(){

    int numero, suma=0;
    cin>> numero;
    for (int count =1 ; count<numero; count++){
            if (numero%count==0){suma+=count;}
    }
    if (suma==numero) {cout <<"Es perfecto";} else{cout <<"No es perfecto";}


    return 0;
}

------------------------------------------------------
int main() {

    int numero = 10, countrev=0;
    cout << numero << endl;
    for (int count = 1; count < numero; count++) {
        cout << numero;
        for (int count2 = -1; count2 < count; count2++) {
            cout << " ";
        }
        cout << numero - count << endl;
    }
    for(int count3=1; count3<numero; count3++){
        cout << numero;
        for (int count4=numero;   count4>count3 ; count4-- ){
            cout << " ";
        }
        cout <<<< endl;
    }
    cout << numero;

}


10
10  9
10   8
10    7
10     6
10      5
10       4
10        3
10         2
10          1
10         -9
10        -8
10       -7
10      -6
10     -5
10    -4
10   -3
10  -2
10 -1
10



_______________________
