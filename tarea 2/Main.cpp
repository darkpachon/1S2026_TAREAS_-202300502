#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <vector>
#include <stdexcept>

using namespace std;

ifstream abrirArchivoInventario(string& rutaUsada) {
    vector<filesystem::path> rutasPosibles = {
        "inventario.inv",
        filesystem::path("..") / "inventario.inv"
    };

    for (const auto& ruta : rutasPosibles) {
        ifstream archivo(ruta);
        if (archivo.is_open()) {
            rutaUsada = filesystem::absolute(ruta).string();
            return archivo;
        }
    }

    throw runtime_error("No se encontró inventario.inv en la carpeta actual ni en la carpeta padre.");
}

void leerArchivo() {
    string rutaUsada;
    ifstream archivo = abrirArchivoInventario(rutaUsada);
    
    string linea;
    cout << "\n--- CONTENIDO DEL ARCHIVO ---\n";
    cout << "Archivo cargado desde: " << rutaUsada << "\n";
    int numLinea = 0;
    
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        
        cout << setw(2) << ++numLinea << ": " << linea << endl;
    }
    
    archivo.close();
    
    if (numLinea == 0) {
        cout << "El archivo está vacío.\n";
    }
}

int main() {
    int opcion;
    
    cout << "Bienvenido al sistema de inventario\n";
    
    do {
        cout << "\nMenu Principal\n";
        cout << "1. Leer archivo inventario.inv e imprimir contenido\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion (1-2): ";
        cin >> opcion;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n'); 
            cout << "Opción no válida. Intente de nuevo.\n";
            continue;
        }
        
        switch (opcion) {
            case 1:
                try {
                    leerArchivo();
                } catch (const exception& e) {
                    cout << "\nError: " << e.what() << endl;
                }
                break;
                
            case 2:
                cout << "Saliendo del programa...\n";
                break;
                
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 2);
    
    return 0;
}