#include "ArbolFechas.h"
#include <algorithm>

void ArbolFechas::insertar(const Cuac* c) {
    arbol.insert(c);
}

vector<const Cuac*> ArbolFechas::ultimos(int n) const {
    vector<const Cuac*> lista;
    
    int contador = 0;
    auto it = arbol.begin();
    
    while (it != arbol.end() && contador < n) {
        lista.push_back(*it);
        ++it;
        ++contador;
    }
    
    return lista;
}