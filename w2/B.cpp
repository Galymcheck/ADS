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

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
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

    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        curr = curr->next;
    }

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