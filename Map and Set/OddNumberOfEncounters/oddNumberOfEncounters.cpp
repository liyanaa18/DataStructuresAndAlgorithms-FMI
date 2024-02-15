#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >>n;
    map<int, int> mp;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(mp[v[i]] % 2 != 0){
            sum += v[i];
        }
    }
    cout << sum;
    return 0;
}
