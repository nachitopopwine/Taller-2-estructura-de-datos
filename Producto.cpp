#include "Producto.h"

Producto::Producto(std::string cat, std::string subcat, float precio, int id) : categoria(cat), subcategoria(subcat), precio(precio), id(id) {}

std::string Producto::getCategoria() const {
    return categoria;
}

std::string Producto::getSubcategoria() const {
    return subcategoria;
}

float Producto::getPrecio() const {
    return precio;
}

int Producto::getId() const {
    return id;
}