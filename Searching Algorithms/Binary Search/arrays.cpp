#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];    
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < m; i++) {
        int digit;
        cin >> digit;
        
        auto lower = lower_bound(v.begin(), v.end(), digit);
        int index = lower - v.begin();
        
        cout << index << " ";
    }
    return 0;
}
