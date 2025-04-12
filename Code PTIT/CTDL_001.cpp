#include <iostream>
#include <vector>

void binary_string(std::vector<int> &a, int &size, bool &is_even) {
    while (true) {
        for (int i = 0; i < size; ++i) std::cout << a[i] << " ";

        if (is_even)
            for (int i = size - 1; i >= 0; --i) std::cout << a[i] << " ";
        else for (int i = size - 2; i >= 0; --i) std::cout << a[i] << " ";
        std::cout << "\n";

        int j = size - 1;

        while (j >= 0 && a[j] == 1) {
            a[j] = 0;
            --j;
        }

        if (j < 0) return;
        a[j] = 1;
    }
}

int main() {
    int n, size;
    bool is_even = true;
    std::cin >> n;

    if (n % 2 == 0)
        size = n / 2;
    else {
        size = n / 2 + 1;
        is_even = false;
    }

    std::vector<int> a(size, 0);
    binary_string(a, size, is_even);
}