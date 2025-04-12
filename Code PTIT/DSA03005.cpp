/*
Cho mảng A[] gồm N số nguyên không âm và số K. Nhiệm vụ của bạn là hãy chia mảng A[] thành hai mảng con có kích cỡ K và N-K sao cho hiệu giữa tổng hai mảng con là lớn nhất. Ví dụ với mảng A[] = {8, 4, 5, 2, 10}, K=2 ta có kết quả là 17 vì mảng A[] được chia thành hai mảng {4, 2} và { 8, 5,10} có hiệu của hai mảng con là 23-6=17 là lớn nhất.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N và số K; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
• T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ K<N ≤50; 0≤A[i]≤1000.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k, result = 0, sum1 = 0, sum2 = 0;
        std::cin >> n >> k;

        k = std::min(k, n - k);

        std::vector<long long> a(n);

        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());

        for (long long i = 0; i < k; ++i) sum1 += a[i];
        for (long long i = k; i < n; ++i) sum2 += a[i];

        std::cout << sum2 - sum1 << "\n";
    }
}