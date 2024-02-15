#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
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

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}
int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, N - 1);
    int temp = K - 1;
    
    int result = arr[temp] - arr[0];
    
    for (int i = 1; i <= N - K; i++) {
        int current = arr[i + temp] - arr[i];
        if(result > current) {
            result = current;
        }
    }

   cout << result;

    return 0;
}