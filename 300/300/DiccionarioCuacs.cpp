#include "DiccionarioCuacs.h"
#include <algorithm>
#include <iostream>
using namespace std;

    void DiccionarioCuacs::insertar(const Cuac &c) {
        porUsuario[c.get_usuario()].push_back(c);
        n_total++;
        const Cuac* ref = &porUsuario[c.get_usuario()].back();
        porFecha.insertar(ref);
    }

    void DiccionarioCuacs::mostrar_follow(const string &nombre) const {
        cout << "follow " << nombre << "\n";
        int cont = 0;
        auto it = porUsuario.find(nombre);
        if (it != porUsuario.end()) {
            auto vec = it->second;
            sort(vec.begin(), vec.end());
            for (size_t i = 0; i < vec.size(); ++i) {
                cout << i+1 << ". ";
                vec[i].escribir();
                cout << "\n";
                cont++;
        }
    }
        cout << "Total: " << cont << " cuac\n";
    }

    void DiccionarioCuacs::mostrar_last(int n) const {
    cout << "last " << n << "\n";
    auto ultimos = porFecha.ultimos(n);
    for (size_t i = 0; i < ultimos.size(); ++i) {
        cout << i + 1 << ". ";
        ultimos[i]->escribir();
        cout << "\n";
    }
    cout << "Total: " << ultimos.size() << " cuac\n";
}