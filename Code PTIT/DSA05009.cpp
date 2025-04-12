/*
Cho tập các số A[] = (a1, a2, .., an). Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con sao cho tổng các phần tử của hai tập con bằng nhau hay không. Đưa ra YES nếu có thể thực hiện được, ngược lại đưa ra NO.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N phần tử của dãy số A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤100; 1≤ A[i] ≤100.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        int sum = std::accumulate(a.begin(), a.end(), 0);

        if (sum % 2) {
            std::cout << "NO\n";
            continue;
        }

        sum /= 2;

        std::vector<int> dp(sum + 1, false);
        dp[0] = true;

        for (const int &num : a) {
            for (int i = sum; i >= num; --i) {
                if (dp[i - num]) dp[i] = true;
            }
        }

        if (dp[sum])
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}