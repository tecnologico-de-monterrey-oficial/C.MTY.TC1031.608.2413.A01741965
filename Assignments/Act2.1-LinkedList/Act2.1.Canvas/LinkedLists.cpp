#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;
int main() {




    LinkedList<string> stringList;
    LinkedList<int> intList;
    LinkedList<string> dummyList;
    LinkedList<string> copiedList;
  
    int option = -2;
    int optionA;
    int optionC;
    string stringData;
    int intData;
    string newStringData;
    int newIntData;
    int position;
    bool created = false;

    //Pruebas de la lista
    dummyList.addFirst(" es la");
    dummyList.addLast(" prueba");
    dummyList.addFirst("Esto ");
    dummyList.addLast(" de operadores");
    copiedList = dummyList;
    copiedList.print();
    cout << copiedList[0] << copiedList[1] << copiedList[2] << copiedList[3] << endl;
    while 
    (option != 0) {

        cout << "1. Crear una lista" << endl;
        cout << "2. Agregar un elemento al inicio" << endl;
        cout << "3. Agregar un elemento al final" << endl;
        cout << "4. Agregar en una posición" << endl;
        cout << "5. Eliminar un elemento" << endl;
        cout << "6. Eliminar un elemento por posición" << endl;
        cout << "7. Obtener un elemento por posición" << endl;
        cout << "8. Actualizar un elemento por posición" << endl;
        cout << "9. Actualizar un elemento" << endl;
        cout << "10. Buscar un elemento" << endl;
        cout << "11. Impresión de la lista" << endl;

        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> option;
        while (option < 0 || option > 11) {
            cout << "Opción inválida. Intente de nuevo: ";
            cin >> option;
        }
        while (option != 1 && !created) {
            cout << "Primero debe crear una lista" << endl;
            cout << "Opción: ";
            cin >> option;
        }
        switch (option) {
            case 1:
                cout << "1. Lista de strings" << endl;
                cout << "2. Lista de enteros" << endl;
                cout << "Opción: ";
                cin >> optionA;
                while (optionA < 1 || optionA > 2) {
                    cout << "Opción inválida. Intente de nuevo: ";
                    cin >> option;
                }
                if (optionA == 1) {
                    stringList = LinkedList<string>();
                    cout << "Lista de strings creada" << endl;
                    cout << "Desea agregar elementos default a la lista?" << endl;
                    cout << "1. Sí" << endl;
                    cout << "2. No" << endl;
                    cout << "Opción: ";
                    cin >> optionC;
                    while (optionC < 1 || optionC > 2 ){
                        cout << "Opción inválida. Intente de nuevo: ";
                        cin >> optionC;
                    }
                    if (optionC == 1) {
                        stringList.addFirst("Hola");
                        stringList.addLast("Mundo");
                        stringList.addFirst("Prueba");
                        stringList.addLast("Final");
                        stringList.print();
                    }

                } else {
                    intList = LinkedList<int>();
                    cout << "Lista de enteros creada" << endl;
                    cout << "Desea agregar elementos default a la lista?" << endl;
                    cout << "1. Sí" << endl;
                    cout << "2. No" << endl;
                    cout << "Opción: ";
                    cin >> optionC;
                    while (optionC < 1 || optionC > 2 ){
                        cout << "Opción inválida. Intente de nuevo: ";
                        cin >> optionC;
                    }
                    if (optionC == 1) {
                        intList.addFirst(1);
                        intList.addLast(2);
                        intList.addFirst(3);
                        intList.addLast(4);
                        intList.print();
                    }

                }
                created = true;
                break;
            case 2:
                if (optionA == 1) {
                    cout << "Ingrese el string a agregar: ";
                    cin >> stringData;
                    stringList.addFirst(stringData);
                    stringList.print();
                } else {
                    cout << "Ingrese el entero a agregar: ";
                    cin >> intData;
                    intList.addFirst(intData);
                    intList.print();
                }
                break;
            case 3:
                if (optionA == 1) {
                    cout << "Ingrese el string a agregar: ";
                    cin >> stringData;
                    stringList.addLast(stringData);
                    stringList.print();
                } else {
                    cout << "Ingrese el entero a agregar: ";
                    cin >> intData;
                    intList.addLast(intData);
                    intList.print();
                }
                break;
            case 4:
                if (optionA == 1) {
                    cout << "Ingrese el string a agregar: ";
                    cin >> stringData;
                    cout << "Ingrese la posición: ";
                    cin >> position;
                    stringList.insertAt(position, stringData);
                    stringList.print();
                } else {
                    cout << "Ingrese el entero a agregar: ";
                    cin >> intData;
                    cout << "Ingrese la posición: ";
                    cin >> position;
                    intList.insertAt(position, intData);
                    intList.print();
                }
                break;
            case 5:
                if (optionA == 1) {
                    cout << "Ingrese el string a eliminar: ";
                    cin >> stringData;
                    stringList.deleteThis(stringData);
                    stringList.print();
                } else {
                    cout << "Ingrese el entero a eliminar: ";
                    cin >> intData;
                    intList.deleteThis(intData);
                    intList.print();
                }
                break;
            case 6:
                if (optionA == 1) {
                    cout << "Ingrese la posición a eliminar: ";
                    cin >> position;
                    stringList.deleteAt(position);
                    stringList.print();
                } else {
                    cout << "Ingrese la posición a eliminar: ";
                    cin >> position;
                    intList.deleteAt(position);
                    intList.print();
                }
                break;
            case 7:
                if (optionA == 1) {
                    cout << "Ingrese la posición a obtener: ";
                    cin >> position;
                    cout << stringList.getData(position) << endl;
                } else {
                    cout << "Ingrese la posición a obtener: ";
                    cin >> position;
                    cout << intList.getData(position) << endl;
                }
                break;
            case 8:
                if (optionA == 1) {
                    cout << "Ingrese la posición a actualizar: ";
                    cin >> position;
                    cout << "Ingrese el nuevo string: ";
                    cin >> stringData;
                    stringList.updateAt(position, stringData);
                    stringList.print();
                } else {
                    cout << "Ingrese la posición a actualizar: ";
                    cin >> position;
                    cout << "Ingrese el nuevo entero: ";
                    cin >> intData;
                    intList.updateAt(position, intData);
                    intList.print();
                }
                break;
            case 9:
                if (optionA == 1) {
                    cout << "Ingrese el string a actualizar: ";
                    cin >> stringData;
                    cout << "Ingrese el nuevo string: ";
                    cin >> newStringData;
                    stringList.updateThis(stringData, newStringData);
                    stringList.print();
                } else {
                    cout << "Ingrese el entero a actualizar: ";
                    cin >> intData;
                    cout << "Ingrese el nuevo entero: ";
                    cin >> newIntData;
                    intList.updateThis(intData, newIntData);
                    intList.print();
                }
                break;
            case 10:
                if (optionA == 1) {
                    cout << "Ingrese el string a buscar: ";
                    cin >> stringData;
                    stringList.findData(stringData);
                } else {
                    cout << "Ingrese el entero a buscar: ";
                    cin >> intData;
                    intList.findData(intData);
                }
                break;
            case 11:
                if (optionA == 1) {
                    stringList.print();
                } else {
                    intList.print();
                }
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
        }
    }
    return 0;
}
