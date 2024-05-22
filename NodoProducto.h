#pragma once
#include <iostream>
#include "Producto.h"

using namespace std;

class NodoProducto {
public:
    Producto* producto;
    NodoProducto* siguiente;

    NodoProducto(Producto* producto);
    ~NodoProducto();
};