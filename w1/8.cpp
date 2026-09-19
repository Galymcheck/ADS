#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Теперь храним в стеке только сам возраст (long long)
    stack<long long> st;

    for (int i = 0; i < n; ++i) {
        // Удаляем тех, кто старше или равен текущему человеку
        while (!st.empty() && st.top() >= a[i]) {
            st.pop();
        }

        // Если стек пуст — выводим -1
        if (st.empty()) {
            cout << -1 << (i == n - 1 ? "" : " ");
        } else {
            // Иначе выводим ВОЗРАСТ человека на вершине стека
            cout << st.top() << (i == n - 1 ? "" : " ");
        }

        // Добавляем текущий возраст в стек
        st.push(a[i]);
    }

    cout << "\n";
    return 0;
}
