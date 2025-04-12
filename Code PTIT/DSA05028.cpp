/*
Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây:

Insert: chèn một ký tự bất kỳ vào str1.
Delete: loại bỏ một ký tự bất kỳ trong str1.
Replace: thay một ký tự bất kỳ trong str1.
Nhiệm vụ của bạn là đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi hai xâu str1 và str2.
T, str1, str2 thỏa mãn ràng buộc: 1≤T≤100;  1≤length(str1),length(str2) ≤100.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;

        int n = s1.size(), m = s2.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        std::cout << std::max(n, m) - dp[n][m] << "\n";
    }
}