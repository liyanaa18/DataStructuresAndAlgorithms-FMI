#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100001;
vector<int> graph[N];
bool visited[N] = {0};

void dfs(int v) {
    visited[v] = 1;
    
    for(auto x : graph[v]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int i = 0; i < N; i++) {
            graph[i].clear();
            visited[i] = 0;
        }
        
        int v, e;
        cin >> v >> e;
        
        while(e--) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        int temp = 0;
        
        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                dfs(i);
                temp++;
            }
        }
        cout << temp << " ";
    }
    return 0;
}
