/*
Dãy số Fibonacci được xác định bằng công thức như sau:

F[0] = 0, F[1] = 1;
F[n] = F[n-1] + F[n-2] với mọi n >= 2.

Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...
Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. Do đáp số có thể rất lớn, in ra kết quả theo modulo 10^9+7.

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
    std::vector<std::vector<long long>> result(2, std::vector<long long>(2, 0));
    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < 2; ++j) {
            for (long long k = 0; k < 2; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

std::vector<std::vector<long long>> bin_pow(long long exp, std::vector<std::vector<long long>> &a) {
    std::vector<std::vector<long long>> result{{1, 0}, {0, 1}};

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

        std::vector<std::vector<long long>> a{{1, 1}, {1, 0}};
        std::vector<std::vector<long long>> result = bin_pow(n, a);

        std::cout << result[0][1] << "\n";
    }
}