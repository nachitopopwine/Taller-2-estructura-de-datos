#pragma once
#include "Cliente.h"

class Embarazada : public Cliente {
public:
    Embarazada(string nombre, int edad);
    string getTipo() ;
};