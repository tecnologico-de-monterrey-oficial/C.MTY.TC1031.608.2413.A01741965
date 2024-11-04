#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
#include "Heap.h"
#include "MinHeap.h"

void printMenu() {
    cout << "Menu de opciones" << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Eliminar elemento con mayor prioridad" << endl;
    cout << "3. Mostrar elemento con mayor prioridad" << endl;
    cout << "4. Verificar si el heap está vacío" << endl;
    cout << "5. Mostrar tamaño del heap" << endl;
    cout << "6. Imprimir heap" << endl;
    cout << "7. HeapSort" << endl;
    cout << "8. Insertar 10 elementos aleatorios" << endl;
    cout << "9. Salir" << endl;
}

int main() {
    int opcion;
    cout << "Seleccione el tipo de heap que desea utilizar" << endl;
    cout << "1. Heap" << endl;
    cout << "2. MinHeap" << endl;
    cin >> opcion;
    if (opcion != 1 && opcion != 2) {
        cout << "Opción inválida" << endl;
        return 0;
    }
    if (opcion == 1 ) {
        Heap<int> heap;
        int opcion;
        do {
            printMenu();
            cin >> opcion;
            switch (opcion) {
                case 1: {
                    int data;
                    cout << "Ingrese el dato a insertar" << endl;
                    cin >> data;
                    heap.push(data);
                }
                break;
                case 2: {
                    if (!heap.empty()) {
                        cout << "Elemento eliminado: " << heap.pop() << endl;
                    } else {
                        cout << "El heap está vacío" << endl;
                    }
                }
                break;
                case 4: {
                    cout << "El heap está vacío: " << heap.empty() << endl;
                }
                break;
                case 5: {
                    cout << "Tamaño del heap: " << heap.size() << endl;
                }
                break;
                case 6: {
                    heap.print();
                }
                break;
                case 7: {
                    vector<int> sorted = heap.heapSort();
                    for (auto el : sorted) {
                        cout << el << " ";
                    }
                    cout << endl;
                }
                break;
                case 8: {
                    for (int i = 0; i < 10; i++) {
                        heap.push(rand() % 100);
                    }
                }
                break;
                case 9: {
                    cout << "Saliendo..." << endl;
                }
                default: {
                    cout << "Opción inválida" << endl;
                }
                break;
            }
        } while (opcion != 9);
    } else {
        MinHeap<int> heap;
        int opcion;
        do {
            printMenu();
            cin >> opcion;
            switch (opcion) {
                case 1: {
                    int data;
                    cout << "Ingrese el dato a insertar" << endl;
                    cin >> data;
                    heap.push(data);
                }
                break;
                case 2: {
                    if (!heap.empty()) {
                        cout << "Elemento eliminado: " << heap.pop() << endl;
                    } else {
                        cout << "El heap está vacío" << endl;
                    }
                }
                break;
                case 3: {
                    if (!heap.empty()) {
                        cout << "Elemento con mayor prioridad: " << heap.top() << endl;
                    } else {
                        cout << "El heap está vacío" << endl;
                    }
                }
                break;
                case 4: {
                    cout << "El heap está vacío: " << heap.empty() << endl;
                }
                break;
                case 5: {
                    cout << "Tamaño del heap: " << heap.size() << endl;
                }  
                break;
                case 6: {
                    heap.print();
                }
                break;
                case 7: {
                    vector<int> sorted = heap.heapSort();
                    for (auto el : sorted) {
                        cout << el << " ";
                    }
                    cout << endl;
                }
                break;
                case 8: {
                    for (int i = 0; i < 10; i++) {
                        heap.push(rand() % 100);
                    }
                }
                break;
                case 9: {
                    cout << "Saliendo..." << endl;
                }
                default: {
                    cout << "Opción inválida" << endl;
                }
            }
        } while (opcion != 9);
    }
    return 0;
}


