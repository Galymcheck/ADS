#include <iostream>
#include <vector>

using namespace std;

void quick(vector<int>& a, int l, int r) {
    int i = l, j = r, p = a[(l + r) / 2];
    while(i <= j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    if (n > 1) quick(a, 0, n - 1);
    if (m > 1) quick(b, 0, m - 1);

    int i = 0, j = 0;
    bool first = true;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            int val = a[i];
            int count1 = 0;
            while (i < n && a[i] == val) {
                count1++;
                i++;
            }
            int count2 = 0;
            while (j < m && b[j] == val) {
                count2++;
                j++;
            }
            int common = min(count1, count2);
            for (int k = 0; k < common; k++) {
                if (!first) {
                    cout << " ";
                }
                cout << val;
                first = false;
            }
        }
    }
    cout << endl;

    return 0;
}