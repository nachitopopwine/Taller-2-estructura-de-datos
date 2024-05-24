#include "Cliente.h"

Cliente::Cliente(string nombre, int edad)
    : nombre(nombre), edad(edad), numeroAtencion(0), tipo("Normal") {}

string Cliente::getNombre() {
    return nombre;
}

int Cliente::getEdad() {
    return edad;
}

int Cliente::getNumeroAtencion() {
    return numeroAtencion;
}

string Cliente::getTipo() {
    return tipo;
}

void Cliente::setNumeroAtencion(int numero) {
    numeroAtencion = numero;
}

ClienteNormal::ClienteNormal(string nombre, int edad)
    : Cliente(nombre, edad) {}

ClientePreferencial::ClientePreferencial(string nombre, int edad, string tipo)
    : Cliente(nombre, edad) {
    this->tipo = tipo;
}

ClienteTerceraEdad::ClienteTerceraEdad(string nombre, int edad)
    : ClientePreferencial(nombre, edad, "TerceraEdad") {}

ClienteDiscapacitado::ClienteDiscapacitado(string nombre, int edad)
    : ClientePreferencial(nombre, edad, "Discapacitado") {}

ClienteEmbarazada::ClienteEmbarazada(string nombre, int edad)
    : ClientePreferencial(nombre, edad, "Embarazada") {}