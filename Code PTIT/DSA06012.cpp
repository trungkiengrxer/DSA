/*
Cho mảng A[] gồm n phần tử, hãy tìm k phần tử lớn nhất của mảng. Các phần tử được đưa ra theo thứ tự giảm dần.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N và K; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤K < N ≤10^3, 1≤A[i] ≤10^6.

Output:
Đưa ra k phần tử lớn nhất trên một dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.rbegin(), a.rend());

        for (int i = 0; i < k; ++i) std::cout << a[i] << " ";
        std::cout << "\n";
    }
}