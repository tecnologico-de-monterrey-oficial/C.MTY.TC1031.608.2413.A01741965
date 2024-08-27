#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool busquedaSecuencial(const vector<int>& lista, int numero) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i] == numero) {
            return true;
        }
    }
    return false;
}

bool busquedaBinaria(const vector<int>& lista, int numero) {
    int inicio = 0;
    int fin = lista.size() - 1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (lista[medio] == numero) {
            return true;
        }
        else if (lista[medio] < numero) {
            inicio = medio + 1;
        }
        else {
            fin = medio - 1;
        }
    }

    return false;
}

int main() {
    vector<int> numeros(10000);
    for (int i = 0; i < numeros.size(); i++) {
        numeros[i] = rand() % 1000000 + 1;
    }
    sort(numeros.begin(), numeros.end());
    

    int numero;
    do {
        cout << "Ingrese un número entre 1 y 1,000,000 (0 para salir): ";
        cin >> numero;

        if (numero != 0) {
            auto start = high_resolution_clock::now();
            bool encontradoSecuencial = busquedaSecuencial(numeros, numero);
            auto end = high_resolution_clock::now();
            auto durationSecuencial = duration_cast<microseconds>(end - start);

            start = high_resolution_clock::now();
            bool encontradoBinaria = busquedaBinaria(numeros, numero);
            end = high_resolution_clock::now();
            auto durationBinaria = duration_cast<microseconds>(end - start);

            cout << "Búsqueda secuencial: ";
            if (encontradoSecuencial) {
                cout << "El número se encuentra en la lista." << endl;
            }
            else {
                cout << "El número no se encuentra en la lista." << endl;
            }
            cout << "Tiempo de búsqueda secuencial: " << durationSecuencial.count() << " microsegundos" << endl;

            cout << "Búsqueda binaria: ";
            if (encontradoBinaria) {
                cout << "El número se encuentra en la lista." << endl;
            }
            else {
                cout << "El número no se encuentra en la lista." << endl;
            }
            cout << "Tiempo de búsqueda binaria: " << durationBinaria.count() << " microsegundos" << endl;
        }
    } while (numero != 0);

    return 0;
}