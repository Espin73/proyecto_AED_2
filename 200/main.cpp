#include "Fecha.h"
#include "Cuac.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "DiccionarioCuacs.h"
using namespace std;


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