#include "DiccionarioCuacs.h"
#include <algorithm>
#include <iostream>
using namespace std;

    void DiccionarioCuacs::insertar(const Cuac &c) {
        porUsuario[c.get_usuario()].push_back(c);
        n_total++;
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


