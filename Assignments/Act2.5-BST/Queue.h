#ifndef Queue_h
#define Queue_h

#include "TNode.h"
#include <iostream>



template <class T>
class Queue {
private:
    TNode<T>* head;
    TNode<T>* tail;
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
    TNode<T>* newNode = new TNode<T>(data);
    if (empty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->right = newNode;
        tail = newNode;
    }
}

using namespace std;
template <class T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw out_of_range("La lista está vacía");
    } else {
        TNode<T>* aux = head;
        T data = aux->data;
        head = head->right;
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
    TNode<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->right;
    }
    cout << endl;
}

#endif