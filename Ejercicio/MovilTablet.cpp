#include <iostream>
#include <string>

using namespace std;

// Clase base "Móvil"
class Movil {
protected:
    string marca;          // Marca del móvil
    string modelo;         // Modelo del móvil
    string sistemaOperativo;  // Sistema operativo del móvil

public:
    // Constructor de la clase base
    Movil(const string& marca, const string& modelo, const string& sistemaOperativo)
        : marca(marca), modelo(modelo), sistemaOperativo(sistemaOperativo) {
        cout << "Constructor de Movil: " << marca << " " << modelo << " con " << sistemaOperativo << endl;
    }

    // Destructor de la clase base
    virtual ~Movil() {
        cout << "Destructor de Movil: " << marca << " " << modelo << endl;
    }

    // Método para mostrar los detalles del móvil
    void mostrarDetalles() const {
        cout << "Marca: " << marca << "\nModelo: " << modelo 
            << "\nSistema Operativo: " << sistemaOperativo << endl;
    }
};

// Clase derivada "Teléfono"
class Telefono : public Movil {
public:
    // Constructor de la clase derivada
    Telefono(const string& marca, const string& modelo, const string& sistemaOperativo)
        : Movil(marca, modelo, sistemaOperativo) {
        cout << "Constructor de Telefono: " << marca << " " << modelo << endl;
    }

    // Destructor de la clase derivada
    ~Telefono() {
        cout << "Destructor de Telefono: " << marca << " " << modelo << endl;
    }
};

// Clase derivada "Tablet"
class Tablet : public Movil {
public:
    // Constructor de la clase derivada
    Tablet(const string& marca, const string& modelo, const string& sistemaOperativo)
        : Movil(marca, modelo, sistemaOperativo) {
        cout << "Constructor de Tablet: " << marca << " " << modelo << endl;
    }

    // Destructor de la clase derivada
    ~Tablet() {
        cout << "Destructor de Tablet: " << marca << " " << modelo << endl;
    }
};

// Función principal
int main() {
    // Crear un objeto de tipo Telefono
    Telefono telefono1("Apple", "iPhone 13", "iOS");
    cout << "\tDetalles del Teléfono:" << endl;
    telefono1.mostrarDetalles();  // Mostrar detalles del teléfono
    
    cout << endl;

    // Crear un objeto de tipo Tablet
    Tablet tablet1("Samsung", "Galaxy Tab S7", "Android");
    cout << "\tDetalles de la Tablet:" << endl;
    tablet1.mostrarDetalles();  // Mostrar detalles de la tablet

    return 0;  // Fin del programa
}
