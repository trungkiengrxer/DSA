#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] == x) std::cout << i + 1 << "\n";
        }
    }
}