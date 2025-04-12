/*
John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Input:
Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách
Dòng 2..N+1:   Ghi lần lượt các số nguyên: w[i]

Output:
Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.
*/

#include <iostream>
#include <vector>

int main() {
    int c, n;
    std::cin >> c >> n;

    std::vector<int> w(n);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(c + 1, 0));
    for (int i = 0; i < n; ++i) std::cin >> w[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1]) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - w[i - 1]] + w[i - 1]);
        }
    }

    std::cout << dp[n][c] << "\n";
}