#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n, result = 1e9;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n, 0);

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int min_value = *std::min_element(a.begin(), a.end());
    std::cout << min_value;

    for (int u = min_value; u >= 1; --u) {
        b[0] = u;
        int previous = a[0] / b[0];
        for (int i = 1; i < n; ++i) {
            b[i] = a[i] / previous;
            previous = a[i] / b[i];
            // if (b[i] != b[i - 1]) break;
        }

        int sum = std::accumulate(b.begin(), b.end(), 0);
        std::cout << sum << "\n";
        result = std::min(result, sum);
    }

    std::cout << result;
}