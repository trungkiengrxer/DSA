/*
Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].

Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và M.
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).

Output:
Với mỗi test, in ra kết quả trên một dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1e9));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        dp[0][0] = a[0][0];

        for (int i = 1; i < n; ++i) dp[i][0] = dp[i - 1][0] + a[i][0];
        for (int i = 1; i < m; ++i) dp[0][i] = dp[0][i - 1] + a[0][i];

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) dp[i][j] = std::min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + a[i][j];
        }

        std::cout << dp[n - 1][m - 1] << "\n";
    }
}