
// para primero enviar el main al compilador se pone en la terminal 
// g++ -o main main.cpp
// despues cuando se envia se pone en la terminal 
// ./main
// y ahi ejecuta el codigo

#include <iostream>
#include "Producto.h"
#include "Cliente.h"


using namespace std;

int main() {
    

    
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
                
                break;
            case 2:
                
                break;
            case 3:
                // Guardar productos en archivo al salir del programa
                
                // Terminar el programa
                return 0;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}