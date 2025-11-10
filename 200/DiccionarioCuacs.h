#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Cuac.h"
#include "Fecha.h"
using namespace std;

class DiccionarioCuacs {
private:
    int n_total;
    unordered_map<string, vector<Cuac>> porUsuario;

public:
    DiccionarioCuacs():n_total(0){}
    void insertar(const Cuac &c);
    void mostrar_follow(const string &nombre) const;
    int total() const { return n_total; }
};
