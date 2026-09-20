#include <iostream>
#include <string>

using namespace std;

struct Node {
    string val;
    Node* next;
    Node(string v) {
        val = v;
        next = nullptr;
    }
};

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        Node* newNode = new Node(s);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* curr = head;
    for (int i = 0; i < k - 1; ++i) {
        curr = curr->next;
    }

    Node* newHead = curr->next;
    curr->next = nullptr;
    tail->next = head;
    head = newHead;

    curr = head;
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