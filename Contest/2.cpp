#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::string first;

    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::cin >> first;

    for (int i = 0; i < n; ++i) {
        if (a[i] == first) {
            std::swap(a[0], a[i]);
            break;
        }
    }

    std::sort(a.begin() + 1, a.end());

    do {
        for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << "\n";
    } while (std::next_permutation(a.begin() + 1, a.end()));
}