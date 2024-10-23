#include <iostream>
using namespace std;

#include "BST.h"

void printMenu() {
    cout << "1. Insertar datos alazar" << endl;
    cout << "2. Insertar dato" << endl;
    cout << "3. Borra dato" << endl;
    cout << "4. Imprimir en orden" << endl;
    cout << "5. Imprimir en preorden" << endl;
    cout << "6. Imprimir en postorden" << endl;
    cout << "7. Imprimir en niveles" << endl;
    cout << "8. Imprimir BST" << endl;
    cout << "9. Que altura tiene el arbol" << endl;
    cout << "10. Que profundidad tiene un dato" << endl;
    cout << "11. Ancestros de un dato" << endl;
    cout << "12. Buscar dato" << endl;
    cout << "0. Salir" << endl;
}

int main() {

    BST<int> bst;
    int option = -1;
    while (option != 0){
        printMenu();
        cin >> option;
        switch (option) {
            case 1: {
                bst.insert(50);
                bst.insert(30);
                bst.insert(20);
                bst.insert(40);
                bst.insert(70);
                bst.insert(60);
                bst.insert(80);
                break;
            }
            case 2: {
                int data;
                cout << "Ingrese el dato a insertar: ";
                cin >> data;
                bst.insert(data);
                break;
            }
            case 3: {
                int data;
                cout << "Ingrese el dato a borrar: ";
                cin >> data;
                bst.remove(data);
                break;
            }
            case 4: {
                bst.visit(2);
                break;
            }
            case 5: {
                bst.visit(1);
            }
            case 6: {
                bst.visit(3);
                break;
            }
            case 7: {
                bst.visit(4);
                break;
            }
            case 8: {
                bst.print();
                break;
            }
            case 9: {
                cout << "La altura del arbol es: " << bst.height() << endl;
                break;
            }
            case 10: {
                int data;
                cout << "Ingrese el dato a buscar: ";
                cin >> data;
                data == bst.getRoot()->data ? cout << "El dato es la raiz" << endl : cout << "La profundidad del dato es: " << bst.whatLevelAmI(data)+1 << endl;
                break;
               
            }
            case 11: {
                int data;
                cout << "Ingrese el dato a buscar: ";
                cin >> data;
                bst.ancestors(data);
                break;
            }
            case 12: {
                int data;
                cout << "Ingrese el dato a buscar: ";
                cin >> data;
                bst.find(data) ? cout << "Si se encontro el dato" << endl : cout << "No se encontro el dato" << endl;
                break;
            }
        }
    }


    
    return 0;
}


