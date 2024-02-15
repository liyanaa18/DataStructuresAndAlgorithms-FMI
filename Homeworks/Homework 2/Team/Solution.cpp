#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    vector<char> digits;
    vector<char> smallLetters;
    vector<char> bigLetters;
    
    for(int i = 0; i < n; i++) {
        char symb;
        cin >> symb;
        
        if(symb >= '0' && symb <= '9') {
            digits.push_back(symb);
        }
        else if(symb >= 'a' && symb <= 'z') {
            smallLetters.push_back(symb);
        }
        else if(symb >= 'A' && symb <= 'Z') {
            bigLetters.push_back(symb);
        }
    }
    
    sort(digits.begin(), digits.end());
    sort(smallLetters.begin(), smallLetters.end());
    sort(bigLetters.begin(), bigLetters.end());
    
    for(int i = 0; i < digits.size(); i++) {
        cout << digits[i];
    }
    for(int i = 0; i < smallLetters.size(); i++) {
        cout << smallLetters[i];
    }
    for(int i = 0; i < bigLetters.size(); i++) {
        cout << bigLetters[i];
    }
    return 0;
}
