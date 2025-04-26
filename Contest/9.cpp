#include <iostream>
#include <string>
#include <vector>

std::string s;

void operation(int x, int y) {
    for (int i = x; i <= y; ++i) {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }
}


int main() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) s.push_back('0');

    while (q--) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        operation(x, y);
    }

    for (int i = 0; i < n; ++i) std::cout << s[i] << " ";
}