#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> result;
    string last = "";

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (result.empty() || s != last) {
            result.push_back(s);
            last = s;
        }
    }

    cout << result.size() << "\n";
    for (const string& name : result) {
        cout << name << "\n";
    }

    return 0;
}