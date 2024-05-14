#include <iostream>
#include <string>

using namespace std;

// Clase base Cliente
class Cliente {
protected:
    string nombre;
    string direccion;
    string numeroTarjeta;

    // Método protegido para encriptar la información antes de ser almacenada
    void encriptarInformacion() {
        // Implementación de la encriptación (puedes personalizarla según necesites)
        cout << "La informacion ha sido encriptada." << endl;
        // Aquí podrías incluir la lógica para encriptar la información antes de almacenarla
    }

public:
    // Constructor
    Cliente(string _nombre, string _direccion, string _numeroTarjeta) : nombre(_nombre), direccion(_direccion), numeroTarjeta(_numeroTarjeta) {}

    // Método para mostrar la información del cliente
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Numero de tarjeta: " << numeroTarjeta << endl;
    }
};

// Clase derivada ClienteSeguro
class ClienteSeguro : public Cliente {
public:
    // Constructor
    ClienteSeguro(string _nombre, string _direccion, string _numeroTarjeta) : Cliente(_nombre, _direccion, _numeroTarjeta) {}

    // Método para verificar la autenticidad del cliente
    bool verificarAutenticidad() {
        // Implementación de la verificación de autenticidad
        // Por simplicidad, aquí solo se devuelve true
        return true;
    }

    // Método para procesar el pago
    void procesarPago() {
        bool autenticado = verificarAutenticidad();
        if (autenticado) {
            encriptarInformacion(); // Encriptar la información antes de almacenarla
            cout << "Cliente autenticado. Procesando pago..." << endl;
            // Aquí iría el código para procesar el pago
        } else {
            cout << "Cliente no autenticado. El pago no puede ser procesado." << endl;
        }
    }
};

int main() {
    ClienteSeguro cliente("Nyldersito FF", "Calle XD", "1234-5678-9012-3456");
    cliente.mostrarInformacion();
    cliente.procesarPago();

    return 0;
}
