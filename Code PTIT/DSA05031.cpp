#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> dp(10001, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= 10001; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }
    
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::cout << dp[n] << "\n";
    }
}