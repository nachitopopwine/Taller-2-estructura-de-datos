#include "ColaClientes.h"

ColaClientes::ColaClientes() : numeroAtencion(0) {}

ColaClientes::~ColaClientes() {
    while (!colaNormal.empty()) {
        delete colaNormal.front();
        colaNormal.pop();
    }
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
}

void ColaClientes::agregarCliente(Cliente* cliente) {
    cliente->setNumeroAtencion(++numeroAtencion);
    if (cliente->getTipo() == "Normal") {
        colaNormal.push(cliente);
    } else if (cliente->getTipo() == "TerceraEdad") {
        colaTerceraEdad.push(cliente);
    } else if (cliente->getTipo() == "Discapacitado") {
        colaDiscapacitado.push(cliente);
    } else if (cliente->getTipo() == "Embarazada") {
        colaEmbarazada.push(cliente);
    }
}

Cliente* ColaClientes::llamarSiguienteCliente() {
    if (!colaTerceraEdad.empty()) {
        Cliente* cliente = colaTerceraEdad.front();
        colaTerceraEdad.pop();
        return cliente;
    }
    if (!colaDiscapacitado.empty()) {
        Cliente* cliente = colaDiscapacitado.front();
        colaDiscapacitado.pop();
        return cliente;
    }
    if (!colaEmbarazada.empty()) {
        Cliente* cliente = colaEmbarazada.front();
        colaEmbarazada.pop();
        return cliente;
    }
    if (!colaNormal.empty()) {
        Cliente* cliente = colaNormal.front();
        colaNormal.pop();
        return cliente;
    }
    return nullptr;
}

int ColaClientes::getSiguienteNumero() {
    return numeroAtencion + 1;
}