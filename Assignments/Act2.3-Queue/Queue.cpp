#include "Queue.h"
#include <iostream>

using namespace std;
int main() {
    Queue<int> queue;
    int option;
    do {
        cout << "Queue Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Print" << endl;
        cout << "0. Exit" << endl;
        cin >> option;
        switch (option) {
            case 1: {
                cout << "Ingrese el dato que desea agregar" << endl;
                int data;
                cin >> data;
                queue.enqueue(data);
                break;
            }
            case 2: {
                cout << "El dato eliminado es " << queue.dequeue() << endl;
                break;
            }
            case 3: {
                cout << "El dato en en Front es " << queue.front() << endl;
                break;
            }
            case 4: {
                queue.print();
                break;
            }
        }
    } while (option != 0);
    return 0;
}