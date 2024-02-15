#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> input(n);  
    
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    
    sort(input.begin(), input.end());
    
    if (n == 0) {
        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            cout << 0 << '\n';
        }
    }
    

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a > b) {
            cout << 0 << '\n';
        } else {
            auto lower = lower_bound(input.begin(), input.end(), a);
            auto upper = upper_bound(input.begin(), input.end(), b);

            int startIndex = lower - input.begin();
            int endIndex = upper - input.begin();

            int count = endIndex - startIndex;

            cout << count << '\n';
        }
    }

    return 0;
}
