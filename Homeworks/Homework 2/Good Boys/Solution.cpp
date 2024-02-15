#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortPairs(const pair<pair<double, double>, int>& a, const pair<pair<double, double>, int>& b) {
    double firstEf = a.first.first * a.first.first / a.first.second;
    double secondEf = b.first.first * b.first.first / b.first.second;

    if (firstEf == secondEf) {
        return a.first.first > b.first.first;
    }

    return firstEf > secondEf;
}

int main() {
    int n;
    cin >> n;
    double di, ti;
    vector<pair<double, double>> pairsBoys;

    for (int i = 0; i < n; i++) {
        cin >> di >> ti;
        pairsBoys.push_back(make_pair(di, ti));
    }

    vector<pair<pair<double, double>, int>> result;

    for(int i = 0; i < n; i++) {
        result.push_back(make_pair(pairsBoys[i], i + 1));
    }

    stable_sort(result.begin(), result.end(), sortPairs);

    for(int i = 0; i < n; i++) {
        cout << result[i].second << " ";
    }

    return 0;
}
