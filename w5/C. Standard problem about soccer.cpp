#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    priority_queue<long long> pq;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    long long total_cost = 0;

    for (int i = 0; i < x; ++i) {
        long long first = pq.top();
        pq.pop();

        total_cost += first;
        pq.push(first - 1);
    }

    cout << total_cost << "\n";

    return 0;
}