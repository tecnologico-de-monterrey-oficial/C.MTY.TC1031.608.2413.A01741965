#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    Stack<int> stack;
    int option;
    do {
        cout << "Stack Menu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Print" << endl;
        cout << "0. Exit" << endl;
        cin >> option;
        switch (option) {
            case 1: {
                cout << "Ingrese el dato que desea agregar" << endl;
                int data;
                cin >> data;
                stack.push(data);
                break;
            }
            case 2: {
                cout << "El dato eliminado es " << stack.pop() << endl;
                break;
            }
            case 3: {
                cout << "El dato en en Top es " << stack.top() << endl;
                break;
            }
            case 4: {
                stack.print();
                break;
            }
        }
    } while (option != 0);
    return 0;
}