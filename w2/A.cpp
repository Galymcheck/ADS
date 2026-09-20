#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> count(26, 0); 
    queue<char> q;            
    
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        
       
        count[ch - 'a']++;
        q.push(ch);
        
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        if (!q.empty()) {
            cout << q.front() << (i == n - 1 ? "" : " ");
        } else {
            cout << -1 << (i == n - 1 ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}