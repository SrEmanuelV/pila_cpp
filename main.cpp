#include <iostream>
#include <limits> // Para std::numeric_limits
using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Prototipos de funciones
void agregarPila(Nodo*& pila, int n);
bool sacarPila(Nodo*& pila, int& n);

int main() {
    Nodo* pila = nullptr;  // Inicializamos la pila
    int dato;
    char rpt;

    do { // Pedimos todos los elementos de la pila
        cout << "Digite un numero: ";
        while (!(cin >> dato)) { // Verificamos la entrada
            cout << "Entrada inválida. Por favor, digite un número entero: ";
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar entrada incorrecta
        }

        agregarPila(pila, dato);

        cout << "\nDesea agregar otro numero a pila (s/n): ";
        cin >> rpt;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
    } while (rpt == 's' || rpt == 'S');

    cout << "\nMostrando los elementos de la pila: ";
    bool first = true; // Variable para manejar la impresión del separador
    while (sacarPila(pila, dato)) {
        if (!first) {
            cout << " , ";
        }
        cout << dato;
        first = false; // Después de imprimir el primer elemento, cambia a false
    }
    cout << "."; // Punto al final de la salida

    return 0;
}

void agregarPila(Nodo*& pila, int n) {
    Nodo* nuevo_nodo = new Nodo{n, pila}; // Uso de inicialización de lista
    pila = nuevo_nodo;

    cout << "\tElemento " << n << " agregado a PILA correctamente" << endl;
}

bool sacarPila(Nodo*& pila, int& n) {
    if (pila == nullptr) {
        return false; // Retorna false si la pila está vacía
    }
    Nodo* aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
    return true; // Retorna true al sacar un elemento
}
