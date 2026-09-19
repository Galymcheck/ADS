#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string x = "";
    string y = "";

    for (char c : a) {
        if (c == '#') {
            if (!x.empty()) {
                x.pop_back();
            }
        } else {
            x += c;
        }
    }

    for (char c : b) {
        if (c == '#') {
            if (!y.empty()) {
                y.pop_back();
            }
        } else {
            y += c;
        }
    }

    if (x == y) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}