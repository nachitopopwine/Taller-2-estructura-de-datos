#pragma once
#include <iostream>
#include <string>

using namespace std;

class Producto {
private:
    string id;
    string nombre;
    double precio;
    string categoria;
    string subcategoria;

public:
    Producto(string id, string nombre, double precio, string categoria, string subcategoria);
    string getId();
    string getNombre();
    double getPrecio();
    string getCategoria();
    string getSubcategoria();
};