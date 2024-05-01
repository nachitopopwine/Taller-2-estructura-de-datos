#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string categoria;
    std::string subcategoria;
    float precio;
    int id;

public:
    Producto(std::string cat, std::string subcat, float precio, int id);
    std::string getCategoria() const;
    std::string getSubcategoria() const;
    float getPrecio() const;
    int getId() const;
};

#endif /* PRODUCTO_H */