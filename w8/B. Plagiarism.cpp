#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2, t;
    if (!(cin >> s1 >> s2 >> t)) return 0;

    long long MOD = 1e9 + 7;
    long long P = 31;

    int len_t = t.length();
    int len_1 = s1.length();
    int len_2 = s2.length();

    long long hash_t = 0;
    for (int i = 0; i < len_t; ++i) {
        hash_t = (hash_t * P + (t[i] - 'a' + 1)) % MOD;
    }

    vector<long long> p_pow(max({len_1, len_2, len_t}) + 1);
    p_pow[0] = 1;
    for (size_t i = 1; i < p_pow.size(); ++i) {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
    }

    vector<long long> h1(len_1 + 1, 0);
    for (int i = 0; i < len_1; ++i) {
        h1[i + 1] = (h1[i] * P + (s1[i] - 'a' + 1)) % MOD;
    }

    vector<long long> h2(len_2 + 1, 0);
    for (int i = 0; i < len_2; ++i) {
        h2[i + 1] = (h2[i] * P + (s2[i] - 'a' + 1)) % MOD;
    }

    int max_i = min(len_1, len_2) - len_t;
    int count = 0;

    for (int i = 0; i <= max_i; ++i) {
        long long sub_h1 = (h1[i + len_t] - h1[i] * p_pow[len_t]) % MOD;
        if (sub_h1 < 0) sub_h1 += MOD;

        long long sub_h2 = (h2[i + len_t] - h2[i] * p_pow[len_t]) % MOD;
        if (sub_h2 < 0) sub_h2 += MOD;

        if (sub_h1 == hash_t && sub_h2 == hash_t) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}