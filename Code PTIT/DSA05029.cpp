/*
Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau: ‘A’->1, ‘B’->2, .., ‘Z’->26. Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M. Ví dụ với bản mã M=”123” nó có thể được giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự số M.
T, M thỏa mãn ràng buộc: 1≤T≤100;  1≤length(M)≤40.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        std::vector<int> dp(s.size() + 1, 0);

        dp[0] = 1;
        if (s[0] != '0') dp[1] = 1;
        for (int i = 2; i <= s.size(); ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];

            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num <= 26 && num >= 10) {
                dp[i] += dp[i - 2];
            }
        }

        std::cout << dp[s.size()] << "\n";
    }
}