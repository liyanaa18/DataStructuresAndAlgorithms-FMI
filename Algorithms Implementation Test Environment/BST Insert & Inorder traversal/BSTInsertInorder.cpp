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
    
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* add(Node* root, int x) {
    if(root == nullptr) {
        return new Node(x);
    }
    else {
        if(root-> data < x) {
            root->right = add(root->right, x);
        }
        else if(root->data > x) {
            root->left = add(root->left, x);
        }
    }
    return root;
}

void print(Node* root) {
    if(root == nullptr) {
        return;
    }
    
    if(root->left) {
        print(root->left);
    }
    cout << root->data << " ";
    if(root->right) {
        print(root->right);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    string command;
    Node* root = nullptr;
    
    for(int i = 0; i < n; i++) {
        cin >> command;
        
        if(command == "add") {
            int x;
            cin >> x;
            root = add(root, x);
        }
        if(command == "inorder") {
            print(root);
            cout << '\n';
        }
    }
    return 0;
}
