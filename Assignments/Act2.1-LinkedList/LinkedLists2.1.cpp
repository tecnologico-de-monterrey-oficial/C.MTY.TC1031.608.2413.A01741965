#include <iostream>
using namespace std;

#include "LinkedList.h"

int main() {

    LinkedList<int> list;
    list.print();
    list.addFirst(5);
    list.addFirst(3);
    list.addFirst(1);
    list.addLast(7);
    list.addLast(9);
    list.print();
    
    cout << list.getData(0);

    return 0;
}