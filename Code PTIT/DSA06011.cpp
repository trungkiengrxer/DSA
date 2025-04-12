/*
Cho mảng A[] gồm n phần tử, hãy tìm cặp phần tử có tổng gần nhất so với 0.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n là số phần tử của mảng A[]; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 2≤N ≤10^3, -10^6≤A[i] ≤10^6.

Output:
Đưa ra tổng gần nhất với 0 của cặp phần tử.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, result = -1e9;
        std::cin >> n;

        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (std::abs(a[i] + a[j]) < std::abs(result)) result = a[i] + a[j];
            }
        }

        std::cout << result << "\n";
    }
}