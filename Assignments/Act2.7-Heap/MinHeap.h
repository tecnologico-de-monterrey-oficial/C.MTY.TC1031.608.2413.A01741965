#ifndef MinHeap_h
#define MinHeap_h

#include <vector>
#include <initializer_list>
#include <iostream>
using namespace std;

template <class T>
class MinHeap {
private:
    vector<T> heap;
    void downSort(int father);
    void swap(int a, int b);
public:
    MinHeap();
    MinHeap(vector<T> list);
    MinHeap(initializer_list<T> list);
    
  
    void push(T data); 
    T pop();           
    T top();          
    bool empty();      
    int size();       
    T remove();
    void print();
    vector<T> heapSort();
    void insert(T data);
};

template <class T>
MinHeap<T>::MinHeap() {}

template <class T>
void MinHeap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void MinHeap<T>::downSort(int father) {
    while (father * 2 + 1 < heap.size()) {
        int son1 = father * 2 + 1;
        int smallest;
        if (father * 2 + 2 < heap.size()) {
            int son2 = father * 2 + 2;
            heap[son1] <= heap[son2] ? smallest = son1 : smallest = son2;
        } else {
            smallest = son1;
        }
        if (heap[smallest] < heap[father]) {
            swap(smallest, father);
            father = smallest;
        } else {
            break;
        }
    }
}

template <class T>
MinHeap<T>::MinHeap(vector<T> list) {
    heap = list;
    int father = (heap.size() - 1) / 2;
    while (father >= 0) {
        downSort(father);
        father--;
    }
}

template <class T>
MinHeap<T>::MinHeap(initializer_list<T> list) {
    heap = list;
    int father = (heap.size() - 1) / 2;
    while (father >= 0) {
        downSort(father);
        father--;
    }
}

template <class T>
T MinHeap<T>::remove() {
    T aux = heap[0];
    swap(0, heap.size() - 1);
    heap.pop_back();
    downSort(0);
    return aux;
}

template <class T>
vector<T> MinHeap<T>::heapSort() {
    vector<T> list;
    while (!empty()) {
        T aux = remove();
        list.push_back(aux);
    }
    return list;
}

template <class T>
void MinHeap<T>::insert(T data) {
    heap.push_back(data);
    int child = heap.size() - 1;
    while (child > 0) {
        int father = (child - 1) / 2;
        if (heap[child] < heap[father]) {
            swap(child, father);
            child = father;
        } else {
            break;
        }
    }
}


template <class T>
void MinHeap<T>::push(T data) {
    insert(data);
}

template <class T>
T MinHeap<T>::pop() {
    return remove();
}

template <class T>
T MinHeap<T>::top() {
    if (!empty()) {
        return heap[0];
    }
    throw runtime_error("Heap vacía"); 
}

template <class T>
bool MinHeap<T>::empty() {
    return heap.size() == 0;
}

template <class T>
int MinHeap<T>::size() {
    return heap.size();
}

template <class T>
void MinHeap<T>::print() {
    for (auto el : heap) {
        cout << el << " ";
    }
    cout << endl;
}

#endif /* MinHeap_h */
