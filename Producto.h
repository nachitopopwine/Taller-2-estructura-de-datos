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
    string getId() const;
    string getNombre()const;
    double getPrecio()const;
    string getCategoria()const;
    string getSubcategoria()const;
};