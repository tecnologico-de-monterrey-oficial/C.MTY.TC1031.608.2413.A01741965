#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "DNode.h"
#include <iostream>

template <class T>
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
    int size;
public:
    DoublyLinkedList();
    void print();
    void printReverse();
    void addFirst(T data);
    void addLast(T data);
    void addAt(T data, int index);
    void deleteData(T data);
    void deleteAt(int index);
    void findData(T data);
    void updateGivenValue(T data, int index);
    void updateAt(T data, int index);
    void duplicate();
    void removeDuplicates();
    void clear();
    DNode <T>* getHead();
    DNode <T>* getTail();

    T getData(int index);
    T& operator[](int index);
    int getSize();
    bool empty();
    void swap(T &a, T &b);
    void quicksort(DNode<T>* low, DNode<T>* high);
    DNode<T>* partition(DNode<T>* low, DNode<T>* high);
    

     
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
void DoublyLinkedList<T>::print() {
    if (size == 0) {
        std::cout << "La Lista esta vacía" << std::endl;
    } else {
        DNode<T>* aux = head;
        while (aux != nullptr) {
            std::cout << aux->data << " - ";
            aux = aux->next;
        }
        std::cout << std::endl;
    }
}

template <class T>
void DoublyLinkedList<T>::printReverse() {
    if (size == 0) {
        std::cout << "La Lista esta vacía" << std::endl;
    } else {
        DNode<T>* aux = tail;
        while (aux != nullptr) {
            std::cout << aux->data << " - ";
            aux = aux->prev;
        }
        std::cout << std::endl;
    }
}

template <class T>
bool DoublyLinkedList<T>::empty() {
    return head == nullptr;
}

template <class T>
void DoublyLinkedList<T>::addFirst(T data) {
    if (empty()) {
        head = new DNode<T>(data);
        tail = head;
    } else {
        head = new DNode<T>(data, head, nullptr);
        head->next->prev = head;
    }
    size++;    
}

template <class T>
void DoublyLinkedList<T>::addLast(T data) {
    if (empty()) {
        tail = new DNode<T>(data);
        head = tail;
    } else {
        tail = new DNode<T>(data, nullptr, tail);
        tail->prev->next = tail;
    }
    size++;    
}

template <class T>
T DoublyLinkedList<T>::getData(int index) {
    if (index >=0 && index < size) {
        if (index <= (size-1)/2) {
            int auxIndex = 0;
            DNode<T>* aux = head;
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }
            return aux->data;
        } else {
            int auxIndex = size-1;
            DNode<T>* aux = tail;
            while (auxIndex > index) {
                aux = aux->prev;
                auxIndex--;
            }
            return aux->data;
        }
    } else {
        throw std::out_of_range("Índice es incorrecto");
    }
}

template <class T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index >=0 && index < size) {
        if (index <= (size-1)/2) {
            int auxIndex = 0;
            DNode<T>* aux = head;
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }
            return aux->data;
        } else {
            int auxIndex = size-1;
            DNode<T>* aux = tail;
            while (auxIndex > index) {
                aux = aux->prev;
                auxIndex--;
            }
            return aux->data;
        }
    } else {
        throw std::out_of_range("Índice es incorrecto");
    }
}

template <class T>
int DoublyLinkedList<T>::getSize() {
    return size;
}

template <class T>
void DoublyLinkedList<T>::addAt(T data, int index) {
    if (index >= 0 && index <= size) {
        if (index == 0) {
            addFirst(data);
        } else if (index == size) {
            addLast(data);
        } else {
            if (index <= (size-1)/2) {
                int auxIndex = 0;
                DNode<T>* aux = head;
                while (auxIndex < index) {
                    aux = aux->next;
                    auxIndex++;
                }
                aux->next = new DNode<T>(data, aux->next, aux);
                aux->next->next->prev = aux->next;
            } else {
                int auxIndex = size-1;
                DNode<T>* aux = tail;
                while (auxIndex > index) {
                    aux = aux->prev;
                    auxIndex--;
                }
                aux->prev = new DNode<T>(data, aux, aux->prev);
                aux->prev->prev->next = aux->prev;
            }
            size++;
        }
    } else {
        throw std::out_of_range("Índice es incorrecto");
    }
}

