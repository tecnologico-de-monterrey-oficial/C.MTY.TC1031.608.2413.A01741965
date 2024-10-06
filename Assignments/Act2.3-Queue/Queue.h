#ifndef Queue_h
#define Queue_h

#include "Node.h"
#include <iostream>



template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();
    T dequeue();
    void enqueue(T data);
    T front();
    void print();
    bool empty();
};

template <class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
bool Queue<T>::empty() {
    return head == nullptr;
}

template <class T>
void Queue<T>::enqueue(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (empty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

using namespace std;
template <class T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw out_of_range("La lista está vacía");
    } else {
        Node<T>* aux = head;
        T data = aux->data;
        head = head->next;
        delete aux;
        return data;
    }
}

template <class T>
T Queue<T>::front() {
    if (empty()) {
        throw out_of_range("La lista está vacía");
    } else {
        return head->data;
    }
}

template <class T>
void Queue<T>::print() {
    if (empty()) {
        cout << "La lista está vacía";
    } else {
        Node<T>* aux = head;
        while (aux != nullptr) {
            cout << aux->data << " - ";
            aux = aux->next;
        }
        cout << endl;
    }
}

#endif /* Queue_h */
