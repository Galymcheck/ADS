#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    // Ускорение ввода-вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> boris, nursik;

    // Считываем первые 5 карт для Бориса
    for (int i = 0; i < 5; ++i) {
        int card;
        cin >> card;
        boris.push(card);
    }

    // Считываем следующие 5 карт для Нурсика
    for (int i = 0; i < 5; ++i) {
        int card;
        cin >> card;
        nursik.push(card);
    }

    int moves = 0;

    // Играем, пока у обоих игроков есть карты
    while (!boris.empty() && !nursik.empty()) {
        moves++;

        // Игроки открывают верхние карты
        int b_card = boris.front();
        boris.pop();

        int n_card = nursik.front();
        nursik.pop();

        // Проверяем, кто выиграл раунд
        bool boris_wins = false;

        if (b_card == 0 && n_card == 9) {
            boris_wins = true; // Исключение: 0 бьет 9
        } else if (b_card == 9 && n_card == 0) {
            boris_wins = false; // Исключение: 0 бьет 9 (выиграл Нурсик)
        } else if (b_card > n_card) {
            boris_wins = true; // В обычных случаях бьет то число, что больше
        } else {
            boris_wins = false;
        }

        // Крупье кладет карты вниз колоды победителя
        if (boris_wins) {
            boris.push(b_card); // Сначала карта Бориса
            boris.push(n_card); // Затем карта Нурсика
        } else {
            nursik.push(b_card); // Сначала карта Бориса
            nursik.push(n_card); // Затем карта Нурсика
        }
    }

    // Выводим имя победителя и количество ходов
    if (boris.empty()) {
        cout << "Nursik " << moves << "\n";
    } else {
        cout << "Boris " << moves << "\n";
    }

    return 0;
}
