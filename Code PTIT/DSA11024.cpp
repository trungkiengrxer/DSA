#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> nodes(n);
        for (int i = 0; i < n; ++i) std::cin >> nodes[i];

        std::sort(nodes.begin(), nodes.end());

        int median = n / 2;
        if (n % 2 == 0) --median;
        std::cout << nodes[median] << "\n";
    }
}