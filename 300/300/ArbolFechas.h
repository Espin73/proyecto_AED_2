#pragma once
#include "Cuac.h"
#include <vector>
#include <set>
using namespace std;

struct ComparadorCuacs {
    bool operator()(const Cuac* a, const Cuac* b) const {
        return *a < *b; 
    }
};

class ArbolFechas {
private:
    set<const Cuac*, ComparadorCuacs> arbol;

public:
    ArbolFechas() {}
    void insertar(const Cuac* c);
    vector<const Cuac*> ultimos(int n) const;
};