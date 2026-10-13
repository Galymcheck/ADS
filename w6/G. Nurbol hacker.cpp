#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void quick(vector<pair<string, string>>& a, int l, int r) {
    int i = l, j = r;
    pair<string, string> p = a[(l + r) / 2];
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
    map<string, string> original_owner;
    map<string, string> current_to_orig;

    for(int i = 0; i < n; i++) {
        string old_nick, new_nick;
        cin >> old_nick >> new_nick;
        if(current_to_orig.find(old_nick) != current_to_orig.end()) {
            string orig = current_to_orig[old_nick];
            original_owner[orig] = new_nick;
            current_to_orig.erase(old_nick);
            current_to_orig[new_nick] = orig;
        } else {
            original_owner[old_nick] = new_nick;
            current_to_orig[new_nick] = old_nick;
        }
    }

    vector<pair<string, string>> result(original_owner.begin(), original_owner.end());
    int q = result.size();

    if (q > 1) {
        quick(result, 0, q - 1);
    }

    cout << q << "\n";
    for(int i = 0; i < q; i++) {
        cout << result[i].first << " " << result[i].second << "\n";
    }

    return 0;
}