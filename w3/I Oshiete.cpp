#include <iostream>
#include <vector>

using namespace std;

bool canSplit(const vector<long long>& a, int k, long long max_sum) {
    int blocks = 1;
    long long current_sum = 0;

    for (long long x : a) {
        if (current_sum + x > max_sum) {
            blocks++;
            current_sum = x;
        } else {
            current_sum += x;
        }
    }

    return blocks <= k;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    long long max_val = 0;
    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
        }
        total_sum += a[i];
    }

    long long left = max_val;
    long long right = total_sum;
    long long ans = total_sum;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canSplit(a, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}