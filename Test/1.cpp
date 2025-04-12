#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const long long MOD = 1e9 + 7;

long long get_digit(long long x) {
    std::vector<long long> a;
    while (x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }

    long long max = -1e9;

    for (long long i = 0; i < a.size(); ++i) {
        max = std::max(max, a[i]);
    }

    long long result = -1e9 + 1;

    for (long long i = 0; i < a.size(); ++i) {
        result = std::max(result, a[i]);
    }

    return result;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long l, r, result = 0;
        std::cin >> l >> r;

        for (long long i = l; i <= r; ++i) {
            result += get_digit(i);
            result %= MOD;
        }

        std::cout << result << "\n";
    }
}