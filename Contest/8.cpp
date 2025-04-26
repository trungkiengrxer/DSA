#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, count = 0, max = 1;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    int max_value = *std::max_element(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        if (a[i] == max_value) {
            ++count;
            max = std::max(max, count);
        } else
            count = 0;
    }

    std::cout << max;
}