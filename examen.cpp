#include <iostream>
#include <array>
using namespace std;

const size_t TAMAÑO{20}; // Tamaño del array

// Función de partición para Quick Sort
int partition(array<int, TAMAÑO>& arr, int low, int high) {
    int pivot = arr[high];  // Selecciona el último elemento como pivote
    int i = low - 1;        // Índice del menor elemento
    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor que el pivote
        if (arr[j] < pivot) {
            i++;            // Incrementa el índice del menor elemento
            swap(arr[i], arr[j]); // Intercambia arr[i] y arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Coloca el pivote en la posición correcta
    return i + 1;                // Devuelve el índice de partición
}

// Función de Quick Sort
void quickSort(array<int, TAMAÑO>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Encuentra el índice de partición
        quickSort(arr, low, pi - 1);        // Ordena recursivamente el lado izquierdo
        quickSort(arr, pi + 1, high);       // Ordena recursivamente el lado derecho
    }
}

int main() {
    array<int, TAMAÑO> a{};  // Array para almacenar los valores ingresados
    size_t subindice{0};      // Índice para el próximo valor no duplicado
    bool duplicado{false};    // Variable para marcar si un número es duplicado

    cout << "Ingrese 20 enteros entre 10 y 100:\n";
    unsigned int i{0};  // Contador para el número de valores ingresados

    // Captura de valores sin duplicados
    while (i < a.size()) {
        duplicado = false;  // Reinicia la variable duplicado para cada iteración
        int valor{0};
        cin >> valor;       // Lee el valor ingresado por el usuario

        // Verifica si el valor está en el rango permitido
        if (valor >= 10 && valor <= 100) {
            // Verifica si el valor ya está en el array
            for (size_t j{0}; j < subindice; ++j) {
                if (valor == a[j]) {   // Si el valor ya existe, marca como duplicado
                    duplicado = true;
                    break;             // Sale del bucle de verificación
                }
            }

            // Si no es duplicado, lo agrega al array
            if (!duplicado) {
                a[subindice++] = valor; // Almacena el valor en la posición subindice
            } else {
                cout << "Número duplicado.\n"; // Mensaje en caso de duplicado
            }

            ++i; // Incrementa el contador de valores ingresados
        } else {
            cout << "Número inválido.\n"; // Mensaje si el valor está fuera del rango
        }
    }
    
    cout << "\nLos valores no duplicados, son:\n";
    for (size_t indice{0}; indice < subindice; ++indice) {
        cout << a[indice] << " "; // Muestra los valores no duplicados
    }

    // Ordenar los valores no duplicados con Quick Sort
    quickSort(a, 0, subindice - 1);

    cout << "\nLos valores no duplicados, ordenados, son:\n";
    for (size_t indice{0}; indice < subindice; ++indice) {
        cout << a[indice] << " "; // Muestra los valores ordenados
    }

    cout << endl;
}
