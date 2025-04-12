/*
Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).

Output:
Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
*/

#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::vector<long long> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;
        for (long long i = 2; i <= n; ++i) {
            for (long long j = 1; j <= k; ++j) {
                if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }

        std::cout << dp[n] << "\n";
    }
}