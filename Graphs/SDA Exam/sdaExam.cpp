#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1001;
vector<int> graph[N];
int dist[N];

void djk(int v) {
    for(int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
    }
    dist[v] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, v});
    
    while(!pq.empty()) {
        int current = pq.top().second;
        int costCurrent = pq.top().first;
        pq.pop();
        
        if(dist[current] < costCurrent) {
            continue;
        }
        
        for(auto x : graph[current]) {
            int child = x;
            
            if(dist[child] > costCurrent + 6) {
                dist[child] = costCurrent + 6;
                pq.push({dist[child], child});
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
   
    for(int i = 0; i < n; i++) {
        int v, e;
        cin >> v >> e;
        while(e--) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int index = 0;
        cin >> index;
        djk(index);

        for(int i = 1; i <= v; i++) {
            if(i != index) {
                if(dist[i] == INT_MAX) {
                    cout << -1 << " ";
                }
                else {
                    cout << dist[i] << " ";
                }
            }
        }
        cout << '\n';
        for(int i = 0; i < N; i++) {
            graph[i].clear();
            dist[i] = INT_MAX;
        }
    }
    return 0;
}