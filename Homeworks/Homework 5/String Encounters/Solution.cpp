#include <iostream>
#include <string>
using namespace std;

int main() {
    string mainString;
    string subString;
    
    cin >> subString;  
    cin >> mainString;
    
    int result = 0;
    int position = mainString.find(subString, 0);

    while (position != string::npos) {
        position++;
        position = mainString.find(subString, position);
        result++;
    }
    
    cout << result;

    return 0;
}
