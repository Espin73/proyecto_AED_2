#include <iostream>
#include <string>
using namespace std;


string mensajes_pcuac(int n) {
    string mensaje;

    switch (n) {
        case 1:
            mensaje = "Afirmativo.";
            break;
        case 2:
            mensaje = "Negativo.";
            break;
        case 3:
            mensaje = "Estoy de viaje en el extranjero.";
            break;
        case 4:
            mensaje = "Muchas gracias a todos mis seguidores por vuestro apoyo.";
            break;
        case 5:
            mensaje = "Enhorabuena, campeones!";
            break;
        case 6:
            mensaje = "Ver las novedades en mi pagina web.";
            break;
        case 7:
            mensaje = "Estad atentos a la gran exclusiva del siglo.";
            break;
        case 8:
            mensaje = "La inteligencia me persigue pero yo soy mas rapido.";
            break;
        case 9:
            mensaje = "Si no puedes convencerlos, confundelos.";
            break;
        case 10:
            mensaje = "La politica es el arte de crear problemas.";
            break;
        case 11:
            mensaje = "Donde estan las llaves, matarile, rile, rile...";
            break;
        case 12:
            mensaje = "Si no te gustan mis principios, puedo cambiarlos por otros.";
            break;
        case 13:
            mensaje = "Un dia lei que fumar era malo y deje de fumar.";
            break;
        case 14:
            mensaje = "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.";
            break;
        case 15:
            mensaje = "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.";
            break;
        case 16:
            mensaje = "Mi vida no es tan glamurosa como mi pagina web aparenta.";
            break;
        case 17:
            mensaje = "Todo tiempo pasado fue anterior.";
            break;
        case 18:
            mensaje = "El azucar no engorda... engorda el que se la toma.";
            break;
        case 19:
            mensaje = "Solo los genios somos modestos.";
            break;
        case 20:
            mensaje = "Nadie sabe escribir tambien como yo.";
            break;
        case 21:
            mensaje = "Si le molesta el mas alla, pongase mas aca.";
            break;
        case 22:
            mensaje = "Me gustaria ser valiente. Mi dentista asegura que no lo soy.";
            break;
        case 23:
            mensaje = "Si el dinero pudiera hablar, me diria adios.";
            break;
        case 24:
            mensaje = "Hoy me ha pasado una cosa tan increible que es mentira.";
            break;
        case 25:
            mensaje = "Si no tienes nada que hacer, por favor no lo hagas en clase.";
            break;
        case 26:
            mensaje = "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.";
            break;
        case 27:
            mensaje = "Me despido hasta la proxima. Buen viaje!";
            break;
        case 28:
            mensaje = "Cualquiera se puede equivocar, inclusivo yo.";
            break;
        case 29:
            mensaje = "Estoy en Egipto. Nunca habia visto las piramides tan solas.";
            break;
        case 30:
            mensaje = "El que quiera saber mas, que se vaya a Salamanca.";
            break;
        default:
            mensaje = "Numero fuera de rango.";
            break;
    }
    return mensaje;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        cout << mensajes_pcuac(n) << endl;
    }
    return 0;
}