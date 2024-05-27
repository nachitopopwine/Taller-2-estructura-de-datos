#include "NodoProducto.h"

NodoProducto::NodoProducto(const Producto& producto) : producto(producto), siguiente(nullptr) {}

NodoProducto::~NodoProducto() {
    //delete producto;
}