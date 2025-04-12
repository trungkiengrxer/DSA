/*
Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.

Input
Dòng đầu ghi số bộ test T (T<10)
Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng A. Sau đó là một dòng ghi N số của mảng C.
Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.

Output
Với mỗi bộ test, ghi trên một dòng giá trị lớn nhất có thể đạt được.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, v;
        std::cin >> n >> v;

        std::vector<int> a(n);
        std::vector<int> c(n);
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(v + 1, 0));

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> c[i];

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= v; ++j) {
                dp[i][j] = dp[i - 1][j];                                                               // Không chọn i đồ vật
                if (a[i - 1] <= j) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - a[i - 1]] + c[i - 1]);  // Chọn i đồ vật
            }
        }

        std::cout << dp[n][v] << "\n";
    }
}