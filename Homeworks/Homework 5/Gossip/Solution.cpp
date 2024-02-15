#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, vector<int>> mp;
    int minDist = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        int digit;
        cin >> digit;
        mp[digit].push_back(i);
    }
    
    for (auto i : mp) {
        vector<int> res = i.second;

        for (int i = 1; i < res.size(); i++) {
            int currentDist = res[i] - res[i - 1];
            minDist = min(minDist, currentDist);
        }
    }

    cout << minDist << '\n';

    return 0;
}
