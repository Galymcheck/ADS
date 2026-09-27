#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    vector<int> queries(t);
    for (int i = 0; i < t; ++i) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < t; ++i) {
        int val = queries[i];
        int left = 0;
        int right = n * m - 1;
        int ans_r = -1;
        int ans_c = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / m;
            int c = (r % 2 == 0) ? (mid % m) : (m - 1 - (mid % m));

            if (a[r][c] == val) {
                ans_r = r;
                ans_c = c;
                break;
            } else if (a[r][c] > val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (ans_r != -1) {
            cout << ans_r << " " << ans_c << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}