template <class T>
void DoublyLinkedList<T>::deleteData(T data) {
    DNode<T>* aux = head;
    while (aux != nullptr) {
        if (aux->data == data) {
            if (aux == head) {
                head = head->next;
                delete aux;
                size--;
                return;
            } else if (aux == tail) {
                tail = tail->prev;
                delete aux;
                size--;
                return;
            } else {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                delete aux;
                size--;
                return;
            }
        }
        aux = aux->next;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        if (index == 0) {
            DNode<T>* aux = head;
            head = head->next;
            delete aux;
            size--;
        } else if (index == size-1) {
            DNode<T>* aux = tail;
            tail = tail->prev;
            delete aux;
            size--;
        } else {
            if (index <= (size-1)/2) {
                int auxIndex = 0;
                DNode<T>* aux = head;
                while (auxIndex < index) {
                    aux = aux->next;
                    auxIndex++;
                }
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                delete aux;
                size--;
            } else {
                int auxIndex = size-1;
                DNode<T>* aux = tail;
                while (auxIndex > index) {
                    aux = aux->prev;
                    auxIndex--;
                }
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                delete aux;
                size--;
            }
        }
    } else {
        throw std::out_of_range("Índice es incorrecto");
    }
}

template <class T>
void DoublyLinkedList<T>::findData(T data) {
    DNode<T>* aux = head;
    int index = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            std::cout << "El dato " << data << " se encuentra en el índice " << index << std::endl;
            return;
        }
        aux = aux->next;
        index++;
    }
    std::cout << "El dato " << data << " no se encuentra en la lista" << std::endl;
}

template <class T>
void DoublyLinkedList<T>::updateGivenValue(T data, int index) {
    DNode<T>* aux = head;
    int auxIndex = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            aux->data = index;
        }
        aux = aux->next;
        auxIndex++;
    }
}

template <class T>
void DoublyLinkedList<T>::updateAt(T data, int index) {
    if (index >= 0 && index < size) {
        if (index == 0) {
            head->data = data;
        } else if (index == size-1) {
            tail->data = data;
        } else {
            if (index <= (size-1)/2) {
                int auxIndex = 0;
                DNode<T>* aux = head;
                while (auxIndex < index) {
                    aux = aux->next;
                    auxIndex++;
                }
                aux->data = data;
            } else {
                int auxIndex = size-1;
                DNode<T>* aux = tail;
                while (auxIndex > index) {
                    aux = aux->prev;
                    auxIndex--;
                }
                aux->data = data;
            }
        }
    } else {
        throw std::out_of_range("Índice es incorrecto");
    }
}

template <class T>
void DoublyLinkedList<T>::duplicate() {
    DNode<T>* aux = head;
    while (aux != nullptr) {
        DNode<T>* newNode = new DNode<T>(aux->data);
        newNode->next = aux->next;
        aux->next = newNode;
        newNode->prev = aux;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        } else {
            tail = newNode;
        }
        aux = newNode->next;
    }
    size = size*2;
}

template <class T>
void DoublyLinkedList<T>::removeDuplicates() {
    DNode<T>* aux = head;
    while (aux != nullptr) {
        DNode<T>* aux2 = aux->next;
        while (aux2 != nullptr) {
            if (aux->data == aux2->data) {
                if (aux2 == tail) {
                    tail = tail->prev;
                    delete aux2;
                    size--;
                    break;
                } else {
                    aux2->prev->next = aux2->next;
                    aux2->next->prev = aux2->prev;
                    DNode<T>* aux3 = aux2;
                    aux2 = aux2->next;
                    delete aux3;
                    size--;
                }
            } else {
                aux2 = aux2->next;
            }
        }
        aux = aux->next;
    }
}

template <class T>
void DoublyLinkedList<T>::clear() {
    DNode<T>* aux = head;
    while (aux != nullptr) {
        head = head->next;
        delete aux;
        aux = head;
    }
    size = 0;
}

template <class T>
DNode<T>* DoublyLinkedList<T>::getHead() {
    return head;
}

template <class T>
DNode<T>* DoublyLinkedList<T>::getTail() {
    return tail;
}

//quicksort
template <class T>
void DoublyLinkedList<T>::quicksort(DNode<T>* low, DNode<T>* high) {
    if (low == nullptr || high == nullptr || low == high || low->prev == high) {
        return;
    }
    DNode<T>* pivot = partition(low, high);
    quicksort(low, pivot->prev);
    quicksort(pivot->next, high);
}

template <class T>
DNode<T>* DoublyLinkedList<T>::partition(DNode<T>* low, DNode<T>* high) {
    T pivot = high->data;
    DNode<T>* i = low->prev;
    for (DNode<T>* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i->data, high->data);
    return i;
}

template <class T>
void DoublyLinkedList<T>::swap(T &a, T &b) {
    T aux = a;
    a = b;
    b = aux;
}


#endif 
