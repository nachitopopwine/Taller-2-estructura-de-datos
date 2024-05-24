#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente {
protected:
    string nombre;
    int edad;
    int numeroAtencion;
    string tipo;

public:
    Cliente(string nombre, int edad);
    virtual ~Cliente() = default;
    string getNombre();
    int getEdad();
    int getNumeroAtencion();
    string getTipo();
    void setNumeroAtencion(int numero);
};

class ClienteNormal : public Cliente {
public:
    ClienteNormal(string nombre, int edad);
};

class ClientePreferencial : public Cliente {
public:
    ClientePreferencial(string nombre, int edad, string tipo);
};

class ClienteTerceraEdad : public ClientePreferencial {
public:
    ClienteTerceraEdad(string nombre, int edad);
};

class ClienteDiscapacitado : public ClientePreferencial {
public:
    ClienteDiscapacitado(string nombre, int edad);
};

class ClienteEmbarazada : public ClientePreferencial {
public:
    ClienteEmbarazada(string nombre, int edad);
};