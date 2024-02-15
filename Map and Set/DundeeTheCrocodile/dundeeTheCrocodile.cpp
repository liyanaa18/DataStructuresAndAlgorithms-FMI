#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<string, int> mp;
    
    string str;
    
    while(cin >> str) {
        mp[str]++;
    }
    
    for(auto x : mp) {
        if(x.second == 1) {
            cout << x.first << '\n';
        }
    }
    return 0;
}
