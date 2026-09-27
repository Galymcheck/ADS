#include <iostream>
#include <vector>

using namespace std;

int findRight(const vector<long long>& pref, int start, long long target) {
    int left = start;
    int right = pref.size() - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (pref[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;
        pref[i] = pref[i - 1] + val;
    }

    int min_len = n + 1;

    for (int i = 1; i <= n; ++i) {
        long long target = pref[i - 1] + k;
        int j = findRight(pref, i, target);
        if (j != -1) {
            int len = j - i + 1;
            if (len < min_len) {
                min_len = len;
            }
        }
    }

    cout << min_len << "\n";

    return 0;
}