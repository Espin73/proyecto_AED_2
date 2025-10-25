#include <iostream>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
    int hora, minuto, segundo;

public:
    Fecha();
    bool leer();
    void escribir();
    void es_menor(Fecha &otra);
    void es_igual(Fecha &otra);
};
Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
    hora=0;
    minuto=0;
    segundo=0;
}

bool Fecha::leer(){

    char b1,b2;
    char p1,p2;
    char espacio;
    
    cin >> dia >> b1 >> mes >> b2 >> anio;
    cin.get(espacio); 
    cin >> hora >> p1 >> minuto >> p2 >> segundo;

    if( b1 != '/' || b2 != '/' || p1 != ':' || p2 != ':'){
        return false;
    }
    return true;
}

void Fecha::escribir(){

    cout << dia << "/" << mes << "/" << anio << " ";

    if(hora < 10){
        cout << "0" << hora;}
    else{cout << hora;}

    if(minuto<10){
        cout << "0" << minuto;}
    else{cout << minuto;}

    if(segundo<10){
        cout << "0" << segundo;}
    else{cout << segundo;}
}

bool Fecha::es_igual(Fecha &otro){

    return dia==otro.dia && mes==otro.mes && anio==otro.anio && hora==otro.hora && minuto==otro.minuto && segundo==otro.segundo;
}

bool Fecha::es_menor(Fecha &otro){
    
    if(anio < otro.anio){
        return true;
    }
    else if(anio == otro.anio){
        if(mes < otro.mes){
            return true;
        }
        else if(mes == otro.mes){
            if(dia < otro.dia){
                return true;
            }
            else if(dia == otro.dia){
                
                if(hora < otro.hora){
                    return true;
                }
                else if(hora == otro.hora){
                    if(minuto < otro.minuto){
                        return true;
                    }
                    else if(minuto == otro.minuto){
                        return segundo < otro.segundo;
                    }
                }
            }
        }
    }
    return false;
}
