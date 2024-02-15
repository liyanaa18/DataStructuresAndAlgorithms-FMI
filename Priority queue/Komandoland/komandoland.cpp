#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    while(n--) {
        int digit;
        cin >> digit;
        
        if(digit == -1) {
            if(!pq.empty()) {
                cout << pq.top() << " ";
                pq.pop();
            }
        }
        else {
            pq.push(digit);
        }
    }
    return 0;
}