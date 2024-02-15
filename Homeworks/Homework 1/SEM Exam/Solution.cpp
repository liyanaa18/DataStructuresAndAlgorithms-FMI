#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_LETTERS = 26;

bool isUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

int* countOccurrences(const string& str) {
    int* res = new int[26]{}; 

    for (char i : str) {
        if (isUpper(i)) {
            res[i - 'A']++; 
        }
    }

    return res;
}

int partition(vector<char>& arr, int left, int right) {
    int pivot = arr[right]; 
    int index = left - 1; 

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            index++;
            swap(arr[index], arr[j]);
        }
    }
    swap(arr[index + 1], arr[right]);
    return index + 1;
}

void quickSort(vector<char>& arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
    int T;
    cin >> T;
    
    int N, K;
    string record;
    
    for (int i = 0; i < T; i++) {

        cin >> N >> K >> record;

        int* result = countOccurrences(record);

        vector<char> output;

        for (int j = 0; j < MAX_LETTERS; j++) {
            if (result[j] >= K) {
                output.push_back(char('A' + j));
            }
        }

        quickSort(output, 0, output.size() - 1); 

        for (char x : output) {
            cout << x;
        }
        cout << '\n';
        delete[] result; 
    }

    return 0;
}
