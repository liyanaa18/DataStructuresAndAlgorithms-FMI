#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int val) {
    if(!root) {
        return new Node(val);    
    }
    else {
        if(root->data > val) {
            root->left = insertNode(root->left, val);
        }
        if(root->data < val) {
            root->right = insertNode(root->right, val);
        }
    }
    return root;
}

void print(Node* root) {
    if(root == nullptr) {
        return;
    }
    else {
        if(root->left && root->right) {
            cout << root->data << " ";
        }
    }
    print(root->left);
    print(root->right);
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        
        Node* root = nullptr;

        
        for(int j = 0; j < m; j++) {
            int digit;
            cin >> digit;
            
            root = insertNode(root, digit);
        }
        
        print(root);
        cout << '\n';
    }
    return 0;
}
