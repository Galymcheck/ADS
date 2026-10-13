#include <iostream>
#include <vector>

using namespace std;

void quick(vector<char>& a, int l, int r) {
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
    vector<char> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char k;
    cin >> k;

    if (n > 1) {
        quick(a, 0, n - 1);
    }

    char ans = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] > k) {
            ans = a[i];
            break;
        }
    }
    cout << ans << endl;

    return 0;
}