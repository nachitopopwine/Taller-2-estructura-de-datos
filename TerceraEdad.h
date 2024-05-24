#pragma once
#include "Cliente.h"

class TerceraEdad : public Cliente {
public:
    TerceraEdad(string nombre, int edad);
    string getTipo() ;
};