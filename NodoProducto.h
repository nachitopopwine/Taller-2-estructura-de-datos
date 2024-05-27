#pragma once
#include <iostream>
#include "Producto.h"

using namespace std;

class NodoProducto {
public:
    Producto producto;
    NodoProducto* siguiente;

    NodoProducto(const Producto& producto);
    ~NodoProducto();
};