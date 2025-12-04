#include "ArbolFechas.h"
#include <algorithm>

ArbolFechas::ArbolFechas() : raiz(nullptr) {}

ArbolFechas::~ArbolFechas() {
    destruir_recursivo(raiz);
}

void ArbolFechas::destruir_recursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        destruir_recursivo(nodo->izq);
        destruir_recursivo(nodo->der);
        delete nodo;
    }
}

void ArbolFechas::insertar(const Cuac* c) {
    insertar_recursivo(raiz, c);
}

void ArbolFechas::insertar_recursivo(Nodo*& nodo, const Cuac* c) {
    if (nodo == nullptr) {
        nodo = new Nodo(c);
    } else {
        if (*c < *nodo->dato) {
            insertar_recursivo(nodo->izq, c);
        } else {
            insertar_recursivo(nodo->der, c);
        }
    }
}

vector<const Cuac*> ArbolFechas::ultimos(int n) const {
    vector<const Cuac*> lista;
    int contador = n;
    ultimos_recursivo(raiz, lista, contador);
    return lista;
}

void ArbolFechas::ultimos_recursivo(Nodo* nodo, vector<const Cuac*>& lista, int& n) const {
    if (nodo == nullptr || n <= 0) return;

    ultimos_recursivo(nodo->izq, lista, n);

    if (n > 0) {
        lista.push_back(nodo->dato);
        n--;
    } else {
        return;
    }

    if (n > 0) {
        ultimos_recursivo(nodo->der, lista, n);
    }
}

vector<const Cuac*> ArbolFechas::buscar_rango(const Fecha& inicio, const Fecha& fin) const {
    vector<const Cuac*> lista;
    buscar_rango_recursivo(raiz, inicio, fin, lista);
    return lista;
}

void ArbolFechas::buscar_rango_recursivo(Nodo* nodo, const Fecha& inicio, const Fecha& fin, vector<const Cuac*>& lista) const {
    if (nodo == nullptr) return;

    const Fecha& f_nodo = nodo->dato->get_fecha();

    bool es_demasiado_nuevo = fin.es_menor(f_nodo);
    
    if (!es_demasiado_nuevo) { 
        buscar_rango_recursivo(nodo->izq, inicio, fin, lista);
    }
    
    bool es_demasiado_viejo = f_nodo.es_menor(inicio);

    if (!es_demasiado_nuevo && !es_demasiado_viejo) {
        lista.push_back(nodo->dato);
    }
    
    if (!es_demasiado_viejo) {
        buscar_rango_recursivo(nodo->der, inicio, fin, lista);
    }
}