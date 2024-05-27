#include <iostream>
#include "ColaClientes.h"
#include "Producto.h"
#include "Hashmap.cpp"

using namespace std;

HashMap Hashmap;
ColaClientes colaClientes;

void mostrarMenu();
void entregarNumero();
void llamarCliente();
void gestionarBodega();
void cargarDatos();
void guardarDatos();

int main() {
    cargarDatos(); 

    int opcion = 0;
    while (opcion != 4) {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                entregarNumero();
                break;
            case 2:
                llamarCliente();
                break;
            case 3:
                gestionarBodega();
                break;
            case 4:
                guardarDatos(); 
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, intente nuevamente." << endl;
        }
    }

    return 0;
}

void mostrarMenu() {
    cout << "-------- MENU PRINCIPAL --------" << endl;
    cout << "1. Entrega de números" << endl;
    cout << "2. Llamar a cliente" << endl;
    cout << "3. Gestionar bodega" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void entregarNumero() {
    string nombre, tipo;
    int edad;

    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << "Ingrese la edad del cliente: ";
    cin >> edad;
    cout << "Ingrese el tipo de cliente (Normal/TerceraEdad/Discapacitado/Embarazada): ";
    cin >> tipo;

    Cliente* nuevoCliente;
    if (tipo == "Normal") {
        nuevoCliente = new ClienteNormal(nombre, edad);
    } else if (tipo == "TerceraEdad") {
        nuevoCliente = new ClienteTerceraEdad(nombre, edad);
    } else if (tipo == "Discapacitado") {
        nuevoCliente = new ClienteDiscapacitado(nombre, edad);
    } else if (tipo == "Embarazada") {
        nuevoCliente = new ClienteEmbarazada(nombre, edad);
    } else {
        cout << "Tipo de cliente no válido." << endl;
        return;
    }

    colaClientes.agregarCliente(nuevoCliente);

    cout << "Número de atención entregado al cliente " << nombre << " (" << tipo << ")" << endl;
}

void llamarCliente() {
    Cliente* cliente = colaClientes.llamarSiguienteCliente();
    if (cliente == nullptr) {
        cout << "No hay clientes en la cola." << endl;
        return;
    }

    string productoID;
    cout << "Cliente " << cliente->getNombre() << " está siendo atendido." << endl;
    cout << "Ingrese el ID del producto solicitado: ";
    cin >> productoID;

//buscar producto 
    const Producto* producto = Hashmap.buscarPorId(productoID);


    if (producto != nullptr) {
        cout << "Producto encontrado: " << producto->getNombre() << " - " << producto->getPrecio() << " $" << endl;
        cout << "¿Desea realizar la compra? (si/no): ";
        string respuesta;
        cin >> respuesta;

        if (respuesta == "si") {
            Hashmap.eliminarPorId(productoID);
            cout << "Compra realizada con éxito." << endl;
            
        } else {
            cout << "Compra cancelada." << endl;
        }
    } else {
        cout << "Producto no encontrado." << endl;
    }
}

void gestionarBodega() {
    int opcion = 0;
    while (opcion != 3) {
        cout << "-------- GESTION DE BODEGA --------" << endl;
        cout << "1. Agregar producto a bodega" << endl;
        cout << "2. Generar boletas de ventas" << endl;
        cout << "3. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string categoria, subcategoria, nombre;
                string id;
                double precio;

                cout << "Ingrese la categoría del producto: ";
                cin >> categoria;
                cout << "Ingrese la subcategoría del producto: ";
                cin >> subcategoria;
                cout << "Ingrese el ID del producto: ";
                cin >> id;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;
                cout << "Ingrese el precio del producto: ";
                cin >> precio;

                Producto* nuevoProducto = new Producto(id, nombre, precio, categoria, subcategoria);
                Hashmap.insert(*nuevoProducto);

                
                cout << "Producto agregado a la bodega con éxito." << endl;
                break;
            }
            case 2:
                //FALTA HACER LA ENTREGA DE BOLETAS, "IDEA: ( CADA VENTAS SE GUARDE LA PERSONAS CON EL PRODUCTO EN ALGUNA LISTA O ALGO Y QUE ACA SOLO IMPRIMA TODO ESO )
                break;
            case 3:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, intente nuevamente." << endl;
        }
    }
}

void cargarDatos() {
    Hashmap.cargarDesdeArchivo("bodega.txt");
}

void guardarDatos() {
    Hashmap.saveToFile("bodega.txt");
    
}