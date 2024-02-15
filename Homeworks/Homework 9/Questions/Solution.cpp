#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <cmath>
using namespace std;

void dfs(int vertex, vector<vector<int>>& graph, vector<int>& visited, int temp) {

    visited[vertex] = temp;

    for (auto i : graph[vertex]) {
        if (!visited[i]) {
            dfs(i, graph, visited, temp);
        }
    }
}
void Union(int from, int to, int vertex, vector<int>& visited) {
    int old = visited[from];
    int neww = visited[to];

    for (int j = 0; j <= vertex; j++) {
            if (visited[j] == old) {
                visited[j] = neww;
            }
        }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> graph;
    vector<int> visited;
    graph.assign(vertex + 1, vector<int>());
    visited.assign(vertex + 1, 0);

    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int temp = 1;
    for (int i = 0; i < vertex; i++) {
        if (visited[i] == false) {
            temp++;
            dfs(i, graph, visited, temp);
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int type, from, to;
        cin >> type >> from >> to;
        if (type == 2) {
            Union(from, to, vertex, visited);
        }
        else if (type == 1) {
            if (visited[from] != visited[to]) {
                cout << 0;
            }
            else {
                cout << 1;
            }
        }
    }

    return 0;
}
