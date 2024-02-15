#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }

    int sum(Node* root) {
        if(!root) {
            return 0;
        }
        if(!root->leftNode && !root->rightNode) {
            if(root->data % 2 == 1) {
                return root->data;
            }
        }
        return sum(root->rightNode) + sum(root->leftNode);
    }
	void leaves(Node *root) {
		// TODO. 

        cout << sum(root);
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leaves(root);
    return 0;
}
