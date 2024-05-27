#include <fstream> 
#include <iostream>
#include <string>
#include "NodoProducto.h"

const int TABLE_SIZE = 10;

class HashMap {
public:
    HashMap();
    ~HashMap();
    void insert(const Producto& producto);
    void display() const;
    void saveToFile(const std::string& filename) const;
    const Producto *HashMap::buscarPorId(const std::string &id) const;
    void HashMap::eliminarPorId(const std::string &id);
    void HashMap::cargarDesdeArchivo(const std::string &filename);

private:
    NodoProducto* table[TABLE_SIZE];
    int hashFunction(const std::string& key) const;
};

HashMap::HashMap() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

HashMap::~HashMap() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        NodoProducto* entry = table[i];
        while (entry != nullptr) {
            NodoProducto* prev = entry;
            entry = entry->siguiente;
            delete prev;
        }
        table[i] = nullptr;
    }
}

int HashMap::hashFunction(const std::string& key) const {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % TABLE_SIZE;
    }
    return hash;
}
const Producto* HashMap::buscarPorId(const std::string& id) const {
    int hash = hashFunction(id);
    NodoProducto* entry = table[hash];
    while (entry != nullptr) {
        if (entry->producto.getId() == id) {
            return &(entry->producto);
        }
        entry = entry->siguiente;
    }
    return nullptr; // Si no se encuentra el producto con el ID especificado
}
void HashMap::eliminarPorId(const std::string& id) {
    int hash = hashFunction(id);
    NodoProducto* entry = table[hash];
    NodoProducto* prev = nullptr;

    while (entry != nullptr) {
        if (entry->producto.getId() == id) {
            // Si el nodo a eliminar es el primero en la lista
            if (prev == nullptr) {
                table[hash] = entry->siguiente;
            } else {
                prev->siguiente = entry->siguiente;
            }
            delete entry;
            std::cout << "Producto con ID " << id << " eliminado correctamente." << std::endl;
            return;
        }
        prev = entry;
        entry = entry->siguiente;
    }

    std::cout << "No se encontró ningún producto con el ID " << id << "." << std::endl;
}
void HashMap::insert(const Producto& producto) {
    int hash = hashFunction(producto.getId());
    NodoProducto* newNode = new NodoProducto(producto);

    if (table[hash] == nullptr) {
        table[hash] = newNode;
    } else {
        NodoProducto* entry = table[hash];
        while (entry->siguiente != nullptr) {
            entry = entry->siguiente;
        }
        entry->siguiente = newNode;
    }
}

void HashMap::display() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        NodoProducto* entry = table[i];
        if (entry != nullptr) {
            std::cout << "bodega " << i << ":\n";
            while (entry != nullptr) {
                std::cout << "    ID: " << entry->producto.getId() << ", Nombre: " << entry->producto.getNombre() << ", Categoria: " << entry->producto.getCategoria() << ", Subcategoria: " << entry->producto.getSubcategoria() << ", Precio: " << entry->producto.getPrecio() << "\n";
                entry = entry->siguiente;
            }
        }
    }
}
void HashMap::cargarDesdeArchivo(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string linea;
    std::string categoria, subcategoria;

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        
        if (linea.back() == ':') {
            if (linea.find("Categoria:") != std::string::npos) {
                categoria = linea.substr(0, linea.size() - 1);
            } else if (linea.find("Subcategoria:") != std::string::npos) {
                subcategoria = linea.substr(0, linea.size() - 1);
            }
        } else {
            std::string nombre, id;
            double precio;

            size_t first_comma = linea.find(',');
            size_t second_comma = linea.find(',', first_comma + 1);
            size_t third_comma = linea.find(',', second_comma + 1);

            nombre = linea.substr(0, first_comma);
            id = linea.substr(first_comma + 1, second_comma - first_comma - 1);
            precio = std::stod(linea.substr(second_comma + 1, third_comma - second_comma - 1));

            Producto producto(id, nombre, precio, categoria, subcategoria);
            insert(producto);
        }
    }

    file.close();
}

void HashMap::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    
    for (int i = 0; i < TABLE_SIZE; ++i) {
        NodoProducto* entry = table[i];
        while (entry != nullptr) {
            file << entry->producto.getCategoria() << ": \n";
            file << entry->producto.getSubcategoria() << ": \n";
            file << entry->producto.getNombre() << "," 
                 << entry->producto.getId() << "," 
                 << entry->producto.getPrecio() << "\n";
            entry = entry->siguiente;
        }
    }

    file.close();
}