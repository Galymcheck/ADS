#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool canCut(const vector<double>& a, int k, double len) {
    long long count = 0;
    for (double x : a) {
        long long pieces = x / len;
        count += pieces;
    }
    return count >= k;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<double> a(n);
    double max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    double left = 0;
    double right = max_val;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = left + (right - left) / 2;
        if (canCut(a, k, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(9) << left << "\n";

    return 0;
}