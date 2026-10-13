#include <iostream>
#include <vector>

using namespace std;

void quick(vector<int>& a, int l, int r) {
    int i = l, j = r, p = a[(l + r) / 2];
    while(i <= j) {
        while(a[i] > p) i++;
        while(a[j] < p) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for(int j = 0; j < m; j++) {
        vector<int> col(n);
        for(int i = 0; i < n; i++) {
            col[i] = mat[i][j];
        }
        if (n > 1) {
            quick(col, 0, n - 1);
        }
        for(int i = 0; i < n; i++) {
            mat[i][j] = col[i];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}