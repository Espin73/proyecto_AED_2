#pragma once
#include "Cuac.h"
#include <vector>
#include <memory>
using namespace std;

struct NodoFecha {
    Fecha fecha;
    vector<const Cuac*> cuacs;
    unique_ptr<NodoFecha> izq, der;

    NodoFecha(const Fecha& f) : fecha(f) {}
};

class ArbolFechas {
private:
    unique_ptr<NodoFecha> raiz;

    void insertar_rec(unique_ptr<NodoFecha>& nodo, const Cuac* c);
    void recorrido_desc(const NodoFecha* nodo, vector<const Cuac*>& lista) const;

public:
    ArbolFechas() {}
    void insertar(const Cuac* c);
    vector<const Cuac*> ultimos(int n) const;
};