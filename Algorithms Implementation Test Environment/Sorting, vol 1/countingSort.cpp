#include <iostream>
#include <vector>
#include <algorithm>
     
using namespace std;
     
void countingSort(vector<int>& arr) {
     
    auto maxNumber = *max_element(arr.begin(), arr.end());
     
    int size = arr.size();
     
    vector<int> countingArray(maxNumber + 1);
     
    for (int i = 0; i < maxNumber + 1; i++) {
        countingArray[i] = 0;
    }
     
    for (int i = 0; i < size; i++) {
        countingArray[arr[i]]++;
    }
     
    int index = 0;
    for (int i = 0; i <= maxNumber; i++) {
       
        for (int j = 0; j < countingArray[i]; j++) {
     
            arr[index++] = i;
        }
     
    }
}
     
int main() {
    
    vector<int> v = { 1, 5, 5, 6, 1, 1, 4, 19, 0 };
    countingSort(v);
     
    for (int i = 0; i < 9; i++) {
        cout << v[i] << ", ";        
    }

    return 0;
}
