#include <iostream>
#include <string>
#include "DLL.h"
#include "Log.h"
#include "Stack.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>

Node* partition(Node* low, Node* high) {
    Log pivot = high->data;
    Node* i = low->prev;
    
    for (Node* j = low; j != high; j = j->next) {
        if (j->data.getKey() <= pivot.getKey()) {
            i = (i == nullptr) ? low : i->next;
            swap(i->data, j->data);
        }
    }
    
    i = (i == nullptr) ? low : i->next;
    swap(i->data, high->data);
    return i;
}


void quicksort(DoublyLinkedList& A) {
    Node* low = A.getHead();
    Node* high = A.getTail();
    quicksortAux(A, low, high);
}

void quicksortAux(DoublyLinkedList& A, Node* low, Node* high) {
    Stack stack;
    stack.push(low->data);
    stack.push(high->data);

    while (!stack.empty()) {
        high = stack.pop();
        low = stack.pop();

        if (low < high) {
            Node* pivot = partition(low, high);

            stack.push(low);
                stack.push(pivot->prev);

            stack.push(pivot->next);
            stack.push(high);
        }
    }
}


int main() {
    ifstream file("log602-2.txt");
    DoublyLinkedList dll;
    string month, day, year, time, ip, message, word;
    while (getline(file, message)) {
        stringstream ss(message);
        ss >> month >> day >> year >> time >> ip >> message;
        while (ss >> word) {
            message += " " + word;
        }
        Log log(year, month, day, time, ip, message);
        dll.insert(log);
    }
    file.close();
    std::cout << "Doubly Linked List Menu" << std::endl;
    std::cout << "1. Ordenar por fecha y hora (Quicksort)" << std::endl;
    std::cout << "2. Busqueda de logs por dia" << std::endl;
    std::cout << "3. Logs descendientes (Stack)" << std::endl;
    std::cout << "0. Salir" << std::endl;
    int option;
    cin >> option;
    switch (option) {
        case 1: {
            quicksort(dll.getHead(), dll.getTail());
            //create file with sorted logs in Logs/sortedlogs.txt
            ofstream outFile("sortedLogs.txt");
            Node* current = dll.getHead();
            while (current != nullptr) {
                Log log = current->data;
                outFile << log.convertFromMonth(log.month) << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " " << log.issue << endl;
                current = current->next;
            }
            outFile.close();
            break;
        }
        case 2: {
            std::cout << "Ingrese el dia a buscar YYYY MM DD" << std::endl;
            string year, month, day;
            cin >> year >> month >> day;
            Node* current = dll.getHead();
            cout << "Logs del dia " << year << " " << month << " " << day << endl;
            while (current != nullptr) {
                Log log = current->data;
                if (log.year == year && log.month == month && log.day == day) {
                    std::cout << log.year << " " << log.convertFromMonth(log.month) << " " << log.day << " " << log.time << " " << log.ip << " " << log.issue << std::endl;
                }
                current = current->next;
            }
        }
        case 3: {
            Stack stack;
            ofstream outFile("stacklogs.txt");
            quicksort(dll.getHead(), dll.getTail());
            Node* current = dll.getHead();
            while (current != nullptr) {
                stack.push(current->data);
                current = current->next;
            }
            while (!stack.empty()) {
                Log log = stack.pop();
                outFile << log.year << " " << log.convertFromMonth(log.month) << " " << log.day << " " << log.time << " " << log.ip << " " << log.issue << endl;
            }
            outFile.close();
            stack.print();

            break;
        }
        case 0: {
            break;
        }
        
        
    }
    return 0;
}