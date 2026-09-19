#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    long long number = 2;

    while (count < n) {
        bool prime = true;

        for (long long i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            count++;

            if (count == n) {
                cout << number;
            }
        }

        number++;
    }

    return 0;
}