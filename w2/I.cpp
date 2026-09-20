#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    Node* prev;
    Node* next;
    Node(string t) {
        title = t;
        prev = nullptr;
        next = nullptr;
    }
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void add_front(string title) {
        Node* newNode = new Node(title);
        if (empty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok\n";
    }

    void add_back(string title) {
        Node* newNode = new Node(title);
        if (empty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok\n";
    }

    void erase_front() {
        if (empty()) {
            cout << "error\n";
            return;
        }
        cout << head->title << "\n";
        Node* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void erase_back() {
        if (empty()) {
            cout << "error\n";
            return;
        }
        cout << tail->title << "\n";
        Node* temp = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void front() {
        if (empty()) {
            cout << "error\n";
        } else {
            cout << head->title << "\n";
        }
    }

    void back() {
        if (empty()) {
            cout << "error\n";
        } else {
            cout << tail->title << "\n";
        }
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        cout << "ok\n";
    }
};

int main() {
    DoublyLinkedList list;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "add_front") {
            string title;
            cin >> title;
            list.add_front(title);
        } else if (cmd == "add_back") {
            string title;
            cin >> title;
            list.add_back(title);
        } else if (cmd == "erase_front") {
            list.erase_front();
        } else if (cmd == "erase_back") {
            list.erase_back();
        } else if (cmd == "front") {
            list.front();
        } else if (cmd == "back") {
            list.back();
        } else if (cmd == "clear") {
            list.clear();
        } else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }

    return 0;
}