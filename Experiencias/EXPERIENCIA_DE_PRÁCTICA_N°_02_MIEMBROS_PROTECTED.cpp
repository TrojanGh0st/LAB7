#include <iostream>
#include <string>

using namespace std;

// Clase Base Cliente
class Cliente {
protected:
    string nombre;          // Nombre del cliente
    string direccion;       // Dirección del cliente
    float saldo;            // Saldo del cliente
    string numeroTarjeta;   // Número de tarjeta del cliente
    string contrasena;      // Contraseña del cliente

    // Método protegido para encriptar la información antes de ser almacenada
    string encriptar(const string& data) const {
        string encriptado = data; // Realiza una copia de la cadena

        // Algoritmo de encriptación simple: suma 1 al código ASCII de cada carácter
        for (char& c : encriptado) {
            if (c == '9') // Si el carácter es '9', cambia a '0'
                c = '0';
            else
                c += 1; // Suma 1 al código ASCII
        }

        return encriptado;
    }

public:
    // Constructor de clase
    Cliente(const string& nom, const string& direc, float _saldo, const string& tarjeta, const string& pass)
        : nombre(nom), direccion(direc), saldo(_saldo), numeroTarjeta(encriptar(tarjeta)), contrasena(encriptar(pass)) {}

    // Destructor de clase
    virtual ~Cliente() {}

    // Método para mostrar datos auténticos del cliente
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "Numero de tarjeta: " << numeroTarjeta << endl;
        cout << "Contrasena: " << contrasena << endl;
    }
};

class ClienteSeguro : public Cliente {
public:
    // Constructor
    ClienteSeguro(const string& nom, const string& direc, float _saldo, const string& tarjeta, const string& pass)
        : Cliente(nom, direc, _saldo, tarjeta, pass) {}

    // Destructor
    ~ClienteSeguro() {}
};

int main() {
    // Instancia de clase derivada
    ClienteSeguro cliente("Juan Perez", "Av. Ejercito 1010", 5000.00, "1234567890", "abc123");

    // Muestra los datos originales del cliente
    cout << "DATOS ORIGINALES DEL CLIENTE:" << endl;
    cliente.mostrarDatos();

    return 0;
}
