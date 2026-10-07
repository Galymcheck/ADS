#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    int operations = 0;

    while (pq.top() < m) {
        if (pq.size() < 2) {
            cout << -1 << "\n";
            return 0;
        }

        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        long long current_sum = first + 2 * second;
        pq.push(current_sum);
        operations++;
    }

    cout << operations << "\n";

    return 0;
}