#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUpperBound(const vector<int>& a, int val) {
    int left = 0;
    int right = a.size() - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= val) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans + 1;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    int p;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        int mark_power;
        cin >> mark_power;

        int count = findUpperBound(a, mark_power);
        long long sum_power = pref[count];

        cout << count << " " << sum_power << "\n";
    }

    return 0;
}