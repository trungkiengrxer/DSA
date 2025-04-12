/*
Cho mảng số N. Ta gọi số đảo của N là R. Hãy tìm lũy thừa R của N. Đưa ra kết quả của bài toán dưới dạng modulo với 10^9 + 7.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là số N được ghi trên một dòng.
• T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10^10.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <string>

const long long MOD = 1e9 + 7;

// long long bin_pow(long long n, long long k) {
//     n %= MOD;
//     long long result = 1;

//     while (k > 0) {
//         if (k % 2 == 1) result = (result * n) % MOD;
//         n = (n * n) % MOD;
//         k /= 2;
//     }

//     return result;
// }

long long bin_pow(long long n, long long k) {
    // n %= MOD;
    if (k == 1) return n % MOD;
    long long x = bin_pow(n, k / 2);
    x = (x * x) % MOD;
    if (k % 2) return (x * n) % MOD;
    return x;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        std::string num;
        std::cin >> num;

        long long n = std::stoll(num);

        std::reverse(num.begin(), num.end());

        long long r = std::stoll(num);

        std::cout << bin_pow(n, r) << "\n";
    }
}