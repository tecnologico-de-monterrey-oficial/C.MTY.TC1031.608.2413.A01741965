#ifndef List_h
#define List_h
using namespace std;


#include <vector>

template <class T>
class List {
private:
    vector<T> list;
    int size;
public:
    List();
    void add(T data);
    void removeLast();
    T getData(int pos);
    int getSize();
    T getMax();
    void print();
};




template <class T>
List<T>::List() {
    cout << "Constructor por default" << endl;
    
    size = 0;
}

template <class T>
void List<T>::add(T data) {
    
    list.push_back(data);
    
    size++;
}

template <class T>
void List<T>::removeLast() {
    if (size > 0) {
        
        cout << list[size - 1] << endl;
        
        list.pop_back();
       
        size--;
    } else {
        
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

template <class T>
T List<T>::getData(int pos) {
    if (pos >= 0 && pos < size) {
        return list[pos];
    } else {
        return T(); 
    }
}

template <class T>
int List<T>::getSize() {
    return size;
}

template <class T>
T List<T>::getMax() {
    if (size == 0) {
        return T(); 
    } 

    T maxElement = list[0];
    for (int i = 1; i < size; ++i) {
        if (list[i] > maxElement) {
            maxElement = list[i];
        }
    }
    return maxElement;
}

template <class T>
void List<T>::print() {
    for (auto el : list) {
        cout << el << " - ";
    }
    cout << endl;
}




#endif 