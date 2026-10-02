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

void findKth(Node* root, int& k, int& result) {
    if (root == nullptr || k <= 0) {
        return;
    }

    findKth(root->left, k, result);

    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    findKth(root->right, k, result);
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    if (k > n) {
        cout << -1 << "\n";
    } else {
        int result = -1;
        findKth(root, k, result);
        cout << result << "\n";
    }

    return 0;
}