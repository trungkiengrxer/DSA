/*
Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.
*/

#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string a, b;
        std::cin >> a;
        std::cin >> b;

        std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));

        for (int i = 1; i <= a.size(); ++i) {
            for (int j = 1; j <= b.size(); ++j) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        std::cout << dp[a.size()][b.size()] << "\n";
    }
}