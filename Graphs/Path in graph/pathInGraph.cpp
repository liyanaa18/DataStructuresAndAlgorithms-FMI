#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000001;
vector<int> graph[N];
int visited[N];
int temp = 1;

void dfs(int v) {
    visited[v] = temp;
    
    for(auto x : graph[v]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v, e;
    cin >> v >> e;
    
    while(e--) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i = 1; i <= v; i++) {
        if(!visited[i]) {
            dfs(i);
            temp++;
        }
    }
    
    int k;
    cin >> k;
    
    for(int i = 0; i < k; i++) {
        int from, to;
        cin >> from >> to;
        
        if(visited[from] == visited[to]) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
    return 0;
}