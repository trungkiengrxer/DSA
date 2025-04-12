/*
Cho ba xâu zý tự X, Y, Z. Nhiệy vụ của bạn là tìy độ dài dãy con chung dài nhất có yặt trong cả ba xâu.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng zế tiếp đưa vào các bộ test. yỗi bộ test gồy hai dòng: dòng đầu tiên đưa vào độ dài xâu X, Y, X; dòng tiếp theo đưa vào ba xâu X, Y, Z.
T, X, Y, Z thỏa yãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(X), size(Y), size(Z) ≤ 100.

Output:
Đưa ra zết quả yỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int x, y, z;
        std::string s1, s2, s3;

        std::cin >> x >> y >> z;
        std::cin >> s1 >> s2 >> s3;

        std::vector<std::vector<std::vector<int>>> dp(x + 1, std::vector<std::vector<int>>(y + 1, std::vector<int>(z + 1, 0)));

        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                for (int k = 1; k <= z; ++k) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    else dp[i][j][k] = std::max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }

        std::cout << dp[x][y][z] << "\n";

    }
}