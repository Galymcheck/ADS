#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    priority_queue<long long> pq;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        if (first != second) {
            pq.push(first - second);
        }
    }

    if (pq.empty()) {
        cout << 0 << "\n";
    } else {
        cout << pq.top() << "\n";
    }

    return 0;
}