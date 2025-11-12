#include "ArbolFechas.h"
#include <algorithm>

void ArbolFechas::insertar(const Cuac* c) {
    insertar_rec(raiz, c);
}

void ArbolFechas::insertar_rec(unique_ptr<NodoFecha>& nodo, const Cuac* c) {
    if (!nodo) {
        nodo = make_unique<NodoFecha>(c->get_fecha());
        nodo->cuacs.push_back(c);
        return;
    }

    if (nodo->fecha.es_igual(const_cast<Fecha&>(c->get_fecha()))) {
        nodo->cuacs.push_back(c);
    }
    else if (nodo->fecha.es_menor(const_cast<Fecha&>(c->get_fecha()))) {
        insertar_rec(nodo->der, c);
    }
    else {
        insertar_rec(nodo->izq, c);
    }
}

void ArbolFechas::recorrido_desc(const NodoFecha* nodo, vector<const Cuac*>& lista) const {
    if (!nodo) return;
    recorrido_desc(nodo->der.get(), lista);
    for (auto c : nodo->cuacs) lista.push_back(c);
    recorrido_desc(nodo->izq.get(), lista);
}

vector<const Cuac*> ArbolFechas::ultimos(int n) const {
    vector<const Cuac*> lista;
    recorrido_desc(raiz.get(), lista);

    sort(lista.begin(), lista.end(),
        [](const Cuac* a, const Cuac* b) { return *a < *b; });

    if (n < (int)lista.size())
        lista.resize(n);
    return lista;
}