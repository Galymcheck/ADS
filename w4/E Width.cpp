#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;

    Node(int i) {
        id = i;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Node*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }

    int maxWidth = 0;
    queue<Node*> q;
    q.push(nodes[1]);

    while (!q.empty()) {
        int levelSize = q.size();
        maxWidth = max(maxWidth, levelSize);

        for (int i = 0; i < levelSize; ++i) {
            Node* curr = q.front();
            q.pop();

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }

    cout << maxWidth << "\n";

    return 0;
}