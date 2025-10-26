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
    bool es_menor(Fecha &otra);
    bool es_igual(Fecha &otra);
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
    
    if(hora < 10) cout << '0' << hora;
    else cout << hora;
    cout << ':';

    if(minuto < 10) cout << '0' << minuto;
    else cout << minuto;
    cout << ':';

    if(segundo < 10) cout << '0' << segundo;
    else cout << segundo;
}

bool Fecha::es_igual(Fecha &otra){

    return dia==otra.dia && mes==otra.mes && anio==otra.anio && hora==otra.hora && minuto==otra.minuto && segundo==otra.segundo;
}

bool Fecha::es_menor(Fecha &otra){
    
    if(anio < otra.anio){
        return true;
    }
    else if(anio == otra.anio){
        if(mes < otra.mes){
            return true;
        }
        else if(mes == otra.mes){
            if(dia < otra.dia){
                return true;
            }
            else if(dia == otra.dia){
                
                if(hora < otra.hora){
                    return true;
                }
                else if(hora == otra.hora){
                    if(minuto < otra.minuto){
                        return true;
                    }
                    else if(minuto == otra.minuto){
                        return segundo < otra.segundo;
                    }
                }
            }
        }
    }
    return false;
}

int main(){

    int N;
    cin >> N;

    Fecha primera;

    if(!primera.leer()){
        return 1;
    }

    for(int i = 1; i < N; ++i){
        Fecha segunda;
        if(!segunda.leer()) return 1;

        if(segunda.es_menor(primera)){
            segunda.escribir();
            cout << " ES ANTERIOR A ";
            primera.escribir();
        }
        else if(segunda.es_igual(primera)){
            segunda.escribir();
            cout << " ES IGUAL A ";
            primera.escribir();
        }
        else{
            segunda.escribir();
            cout << " ES POSTERIOR A ";
            primera.escribir();
        }
        cout << '\n';

        primera = segunda;
    }
    
    return 0;
}