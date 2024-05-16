#include <iostream>
#include <string>

using namespace std;

// Clase base "Persona"
class Persona {
protected:
    string nombre;       // Nombre de la persona
    int edad;            // Edad de la persona
    double salario;      // Salario de la persona
    string email;        // Dirección de correo electrónico (protected para acceso en clases derivadas)

public:
    // Constructor de la clase base
    Persona(const string& nombre, int edad, double salario, const string& email)
        : nombre(nombre), edad(edad), salario(salario), email(email) {}

    // Método para mostrar los detalles de la persona
    void mostrarDetalles() const {
        cout << "Nombre: " << nombre << "\nEdad: " << edad 
            << "\nSalario: $" << salario << endl;
    }
};

// Clase derivada "Empleado"
class Empleado : public Persona {
public:
    // Constructor de la clase derivada
    Empleado(const string& nombre, int edad, double salario, const string& email)
        : Persona(nombre, edad, salario, email) {}

    // Método para mostrar los detalles del empleado, incluyendo el correo electrónico
    void mostrarDetalles() const {
        Persona::mostrarDetalles(); // Llama al método de la clase base
        cout << "Email: " << email << endl; // Acceso al email (protected en la clase base)
    }
};

// Clase derivada "Cliente"
class Cliente : public Persona {
public:
    // Constructor de la clase derivada
    Cliente(const string& nombre, int edad, double salario, const string& email)
        : Persona(nombre, edad, salario, email) {}

    // Método para mostrar los detalles del cliente, incluyendo el correo electrónico
    void mostrarDetalles() const {
        Persona::mostrarDetalles(); // Llama al método de la clase base
        cout << "Email: " << email << endl; // Acceso al email (protected en la clase base)
    }
};

// Función principal
int main() {
    // Crear un objeto de tipo Empleado
    Empleado empleado1("Nylderzzz", 30, 50000, "bynylder@gemail.com");
    cout << "\tDetalles del Empleado:" << endl;
    empleado1.mostrarDetalles();  // Mostrar detalles del empleado

    cout << endl;

    // Crear un objeto de tipo Cliente
    Cliente cliente1("Miguelito CD", 25, 50000, "bymiguelon@gemail.com");
    cout << "\tDetalles del Cliente:" << endl;
    cliente1.mostrarDetalles();  // Mostrar detalles del cliente

    return 0;  // Fin del programa
}
