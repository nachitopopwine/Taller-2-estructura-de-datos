#include "Producto.h"

Producto::Producto(string id, string nombre, string categoria, string subcategoria, double precio) {
    this->id = id;
    this->nombre = nombre;
    this->categoria = categoria;
    this->subcategoria = subcategoria;
    this->precio = precio;
}

string Producto::getId() {
    return this->id;
}

string Producto::getNombre() {
    return this->nombre;
}

string Producto::getCategoria() {
    return this->categoria;
}

string Producto::getSubcategoria() {
    return this->subcategoria;
}

double Producto::getPrecio() {
    return this->precio;
}

void Producto::setId(string id) {
    this->id = id;
}

void Producto::setNombre(string nombre) {
    this->nombre = nombre;
}

void Producto::setCategoria(string categoria) {
    this->categoria = categoria;
}

void Producto::setSubcategoria(string subcategoria) {
    this->subcategoria = subcategoria;
}

void Producto::setPrecio(double precio) {
    this->precio = precio;
}

Producto::~Producto() {}