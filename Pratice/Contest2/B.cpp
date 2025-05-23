#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int lnds(const std::string &s) {
    std::vector<char> tail;

    for (char c : s) {
        auto it = std::upper_bound(tail.begin(), tail.end(), c);
        if (it == tail.end())
            tail.push_back(c);
        else
            *it = c;  
    }

    return tail.size();
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;

        std::cout << lnds(s) << "\n";
    }
    return 0;
}
