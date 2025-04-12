#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

int main() {
    long long t;
    std::cin >> t;

    std::vector<std::vector<long long>> dp(1001, std::vector<long long>(1001, 0));

    for (long long n = 0; n <= 1000; ++n) {
        dp[n][0] = 1;
    }

    for (long long n = 1; n <= 1000; ++n) {
        for (long long k = 1; k <= n; ++k) {
            dp[n][k] = (n * dp[n - 1][k - 1]) % MOD;
        }
    }

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        if (k > n) {
            std::cout << 0 << "\n";
            continue;
        }
        std::cout << dp[n][k] << "\n";
    }

    return 0;
}