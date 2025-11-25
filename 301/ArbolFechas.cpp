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
vector<const Cuac*> ArbolFechas::buscar_rango(const Fecha& inicio, const Fecha& fin) const {
    vector<const Cuac*> lista;
    Cuac claveFin;
    claveFin.set_fecha(fin); 
    auto it = arbol.lower_bound(&claveFin);
    while (it != arbol.end()) {
        const Cuac* c = *it;
        if (c->get_fecha().es_menor(inicio)) {
            break; 
        }
        
        lista.push_back(c);
        ++it;
    }
    
    return lista;
}