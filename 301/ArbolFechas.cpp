#include "ArbolFechas.h"
#include <iostream>

using namespace std;

ArbolFechas::ArbolFechas() : raiz(nullptr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ArbolFechas::~ArbolFechas() {
    destruir_recursivo(raiz);
}

void ArbolFechas::destruir_recursivo(Nodo* nodo) {
    if (nodo) {
        destruir_recursivo(nodo->izq);
        destruir_recursivo(nodo->der);
        delete nodo;
    }
}

int ArbolFechas::get_altura(Nodo* n) const {
    if (!n) return 0;
    return n->altura;
}

int ArbolFechas::get_balance(Nodo* n) const {
    if (!n) return 0;
    return get_altura(n->izq) - get_altura(n->der);
}

Nodo* ArbolFechas::rotar_derecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = max(get_altura(y->izq), get_altura(y->der)) + 1;
    x->altura = max(get_altura(x->izq), get_altura(x->der)) + 1;

    return x;
}

Nodo* ArbolFechas::rotar_izquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = max(get_altura(x->izq), get_altura(x->der)) + 1;
    y->altura = max(get_altura(y->izq), get_altura(y->der)) + 1;

    return y;
}


void ArbolFechas::insertar(const Cuac* c) {
    raiz = insertar_recursivo(raiz, c);
}

Nodo* ArbolFechas::insertar_recursivo(Nodo* nodo, const Cuac* c) {
    if (!nodo) return new Nodo(c);

    if (*c < *nodo->dato) {
        nodo->izq = insertar_recursivo(nodo->izq, c);
    } else {
        nodo->der = insertar_recursivo(nodo->der, c);
    }

    nodo->altura = 1 + max(get_altura(nodo->izq), get_altura(nodo->der));

    int balance = get_balance(nodo);


    if (balance > 1 && *c < *nodo->izq->dato) {
        return rotar_derecha(nodo);
    }

    if (balance < -1 && !(*c < *nodo->der->dato)) {
        return rotar_izquierda(nodo);
    }

    if (balance > 1 && !(*c < *nodo->izq->dato)) {
        nodo->izq = rotar_izquierda(nodo->izq);
        return rotar_derecha(nodo);
    }

    if (balance < -1 && (*c < *nodo->der->dato)) {
        nodo->der = rotar_derecha(nodo->der);
        return rotar_izquierda(nodo);
    }

    return nodo;
}

vector<const Cuac*> ArbolFechas::ultimos(int n) const {
    vector<const Cuac*> lista;
    if (n > 0) {
        lista.reserve(n);
        int contador = n;
        ultimos_recursivo(raiz, lista, contador);
    }
    return lista;
}

void ArbolFechas::ultimos_recursivo(Nodo* nodo, vector<const Cuac*>& lista, int& n) const {
    if (!nodo || n <= 0) return;

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
    if (!nodo) return;

    const Fecha& f_nodo = nodo->dato->get_fecha();
    bool muy_nuevo = fin.es_menor(f_nodo);
    
    if (!muy_nuevo) {
        buscar_rango_recursivo(nodo->izq, inicio, fin, lista);
    }

    bool muy_viejo = f_nodo.es_menor(inicio);

    if (!muy_nuevo && !muy_viejo) {
        lista.push_back(nodo->dato);
    }

    if (!muy_viejo) {
        buscar_rango_recursivo(nodo->der, inicio, fin, lista);
    }
}