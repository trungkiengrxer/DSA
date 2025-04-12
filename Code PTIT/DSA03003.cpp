/*
Cho mảng A[] gồm N phần tử.Nhiệm vụ của bạn là tìm  bằng cách sắp đặt lại các phần tử trong mảng. Chú ý, kết quả của bài toán có thể rất lớn vì vậy bạn hãy đưa ra kết quả lấy modulo với 10^9+7.
max = A[i] * i với 0 <= i < n

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
• T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10^7.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1e9 + 7;

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, max = 0;
        std::cin >> n;

        std::vector<long long> a(n);

        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());
        for (long long i = 0; i < n; ++i) max = (max + a[i] * i) % MOD;
        
        std::cout << max << "\n";
    }
}

