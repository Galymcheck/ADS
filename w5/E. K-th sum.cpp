#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    int q, k;
    if (!(cin >> q >> k)) return 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long total_sum = 0;

    for (int i = 0; i < q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            long long a;
            cin >> a;

            if (pq.size() < k) {
                pq.push(a);
                total_sum += a;
            } else if (a > pq.top()) {
                total_sum -= pq.top();
                pq.pop();
                pq.push(a);
                total_sum += a;
            }
        } else if (command == "print") {
            cout << total_sum << "\n";
        }
    }

    return 0;
}