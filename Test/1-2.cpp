#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n;

    std::cin >> k;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) std::cin >> h[i];

    std::vector<int> dp(n + 1, 1e9);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) dp[i] = std::min(dp[i], dp[i - j] + std::abs(h[i] - h[i - j]));
        }
    }

    std::cout << dp[n - 1] << "\n";
}