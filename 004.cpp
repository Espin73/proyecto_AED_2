#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
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


class Cuac {
private:
    string usuario;
    string fecha_hora;
    string mensaje;

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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Cuac> cuacs;
    Cuac c;

    while (!cin.eof()) {
        c.leer();
        if (cin.fail()) break;

        cuacs.push_back(c);
        cuacs.back().mostrar(cuacs.size());
    }

    return 0;
}