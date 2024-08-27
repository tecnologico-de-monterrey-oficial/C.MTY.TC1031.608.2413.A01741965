#include <iostream>
#include <vector>
#include <string>
using namespace std;
string findMissingCharacterSecuential(const string& str) {
    int comparisons = 0;
    for (int n = 0; n < str.length() - 1; n += 2) {

        if (str[n] != str[n + 1]) {
            comparisons++;
            return string(1, str[n]) + " " + to_string(comparisons);
        }
        comparisons++;
    }
    return string(1, str[str.length() - 1]) + " " + to_string(comparisons);
}

string findMissingCharacterBinary(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    int comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (str[mid] != str[mid + 1] && str[mid] != str[mid - 1]) {
            comparisons++;
            if (mid == right) {
                comparisons--;
            }
            return string(1, str[mid]) + " " + to_string(comparisons);
            
        }

        if (mid % 2 == 0) {
            if (str[mid] == str[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            comparisons++;
        
        } else {
            if (str[mid] == str[mid - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            comparisons++;
        }

    }

    return "0";
}

int main() {
    int n;
    cout << "How many strings do you want to enter?" << endl;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
    
        cin >> strings[i];
    }

    for (const string& str : strings) {
        string result = findMissingCharacterSecuential(str) + " " + findMissingCharacterBinary(str);
        cout << result << endl;
    }
}
