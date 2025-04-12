#include <iostream>
#include <vector>

void next_permutation(int n, std::vector<int> &a) {
    int i = n - 2;
    while (i >= 0 && a[i] > a[i + 1]) --i;

    if (i < 0) {
        int left = 0, right = n - 1;
        while (left <= right) std::swap(a[left++], a[right--]);
        return;
    }

    int j = n - 1;
    while (a[j] < a[i]) --j;

    std::swap(a[i], a[j]);

    int left = i + 1, right = n - 1;
    while (left < right) std::swap(a[left++], a[right--]);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        next_permutation(n, a);

        for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << "\n";
    }
}