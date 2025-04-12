#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::sort(a.rbegin(), a.rend());

    std::cout << std::max({a[0] * a[1] * a[2], a[0] * a[1], a[n - 1] * a[n - 2], a[0] * a[n - 1] * a[n - 2], a[n - 1] * a[n - 2] * a[n - 3]});
}