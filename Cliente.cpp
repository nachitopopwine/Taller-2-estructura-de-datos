#include "Cliente.h"

Cliente::Cliente(std::string tipo) : tipo(tipo) {}

std::string Cliente::getTipo() const {
    return tipo;
}