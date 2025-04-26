#include <iostream>
#include <vector>

const long long MAX = 1e6 + 1;
std::vector<long long> smallest(MAX);

void sieve() {
    for (long long i = 0; i < MAX; ++i) smallest[i] = i;
    for (long long i = 2; i * i < MAX; ++i) {
        if (smallest[i] == i) {
            for (long long j = i * i; j < MAX; j += i) {
                smallest[j] = i;
            }
        }
    }
}

long long find(long long x) {
    long long result = 0;

    while (x > 1) {
        long long fact = smallest[x];
        result = std::max(result, fact);
        while (x % fact == 0) x /= fact;
    }
    return result;
}

int main() {
    sieve();
    long long t;
    std::cin >> t;

    while (t--) {
        long long l, r, sum = 0;
        std::cin >> l >> r;

        for (long long i = l; i <= r; ++i) sum += find(i);

        std::cout << sum << "\n";
    }
}