#include <iostream>

using namespace  std;

char selec_zona(){
    char zona;
    while(true){
        cout << "[+] Ingrese la zona V/P/O: " << endl; cin>>zona; zona= toupper(zona);
        if (zona=='V'|| zona=='P'|| zona=='O') { break;} else{continue;}
    } return zona;
}

char tipo_pago(){
    char cont_cred;
    while(true){
        cout << "[+] Ingrese el tipo de pago C/T: " << endl; cin>>cont_cred; cont_cred= toupper(cont_cred);
        if(cont_cred=='C' || cont_cred=='T'){break;} else{ continue;}
    } return cont_cred;
}

char bancos(){
    char tipo_bancos;
    while (true) {
        cout << "[+] Ingrese el tipo de banco que usara: "<< endl;cin >> tipo_bancos;tipo_bancos = toupper(tipo_bancos);
        if(tipo_bancos == 'C' || tipo_bancos=='N' || tipo_bancos=='O') {break;} else{ continue;}
    } return  tipo_bancos;
 }

 bool verif(unsigned short mes, unsigned short dia){
    if ((mes*30)-dia<285) {return true;} else{return false;}
}

int main(){
    char zona, tipo_pagoc, banco; unsigned short precio, mes,dia;

    while (true) {
        zona = selec_zona();
        tipo_pagoc = tipo_pago();
        if(tipo_pagoc == 'C'){switch (zona) {case 'V': precio=1500; break;case 'P': precio=750; break;case 'O': precio=265; break;}}
        else{
            banco=bancos();
            switch (zona) {
                case 'V':
                    switch (banco) {
                        case 'C':precio=2000; break;case 'N':precio=1900; break;case 'O':precio=2100; break;
                        default: break;}break;
                case 'P': switch (banco) {
                    case 'C':precio=750; break;case 'N':precio=875; break;case 'O':precio=1020; break;
                        default: break;}break;
                case 'O':  switch (banco) {
                        case 'C':precio=320; break;case 'N':precio=300; break;case 'O':precio=335; break;
                        default: break;}break;
                default:break;
            }
        }
        do{
            cout << "Ingrese el mes que compro: " << endl;cin>> mes;
            cout << "Ingrese el dia que compro: " << endl; cin>>dia; if (dia>0 && dia<30 && mes>0 && mes<=10){break;}
        }while(true);
        if(verif(mes, dia)){cout << "Precio de la entrada: "<< precio-(precio*0.10)<<endl;} else{cout << "Precio de la entrada: "<< precio<< endl;}
    }
}
-----------------------
Ejercicio 2
-----------------------
#include <iostream>

using namespace std;
unsigned short ca=0, cp=0, cadm=0,sp=0, sa=0,sd=0,cmadru=0,cmañan=0, ctarde=0, cnoche=0;

char tipo_usuario(){
    char usuario;
    while(true){
        cout << "[+] Ingrese el tipo de usuariio P/A/D: " << endl; cin>>usuario; usuario=toupper(usuario);
        if(usuario=='P' || usuario=='A' || usuario=='D'|| usuario=='X'){break;} else{continue;}
    } return usuario;
}

char servicio(){
    char servicio_t;
    while (true){
        cout << "[+] Ingrese el tipo de servicio P/A/D: " << endl; cin>>servicio_t; servicio_t= toupper(servicio_t);
        if(servicio_t=='P' || servicio_t=='A'|| servicio_t=='D'){break;} else{ continue;}
    } return servicio_t;
}

int main(){
    char usuario, tipo_servicio;string ingreso;  unsigned short hora, max_accesos, max_predonima;
    while(true){
        usuario= tipo_usuario();
        if (usuario=='X'){break;}
        while(true){cout << "[+] Ingrese la hora de acceso: " << endl; cin>>hora;if(hora>0 && hora<=23){break;}}
        hora>0 && hora<=5 ? ingreso="madrugada" : hora>=6 && hora<=12 ? ingreso="mañana": hora>=13 && hora<=17 ?
                            ingreso="tarde": hora>=18 && hora<=23 ? ingreso="noche" : ingreso="noche";
        if(ingreso=="madrugada: "){cmadru++;}if(ingreso=="mañana"){cmañan++;}if(ingreso=="tarde"){ctarde++;}
        if(ingreso=="noche"){cnoche++;}
        tipo_servicio=servicio();
        switch (usuario) {case 'P': cp++; break;case 'A': ca++;break;case 'D': cadm++; break; default:break;}
        switch (tipo_servicio) {case 'P': sp++; break;case 'A': sa++; break;case 'D': sd++;break; default:break;}
    }
    cout << "Profesores: " << cp<<endl;
    cout << "Alumnos: "<< ca<<endl;
    cout << "Administrativos: " << cadm<<endl;
    cout << "SE TUVIERON MAS ACCESOS ";
    max_predonima=max(cmadru, max(cmañan, max(ctarde, cnoche)));
    if (max_predonima==cmadru){cout<< "madrugada";} if(max_predonima==cmañan){cout << "mañana";} if(max_predonima==ctarde){cout << "tarde";}
    if(max_predonima==cnoche){cout << "noche";}
    max_accesos= max(cp, max(ca, cadm));
    cout <<endl<< "PREDOMINAN LOS SERVICIOS DE: " << endl;
    if(max_accesos==cp){cout << "Personal";} if(max_accesos==ca){cout << "Academico";} if (max_accesos==cadm){cout << "ADM";}
}

