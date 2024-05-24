#pragma once
#include "Cliente.h"

class Discapacitado : public Cliente {
public:
    Discapacitado(string nombre, int edad);
    string getTipo() ;
};