#include <iostream>
#include <vector>
#include <string>

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
    string s;
    cin >> s;
    int n = s.length();
    vector<char> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = s[i];
    }

    if (n > 1) {
        quick(a, 0, n - 1);
    }

    for(int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;

    return 0;
}