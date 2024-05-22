#include "Cliente.h"

Cliente::Cliente(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

string Cliente::getNombre() {
    return this->nombre;
}

int Cliente::getEdad() {
    return this->edad;
}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setEdad(int edad) {
    this->edad = edad;
}

Cliente::~Cliente() {}