#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    std::string tipo;

public:
    Cliente(std::string tipo);
    std::string getTipo() const;
};

#endif /* CLIENTE_H */