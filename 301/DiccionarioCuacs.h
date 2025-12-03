#pragma once
#include <string>
#include <vector>
#include <list>
#include "Cuac.h"
#include "Fecha.h"
#include "ArbolFechas.h"
using namespace std;

struct EntradaUsuario {
    string nombre;
    list<Cuac> mensajes;
};

class DiccionarioCuacs {
private:
    int n_total;
    
    static const int TAM_TABLA = 10007; 
    
    vector<list<EntradaUsuario>> tabla; 

    unsigned long hashStr(const string &str) const;

    ArbolFechas porFecha;

public:
    DiccionarioCuacs();
    
    void insertar(const Cuac &c);
    void mostrar_follow(const string &nombre) const;
    void mostrar_last(int n) const;
    void mostrar_date(const Fecha& ini, const Fecha& fin) const;

    int total() const { return n_total; }
};