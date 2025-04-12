/*
Cho dãy số A[] gồm N phần tử. Hãy tìm tổng lớn nhất của dãy con của dãy số A[] sao cho dãy con không có hai số cạnh nhau trong A[]. Ví dụ với A[] = {6, 7, 1, 3, 8, 2, 4} ta có kết quả là 19 tương ứng với tổng của dãy con {6, 1, 6, 4} không có haI phần tử nào kề nhau trong A[].

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤10^6; 1≤A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> dp(n);

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        dp[0] = a[0];
        dp[1] = std::max(a[1], a[0]);

        for (int i = 2; i < n; ++i) dp[i] = std::max(dp[i - 2] + a[i], dp[i - 1]);

        std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    }
}