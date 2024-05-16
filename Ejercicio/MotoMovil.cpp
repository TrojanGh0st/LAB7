#include <iostream>
#include <string>

using namespace std;

// Clase base "Vehículo"
class Vehiculo {
protected:
    string marca;  // Marca del vehículo
    string modelo;  // Modelo del vehículo
    int anioFabri;  // Año de fabricación del vehículo
    double precio;  // Precio del vehículo

public:
    // Constructor de la clase base
    Vehiculo(const string& marca, const string& modelo, int anio, double precio)
        : marca(marca), modelo(modelo), anioFabri(anio), precio(precio) {}

    // Método para mostrar los detalles del vehículo
    void mostrarDetalles() const {
        cout << "Marca: " << marca << "\nModelo: " << modelo 
            << "\nAño de Fabricación: " << anioFabri 
            << "\nPrecio: S/ " << precio << endl;
    }
};

// Clase derivada "Automóvil"
class Automovil : public Vehiculo {
private:
    int numPuertas;  // Número de puertas del automóvil
    string tipoCombustible;  // Tipo de combustible del automóvil

public:
    // Constructor de la clase derivada
    Automovil(const string& marca, const string& modelo, int anio, double precio,
            int numPuertas, const string& tipoCombustible)
        : Vehiculo(marca, modelo, anio, precio), numPuertas(numPuertas), tipoCombustible(tipoCombustible) {}

    // Método para mostrar los detalles del automóvil
    void mostrarDetalles() const {
        Vehiculo::mostrarDetalles(); // Llama al método de la clase base para mostrar detalles comunes
        cout << "Número de Puertas: " << numPuertas 
            << "\nTipo de Combustible: " << tipoCombustible << endl;
    }
};

// Clase derivada "Motocicleta"
class Motocicleta : public Vehiculo {
private:
    int cilindrada;  // Cilindrada de la motocicleta

public:
    // Constructor de la clase derivada
    Motocicleta(const string& marca, const string& modelo, int anio, double precio,
                int cilindrada)
        : Vehiculo(marca, modelo, anio, precio), cilindrada(cilindrada) {}

    // Método para mostrar los detalles de la motocicleta
    void mostrarDetalles() const {
        Vehiculo::mostrarDetalles(); // Llama al método de la clase base para mostrar detalles comunes
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};

// Función principal
int main() {
    // Crear un objeto de tipo Automóvil
    Automovil auto1("Toyota", "Corolla", 2020, 20000, 4, "Gasolina");
    cout << "\tDetalles del Automóvil:" << endl;
    auto1.mostrarDetalles();  // Mostrar detalles del automóvil
    
    cout << endl;

    // Crear un objeto de tipo Motocicleta
    Motocicleta moto1("Yamaha", "MT-07", 2021, 7000, 689);
    cout << "\tDetalles de la Motocicleta:" << endl;
    moto1.mostrarDetalles();  // Mostrar detalles de la motocicleta

    return 0;  // Fin del programa
}
