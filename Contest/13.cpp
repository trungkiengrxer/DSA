#include <iostream>
#include <vector>

int main() {
    long long n, q;
    std::cin >> n >> q;

    std::vector<long long> prefix(n, 0);
    std::vector<long long> a(n);

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    for (long long i = 0; i < n; ++i) {
        if (i == 0 && a[i] > 0) {
            prefix[i] = a[i];
            continue;
        }
        if (a[i] < 0 && i > 0)
            prefix[i] = prefix[i - 1];
        else if (a[i] < 0 && i == 0)
            prefix[i] = 0;
        else
            prefix[i] = prefix[i - 1] + a[i];
    }

    while (q--) {
        long long l, r;
        std::cin >> l >> r;
        --l, --r;

        if (l == 0)
            std::cout << prefix[r] << "\n";
        else
            std::cout << prefix[r] - prefix[l - 1] << "\n";
    }
}