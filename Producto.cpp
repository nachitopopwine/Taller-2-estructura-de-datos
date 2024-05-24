#include "Producto.h"

Producto::Producto(string id, string nombre, double precio, string categoria, string subcategoria)
    : id(id), nombre(nombre), precio(precio), categoria(categoria), subcategoria(subcategoria) {}

string Producto::getId() {
    return id;
}

string Producto::getNombre() {
    return nombre;
}

double Producto::getPrecio() {
    return precio;
}

string Producto::getCategoria() {
    return categoria;
}

string Producto::getSubcategoria() {
    return subcategoria;
}
