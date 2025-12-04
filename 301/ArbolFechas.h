#pragma once
#include "Cuac.h"
#include <vector>
using namespace std;

struct Nodo {
    const Cuac* dato;
    Nodo* izq;
    Nodo* der;

    Nodo(const Cuac* c) : dato(c), izq(nullptr), der(nullptr) {}
};

class ArbolFechas {
private:
    Nodo* raiz;

    void insertar_recursivo(Nodo*& nodo, const Cuac* c);
    void ultimos_recursivo(Nodo* nodo, vector<const Cuac*>& lista, int& n) const;
    void buscar_rango_recursivo(Nodo* nodo, const Fecha& inicio, const Fecha& fin, vector<const Cuac*>& lista) const;
    void destruir_recursivo(Nodo* nodo);

public:
    ArbolFechas();
    ~ArbolFechas();

    void insertar(const Cuac* c);
    vector<const Cuac*> ultimos(int n) const;
    
    vector<const Cuac*> buscar_rango(const Fecha& inicio, const Fecha& fin) const;
};