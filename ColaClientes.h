#pragma once
#include <iostream>
#include "NodoCliente.h"
#include <queue>

using namespace std;

class ColaClientes {
private:
    queue<NodoCliente*> colaTerceraEdad;
    queue<NodoCliente*> colaDiscapacitado;
    queue<NodoCliente*> colaEmbarazada;
    queue<NodoCliente*> colaNormal;

public:
    ColaClientes();
    ~ColaClientes();
    void agregarCliente(Cliente* cliente);
    Cliente* llamarSiguienteCliente();
    void mostrarClientes();
};