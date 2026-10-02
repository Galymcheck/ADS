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

void transformAndPrint(Node* root, int& sum) {
    if (root == nullptr) {
        return;
    }
    transformAndPrint(root->right, sum);
    sum += root->val;
    root->val = sum;
    cout << root->val << " ";
    transformAndPrint(root->left, sum);
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

    int sum = 0;
    transformAndPrint(root, sum);
    cout << "\n";

    return 0;
}