#include <iostream>
#include <set>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::multiset<long long> window;

        std::cin >> n >> k;

        std::vector<long long> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        for (long long i = 0; i < k; ++i) window.insert(a[i]);

        for (long long i = k; i < n; ++i) {
            std::cout << *window.rbegin() << " ";
            window.erase(window.find(a[i - k]));
            window.insert(a[i]);
        }

        std::cout << *window.rbegin();
        std::cout << "\n";
    }
}