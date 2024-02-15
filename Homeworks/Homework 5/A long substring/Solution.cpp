#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int sizeStr1 = str1.length();
    int sizeStr2 = str2.length();

    if (sizeStr1 == 0 || sizeStr2 == 0) {
        cout << 0;
        return 0;
    }

    int smallerSize = min(sizeStr1, sizeStr2);

    vector<int> currentRow(sizeStr2 + 1, 0);
    vector<int> previousRow(sizeStr2 + 1, 0);

    int res = 0;

    for (int i = 0, j = 0; i < smallerSize; i++, j++) {
        currentRow[j + 1] = (str1[i] == str2[j]) ? previousRow[j] + 1 : 0;
        res = max(res, currentRow[j + 1]);
        swap(currentRow, previousRow);
    }

    cout << res;

    return 0;
}
