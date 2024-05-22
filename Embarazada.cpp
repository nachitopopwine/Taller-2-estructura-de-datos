#include "Embarazada.h"

Embarazada::Embarazada(string nombre, int edad) : Cliente(nombre, edad) {}

string Embarazada::getTipo() {
    return "Embarazada";
}