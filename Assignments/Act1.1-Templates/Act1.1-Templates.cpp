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
    // Constructor por default
    List();
    // inserta un elemento al final de la lista
    void add(T data);
    //remueve el último elemento de la lista
    void removeLast();
    // obtiene el elemento en una posición específica
    T getData(int pos);
    // regresa el tamaño de la lista con el valor del atributo size
    int getSize();
    // regresa el valor máximo en la lista
    T getMax();
    // print
    void print();
};



//Definir los métodos

// constructor por default
template <class T>
List<T>::List() {
    cout << "Constructor por default" << endl;
    // inicializa el tamaño de la lista en 0
    size = 0;
}

// agrega un elemento a la lista
template <class T>
void List<T>::add(T data) {
    // agrega data al final de la lista
    list.push_back(data);
    // incrementa el tamaño de la lista
    size++;
}

//remueve el último elemnto de la lista
template <class T>
void List<T>::removeLast() {
    if (size > 0) {
        // Despliega el último elemento de la lista
        cout << list[size - 1] << endl;
        // Elimina el último elemento
        list.pop_back();
        // Decrementa el tamaño de la lista
        size--;
    } else {
        // Si la lista está vacía
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

template <class T>
T List<T>::getData(int pos) {
    if (pos >= 0 && pos < size) {
        return list[pos];
    } else {
        return T(); // Devuelve el valor por defecto de T
    }
}

// regresa el tamaño de la lista con size
template <class T>
int List<T>::getSize() {
    return size;
}

template <class T>
T List<T>::getMax() {
    if (size == 0) {
        return T(); // Devuelve el valor por defecto de T si la lista está vacía
    }
    T maxElement = list[0];
    for (int i = 1; i < size; ++i) {
        if (list[i] > maxElement) {
            maxElement = list[i];
        }
    }
    return maxElement;
}

// imprime la lista
template <class T>
void List<T>::print() {
    for (auto el : list) {
        cout << el << " - ";
    }
    cout << endl;
}




#endif /* List_h */