#include <map>
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
    map<int, int> mp;
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int res = 0;
    
    for(int i = 0; i < n; i++) {
        int digit;
        cin >> digit;
        mp[v[i]]++;

        if(mp[digit] == 0) {
            res++;
        }
        else {
            mp[digit]--;
        }
    }
    
    cout << res;
    return 0;
}