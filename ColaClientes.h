#pragma once
#include <iostream>
#include <queue>
#include <string>
#include "Cliente.h"

using namespace std;

class ColaClientes {
private:
    queue<Cliente*> colaNormal;
    queue<Cliente*> colaTerceraEdad;
    queue<Cliente*> colaDiscapacitado;
    queue<Cliente*> colaEmbarazada;
    int numeroAtencion;

public:
    ColaClientes();
    ~ColaClientes();
    void agregarCliente(Cliente* cliente);
    Cliente* llamarSiguienteCliente();
    int getSiguienteNumero();
};