#include "Bnode.h"
#include <iostream>

class BST {
    private:
        Bnode* root;
        Bnode* insert(Bnode* root, int data);
        void print(Bnode* root);
        void destroy(Bnode* root);
    public:
        BST();
        ~BST();
        void insert(int data);
        void print();
};

void BST::destroy(Bnode* root) {
    if (root == nullptr) {
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root;
}

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    destroy(root);
}

Bnode* BST::insert(Bnode* root, int data) {
    if (root == nullptr) {
        Bnode* newNode = new Bnode;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void BST::insert(int data) {
    root = insert(root, data);
}




void BST::print(Bnode* root) {
    if (root == nullptr) {
        return;
    }
    print(root->left);
    std::cout << root->data << " ";
    print(root->right);
}

void BST::print() {
    print(root);
    std::cout << std::endl;
}

