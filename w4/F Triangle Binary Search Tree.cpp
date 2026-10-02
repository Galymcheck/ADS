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

int countTriangles(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if (root->left != nullptr && root->right != nullptr) {
        count = 1;
    }
    return count + countTriangles(root->left) + countTriangles(root->right);
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

    cout << countTriangles(root) << "\n";

    return 0;
}