#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int digit;
        cin >> digit;
        auto upper = upper_bound(v.begin(), v.end(), digit);
        auto lower = lower_bound(v.begin(), v.end(), digit);
        
        int start = lower - v.begin();
        int end = upper - v.begin() - 1;
        
        if(v[start] == digit && v[end] == digit) {
            cout << start << " " << end << '\n';
        }
        else {
            cout << start << '\n';
        }
    }
    return 0;
}
