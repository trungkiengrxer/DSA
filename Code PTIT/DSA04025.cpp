/*
Dãy số nguyên dương vô hạn A[] được định nghĩa một cách đệ quy như sau:

A[0] = 0
A[1] = 1;
A[i] = A[i-1] + A[i-2] với mọi n ≥ 2.
Cho số nguyên dương N không quá 109. Hãy xác định số thứ N trong dãy A[]. Nếu kết quả quá lớn, hãy in ra theo modulo 109+7.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).
Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 10^9).

Output:
Với mỗi test, in ra đáp án trên một dòng.
*/

#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

std::vector<std::vector<long long>> multiply(std::vector<std::vector<long long>> &a, std::vector<std::vector<long long>> &b) {
    std::vector<std::vector<long long>> result(2, std::vector<long long>(2));

    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (long long k = 0; k < 2; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

std::vector<std::vector<long long>> bin_pow(std::vector<std::vector<long long>> &a, long long exp) {
    std::vector<std::vector<long long>> result = {{1, 0}, {0, 1}};

    while (exp > 0) {
        if (exp % 2) result = multiply(result, a);
        a = multiply(a, a);
        exp /= 2;
    }

    return result;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<std::vector<long long>> a = {{1, 1}, {1, 0}};
        std::vector<std::vector<long long>> result = bin_pow(a, n);

        std::cout << result[0][1] << "\n";
    }
}