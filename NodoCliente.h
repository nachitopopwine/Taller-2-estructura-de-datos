#pragma once
#include <iostream>
#include "Cliente.h"

using namespace std;

class NodoCliente {
public:
    Cliente* cliente;
    NodoCliente* siguiente;

    NodoCliente(Cliente* cliente);
    ~NodoCliente();
};