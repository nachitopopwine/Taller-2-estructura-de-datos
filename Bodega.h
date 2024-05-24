#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Producto.h"

using namespace std;

class Bodega {
private:
    unordered_map<string, vector<Producto*>> productos;

public:
    Bodega();
    ~Bodega();
    void agregarProducto(Producto* producto);
    Producto* buscarProducto(string id);
    void venderProducto(string id);
    void cargarDatos();
    void guardarDatos();
};
