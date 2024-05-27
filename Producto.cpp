#include "Producto.h"

Producto::Producto(string id, string nombre, string precio, string categoria, string subcategoria)
    : id(id), nombre(nombre), precio(precio), categoria(categoria), subcategoria(subcategoria) {}

string Producto::getId() const {
    return this->id;
}

string Producto::getNombre() const{
    return this-> nombre;
}

string Producto::getPrecio() const{
    return this->precio;
}

string Producto::getCategoria() const{
    return this->categoria;
}

string Producto::getSubcategoria() const{
    return this->subcategoria;
}
