#include "NodoCliente.h"

NodoCliente::NodoCliente(Cliente* cliente) {
    this->cliente = cliente;
    this->siguiente = nullptr;
}

NodoCliente::~NodoCliente() {
    delete cliente;
}