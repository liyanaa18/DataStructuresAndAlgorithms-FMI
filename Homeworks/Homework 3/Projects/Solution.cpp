#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, D;
    cin >> N >> D;
    
    vector<int> input(N);
    
    for(int i = 0; i < N; i++) {
        cin >> input[i]; 
    }
    
    sort(input.begin(), input.end()); 
    int counter = 0;
    
    for(int i = 0; i < N; i++) {
        int x = input[i] + D; 
        auto pos = lower_bound(input.begin(), input.end(), x); 
        if (*pos == x) {
            counter++; 
        }
    }
    
    cout << counter;
    
    return 0;
}