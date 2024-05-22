#include "ColaClientes.h"

ColaClientes::ColaClientes() {
    
}

ColaClientes::~ColaClientes() {
    while (!colaTerceraEdad.empty()) {
        delete colaTerceraEdad.front();
        colaTerceraEdad.pop();
    }
    while (!colaDiscapacitado.empty()) {
        delete colaDiscapacitado.front();
        colaDiscapacitado.pop();
    }
    while (!colaEmbarazada.empty()) {
        delete colaEmbarazada.front();
        colaEmbarazada.pop();
    }
    while (!colaNormal.empty()) {
        delete colaNormal.front();
        colaNormal.pop();
    }
}

void ColaClientes::agregarCliente(Cliente* cliente) {
    NodoCliente* nuevo = new NodoCliente(cliente);
    
    if (cliente->getTipo() == "TerceraEdad") {
        colaTerceraEdad.push(nuevo);
    } else if (cliente->getTipo() == "Discapacitado") {
        colaDiscapacitado.push(nuevo);
    } else if (cliente->getTipo() == "Embarazada") {
        colaEmbarazada.push(nuevo);
    } else {
        colaNormal.push(nuevo);
    }
}

Cliente* ColaClientes::llamarSiguienteCliente() {
    if (!colaTerceraEdad.empty()) {
        NodoCliente* nodo = colaTerceraEdad.front();
        colaTerceraEdad.pop();
        Cliente* cliente = nodo->cliente;
        delete nodo;
        return cliente;
    } else if (!colaDiscapacitado.empty()) {
        NodoCliente* nodo = colaDiscapacitado.front();
        colaDiscapacitado.pop();
        Cliente* cliente = nodo->cliente;
        delete nodo;
        return cliente;
    } else if (!colaEmbarazada.empty()) {
        NodoCliente* nodo = colaEmbarazada.front();
        colaEmbarazada.pop();
        Cliente* cliente = nodo->cliente;
        delete nodo;
        return cliente;
    } else if (!colaNormal.empty()) {
        NodoCliente* nodo = colaNormal.front();
        colaNormal.pop();
        Cliente* cliente = nodo->cliente;
        delete nodo;
        return cliente;
    } else {
        return nullptr;
    }
}

void ColaClientes::mostrarClientes() {
    cout << "Clientes de tercera edad:" << endl;
    queue<NodoCliente*> tempTerceraEdad = colaTerceraEdad;
    while (!tempTerceraEdad.empty()) {
        NodoCliente* actual = tempTerceraEdad.front();
        cout << "Nombre: " << actual->cliente->getNombre() << ", Edad: " << actual->cliente->getEdad() << ", Tipo: " << actual->cliente->getTipo() << endl;
        tempTerceraEdad.pop();
    }

    cout << "Clientes discapacitados:" << endl;
    queue<NodoCliente*> tempDiscapacitado = colaDiscapacitado;
    while (!tempDiscapacitado.empty()) {
        NodoCliente* actual = tempDiscapacitado.front();
        cout << "Nombre: " << actual->cliente->getNombre() << ", Edad: " << actual->cliente->getEdad() << ", Tipo: " << actual->cliente->getTipo() << endl;
        tempDiscapacitado.pop();
    }

    cout << "Clientes embarazadas:" << endl;
    queue<NodoCliente*> tempEmbarazada = colaEmbarazada;
    while (!tempEmbarazada.empty()) {
        NodoCliente* actual = tempEmbarazada.front();
        cout << "Nombre: " << actual->cliente->getNombre() << ", Edad: " << actual->cliente->getEdad() << ", Tipo: " << actual->cliente->getTipo() << endl;
        tempEmbarazada.pop();
    }

    cout << "Clientes normales:" << endl;
    queue<NodoCliente*> tempNormal = colaNormal;
    while (!tempNormal.empty()) {
        NodoCliente* actual = tempNormal.front();
        cout << "Nombre: " << actual->cliente->getNombre() << ", Edad: " << actual->cliente->getEdad() << ", Tipo: " << actual->cliente->getTipo() << endl;
        tempNormal.pop();
    }
}