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
    vector<string> v(n);
    map<string, int> mp;
    for(int i = 0;i<n;i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for(int i = 0; i < n; i++) {
        cout << mp[v[i]] << " ";
    }
    return 0;
}
