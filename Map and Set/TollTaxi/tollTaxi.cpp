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
    
    string str;
    int digit;
    map<string, int> mp;
    
    while(n--) {
        cin >> str >> digit;
        mp[str] = digit;
    }
    
    string newStr;
    long sum = 0;
    
    for(int i = 0; i < m; i++) {
        cin >> newStr;
        sum += mp[newStr];
    }
    
    cout << sum;
    
    return 0;
}
