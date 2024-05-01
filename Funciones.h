#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <unordered_map>
#include <vector>
#include <queue>
#include "Producto.h"
#include "Cliente.h"

void cargarProductosDesdeArchivo(std::string nombreArchivo, std::unordered_map<std::string, std::vector<Producto>>& bodega);
void guardarProductosEnArchivo(std::string nombreArchivo, std::unordered_map<std::string, std::vector<Producto>>& bodega);
void gestionarClientes();
void gestionarVentas(std::unordered_map<std::string, std::vector<Producto>>& bodega, std::queue<Cliente>& filaClientes);

#endif /* FUNCIONES_H */