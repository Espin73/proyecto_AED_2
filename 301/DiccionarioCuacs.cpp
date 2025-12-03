#include "DiccionarioCuacs.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

DiccionarioCuacs::DiccionarioCuacs() : n_total(0) {
    tabla.resize(TAM_TABLA);
}

DiccionarioCuacs::~DiccionarioCuacs() {
    for (auto &bucket : tabla) {
        for (auto &entrada : bucket) {
            for (auto *c : entrada.mensajes) {
                delete c;
            }
        }
    }
}

unsigned long DiccionarioCuacs::hashStr(const string &str) const {
    unsigned long hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TAM_TABLA;
}

void DiccionarioCuacs::insertar(const Cuac &c) {
    string usuario = c.get_usuario();
    int indice = hashStr(usuario);

    bool encontrado = false;
    vector<EntradaUsuario>& bucket = tabla[indice];
    
    for (auto &entrada : bucket) {
        if (entrada.nombre == usuario) {
            Cuac* nuevo_cuac = new Cuac(c);
            entrada.mensajes.push_back(nuevo_cuac);
            encontrado = true;
            
            porFecha.insertar(nuevo_cuac);
            break;
        }
    }

    if (!encontrado) {
        EntradaUsuario nueva;
        nueva.nombre = usuario;
        
        Cuac* nuevo_cuac = new Cuac(c);
        nueva.mensajes.push_back(nuevo_cuac);
        
        bucket.push_back(nueva);
        
        porFecha.insertar(nuevo_cuac);
    }

    n_total++;
}

void DiccionarioCuacs::mostrar_follow(const string &nombre) const {
    cout << "follow " << nombre << "\n";
    
    int indice = hashStr(nombre);
    const vector<EntradaUsuario>& bucket = tabla[indice];
    
    const vector<Cuac*>* lista_ptr = nullptr;
    
    for (const auto &entrada : bucket) {
        if (entrada.nombre == nombre) {
            lista_ptr = &entrada.mensajes;
            break;
        }
    }

    int cont = 0;
    if (lista_ptr != nullptr) {
        vector<Cuac*> copiaLista = *lista_ptr;
        
        sort(copiaLista.begin(), copiaLista.end(), [](const Cuac* a, const Cuac* b) {
            return *a < *b;
        });

        int i = 1;
        for (const auto* cuac : copiaLista) {
            cout << i << ". ";
            cuac->escribir();
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

void DiccionarioCuacs::mostrar_date(const Fecha& ini, const Fecha& fin) const {
    cout << "date ";
    ini.escribir();
    cout << " ";
    fin.escribir();
    cout << "\n";

    vector<const Cuac*> encontrados = porFecha.buscar_rango(ini, fin);

    for (size_t i = 0; i < encontrados.size(); ++i) {
        cout << i + 1 << ". ";
        encontrados[i]->escribir();
        cout << "\n";
    }
    cout << "Total: " << encontrados.size() << " cuac\n";
}