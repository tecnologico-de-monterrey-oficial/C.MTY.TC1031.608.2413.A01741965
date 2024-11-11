#pragma once
#include <string>
#include <iostream>
#include "Log.h"

class BSTNode {
public:
    std::string ip;
    int count;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const std::string& ip) : ip(ip), count(1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, const std::string& ip) {
        if (!node) return new BSTNode(ip);

        if (ip < node->ip) {
            node->left = insert(node->left, ip);
        } else if (ip > node->ip) {
            node->right = insert(node->right, ip);
        } else {
            node->count++;
        }
        return node;
    }

    int search(BSTNode* node, const std::string& ip) const {
        if (!node) return 0;
        if (ip == node->ip) return node->count;
        if (ip < node->ip) return search(node->left, ip);
        return search(node->right, ip);
    }

    void clear(BSTNode* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void print(BSTNode* node) const {
        if (node) {
            print(node->left);
            std::cout << node->ip << " - Count: " << node->count << std::endl;
            print(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(const std::string& ip) {
        root = insert(root, ip);
    }

    int search(const std::string& ip) const {
        return search(root, ip);
    }

    bool empty() const {
        return !root;
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    void print() const {
        print(root);
    }

    BSTNode* getRoot() const {
        return root;
    }

   
};
