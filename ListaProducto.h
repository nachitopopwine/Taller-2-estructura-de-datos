#pragma once
#include <iostream>
#include "NodoProducto.h"

using namespace std;

class ListaProducto {
private:
    NodoProducto* cabeza;

public:
    ListaProducto();
    ~ListaProducto();
    void agregarProducto(Producto* producto);
    Producto* buscarProducto(string id);
    void mostrarProductos();
};