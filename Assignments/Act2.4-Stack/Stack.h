#ifndef Stack_h
#define Stack_h

#include "Node.h"
#include <iostream>



template <class T>
class Stack {
private:
    Node<T>* head;
public:
    Stack();
    T pop();
    void push(T data);
    T top();
    void print();
    bool empty();
};;

template <class T>
Stack<T>::Stack() {
    head = nullptr;
}

template <class T>
bool Stack<T>::empty() {
    return head == nullptr;
}

template <class T>
void Stack<T>::push(T data) {
    head = new Node<T>(data, head);
}

using namespace std;
template <class T>
T Stack<T>::pop() {
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
T Stack<T>::top() {
    if (empty()) {
        throw out_of_range("La lista está vacía");
    } else {
        return head->data;
    }
} 

template <class T>
void Stack<T>::print() {
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







#endif /* Stack_h */