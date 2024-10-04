#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
#include <iostream> 
#include <string> 
using namespace std;
template <class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void addFirst(T data);
    void addLast(T data);
    void print();
    bool empty();
    T getData(int index); 
},

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
bool LinkedList<T>::empty() {
    return head == nullptr;
}


template <class T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
    if (empty()) {
        head = new Node<T>(data);
    } else {
        Node<T>* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    }    
    size++;
}

template <class T>
void LinkedList<T>::print() {
    if (empty()) {
        cout << "La lista está vacía";
    } else {
        Node<T>* aux = head;
        while (aux != nullptr) {
            cout << aux->data << " - ";
            aux = aux->next;
        }
    }
    cout << endl;
    
}
template <class T>
T LinkedList<T>::getData(int index) {
    if (index > this->size -1){
        throw out_of_range("Indice incorrecto");
    else {
        int x = 0; 
        Node<T>* node = this->head;
        while (x < indxex) {
            node = node->next; 
            x++;
        }
        return node->data; 
    }
}

#endif 
