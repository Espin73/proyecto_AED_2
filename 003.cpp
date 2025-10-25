#include <iostream>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
    int hora, mes, segundo;

public:
    Fecha();
    bool leer();
    void escribir();
    void es_menor(Fecha &otra);
    void es_igual(Fecha &otra);

Fecha:Fecha(){
    dia=0;
    mes=0;
    anio=0;
    hora=0;
    minuto=0;
    segundo=0;
}

void Fecha:leer(){

    char b1,b2;
    char p1,p2;

    cin >> dia >> b1 >> mes >> b2 >> anio;
    cin >> hora >> p1 >> segundo; 

}

void Fecha:escribir(){

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
