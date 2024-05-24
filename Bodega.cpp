#include "Bodega.h"


Bodega::Bodega() {}

Bodega::~Bodega() {
    for (auto& par : productos) {
        for (Producto* producto : par.second) {
            delete producto;
        }
    }
}

void Bodega::agregarProducto(Producto* producto) {
    productos[producto->getId()].push_back(producto);
}

Producto* Bodega::buscarProducto(string id) {
    if (productos.find(id) != productos.end() && !productos[id].empty()) {
        return productos[id].front();
    }
    return nullptr;
}

void Bodega::venderProducto(string id) {
    if (productos.find(id) != productos.end() && !productos[id].empty()) {
        delete productos[id].front();
        productos[id].erase(productos[id].begin());
    }
}

void Bodega::cargarDatos() {
    cout << "cargar datos" << endl;
    
}

void Bodega::guardarDatos() {
    cout << "guardar datos" << endl;
    
}
