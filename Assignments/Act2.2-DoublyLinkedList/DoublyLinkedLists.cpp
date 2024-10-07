#include "DoublyLinkedLists.h"
#include <iostream>




int main() {
    DoublyLinkedList<int> dll;
    int option;
        std::cout << "Creacion de lista doblemente enlazada" << std::endl;
        std::cout << "1. Ingresar datos manualmente" << std::endl;
        std::cout << "2. Generar datos aleatorios" << std::endl;
        std::cin >> option;
        switch (option) {
            case 1: {
                int data;
                std::cout << "Ingrese los datos que desea agregar, -1 para terminar" << std::endl;
                while (true) {
                    std::cin >> data;
                    if (data == -1) {
                        break;
                    }
                    dll.addLast(data);
                }
                break;
            }
            case 2: {
                int size;
                std::cout << "Ingrese el tamaño de la lista" << std::endl;
                std::cin >> size;
                for (int i = 0; i < size; i++) {
                    dll.addFirst(rand()%100);
                }
                break;
            }
        }
        

    do {
        std::cout << "Menu de lista doblemente enlazada" << std::endl;
        std::cout << "1. Agregar al inicio" << std::endl;
        std::cout << "2. Agregar al final" << std::endl;
        std::cout << "3. Agregar en una posicion" << std::endl;
        std::cout << "4. Borrar elemento dado" << std::endl;
        std::cout << "5. Borrar por posicion" << std::endl;
        std::cout << "6. Obten el dato de una posicion" << std::endl;
        std::cout << "7. Actualizar dato de una posicion" << std::endl;
        std::cout << "8. Actualizar dato por valor" << std::endl;
        std::cout << "9. Buscar dato" << std::endl;
        std::cout << "10. Imprimir lista" << std::endl;
        std::cout << "11. Limpiar lista" << std::endl;
        std::cout << "12. Ordenar lista" << std::endl;
        std::cout << "13. Duplicar lista" << std::endl;
        std::cout << "14. Quitar duplicados" << std::endl;
        std::cout << "15. Prueba de sobrecarga de operadores" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cin >> option;
        switch (option) {
            case 1: {
                int data;
                std::cout << "Ingrese el dato que desea agregar" << std::endl;
                std::cin >> data;
                dll.addFirst(data);
                break;
            }
            case 2: {
                int data;
                std::cout << "Ingrese el dato que desea agregar" << std::endl;
                std::cin >> data;
                dll.addLast(data);
                break;
            }
            case 3: {
                int data, index;
                std::cout << "Ingrese el dato que desea agregar" << std::endl;
                std::cin >> data;
                std::cout << "Ingrese la posicion en la que desea agregar" << std::endl;
                std::cin >> index;
                dll.addAt(data, index);
                break;
            }
            case 4: {
                int data;
                std::cout << "Ingrese el dato que desea borrar" << std::endl;
                std::cin >> data;
                dll.deleteData(data);
                break;
            }
            case 5: {
                int index;
                std::cout << "Ingrese la posicion que desea borrar" << std::endl;
                std::cin >> index;
                dll.deleteAt(index);
                break;
            }
            case 6: {
                int index;
                std::cout << "Ingrese la posicion que desea obtener" << std::endl;
                std::cin >> index;
                std::cout << "El dato en la posicion " << index << " es " << dll.getData(index) << std::endl;
                break;
            }
            case 7: {
                int data, index;
                std::cout << "Ingrese la posicion que desea actualizar" << std::endl;
                std::cin >> index;
                std::cout << "Ingrese el nuevo dato" << std::endl;
                std::cin >> data;
            
                dll.updateAt(data, index);
                break;
            }
            case 8: {
                int data, old;
                std::cout << "Ingrese el valor que desea actualizar" << std::endl;
                std::cin >> old;
                std::cout << "Ingrese el nuevo dato" << std::endl;
                std::cin >> data;
                dll.updateGivenValue(old, data);
                break;
            }
            case 9: {
                int data;
                std::cout << "Ingrese el dato que desea buscar" << std::endl;
                std::cin >> data;
                dll.findData(data);
                break;
            }
            case 10: {
                dll.print();
                break;
            }
            case 11: {
                dll.clear();
                break;
            }
            case 12: {
                dll.quicksort(dll.getHead(), dll.getTail());
                break;
            }
            case 13: {
                dll.duplicate();
                break;
            }
            case 14: {
                dll.quicksort(dll.getHead(), dll.getTail());
                dll.removeDuplicates();
                break;
            }
            case 15: {
                int index;
                std::cout << "Ingrese la posicion que desea obtener []" << std::endl;
                std::cin >> index;
                std::cout << "El dato en la posicion " << index << " es " << dll[index] << std::endl;
                std::cout << "Lista creada" << std::endl;
                std::cout << "Datos en la lista: " << std::endl;
                dll.print();
                std::cout << "Prueba de sobre carga de operadores =" << std::endl;
                DoublyLinkedList<int> dll2;
                dll2 = dll;
                std::cout << "Datos en la lista 2: " << std::endl;
                dll2.print();
                break;
            }
        }
    } while (option != 0);
    return 0;
}
