#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCatch(const vector<long long>& req, int k, long long mid) {
    int count = 0;
    for (long long x : req) {
        if (x <= mid) {
            count++;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> req(n);
    long long max_val = 0;
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        req[i] = max(x2, y2);
        if (req[i] > max_val) {
            max_val = req[i];
        }
    }

    long long left = 1;
    long long right = max_val;
    long long ans = max_val;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canCatch(req, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}