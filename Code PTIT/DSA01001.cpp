#include <iostream>
#include <string>
#include <vector>

void next_binary_string(std::string &s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1') {
        s[i] = '0';
        --i;
    }
    if (i < 0) return;
    s[i] = '1';
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;
        next_binary_string(s);
        std::cout << s << "\n";
    }
}