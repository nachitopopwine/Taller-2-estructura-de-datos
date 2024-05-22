#include "TerceraEdad.h"

TerceraEdad::TerceraEdad(string nombre, int edad) : Cliente(nombre, edad) {}

string TerceraEdad::getTipo() {
    return "TerceraEdad";
}