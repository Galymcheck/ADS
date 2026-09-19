#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;

    string stack = ""; // Используем обычную строку как эффективный стек

    for (char c : s) {
        if (!stack.empty() && stack.back() == c) {
            stack.pop_back();
        } else {
            stack.push_back(c);
        }
    }

    if (stack.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
