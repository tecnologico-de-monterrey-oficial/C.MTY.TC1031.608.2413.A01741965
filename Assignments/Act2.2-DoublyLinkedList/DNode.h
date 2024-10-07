#pragma once

template <class T>
struct DNode {
    T data;
    DNode<T>* next;
    DNode<T>* prev;
    DNode(T data);
    DNode(T data, DNode<T>* next, DNode<T>* prev);
};

template <class T>
DNode<T>::DNode(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
DNode<T>::DNode(T data, DNode<T>* next, DNode<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}