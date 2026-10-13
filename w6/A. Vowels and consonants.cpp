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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    
    if (n > 1) {
        quick(a, 0, n - 1);
    }
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}