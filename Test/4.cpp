#include <cmath>
#include <iostream>
#include <vector>

const int MAX = 1e5 + 1;
std::vector<bool> is_prime(MAX, true);
std::vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) is_prime[j] = false;
        }
    }

    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

int main() {
    sieve();

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        for (const int &x : primes) {
            int count = 0;
            if (x * x > n) break;
            while (n % x == 0) {
                ++count;
                n /= x;
            }

            if (count > 0) std::cout << x << " " << count << " ";
        }

        if (n > 1) std::cout << n << " " << 1;
        std::cout << "\n";
    }
}