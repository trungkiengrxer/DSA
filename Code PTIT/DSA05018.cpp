/*
Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

Hãy tìm xâu con đối xứng dài nhất của S.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.

Output: Với mỗi test, in ra đáp án tìm được.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s, t;

        std::cin >> s;

        t = s;
        std::reverse(t.begin(), t.end());
        int n = s.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        std::cout << dp[n][n] << "\n";
    }
}