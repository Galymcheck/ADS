#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

int getLength(Node* head) {
    int len = 0;
    Node* curr = head;
    while (curr != nullptr) {
        len++;
        curr = curr->next;
    }
    return len;
}

Node* insert(Node* head, Node* node, int p){
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* curr = head;
    for (int i = 0; i < p - 1; ++i) {
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
    return head;
}

Node* remove(Node* head, int p){
    if (head == nullptr) return nullptr;
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    for (int i = 0; i < p - 1; ++i) {
        curr = curr->next;
    }
    Node* temp = curr->next;
    if (temp != nullptr) {
        curr->next = temp->next;
        delete temp;
    }
    return head;
}

Node* replace(Node* head, int p1, int p2){
    if (head == nullptr) return nullptr;
    Node* target = nullptr;
    if (p1 == 0) {
        target = head;
        head = head->next;
    } else {
        Node* curr = head;
        for (int i = 0; i < p1 - 1; ++i) {
            curr = curr->next;
        }
        target = curr->next;
        curr->next = target->next;
    }
    target->next = nullptr;
    return insert(head, target, p2);
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void print(Node* head){
    if (head == nullptr) {
        cout << -1 << "\n";
        return;
    }
    Node* curr = head;
    bool first = true;
    while (curr != nullptr) {
        if (!first) cout << " ";
        cout << curr->val;
        first = false;
        curr = curr->next;
    }
    cout << "\n";
}

Node* cyclic_left(Node* head, int x){
    if (head == nullptr || head->next == nullptr) return head;
    int len = getLength(head);
    x %= len;
    if (x == 0) return head;

    Node* curr = head;
    for (int i = 0; i < x - 1; ++i) {
        curr = curr->next;
    }
    Node* newHead = curr->next;
    curr->next = nullptr;

    Node* tail = newHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head;

    return newHead;
}

Node* cyclic_right(Node* head, int x){
    if (head == nullptr || head->next == nullptr) return head;
    int len = getLength(head);
    x %= len;
    if (x == 0) return head;
    return cyclic_left(head, len - x);
}

int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}