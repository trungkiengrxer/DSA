#include <iostream>
#include <vector>

int main() {
    long long n, q;
    std::cin >> n >> q;

    std::vector<long long> a(n);
    std::vector<long long> prefix(n);

    for (long long i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i == 0) {
            prefix[i] = a[i];
            continue;
        }
        if (a[i] < 0)
            prefix[i] = prefix[i - 1];
        else
            prefix[i] = prefix[i - 1] + a[i];
    }

    while (q--) {
        long long l, r;
        std::cin >> l >> r;
        --l;
        --r;

        std::cout << prefix[r] - prefix[l - 1] << "\n";
    }
}