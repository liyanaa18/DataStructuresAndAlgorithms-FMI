#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> input(N);
    
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    
    vector<int> copyInput = input;
    sort(copyInput.begin(), copyInput.end());
    
    int result = 0;
    
    for(int i = 0; i < N; i++) {
        
        if(input[i] == copyInput[i]) {
            continue;
        }
        
        int j = N - 1; 
        while (j >= 0 && input[j] == copyInput[j]) {
            j--;
        }
        
        result = j - i + 1;
        break;
    }
    
    cout << result;
    
    return 0;
}
