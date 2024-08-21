#include <iostream>
#include <vector>

using namespace std;

template <class T>
int search(vector<T> list, T data) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == data) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> list, int data) {
    int left = 0;
    int right = list.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (list[mid] == data) {
            return mid;
        } else if (list[mid] < data) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}



int main() {
    // Your code goes here
    vector <int> list = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << search(list, 5) << endl;
    
    return 0;
}
