#include "BST.h"
#include <iostream>

int main() {
    BST<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    int dato = 9;
    if (tree.find(dato)) {
        std::cout << "El dato " << dato << " se encuentra en el árbol.\n";
    } else {
        std::cout << "El dato " << dato << " no se encuentra en el árbol.\n";
    }
    return 0;
}