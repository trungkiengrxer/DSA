/*
Cho mảng A[] gồm n số nguyên dương và số k. Nhiệm vụ của bạn là đếm số các cặp phần tử có hiệu nhỏ hơn k. Ví dụ A[] = {1, 10, 4, 2 }, k=3 ta nhận được kết quả là 2 tương ứng với hiệu các cặp (1, 2), (4, 2).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, tương ứng với số phần tử của mảng A[] và số k; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1 ≤  T  ≤ 100; 1 ≤  n  ≤ 10^4; 1 ≤  k ≤ 10^3; 1 ≤  A[i]  ≤ 10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k, count = 0;
        std::cin >> n >> k;

        std::vector<long long> a(n);

        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());

        long long l = 0, r = 0;
        while (l < n) {
            while (r < n && a[r] - a[l] < k) ++r;
            count += (r - l - 1);
            ++l;
        }

        std::cout << count << "\n";
    }
}