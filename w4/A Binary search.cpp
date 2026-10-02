#include <iostream>
#include <string>

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
    if (val <= root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool checkPath(Node* root, const string& path) {
    Node* curr = root;
    for (char step : path) {
        if (curr == nullptr) {
            return false;
        }
        if (step == 'L') {
            curr = curr->left;
        } else if (step == 'R') {
            curr = curr->right;
        }
    }
    return curr != nullptr;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    for (int i = 0; i < m; ++i) {
        string path;
        cin >> path;
        if (checkPath(root, path)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}