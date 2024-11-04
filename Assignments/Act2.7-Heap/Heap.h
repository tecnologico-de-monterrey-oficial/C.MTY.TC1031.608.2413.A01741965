#ifndef Heap_h
#define Heap_h

#include <vector>
#include <initializer_list>
#include <iostream>
using namespace std;

template <class T>
class Heap {
private:
    vector<T> heap;
    void downSort(int father);
    void swap(int a, int b);
public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    
    // Métodos requeridos
    void push(T data); // agrega un elemento al heap
    T pop(); // elimina y devuelve el elemento con mayor prioridad
    T top(); // devuelve el elemento con mayor prioridad sin eliminarlo
    bool empty(); // verifica si el heap está vacío
    int size(); // devuelve el tamaño del heap
    T remove();
    void print();
    vector<T> heapSort();
    void insert(T data);
};

template <class T>
Heap<T>::Heap() {}

template <class T>
void Heap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::downSort(int father) {
    while (father * 2 + 1 < heap.size()) {
        int son1 = father * 2 + 1;
        int biggest;
        if (father * 2 + 2 < heap.size()) {
            int son2 = father * 2 + 2;
            heap[son1] >= heap[son2] ? biggest = son1 : biggest = son2;
        } else {
            biggest = son1;
        }
        if (heap[biggest] > heap[father]) {
            swap(biggest, father);
            father = biggest;
        } else {
            father = heap.size();
        }
    }
}

template <class T>
Heap<T>::Heap(vector<T> list) {
    heap = list;
    int father = (heap.size() - 1) / 2;
    while (father >= 0) {
        downSort(father);
        father--;
    }
}

template <class T>
Heap<T>::Heap(initializer_list<T> list) {
    heap = list;
    int father = (heap.size() - 1) / 2;
    while (father >= 0) {
        downSort(father);
        father--;
    }
}

template <class T>
T Heap<T>::remove() {
    T aux = heap[0];
    swap(0, heap.size() - 1);
    heap.pop_back();
    downSort(0);
    return aux;
}

template <class T>
vector<T> Heap<T>::heapSort() {
    vector<T> list;
    while (!empty()) {
        T aux = remove();
        list.push_back(aux);
    }
    return list;
}

template <class T>
void Heap<T>::insert(T data) {
    heap.push_back(data);
    int child = heap.size() - 1;
    while (child > 0) {
        int father = (child - 1) / 2;
        if (heap[child] > heap[father]) {
            swap(child, father);
            child = father;
        } else {
            break;
        }
    }
}


template <class T>
void Heap<T>::push(T data) {
    insert(data);
}

template <class T>
T Heap<T>::pop() {
    return remove();
}

template <class T>
T Heap<T>::top() {
    if (!empty()) {
        return heap[0];
    }
    throw runtime_error("Heap is empty"); // Lanza una excepción si el heap está vacío
}

template <class T>
bool Heap<T>::empty() {
    return heap.size() == 0;
}

template <class T>
int Heap<T>::size() {
    return heap.size();
}

template <class T>
void Heap<T>::print() {
    for (auto el : heap) {
        cout << el << " ";
    }
    cout << endl;
}

#endif /* Heap_h */
