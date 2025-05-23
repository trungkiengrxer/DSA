#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(std::string &s, int &l, int &r) {
    --l;
    --r;

    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }

    return true;
}

void insert(std::string &s, int u, char x) {
    s[u - 1] = x;
}

int main() {
    std::string s;
    std::cin >> s;

    int q;
    std::cin >> q;

    while (q--) {
        char type;
        std::cin >> type;
        
        if (type == 'q') {
            int start, end;
            std::cin >> start >> end;

            if (is_palindrome(s, start, end)) std::cout << "YES\n";
            else std::cout << "NO\n";
        } else {
            int u;
            char x;
            std::cin >> u >> x;
            insert(s, u, x);
        }
    }
}