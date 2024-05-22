#include "Discapacitado.h"

Discapacitado::Discapacitado(string nombre, int edad) : Cliente(nombre, edad) {}

string Discapacitado::getTipo() {
    return "Discapacitado";
}