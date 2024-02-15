#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int> > pq; 
    
    for(int i = 0;i<n;i++){
        int digit;
        cin >> digit;
        pq.push(digit);
    }
    int counter = 0;
    
    while(pq.top() < m && pq.size() >= 2){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        pq.push(first + 2 * second);
        counter++;
    }
    
    if(pq.top() >= m) {
        cout << counter << '\n';
    }
    else {
        cout << -1;
    }
    
    return 0;
}