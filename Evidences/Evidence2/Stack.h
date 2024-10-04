#include <iostream>
#include "Log.h""

struct StackNode {
    Log data;
    StackNode* next;
    StackNode(Log data, StackNode* next) : data(data), next(next) {}
};

class Stack {
private:
    StackNode* head;
public:
    Stack();
    void push(Log data);
    Log pop();
    Log top();
    bool empty();
    void print();
};

Stack::Stack() {
    head = nullptr;
}
void Stack::push(Log data) {
    head = new StackNode(data, head);
}
Log Stack::pop() {
    if (empty()) {
        throw out_of_range("Stack is empty");
    }
    StackNode* aux = head;
    Log data = aux->data;
    head = head->next;
    delete aux;
    return data;
}
Log Stack::top() {
    if (empty()) {
        throw out_of_range("Stack is empty");
    }
    return head->data;
}
bool Stack::empty() {
    return head == nullptr;
}
void Stack::print() {
    StackNode* aux = head;
    while (aux != nullptr) {
        cout << aux->data.year << " " << aux->data.month << " " << aux->data.day << " " << aux->data.time << " " << aux->data.ip << " " << aux->data.issue << endl;
        aux = aux->next;
    }
}



