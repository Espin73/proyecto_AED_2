#pragma once
#include "Cuac.h"
#include <vector>
#include <algorithm>
using namespace std;

struct Nodo {
    const Cuac* dato;
    Nodo* izq;
    Nodo* der;
    int altura;

    Nodo(const Cuac* c) : dato(c), izq(nullptr), der(nullptr), altura(1) {}
};

class ArbolFechas {
private:
    Nodo* raiz;

    int getAltura(Nodo* n) const;
    int getEquilibrio(Nodo* n) const;
    
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    
    Nodo* insertarRec(Nodo* nodo, const Cuac* c);

    void inordenRec(Nodo* nodo, vector<const Cuac*>& lista, int& contador, int n) const;

    void rangoRec(Nodo* nodo, const Fecha& ini, const Fecha& fin, vector<const Cuac*>& lista) const;

    void liberarArbol(Nodo* nodo);

public:
    ArbolFechas();
    ~ArbolFechas();
    
    void insertar(const Cuac* c);
    vector<const Cuac*> ultimos(int n) const;
    vector<const Cuac*> rango(const Fecha& ini, const Fecha& fin) const;
};