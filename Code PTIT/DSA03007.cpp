/*
Cho mảng A[], B[] đều có N phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất của  biểu thức P = A[0]*B[0] + A[1]*B[1] + ..+A[N-1]*B[N-1] bằng cách tráo đổi vị trí các phần tử của cả mảng A[] và B[].

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i]; dòng cuối cùng đưa vào N số B[i] các số được viết cách nhau một vài khoảng trống.
T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N ≤10^7; 0≤A[i], B[i] ≤10^18.

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
        long long n, min = 0;
        std::cin >> n;

        std::vector<long long> a(n), b(n);

        for (long long i = 0; i < n; ++i) std::cin >> a[i];
        for (long long i = 0; i < n; ++i) std::cin >> b[i];

        std::sort(a.begin(), a.end());
        std::sort(b.rbegin(), b.rend());

        for (long long i = 0; i < n; ++i) min += (a[i] * b[i]);

        std::cout << min << "\n";
    }
}