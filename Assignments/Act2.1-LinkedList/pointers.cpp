#include <iostream>
using namespace std;

#include "Log.h"
#include "Node.h"

int main() {
    int a = 5;
    cout << "a : " << a << endl;
    cout << "&a: " << &a << endl;
    int *p;
    p = new int(4);
    cout << "p: " << p << endl;
    cout << "&p:" << &p << endl;
    cout << "*P:" << *p << endl;
    int *q;
    cout << "&q:" << &q << endl;
    q = p;
    cout << "q: " << q << endl;
    cout << "*q:" << *q << endl;
    p = &a;
    cout << "p: " << p << endl;
    a = 10;
    cout << "*P:" << *p << endl;
    delete p;
    cout << "a: " << a << endl;

    Log *l;
    cout << "&l:" << &l << endl;
    l = new Log("2024", "Jan", "02", "00:00:00", "10.14.255.50", "error");
    cout << l << endl;
    cout << l->year << endl;

    Node<int>* head;

    head = new Node<int>(5);

    cout << head->data << endl;

    head->next = new Node<int>(10);

    cout << head->data << " " << head->next->data << endl;

    Node<int>* aux = new Node<int>(20);
    head->next->next = new Node(15, aux);

    cout << head->data << " " << head->next->data << " " << head->next->next->data << " " << head->next->next->next->data << endl;
    



    return 0;
}