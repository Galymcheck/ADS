#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> d;

    // Идем в обратном порядке от N до 1
    for (int i = n; i >= 1; --i) {
        // 1. Возвращаем карту 'i' на вершину колоды
        d.push_front(i);

        // 2. Делаем обратное движение карт: из конца в начало 'i' раз
        for (int j = 0; j < i; ++j) {
            int last = d.back();
            d.pop_back();
            d.push_front(last);
        }
    }

    // Выводим результат
    for (int i = 0; i < n; ++i) {
        cout << d[i] << (i == n - 1 ? "" : " ");
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
