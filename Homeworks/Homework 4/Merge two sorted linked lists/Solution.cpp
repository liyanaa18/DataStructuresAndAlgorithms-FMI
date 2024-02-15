#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* p, *q, *s;
    SinglyLinkedListNode* head = nullptr;
    p = head1;
    q = head2;

    if (p->data <= q->data) {
        s = p;
        p = s->next;
    } else {
        s = q;
        q = s->next;
    }
    head = s;

    while (p && q) {
        if (p->data <= q->data) {
            s->next = p;
            s = p;
            p = s->next;
        } else {
            s->next = q;
            s = q;
            q = s->next;
        }
    }

    if (p == nullptr) {
        s->next = q;
    } else if (q == nullptr) {
        s->next = p;
    }
    return head;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int t, m;
        cin >> t;

        SinglyLinkedListNode* headA = nullptr;
        SinglyLinkedListNode* tailA = nullptr;

        for (int i = 0; i < t; i++) {
            int data;
            cin >> data;

            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

            if (!headA) {
                headA = newNode;
                tailA = newNode;
            } else {
                tailA->next = newNode;
                tailA = newNode;
            }
        }

        cin >> m;

        SinglyLinkedListNode* headB = nullptr;
        SinglyLinkedListNode* tailB = nullptr;

        for (int i = 0; i < m; i++) {
            int data;
            cin >> data;

            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

            if (!headB) {
                headB = newNode;
                tailB = newNode;
            } else {
                tailB->next = newNode;
                tailB = newNode;
            }
        }

        SinglyLinkedListNode* merged = mergeLists(headA, headB);

        while (merged) {
            cout << merged->data << " ";
            merged = merged->next;
        }
        cout << '\n';
    }

    return 0;
}
