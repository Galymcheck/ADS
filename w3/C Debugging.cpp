#include <iostream>
#include <vector>

using namespace std;

int findBlock(const vector<long long>& pref, long long line) {
    int left = 0;
    int right = pref.size() - 1;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (pref[mid] >= line) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans + 1;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> pref(n);
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (i == 0) {
            pref[i] = a;
        } else {
            pref[i] = pref[i - 1] + a;
        }
    }

    for (int i = 0; i < m; ++i) {
        long long b;
        cin >> b;
        cout << findBlock(pref, b) << "\n";
    }

    return 0;
}