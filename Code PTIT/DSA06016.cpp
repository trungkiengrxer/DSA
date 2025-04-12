/*
Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử. Nhiệm vụ của bạn là tìm tích giữa phần tử lớn nhất của mảng A[] và phần tử nhỏ nhất của mảng B[]. Ví dụ A[] = {5, 7, 112, 9, 3, 6, 2 }, B[] = {1, 2, 6, -1, 0, 9} ta có kết quả là -9 = 9*(-1).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m tương ứng với số phần tử của mảng A[] và B[]; dòng tiếp theo là n số A[i] ; dòng cuối cùng là m số B[i]; các số được viết cách nhau một vài khoảng trống.
T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤10^6; -10^8≤ A[i] ≤10^8.

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
        long long n, m;
        std::cin >> n >> m;

        std::vector<long long> a(n), b(m);

        for (long long i = 0; i < n; ++i) std::cin >> a[i];
        for (long long i = 0; i < m; ++i) std::cin >> b[i];

        std::cout << *std::max_element(a.begin(), a.end()) * *std::min_element(b.begin(), b.end()) << "\n";
    }
}