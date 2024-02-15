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
    vector<string> res;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        map<string, int> mp;
        
        for(int j = 0; j < a; j++) {
            string str;
            cin >> str;
            mp[str]++;
        }
        int count = 0;
        
        for(int k = 0; k < b; k++) {
            string sstr;
            cin >> sstr;
            if(mp[sstr] > 0) {
                count++;
                mp[sstr]--;
            }
        }
        
        if(count == b) {
            res.push_back("Yes");
        }
        else {
            res.push_back("No");
        }
        
        mp.clear();
    }
    
    for(int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}