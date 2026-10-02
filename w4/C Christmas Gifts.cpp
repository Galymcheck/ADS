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

Node* findNode(Node* root, int k) {
    if (root == nullptr || root->val == k) {
        return root;
    }
    if (k < root->val) {
        return findNode(root->left, k);
    }
    return findNode(root->right, k);
}

void printPreOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
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

    int k;
    cin >> k;

    Node* target = findNode(root, k);
    printPreOrder(target);
    cout << "\n";

    return 0;
}