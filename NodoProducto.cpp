#include "NodoProducto.h"

NodoProducto::NodoProducto(Producto* producto) {
    this->producto = producto;
    this->siguiente = nullptr;
}

NodoProducto::~NodoProducto() {
    delete producto;
}