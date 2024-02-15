#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<int> res;
    
    for(int i = 0; i < n; i++) {
        if(mp[v[i]] == 1) {
            res.push_back(v[i]);
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(mp[v[i]] > 1) {
            res.push_back(v[i]);
            mp[v[i]] = 0;
        }
    }
    
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
