#pragma once

template <class T>
struct TNode {
    T data;
    TNode<T>* left;
    TNode<T>* right;
    TNode(T data);
    TNode(T data, TNode<T>* left, TNode<T>* right);
};

template <class T>
TNode<T>::TNode(T data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
TNode<T>::TNode(T data, TNode<T>* left, TNode<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}