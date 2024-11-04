#include "Log.h"

struct Node {
    Log data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(const Log& log) {
        Node* newNode = new Node;
        newNode->data = log;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    Node* getHead() {
        return head;
    }
    Node* getTail() {
        return tail;
    }
    void addFirst(const Log& log) {
        Node* newNode = new Node;
        newNode->data = log;
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void removeFirst() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void removeLast() {
        if (tail == nullptr) {
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        size--;
    }
    void remove(Node* node) {
        if (node == nullptr) {
            return;
        }
        if (node == head) {
            removeFirst();
        } else if (node == tail) {
            removeLast();
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
        size--;
    }
    void clear() {
        while (head != nullptr) {
            removeFirst();
        }
        size = 0;
    }
    int getSize() {
        return size;
    }
    ~DoublyLinkedList() {
        clear();
    }

   
    

};