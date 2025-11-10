#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Cuac.h"
#include "Fecha.h"
using namespace std;

class DiccionarioCuacs {
private:
    vector<Cuac> lista;
    unordered_map<string, vector<Cuac>> porUsuario;

public:
    void insertar(const Cuac &c);
    void mostrar_last(int n) const;
    void mostrar_follow(const string &nombre) const;
    void mostrar_date(Fecha f1, Fecha f2) const;
    int total() const { return (int)lista.size(); }
};
