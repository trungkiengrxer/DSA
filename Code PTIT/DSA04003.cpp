/*
Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n.

Dữ liệu vào: dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ liệu ghi một số nguyên dương n duy nhất không qua 1018.

Kết quả: Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư của kết quả tìm được khi chia cho 123456789.
*/

#include <iostream>
#include <vector>

const long long MOD = 123456789;

long long bin_pow(long long n, long long k) {
    long long result = 1;

    n %= MOD;
    while (k > 0) {
        if (k % 2) result = (result * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }

    return result;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;
        std::cout << bin_pow(2, n - 1) << "\n";
    }
}