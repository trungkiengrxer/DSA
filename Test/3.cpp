#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::vector<long long> a(k);
        std::vector<long long> dp(n + 1, 0);
        std::vector<long long> parent(n + 1, 0);

        for (long long i = 0; i < k; ++i) {
            std::cin >> a[i];
            dp[a[i]] = 1;
        }

        for (long long i = 1; i <= n; ++i) {
            for (long long x : a) {
                if (i - x >= 0 && dp[i - x]) {
                    if (dp[i] == 0)
                        dp[i] = dp[i - x] + 1;
                    else
                        dp[i] = std::min(dp[i], dp[i - x] + 1);
                }
            }
        }

        if (dp[n] == 0)
            std::cout << "-1\n";
        else
            std::cout << dp[n] << "\n";

        
    }
}