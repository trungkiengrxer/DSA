/*
Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên cho trước. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 10^9) là kích thước của ma trận và số mũ.

Output:
Với mỗi test, in ra kết quả của ma trận X.
*/

#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

std::vector<std::vector<long long>> multiply(std::vector<std::vector<long long>> &a, std::vector<std::vector<long long>> &b) {
    long long n = a.size();
    std::vector<std::vector<long long>> result(n, std::vector<long long>(n, 0));

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            for (long long k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

std::vector<std::vector<long long>> bin_pow(long long exp, std::vector<std::vector<long long>> &mat) {
    long long n = mat.size();
    std::vector<std::vector<long long>> result(n, std::vector<long long>(n, 0));

    for (long long i = 0; i < n; ++i) result[i][i] = 1;

    while (exp > 0) {
        if (exp % 2) result = multiply(result, mat);
        mat = multiply(mat, mat);
        exp /= 2;
    }

    return result;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::vector<std::vector<long long>> a(n, std::vector<long long>(n));

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < n; ++j) std::cin >> a[i][j];
        }

        std::vector<std::vector<long long>> result = bin_pow(k, a);

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < n; ++j) std::cout << result[i][j] << " ";
            std::cout << "\n";
        }
    }
}