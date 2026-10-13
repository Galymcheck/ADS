#include <iostream>
#include <vector>
#include <string>

using namespace std;

int toInt(string s) {
    int d = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int y = stoi(s.substr(6, 4));
    return y * 10000 + m * 100 + d;
}

void quick(vector<string>& a, int l, int r) {
    int i = l, j = r;
    string p = a[(l + r) / 2];
    int p_val = toInt(p);
    while(i <= j) {
        while(toInt(a[i]) < p_val) i++;
        while(toInt(a[j]) > p_val) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (n > 1) {
        quick(a, 0, n - 1);
    }
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }

    return 0;
}