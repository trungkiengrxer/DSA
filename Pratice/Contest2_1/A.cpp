#include <algorithm>
#include <iostream>
#include <vector>

bool is_valid(std::vector<int> &a) {
    int sum = 0;
    for (int i = 0; i < a.size() - 1; ++i) sum += (a[i] - a[i + 1]);
    return sum > 0;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i + 1;

    do {
        if (is_valid(a)) {
            for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
            std::cout << "\n";
        }
    } while (std::next_permutation(a.begin(), a.end()));
}