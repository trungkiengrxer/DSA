#include <iostream>
#include <vector>
#include <string>

void binary_string(int n, std::string &s) {
    for (int i = 0; i < n; ++i) s.push_back('A');

    while (true) {
        std::cout << s << " ";

        int i = n - 1;
        while (i >= 0 && s[i] == 'B') {
            s[i] = 'A';
            --i;
        }

        if (i < 0) return;
        s[i] = 'B';
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string s;
        binary_string(n, s);
        std::cout << "\n";
    }
}