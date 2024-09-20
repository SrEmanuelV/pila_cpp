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
bool eliminarElemento(Nodo*& pila, int n);
void mostrarPila(Nodo* pila); // Función para mostrar la pila sin modificarla

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

    // Mostrar los elementos de la pila sin vaciarla
    cout << "\nMostrando los elementos de la pila: ";
    mostrarPila(pila);
    cout << "."; // Punto al final de la salida

    // Opción para eliminar un elemento
    cout << "\n\nDesea eliminar un elemento de la pila? (s/n): ";
    cin >> rpt;
    if (rpt == 's' || rpt == 'S') {
        cout << "Digite el numero a eliminar: ";
        cin >> dato;
        if (eliminarElemento(pila, dato)) {
            cout << "\tElemento " << dato << " eliminado de la pila correctamente." << endl;
        } else {
            cout << "\tElemento " << dato << " no encontrado en la pila." << endl;
        }
    }

    // Mostrar la pila después de la eliminación
    cout << "\nMostrando los elementos de la pila después de la eliminación: ";
    mostrarPila(pila);
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

bool eliminarElemento(Nodo*& pila, int n) {
    Nodo* actual = pila;
    Nodo* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->dato == n) {
            if (anterior == nullptr) {
                // Eliminar el primer nodo
                pila = actual->siguiente;
            } else {
                // Eliminar un nodo del medio o final
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            return true; // Elemento eliminado
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false; // Elemento no encontrado
}

void mostrarPila(Nodo* pila) {
    Nodo* actual = pila;
    bool first = true; // Variable para manejar la impresión del separador
    while (actual != nullptr) {
        if (!first) {
            cout << " , ";
        }
        cout << actual->dato;
        actual = actual->siguiente;
        first = false; // Después de imprimir el primer elemento, cambia a false
    }
}
