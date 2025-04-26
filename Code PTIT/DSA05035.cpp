#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

int main() {
    std::vector<std::vector<int>> dp(101, std::vector<int>(10, 0));

    for (int i = 0; i <= 9; ++i) dp[1][i] = 1;

    for (int i = 2; i <= 100; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int t;
    std::cin >> t;

    while (t--) {
        int n, result = 0;
        std::cin >> n;

        for (int i = 0; i <= 9; ++i) result = (result + dp[n][i]) % MOD;

        std::cout << result << "\n";
    }
}