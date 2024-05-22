#pragma once
#include <iostream>

using namespace std;

class Producto {
private:
    string id;
    string nombre;
    string categoria;
    string subcategoria;
    double precio;

public:
    Producto(string id, string nombre, string categoria, string subcategoria, double precio);
    string getId();
    string getNombre();
    string getCategoria();
    string getSubcategoria();
    double getPrecio();
    void setId(string id);
    void setNombre(string nombre);
    void setCategoria(string categoria);
    void setSubcategoria(string subcategoria);
    void setPrecio(double precio);
    ~Producto();
};