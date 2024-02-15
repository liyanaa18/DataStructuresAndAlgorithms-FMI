#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }
    
    void print(Node* root, int k, int level) {
        if(root == nullptr) {
            return;
        }
        
        print(root->right, k, level + 1);
        
        if(k == level) {
            cout << root->value << " ";
        }
        
        print(root->left, k, level + 1);
    }
    void printSFB(int k) {
      //TODO: implement this method
        print(root, k, 0);
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
  int m;
    cin >> m;
    tree.printSFB(m);
    return 0;
}