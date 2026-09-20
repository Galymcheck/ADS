#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

Node* createList(int count) {
    if (count == 0) return nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < count; ++i) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    int n, m;

    if (!(cin >> n)) return 0;
    Node* head1 = createList(n);

    if (!(cin >> m)) return 0;
    Node* head2 = createList(m);

    Node dummy(0);
    Node* tail = &dummy;

    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val <= p2->val) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }

    if (p1 != nullptr) {
        tail->next = p1;
    } else {
        tail->next = p2;
    }

    Node* mergedHead = dummy.next;

    Node* curr = mergedHead;
    bool first = true;
    while (curr != nullptr) {
        if (!first) {
            cout << " ";
        }
        cout << curr->val;
        first = false;
        curr = curr->next;
    }
    cout << "\n";

    return 0;
}