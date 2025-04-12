#include <iostream>
#include <vector>

void combination(int n, int k) {
    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) a[i] = i + 1;

    while (true) {
        for (int i = 0; i < k; ++i) std::cout << a[i];
        std::cout << " ";

        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1) --i;

        if (i < 0) return;
        ++a[i];
        for (int j = i + 1; j < k; ++j) a[j] = a[j - 1] + 1;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;
        combination(n, k);
        std::cout << "\n";
    }
}