#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


int main() {

    char word[100];
    char S;

    int N;
    int counter = 0;
    
    cin >> word >> N >> S;
    int size = strlen(word);
    
    for (int i = 0; i < size; i++) {
        if (word[i] == S) {
            counter++;
        }
    }
    
    int temp = N / size;
    int tempS = N % size;
    
    int result = counter * temp;
    
    counter = 0;
    
    for (int i = 0; i < tempS; i++) {
        if (word[i] == S) {
            result++;
        }
    }

    cout << result;
    
    return 0;
}