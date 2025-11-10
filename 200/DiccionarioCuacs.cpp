#include "DiccionarioCuacs.h"
#include <algorithm>
#include <iostream>
using namespace std;

    void DiccionarioCuacs::insertar(const Cuac &c) {
        lista.push_back(c);
        sort(lista.begin(), lista.end());
        porUsuario[c.get_usuario()].push_back(c);
    }

    void DiccionarioCuacs::mostrar_last(int n) const {
        cout << "last " << n << "\n";
        int t = min(n, (int)lista.size());
        for (int i = 0; i < t; ++i) {
            cout << i+1 << ". ";
            lista[i].escribir();
            cout << "\n";
        }
    cout << "Total: " << t << " cuac\n";
    }

    void DiccionarioCuacs::mostrar_follow(const string &nombre) const {
        cout << "follow " << nombre << "\n";
        int cont = 0;
        auto it = porUsuario.find(nombre);
        if (it != porUsuario.end()) {
            const auto &vec = it->second;
            for (size_t i = 0; i < vec.size(); ++i) {
                cout << i+1 << ". ";
                vec[i].escribir();
                cout << "\n";
                cont++;
        }
    }
        cout << "Total: " << cont << " cuac\n";
    }

    void DiccionarioCuacs::mostrar_date(Fecha f1, Fecha f2) const {
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

