#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> result;
std::string s;

void binary_string(int n) {
    for (int i = 0; i < n; ++i) s.push_back('0');

    while (true) {
        result.push_back(s);
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            --i;
        }

        if (i < 0) return;
        s[i] = '1';
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    binary_string(n);
    for (int i = 0; i < result.size(); i += k) std::cout << result[i] << "\n";
}