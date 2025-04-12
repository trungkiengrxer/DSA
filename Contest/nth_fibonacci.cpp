#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

std::vector<std::vector<long long>> multiply(std::vector<std::vector<long long>> &a, std::vector<std::vector<long long>> &b) {
    std::vector<std::vector<long long>> c(2, std::vector<long long>(2, 0));

    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < 2; ++j) {
            for (long long k = 0; k < 2; ++k) {
                c[i][j] += (a[i][k] * b[k][j]);
                c[i][j] %= MOD;
            }
        }
    }

    return c;
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