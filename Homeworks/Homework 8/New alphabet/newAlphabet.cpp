#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

unordered_map<char, vector<char>> adjacency_list;
unordered_map<char, bool> visited;
stack<char> alphabet;

void dfs(char vertex) {
    visited[vertex] = true;
    for (auto temp : adjacency_list[vertex]) {
        if (!visited[temp]) {
            dfs(temp);
        }   
    }
    alphabet.push(vertex);
}

void topologicalSort() {
    for (auto temp : adjacency_list) {
        char vertex = temp.first;
        if (!visited[vertex]) {
            dfs(vertex);
        }
    }
}

int main() {
    int n;
    cin >> n;
    string word;
    cin >> word;

    for (int i = 1; i < n; i++) {
        string secondWord;
        cin >> secondWord;

        for (int j = 0; j < word.size() && j < secondWord.size(); j++) {
            if (word[j] != secondWord[j]) {
                adjacency_list[word[j]].push_back(secondWord[j]);
                adjacency_list[secondWord[j]];  
                visited[word[j]] = false;
                visited[secondWord[j]] = false;
                break;
            }
        }
        word = secondWord;
    }

    topologicalSort();

    while (!alphabet.empty()) {
        cout << alphabet.top() << " ";
        alphabet.pop();
    }

    return 0;
}
