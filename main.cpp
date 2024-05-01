
// para primero enviar el main al compilador se pone en la terminal 
// g++ -o main main.cpp
// despues cuando se envia se pone en la terminal 
// ./main
// y ahi ejecuta el codigo

#include <iostream>
#include <queue>
#include <unordered_map>
#include "Producto.h"
#include "Cliente.h"
#include "Funciones.h"

int main() {
    // Inicialización de variables y estructuras de datos
    std::unordered_map<std::string, std::vector<Producto>> bodega;
    std::queue<Cliente> filaClientes;

    // Cargar productos desde archivo al inicio del programa
    cargarProductosDesdeArchivo("bodega.txt", bodega);

    // Loop principal del programa
    while (/*condición de salida del programa*/true) {
        // Mostrar menú de opciones al usuario y gestionar selección
        int opcion;
        std::cout << "----- Menú Principal -----" << std::endl;
        std::cout << "1. Gestionar clientes" << std::endl;
        std::cout << "2. Gestionar ventas" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarClientes();
                break;
            case 2:
                gestionarVentas(bodega, filaClientes);
                break;
            case 3:
                // Guardar productos en archivo al salir del programa
                guardarProductosEnArchivo("bodega.txt", bodega);
                // Terminar el programa
                return 0;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}