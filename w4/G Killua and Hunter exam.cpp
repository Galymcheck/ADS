#include <iostream>
#include <algorithm>

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
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

int getHeightAndCalculateDiameter(Node* root, int& maxDiameter) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeightAndCalculateDiameter(root->left, maxDiameter);
    int rightHeight = getHeightAndCalculateDiameter(root->right, maxDiameter);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight + 1);

    return 1 + max(leftHeight, rightHeight);
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

    int maxDiameter = 0;
    getHeightAndCalculateDiameter(root, maxDiameter);

    cout << maxDiameter << "\n";

    return 0;
}