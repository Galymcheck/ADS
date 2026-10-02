#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* findNode(Node* root, int x) {
    if (root == nullptr || root->val == x) {
        return root;
    }
    if (x < root->val) {
        return findNode(root->left, x);
    }
    return findNode(root->right, x);
}

int getSize(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int x;
    cin >> x;

    Node* target = findNode(root, x);
    cout << getSize(target) << "\n";

    return 0;
}