#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    std::vector<std::vector<int>> result;

    do {
        if (a[0] == m) {
            result.push_back(a);
        }
    } while (std::next_permutation(a.begin(), a.end()));

    std::sort(result.begin(), result.end());

    for (const auto nums : result) {
        for (const int num : nums) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}