#include <iostream>
#include <vector>

using namespace std;

bool canSteal(const vector<int>& bags, long long h, int k) {
    long long total_hours = 0;
    for (int b : bags) {
        total_hours += (b + k - 1) / k;
    }
    return total_hours <= h;
}

int main() {
    int n;
    long long h;
    if (!(cin >> n >> h)) return 0;

    vector<int> bags(n);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> bags[i];
        if (bags[i] > max_val) {
            max_val = bags[i];
        }
    }

    int left = 1;
    int right = max_val;
    int ans = max_val;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canSteal(bags, h, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}