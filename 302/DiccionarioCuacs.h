#pragma once
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "Cuac.h"
#include "Fecha.h"
#include "ArbolFechas.h"
using namespace std;

class DiccionarioCuacs {
private:
    int n_total;
    unordered_map<string, list<Cuac>> porUsuario;
    ArbolFechas porFecha;
public:
    DiccionarioCuacs():n_total(0){}
    void insertar(const Cuac &c);
    void mostrar_follow(const string &nombre) const;
    void mostrar_last(int n) const;
    void mostrar_date(const Fecha& inicio, const Fecha& fin) const;
    int total() const { return n_total; }
};
