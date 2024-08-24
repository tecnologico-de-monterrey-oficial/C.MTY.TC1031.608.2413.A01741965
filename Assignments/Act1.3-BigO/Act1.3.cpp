#include <iostream>
#include <vector>

using namespace std;

// iterativa  complejidad - O(n)
int sumaImparesIterativa(const vector<int>& vec) {
    int suma = 0;
    for (int num : vec) {
        if (num % 2 != 0) {
            suma += num;
        }
    }
    return suma;
}

// Recursiva complejidad - O(n)
int sumaImparesRecursiva(const vector<int>& vec, size_t i) {
    if (i == vec.size()) {
        return 0;
    }
    if (vec[i] % 2 != 0) {
        return vec[i] + sumaImparesRecursiva(vec, i + 1);
    }
    return sumaImparesRecursiva(vec, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Suma de los impares iterativa: " << sumaImparesIterativa(arr) << endl;
    cout << "Suma de los impares recursiva: " << sumaImparesRecursiva(arr, 0) << endl;
    return 0;
}