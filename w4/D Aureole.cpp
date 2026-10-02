#include <iostream>
#include <vector>
#include <queue>

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

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    vector<long long> levelSums;
    if (root != nullptr) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            long long currentSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();

                currentSum += curr->val;

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            levelSums.push_back(currentSum);
        }
    }

    cout << levelSums.size() << "\n";
    for (size_t i = 0; i < levelSums.size(); ++i) {
        cout << levelSums[i] << (i + 1 == levelSums.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}