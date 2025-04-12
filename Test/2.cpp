#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, q;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> a(n);

    for (long long i = 0; i < n; ++i) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::vector<std::vector<long long>> b(1001, std::vector<long long>(10001, 0));

    for (long long i = 0; i < n; ++i) {
        for (long long j = a[i].first - 1; j <= a[i].second - 1; ++j) b[i][j] = 1;
    }

    std::cin >> q;

    std::vector<long long> queries(q);

    for (long long i = 0; i < q; ++i) {
        std::cin >> queries[i];
        --queries[i];
    }

    for (long long query : queries) {
        long long result = 0;
        for (long long i = 0; i < n; ++i) {
            result += b[i][query];
        }

        std::cout << result << "\n";
    }
}