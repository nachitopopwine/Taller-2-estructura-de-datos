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
    const Producto* buscarPorId(const std::string& id) const;
    void eliminarPorId(const std::string& id);
    void cargarDesdeArchivo(const std::string& filename);

private:
    NodoProducto* table[TABLE_SIZE];
    int hashFunction(const std::string& key) const;
};
