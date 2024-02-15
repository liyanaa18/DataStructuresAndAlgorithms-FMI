#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Node {
    int data;
    int leftIndex;
    int rightIndex;
    Node* left;
    Node* right;
    Node(int data, int left, int right) : data(data), leftIndex(left), rightIndex(right), left(nullptr), right(nullptr){}
};

void verticalSum(vector<long long>& vec, Node* root, int weight, int offset) {
    if (!root)
        return;

    int index = weight + offset;

    if (index < 0) {
        vec.insert(vec.begin(), -index, 0);
        index = 0;
    } else if (index >= vec.size()) {
        vec.resize(index + 1, 0);
    }

    vec[index] += root->data;

    verticalSum(vec, root->left, weight - 1, offset);
    verticalSum(vec, root->right, weight + 1, offset);
}

int main() {
    int N;
    cin >> N;
    vector<Node*> nodes(N);

    for (int i = 0; i < N; i++) {
        int num, leftIndex, rightIndex;
        cin >> num >> leftIndex >> rightIndex;
        nodes[i] = new Node(num, leftIndex, rightIndex);
    }

    for (int i = 0; i < N; i++) {
        if (nodes[i]->leftIndex != -1) {
            nodes[i]->left = nodes[nodes[i]->leftIndex];
        }
        if (nodes[i]->rightIndex != -1) {
            nodes[i]->right = nodes[nodes[i]->rightIndex];
        }
    }

    vector<long long> result;
    verticalSum(result, nodes[0], 0, 1000); 

    for (int i = 0; i < result.size(); i++) {
        if(result[i] != 0) {
            cout << result[i] << " ";
        }
        
    }


    return 0;
}
