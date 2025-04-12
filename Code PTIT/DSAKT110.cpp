/*
Có N ngôi nhà trên một dãy phố, mỗi ngôi nhà chứa đựng một số lượng tài sản khác nhau. Một tên trộm muốn ăp cắp được nhiều nhất tài sản của dãy phố nhưng không muốn lấy tài sản của hai nhà kề nhau. Hãy cho biết, bằng cách đó tên trộm có thể đánh cắp được nhiều nhất bao nhiêu tài sản.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N là số lượng ngôi nhà; dòng tiếp theo đưa vào N số là tài sản tương ứng trong mỗi ngôi nhà; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤10^6; 1≤A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> dp(n + 1, -1e9);

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        dp[0] = 0;
        dp[1] = a[0];

        for (int i = 2; i <= n; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + a[i - 1]);
        }

        std::cout << dp[n] << "\n";
    }
}