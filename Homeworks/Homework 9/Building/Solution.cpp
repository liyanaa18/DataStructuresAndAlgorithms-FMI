#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Road {
public:
    int from, to, id; 
    long long int trouble, profit;

    Road() = default;

    Road(int from, int to, long long int trouble, long long int profit, int id);

    bool operator<(const Road& other) const;
};

Road::Road(int from, int to, long long int trouble, long long int profit, int id) {
    this->from = from;
    this->to = to;
    this->trouble = trouble;
    this->profit = profit;
    this->id = id;
}
bool Road::operator<(const Road& other) const {
    return (this->trouble == other.trouble) ? this->profit >= other.profit : this->trouble < other.trouble;
}

const int N = 200001;
vector<Road> edgeList;
int parent[N], depth[N]{0};
int edgeCount = 0;
vector<int> result;

int find(int v) {
    
    int temp = parent[v];
    if (temp != v) {
        return temp = find(temp);
    }
    return v;
}

void Union(int from, int to) {

    int start = find(from);
    int end = find(to);

    if (depth[start] < depth[end]) {
        parent[start] = end;
    }
    else {
        
        if(depth[start] == depth[end]){
            depth[start]++;
        }
        parent[end] = start;
    }

}
void kruskal() {

    sort(edgeList.begin(), edgeList.end());

    for (Road road : edgeList) {
        
        if (find(road.from) != find(road.to)) {
            Union(road.from, road.to);
            result.push_back(road.id);
        }
    }
    for (int temp : result) {
        cout << temp << "\n";
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Road road;

    int vertexCount = 0;
    cin >> vertexCount >> edgeCount;
    
    for (int i = 0; i < vertexCount; i++) {
        parent[i] = i;
    }
    
    for (int i = 1; i <= edgeCount; i++) {

        cin >> road.from >> road.to >> road.trouble >> road.profit;
        road.id = i;
        edgeList.push_back(road);
    }

    kruskal();

    return 0;
}