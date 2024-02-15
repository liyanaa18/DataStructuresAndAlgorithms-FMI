#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* add(Node* root, int x) {
    if (root == nullptr) {
        return new Node(x);
    } else {
        if (root->data < x) {
            root->right = add(root->right, x);
        } else if (root->data > x) {
            root->left = add(root->left, x);
        }
    }
    return root;
}

void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";

        if (current->left) {
            q.push(current->left);
        }

        if (current->right) {
            q.push(current->right);
        }

        q.pop();
    }
}

int main() {
    int n;
    cin >> n;

    string command;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> command;

        if (command == "add") {
            int x;
            cin >> x;
            root = add(root, x);
        } else if (command == "levelorder") {
            levelOrder(root);
            cout << '\n';
        }
    }

    return 0;
}
