#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000001;
vector<int> graph[N];
bool visited[N];

int dfs(int v) {
    visited[v] = 1;
    int component = 1;
    for(auto x : graph[v]) {
        if(!visited[x]) {
            component += dfs(x);
        }
    }
    return component;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v, e, k;
    cin >> v >> e >> k;
    
    while(e--) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int res = 0;
    
    for(int i = 0; i < v; i++) {
        
        if(!visited[i] && (dfs(i) % k == 0)) {
            dfs(i);
            res++;
        }
    }
    cout << res;
    return 0;
}
