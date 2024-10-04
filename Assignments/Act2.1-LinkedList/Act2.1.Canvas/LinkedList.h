#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class LinkedList {
private:
    Node<T>* head;
    int size;

    void clear();
    void copyFrom(const LinkedList& other);

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    void addFirst(T data);
    void addLast(T data);
    void print();
    bool empty();
    T getData(int index);
    void insertAt(int index, T data);
    void deleteAt(int index);
    void deleteThis(T data);
    void updateAt(int index, T data);
    void updateThis(T data, T newData);
    void findData(T data);

    T& operator[](int index);
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <class T>
void LinkedList<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* aux = current;
        current = current->next;
        delete aux;
    }
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    head = nullptr;
    size = 0;
    copyFrom(other);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <class T>
void LinkedList<T>::copyFrom(const LinkedList& other) {
    Node<T>* current = other.head;
    while (current != nullptr) {
        addLast(current->data);
        current = current->next;
    }
}

template <class T>
T& LinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Índice incorrecto");
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
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
        cout << "La lista está vacía" << endl;
    } else {
        Node<T>* aux = head;
        while (aux != nullptr) {
            cout << aux->data << " - ";
            aux = aux->next;
        }
        cout << endl;
    }
}

template <class T>
bool LinkedList<T>::empty() {
    return head == nullptr;
}

template <class T>
T LinkedList<T>::getData(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Índice incorrecto");
    } else {
        int x = 0;
        Node<T>* node = head;
        while (x < index) {
            node = node->next;
            x++;
        }
        return node->data;
    }
}

template <class T>
void LinkedList<T>::insertAt(int index, T data) {
    if (index < 0 || index > size) {
        throw out_of_range("Índice incorrecto");
    } else if (index == 0) {
        addFirst(data);
    } else if (index == size) {
        addLast(data);
    } else {
        int x = 0;
        Node<T>* node = head;
        while (x < index - 1) {
            node = node->next;
            x++;
        }
        node->next = new Node<T>(data, node->next);
        size++;
    }
}

template <class T>
void LinkedList<T>::deleteAt(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Índice incorrecto");
    } else if (index == 0) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
    } else {
        int x = 0;
        Node<T>* node = head;
        while (x < index - 1) {
            node = node->next;
            x++;
        }
        Node<T>* aux = node->next;
        node->next = aux->next;
        delete aux;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteThis(T data) {
    if (head == nullptr) return;

    if (head->data == data) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
        return;
    }

    Node<T>* node = head;
    while (node->next != nullptr) {
        if (node->next->data == data) {
            Node<T>* aux = node->next;
            node->next = aux->next;
            delete aux;
            size--;
            return;
        }
        node = node->next;
    }
}

template <class T>
void LinkedList<T>::updateAt(int index, T data) {
    if (index < 0 || index >= size) {
        throw out_of_range("Índice incorrecto");
    } else {
        int x = 0;
        Node<T>* node = head;
        while (x < index) {
            node = node->next;
            x++;
        }
        node->data = data;
    }
}

template <class T>
void LinkedList<T>::updateThis(T data, T newData) {
    Node<T>* node = head;
    while (node != nullptr) {
        if (node->data == data) {
            node->data = newData;
            return;
        }
        node = node->next;
    }
}

template <class T>
void LinkedList<T>::findData(T data) {
    Node<T>* node = head;
    int x = 0;
    while (node != nullptr) {
        if (node->data == data) {
            cout << "El dato se encuentra en la posición " << x << endl;
            return;
        }
        node = node->next;
        x++;
    }
    cout << "El dato no se encuentra en la lista" << endl;
}

#endif 