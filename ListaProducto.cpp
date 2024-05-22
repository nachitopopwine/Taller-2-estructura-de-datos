#include "ListaProducto.h"

ListaProducto::ListaProducto() {
    cabeza = nullptr;
}

ListaProducto::~ListaProducto() {
    NodoProducto* actual = cabeza;
    while (actual != nullptr) {
        NodoProducto* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaProducto::agregarProducto(Producto* producto) {
    NodoProducto* nuevo = new NodoProducto(producto);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

Producto* ListaProducto::buscarProducto(string id) {
    NodoProducto* actual = cabeza;
    while (actual != nullptr) {
        if (actual->producto->getId() == id) {
            return actual->producto;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaProducto::mostrarProductos() {
    NodoProducto* actual = cabeza;
    while (actual != nullptr) {
        cout << "ID: " << actual->producto->getId() << ", Nombre: " << actual->producto->getNombre() << ", Categoria: " << actual->producto->getCategoria() << ", Subcategoria: " << actual->producto->getSubcategoria() << ", Precio: " << actual->producto->getPrecio() << endl;
        actual = actual->siguiente;
    }
}