#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

string mensajes_pcuac(int n) {
    switch (n) {
        case 1: return "Afirmativo.";
        case 2: return "Negativo.";
        case 3: return "Estoy de viaje en el extranjero.";
        case 4: return "Muchas gracias a todos mis seguidores por vuestro apoyo.";
        case 5: return "Enhorabuena, campeones!";
        case 6: return "Ver las novedades en mi pagina web.";
        case 7: return "Estad atentos a la gran exclusiva del siglo.";
        case 8: return "La inteligencia me persigue pero yo soy mas rapido.";
        case 9: return "Si no puedes convencerlos, confundelos.";
        case 10: return "La politica es el arte de crear problemas.";
        case 11: return "Donde estan las llaves, matarile, rile, rile...";
        case 12: return "Si no te gustan mis principios, puedo cambiarlos por otros.";
        case 13: return "Un dia lei que fumar era malo y deje de fumar.";
        case 14: return "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.";
        case 15: return "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.";
        case 16: return "Mi vida no es tan glamurosa como mi pagina web aparenta.";
        case 17: return "Todo tiempo pasado fue anterior.";
        case 18: return "El azucar no engorda... engorda el que se la toma.";
        case 19: return "Solo los genios somos modestos.";
        case 20: return "Nadie sabe escribir tambien como yo.";
        case 21: return "Si le molesta el mas alla, pongase mas aca.";
        case 22: return "Me gustaria ser valiente. Mi dentista asegura que no lo soy.";
        case 23: return "Si el dinero pudiera hablar, me diria adios.";
        case 24: return "Hoy me ha pasado una cosa tan increible que es mentira.";
        case 25: return "Si no tienes nada que hacer, por favor no lo hagas en clase.";
        case 26: return "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.";
        case 27: return "Me despido hasta la proxima. Buen viaje!";
        case 28: return "Cualquiera se puede equivocar, inclusivo yo.";
        case 29: return "Estoy en Egipto. Nunca habia visto las piramides tan solas.";
        case 30: return "El que quiera saber mas, que se vaya a Salamanca.";
        default: return "Numero fuera de rango.";
    }
}

class Fecha {
private:
    int dia, mes, anio;
    int hora, minuto, segundo;

public:
    Fecha();
    bool leer();
    void escribir() const;
    bool es_menor(Fecha &otra) const;
    bool es_igual(Fecha &otra) const;
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

void Fecha::escribir() const{
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

bool Fecha::es_igual(Fecha &otra) const{

    return dia==otra.dia && mes==otra.mes && anio==otra.anio && hora==otra.hora && minuto==otra.minuto && segundo==otra.segundo;
}

bool Fecha::es_menor(Fecha &otra) const{
    
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

class Cuac {
private:
    string usuario;
    string mensaje;
    string fecha_hora;
    Fecha fecha;

public:
    Cuac() {}
    
    void leer() {
        string entradatx;
        cin >> entradatx >> usuario;
        cin.ignore(); 

        getline(cin, fecha_hora);

        if (entradatx == "mcuac") {
            getline(cin, mensaje);
        } else if (entradatx == "pcuac") {
            int n;
            cin >> n;
            cin.ignore();
            mensaje = mensajes_pcuac(n);
        }
    }

    
    void mostrar(int n) const {
        cout << n << " cuac\n";
        cout << usuario << " " << fecha_hora << "\n";
        cout << "   " << mensaje << "\n";
    }

    
    bool operator<(const Cuac &otro) const {
       
        if (fecha_hora != otro.fecha_hora)
            return fecha_hora > otro.fecha_hora;

        
        if (mensaje != otro.mensaje)
            return mensaje < otro.mensaje;

       
        return usuario < otro.usuario;
    }

void leer_mcuac(){
        cin >> usuario;
        cin.ignore();
        fecha.leer();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, mensaje);
    }

    void leer_pcuac(){
        cin >> usuario;
        cin.ignore();
        fecha.leer();
        int n;
        cin >> n;
        cin.ignore();
        mensaje = mensajes_pcuac(n);
    }

    void escribir() const{
        cout << usuario << " ";
        fecha.escribir();
        cout << "\n   " << mensaje;
    }

    string get_usuario() const { return usuario; }
    const Fecha& get_fecha() const { return fecha; }
};


class DiccionarioCuacs {
private:
    vector<Cuac> lista;

public:
    void insertar(const Cuac &c) {
        lista.push_back(c);
        sort(lista.begin(), lista.end());
    }

    void mostrar_last(int n) const {
        cout << "last " << n << "\n";
        int total = min(n, (int)lista.size());
        for (int i = 0; i < total; ++i) {
            cout << i+1 << ". ";
            lista[i].escribir();
            cout << "\n";
        }
        cout << "Total: " << total << " cuac\n";
    }

    void mostrar_follow(const string &nombre) const {
        cout << "follow " << nombre << "\n";
        int cont = 0;
        for (size_t i = 0; i < lista.size(); ++i) {
            if (lista[i].get_usuario() == nombre) {
                cout << ++cont << ". ";
                lista[i].escribir();
                cout << "\n";
            }
        }
        cout << "Total: " << cont << " cuac\n";
    }

    void mostrar_date(Fecha f1, Fecha f2) const {
        cout << "date ";
        f1.escribir();
        cout << " ";
        f2.escribir();
        cout << "\n";

        int cont = 0;
        for (size_t i = 0; i < lista.size(); ++i) {
            if (!lista[i].get_fecha().es_menor(f1) && !f2.es_menor(const_cast<Fecha&>(lista[i].get_fecha()))) {
                cout << ++cont << ". ";
                lista[i].escribir();
                cout << "\n";
            }
        }
        cout << "Total: " << cont << " cuac\n";
    }

    int total() const { return lista.size(); }
};


int main() {
    DiccionarioCuacs dic;
    string comando;

    while (cin >> comando) {
        if (comando == "exit") break;

        if (comando == "mcuac") {
            Cuac c;
            c.leer_mcuac();
            dic.insertar(c);
            cout << dic.total() << " cuac\n";
        }
        else if (comando == "pcuac") {
            Cuac c;
            c.leer_pcuac();
            dic.insertar(c);
            cout << dic.total() << " cuac\n";
        }
        else if (comando == "last") {
            int n; cin >> n;
            dic.mostrar_last(n);
        }
        else if (comando == "follow") {
            string nombre; cin >> nombre;
            dic.mostrar_follow(nombre);
        }
        else if (comando == "date") {
            Fecha f1, f2;
            f1.leer(); f2.leer();
            dic.mostrar_date(f1, f2);
        }
    }

    return 0;
}