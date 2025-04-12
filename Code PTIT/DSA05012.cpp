/*
Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 109+7.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).

Output:
Với mỗi test, in ra đáp án trên một dòng.
*/

#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

std::vector<std::vector<long long>> c(1001, std::vector<long long>(1001));

void combination() {
    c[0][0] = 1;
    for (int i = 0; i <= 1000; ++i) c[i][0] = 1;

    for (long long i = 1; i <= 1000; ++i) {
        for (long long j = 1; j <= 1000; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    combination();
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        std::cout << c[n][k] << "\n";
    }
}