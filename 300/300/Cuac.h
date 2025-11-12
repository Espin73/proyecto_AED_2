#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
using namespace std;

class Cuac {
private:
    string usuario;
    string mensaje;
    string fecha_hora;
    Fecha fecha;

public:
    Cuac() {}
    
    void leer_mcuac();
    void leer_pcuac();

    void escribir() const;

    string get_usuario() const { return usuario; }
    const Fecha& get_fecha() const { return fecha; }

    bool operator<(const Cuac &otro) const;
};

string mensajes_pcuac(int n);
