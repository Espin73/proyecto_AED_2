#pragma once
#include <iostream>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
    int hora, minuto, segundo;

public:
    Fecha();
    bool leer();
    void escribir() const;
    bool es_menor(const Fecha &otra) const;
    bool es_igual(const Fecha &otra) const;
};