/*
Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

Input: Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, s;
        std::cin >> n >> s;

        std::vector<int> a(n);
        std::vector<bool> dp(s + 1, false);

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        dp[0] = true;
        for (const int num : a) {
            for (int i = s; i >= num; --i) {
                if (dp[i - num]) dp[i] = true;
            }
        }

        if (dp[s])
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}