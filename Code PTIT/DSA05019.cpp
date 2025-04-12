/*
Cho một bảng số N hàng, M cột chỉ gồm 0 và 1. Bạn hãy tìm hình vuông có kích thước lớn nhất, sao cho các số trong hình vuông toàn là số 1.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test bắt đầu bởi 2 số nguyên N, M (1 ≤ N, M ≤ 500).
N dòng tiếp theo, mỗi dòng gồm M số mô tả một hàng của bảng.

Output: 
Với mỗi test, in ra đáp án là kích thước của hình vuông lớn nhất tìm được trên một dòng.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, max = 0;
        std::cin >> n >> m;

        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        for (int i = 0; i < n; ++i) if (a[i][0]) dp[i][0] = 1;
        for (int i = 0; i < m; ++i) if (a[0][i]) dp[0][i] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (a[i][j]) dp[i][j] = std::min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
                max = std::max(max, dp[i][j]);
            }
        }

        std::cout << max << "\n";
    }
}