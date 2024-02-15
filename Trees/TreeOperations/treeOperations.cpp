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

Node* add(Node* root, int X) {
    if(root == nullptr) {
        return new Node(X);
    }
    
    else {
        if(root->data > X) {
            root->left = add(root->left, X);
        }
        if(root->data < X) {
            root->right = add(root->right, X);
        }
    }
    return root;
}

void print(Node* root) {
    
    if(root == nullptr) {
        return;
    }
    else {
        cout << root->data << " ";
    
        if(root->left) {
            print(root->left);
        }
        if(root->right) {
            print(root->right);
        }   
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    Node* root = nullptr;
    
    for(int i = 0; i < n; i++) {
        
        string command;
        cin >> command;
        
        if(command == "add") {
            int digit;
            cin >> digit;
            root = add(root, digit);
        }
        
        if(command == "print") {
            print(root);
        }
    }
    return 0;
}
