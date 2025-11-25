#include "DiccionarioCuacs.h"
#include <algorithm>
#include <iostream>
#include <vector>
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
        list<Cuac> lista = it->second;
        lista.sort(); 
        int i = 1;
        for (const auto& cuac : lista) {
            cout << i << ". ";
            cuac.escribir();
            cout << "\n";
            cont++;
            i++;
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

void DiccionarioCuacs::mostrar_date(const Fecha& inicio, const Fecha& fin) const {
    cout << "date ";
    inicio.escribir();
    cout << " ";
    fin.escribir();
    cout << endl;

    vector<const Cuac*> resultados = porFecha.buscar_rango(inicio, fin);

    for (size_t i = 0; i < resultados.size(); ++i) {
        cout << i + 1 << ". ";
        resultados[i]->escribir();
        cout << "\n";
    }
    cout << "Total: " << resultados.size() << " cuac\n";
}