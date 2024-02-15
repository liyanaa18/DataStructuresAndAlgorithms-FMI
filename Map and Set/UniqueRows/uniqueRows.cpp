#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    map<vector<int>, int> mp;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
        mp[matrix[i]]++;
    }
    int res = 0;
    for(auto x : mp) {
        if(x.second == 1) {
            res++;
        }
    }
    cout << res;
    return 0;
}