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

    // Declaración de métodos virtuales
    virtual string encriptarTarjeta() const = 0;
    virtual string encriptarContrasena() const = 0;

public:
    // Constructor de clase
    Cliente(const string& nom, const string& direc, float _saldo, const string& tarjeta, const string& pass)
        : nombre(nom), direccion(direc), saldo(_saldo), numeroTarjeta(tarjeta), contrasena(pass) {}

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

    // Encriptacion de numero de tarjeta con sobreescritura
    string encriptarTarjeta() const override {
        string temp = numeroTarjeta;
        string encriptado = "";

        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '9')
                temp[i] = '0';
            else
                temp[i] += 1;
            encriptado += temp[i];
        }
        return encriptado;
    }

    // Encriptación de contraseña con sobreescritura
    string encriptarContrasena() const override {
        string temp = contrasena;
        string encriptado = "";

        for (int i = 0; i < temp.length(); i++) {
            switch (contrasena[i]) {
                case '9':
                    temp[i] = '0';
                    break;
                case 'z':
                    temp[i] = 'a';
                    break;
                case 'Z':
                    temp[i] = 'A';
                    break;
                default:
                    temp[i] += 1;
                    break;
            }
            encriptado += temp[i];
        }
        return encriptado;
    }

    // Método para mostrar datos encriptados
    void mostrarEncriptacion() const {
        cout << "DATOS ENCRIPTADOS DEL CLIENTE:" << endl;
        cout << "Numero de tarjeta: " << encriptarTarjeta() << endl;
        cout << "Contrasena: " << encriptarContrasena() << endl;
    }

    // Método para verificar autenticidad
    bool autenticar(const string& tarjeta, const string& pass) const {
        return numeroTarjeta == tarjeta && contrasena == pass;
    }
};

int main() {
    // Instancia de clase derivada
    ClienteSeguro cliente("Juan Perez", "Av. Ejercito 1010", 5000.00, "1234567890", "abc123");

    // Muestra los datos originales del cliente
    cout << "DATOS ORIGINALES DEL CLIENTE:" << endl;
    cliente.mostrarDatos();

    // Muestra datos encriptados
    cliente.mostrarEncriptacion();

    // Ingreso de datos por teclado
    string tarjeta, pass;
    cout << "Ingrese numero de tarjeta: ";
    cin >> tarjeta;
    cout << "Ingrese contrasena: ";
    cin >> pass;

    // Verifica la autenticidad
    if (cliente.autenticar(tarjeta, pass)) {
        cout << "Autenticacion exitosa" << endl;
        // Muestra los datos reales del cliente
        cliente.mostrarDatos();
    } else
        cout << "Autenticacion fallida" << endl;

    return 0;
}
