#include <iostream>
#include <vector>
using namespace std;

vector<int> swapSort(vector<int> list, int n) {
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                swaps++;
            }
        }
    }
    return list;
}

int main() {
    vector<int> list = {9, 12, 15, 2, 7, 3, 6, 8, 1, 4};
    vector<int> sortedList = swapSort(list, list.size());
    
    cout << "Sorted List: ";
    for (int i = 0; i < sortedList.size(); i++) {
        cout << sortedList[i] << " ";
    }
    cout << endl;
    
    return 0;
}
