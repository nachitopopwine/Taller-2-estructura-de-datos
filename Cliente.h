#pragma once
#include <iostream>

using namespace std;

class Cliente {
protected:
    string nombre;
    int edad;

public:
    Cliente(string nombre, int edad);
    string getNombre();
    int getEdad();
    void setNombre(string nombre);
    void setEdad(int edad);
    virtual string getTipo() = 0;
    virtual ~Cliente();
};