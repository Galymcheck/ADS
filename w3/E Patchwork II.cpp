#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerBound(const vector<int>& a, long long val) {
    int left = 0;
    int right = a.size() - 1;
    int ans = a.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= val) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int upperBound(const vector<int>& a, long long val) {
    int left = 0;
    int right = a.size() - 1;
    int ans = a.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] > val) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int countInRange(const vector<int>& a, long long l, long long r) {
    if (l > r) return 0;
    return upperBound(a, r) - lowerBound(a, l);
}

int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }

        if (l2 <= r1) {
            long long merged_r = max(r1, r2);
            cout << countInRange(a, l1, merged_r) << "\n";
        } else {
            cout << countInRange(a, l1, r1) + countInRange(a, l2, r2) << "\n";
        }
    }

    return 0;
}