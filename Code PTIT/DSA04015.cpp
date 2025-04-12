/*
Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số N là số phần tử của mảng A[] và số X; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 1≤ A[i]≤10^18.

Output:
Đưa ra vị trí của  floor(X) trong mảng A[] hoặc -1 nếu không tồn tại floor(X) của mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, x, index = -2;
        std::cin >> n >> x;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (a[mid] > x)
                right = mid - 1;
            else {
                index = mid;
                left = mid + 1;
            }
        }

        std::cout << index + 1 << "\n";
    }
}