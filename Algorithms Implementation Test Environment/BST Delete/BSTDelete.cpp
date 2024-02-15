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
Node* minValueNode(Node* root) {
    Node* current = root;
    while(current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* remove(Node* root, int x) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->data < x) {
        root->right = remove(root->right, x);
    }
    else if(root->data > x) {
        root->left = remove(root->left, x);
    }
    else {
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* minRight = minValueNode(root->right);
        root->data = minRight->data;
        root->right = remove(root->right, minRight->data);
    }
    
    return root;
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
        if(command == "del") {
            int x;
            cin >> x;
            root = remove(root, x);
        }
    }
    return 0;
}
