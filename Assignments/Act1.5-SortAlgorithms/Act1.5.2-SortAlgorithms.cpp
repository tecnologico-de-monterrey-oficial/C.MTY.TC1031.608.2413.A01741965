//Swap and search Algorithms Oscar Cardenas Valdez A01741965
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>



using namespace std;
using namespace std::chrono;




vector<int> generarLista(int tam) {
    vector<int> lista(tam);
    for (int i = 0; i < tam; i++) {
        lista[i] = rand() % 100;  // Genera números entre 0 y 99
    }
    return lista;
}





// Swap Sort
void swapSort(vector<int> &arr, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            comparaciones++;
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                intercambios++;
            }
        }
    }
}



// Bubble Sort
void bubbleSort(vector<int> &arr, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int> &arr, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            comparaciones++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            intercambios++;
        }
    }
}

// Insertion Sort
void insertionSort(vector<int> &arr, int &comparaciones, int &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        comparaciones++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            intercambios++;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Shell Sort
void shellSort(vector<int> &arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void mostrarVector(const vector<int> &arr) {
    for (const int &num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));  
    int tam;
    vector<int> lista;

    int opcion, comparaciones, intercambios;
    do {
        cout << "Menú de opciones:\n";
        cout << "1. Crear lista de datos\n";
        cout << "2. Ordenar con Swap Sort\n";
        cout << "3. Ordenar con Bubble Sort\n";
        cout << "4. Ordenar con Selection Sort\n";
        cout << "5. Ordenar con Insertion Sort\n";
        cout << "6. Ordenar con Merge Sort\n";
        cout << "7. Ordenar con Quick Sort\n";
        cout << "8. Ordenar con Shell Sort\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Ingrese el tamaño de la lista: ";
            cin >> tam;
            lista = generarLista(tam);
            cout << "Lista generada: ";
            mostrarVector(lista);
        } else if (opcion >= 2 && opcion <= 8 && lista.size() > 0) {
            vector<int> listaCopia = lista;  
            auto start = high_resolution_clock::now();
            
            switch (opcion) {
                case 2:
                    swapSort(listaCopia, comparaciones, intercambios);
                    cout << "Ordenada con Swap Sort: ";
                    cout << "\nComparaciones: " << comparaciones;
                    cout << "\nIntercambios: " << intercambios << endl;
                    break;
                case 3:
                    bubbleSort(listaCopia, comparaciones, intercambios);
                    cout << "Ordenada con Bubble Sort: ";
                    cout << "\nComparaciones: " << comparaciones;
                    cout << "\nIntercambios: " << intercambios << endl;
                    break;
                case 4:
                    selectionSort(listaCopia, comparaciones, intercambios);
                    cout << "Ordenada con Selection Sort: ";
                    cout << "\nComparaciones: " << comparaciones;
                    cout << "\nIntercambios: " << intercambios << endl;
                    break;
                case 5:
                    insertionSort(listaCopia, comparaciones, intercambios);
                    cout << "Ordenada con Insertion Sort: ";
                    cout << "\nComparaciones: " << comparaciones;
                    cout << "\nIntercambios: " << intercambios << endl;
                    break;
                case 6:
                    mergeSort(listaCopia, 0, listaCopia.size() - 1);
                    cout << "Ordenada con Merge Sort: ";
                    break;
                case 7:
                    quickSort(listaCopia, 0, listaCopia.size() - 1);
                    cout << "Ordenada con Quick Sort: ";
                    break;
                case 8:
                    shellSort(listaCopia);
                    cout << "Ordenada con Shell Sort: ";
                    break;
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Tiempo de ejecución: " << duration.count() << " microsegundos\n";
            //Mostrar Vector?
            cout << "¿Desea mostrar el vector ordenado? (s/n): ";
            char mostrar;
            cin >> mostrar;
            if (mostrar == 's' || mostrar == 'S') {
                mostrarVector(listaCopia);
            }
        } else if (lista.size() == 0 && opcion != 9) {
            cout << "Primero debe crear una lista de datos.\n";
        }
    } while (opcion != 9);

    return 0;
}
