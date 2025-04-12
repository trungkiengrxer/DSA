/*
Cho hai số nguyên lớn N và M có không quá 1000 chữ số. Người ta muốn tính xem liệu có thể lấy ra nhiều nhất bao nhiêu chữ số trong N (không cần liên tiếp) và giữ nguyên thứ tự của nó để tạo ra một số X sao cho ta cũng có thể tìm thấy X trong số M theo cách tương tự.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, dòng thứ nhất ghi số N, dòng thứ 2 ghi số M.

Output:  Với mỗi test, hãy in ra số chữ số nhiều nhất có thể của X.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> dp(n.size() + 1, std::vector<int>(m.size() + 1, 0));

        for (int i = 1; i <= n.size(); ++i) {
            for (int j = 1; j <= m.size(); ++j) {
                if (n[i - 1] == m[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        std::cout << dp[n.size()][m.size()] << "\n";
    }
}