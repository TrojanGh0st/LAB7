#include <iostream>
#include <string>

using namespace std;

// Clase base Cliente
class Cliente {
protected:
    string nombre;
    string direccion;
    string numeroTarjeta;

public:
    // Constructor
    Cliente(string _nombre, string _direccion, string _numeroTarjeta) : nombre(_nombre), direccion(_direccion), numeroTarjeta(_numeroTarjeta) {}

    // Método para mostrar la información del cliente
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Numero de tarjeta: " << numeroTarjeta << endl;
    }

    // Destructor virtual para permitir la destrucción polimórfica
    virtual ~Cliente() {
        cout << "Destructor de Cliente llamado." << endl;
    }

protected:
    // Método protegido para encriptar la información antes de ser almacenada
    void encriptarInformacion() {
        // Implementación de la encriptación (puedes personalizarla según necesites)
        cout << "La información ha sido encriptada." << endl;
        // Aquí podrías incluir la lógica para encriptar la información antes de almacenarla
    }
};

// Clase derivada ClienteSeguro
class ClienteSeguro : public Cliente {
public:
    // Constructor que llama al constructor de la clase base y inicializa los atributos adicionales
    ClienteSeguro(string _nombre, string _direccion, string _numeroTarjeta) : Cliente(_nombre, _direccion, _numeroTarjeta) {
        // Inicializar los atributos adicionales si es necesario
    }

    // Destructor que libera los recursos utilizados por la clase derivada y por la clase base
    ~ClienteSeguro() {
        // Aquí podrías liberar los recursos adicionales si es necesario
        cout << "Destructor de ClienteSeguro llamado." << endl;
    }

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

// Clase derivada con herencia pública
class ClientePublico : public Cliente {
public:
    ClientePublico(string _nombre, string _direccion, string _numeroTarjeta) : Cliente(_nombre, _direccion, _numeroTarjeta) {}

    void mostrarInformacion() {
        cout << "Nombre público: " << nombre << endl; // Acceso a miembro público de la clase base
    }
};

// Clase derivada con herencia protegida
class ClienteProtegido : protected Cliente {
public:
    ClienteProtegido(string _nombre, string _direccion, string _numeroTarjeta) : Cliente(_nombre, _direccion, _numeroTarjeta) {}

    void mostrarInformacion() {
        cout << "Nombre protegido: " << nombre << endl; // Acceso a miembro protegido de la clase base
    }
};

// Clase derivada con herencia privada
class ClientePrivado : private Cliente {
public:
    ClientePrivado(string _nombre, string _direccion, string _numeroTarjeta) : Cliente(_nombre, _direccion, _numeroTarjeta) {}

    void mostrarInformacion() {
        cout << "Nombre privado: " << nombre << endl; // Acceso a miembro privado de la clase base
    }
};

int main() {
    // Ejemplo de uso de ClienteSeguro
    ClienteSeguro cliente("Nyldersito FF", "Calle XD", "1234-5678-9012-3456");
    cliente.mostrarInformacion();
    cliente.procesarPago();

    // Ejemplo de uso de ClientePublico
    ClientePublico clientePublico("Nyldersito Publico", "Direccion Publica", "1234");
    cout << "Herencia pública:" << endl;
    clientePublico.mostrarInformacion();
    cout << endl;

    // Ejemplo de uso de ClienteProtegido
    ClienteProtegido clienteProtegido("Nyldersito Protegido", "Direccion Protegida", "5678");
    cout << "Herencia protegida:" << endl;
    clienteProtegido.mostrarInformacion();
    cout << endl;

    // Ejemplo de uso de ClientePrivado
    ClientePrivado clientePrivado("Nyldersito Privado", "Direccion Privada", "9012");
    cout << "Herencia privada:" << endl;
    clientePrivado.mostrarInformacion();
    cout << endl;

    return 0;
}
