/*
Cho số nguyên dương N và K. Hãy tính NK modulo 10^9+7.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 1 số nguyên N và K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 109).

Output:
Với mỗi test, in ra đáp án trên một dòng.
*/

#include <iostream>

const long long MOD = 1e9 + 7;

long long bin_pow(long long n, long long k) {
    long long result = 1;

    while (k > 0) {
        if (k % 2 == 1) result = (result * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }

    return result;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::cout << bin_pow(n, k) << "\n";
    }
}