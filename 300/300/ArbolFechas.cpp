#include "ArbolFechas.h"
#include <iostream>

ArbolFechas::ArbolFechas() : raiz(nullptr) {}

ArbolFechas::~ArbolFechas() {
    liberarArbol(raiz);
}

void ArbolFechas::liberarArbol(Nodo* nodo) {
    if (nodo != nullptr) {
        liberarArbol(nodo->izq);
        liberarArbol(nodo->der);
        delete nodo;
    }
}

int ArbolFechas::getAltura(Nodo* n) const {
    if (n == nullptr) return 0;
    return n->altura;
}

int ArbolFechas::getEquilibrio(Nodo* n) const {
    if (n == nullptr) return 0;
    return getAltura(n->izq) - getAltura(n->der);
}

Nodo* ArbolFechas::rotarDerecha(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = max(getAltura(y->izq), getAltura(y->der)) + 1;
    x->altura = max(getAltura(x->izq), getAltura(x->der)) + 1;

    return x;
}

Nodo* ArbolFechas::rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = max(getAltura(x->izq), getAltura(x->der)) + 1;
    y->altura = max(getAltura(y->izq), getAltura(y->der)) + 1;

    return y;
}

Nodo* ArbolFechas::insertarRec(Nodo* nodo, const Cuac* c) {
    if (nodo == nullptr) {
        return new Nodo(c);
    }
    if (*c < *(nodo->dato)) {
        nodo->izq = insertarRec(nodo->izq, c);
    }
    else if (*(nodo->dato) < *c) {
        nodo->der = insertarRec(nodo->der, c);
    }
    else {
        return nodo;
    }

    nodo->altura = 1 + max(getAltura(nodo->izq), getAltura(nodo->der));

    int balance = getEquilibrio(nodo);
    if (balance > 1 && *c < *(nodo->izq->dato))
        return rotarDerecha(nodo);

    if (balance < -1 && *(nodo->der->dato) < *c)
        return rotarIzquierda(nodo);

    if (balance > 1 && *(nodo->izq->dato) < *c) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }
    if (balance < -1 && *c < *(nodo->der->dato)) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }
    return nodo;
}

void ArbolFechas::insertar(const Cuac* c) {
    raiz = insertarRec(raiz, c);
}

void ArbolFechas::inordenRec(Nodo* nodo, vector<const Cuac*>& lista, int& contador, int n) const {
    if (nodo == nullptr || contador >= n) return;

    inordenRec(nodo->izq, lista, contador, n);

    if (contador < n) {
        lista.push_back(nodo->dato);
        contador++;
    } else {
        return;
    }

    inordenRec(nodo->der, lista, contador, n);
}

void ArbolFechas::rangoRec(Nodo* nodo, const Fecha& ini, const Fecha& fin, vector<const Cuac*>& lista) const {
    if (nodo == nullptr) return;

    const Fecha& fNode = nodo->dato->get_fecha();

    bool nodo_es_mayor_que_fin = fin.es_menor(fNode);
    
    if (!nodo_es_mayor_que_fin) {
        rangoRec(nodo->izq, ini, fin, lista);
    }


    bool mayor_igual_ini = !fNode.es_menor(ini);
    bool menor_igual_fin = !fin.es_menor(fNode);
    
    if (mayor_igual_ini && menor_igual_fin) {
        lista.push_back(nodo->dato);
    }
    
    bool nodo_es_menor_que_ini = fNode.es_menor(ini);
    
    if (!nodo_es_menor_que_ini) {
        rangoRec(nodo->der, ini, fin, lista);
    }
}

vector<const Cuac*> ArbolFechas::ultimos(int n) const {
    vector<const Cuac*> lista;
    int contador = 0;
    
    if (n > 0) {
        inordenRec(raiz, lista, contador, n);
    }
    
    return lista;
}

vector<const Cuac*> ArbolFechas::rango(const Fecha& ini, const Fecha& fin) const {
    vector<const Cuac*> lista;
    rangoRec(raiz, ini, fin, lista);
    return lista;
}