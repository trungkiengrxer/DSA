#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long p;
        std::vector<long long> n;
        std::cin >> p;

        if (p == 1) {
            std::cout << "1\n";
            continue;
        }

        for (long long i = 9; i > 1; --i) {
            while (p % i == 0 && p > 1) {
                n.push_back(i);
                p /= i;
            }
        }

        std::reverse(n.begin(), n.end());

        if (p > 1)
            std::cout << "-1\n";
        else
            for (long long i = 0; i < n.size(); ++i) std::cout << n[i];
        std::cout << "\n";
    }
}