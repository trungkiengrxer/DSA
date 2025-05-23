#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int n;
std::vector<std::string> result;

bool comparator(std::string a, std::string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void backtrack(int len, std::string current) {
    if (current.size() * 2 > len) return;

    if (current.size() > 0) {
        std::string num = current;
        std::reverse(num.begin(), num.end());
        result.push_back(current + num);
    }

    for (std::string s : {"6", "8"}) {
        backtrack(len, current + s);
    }
}

int main() {
    int t;
    std::cin >> t;

    result.clear();

    std::string current = "";
    backtrack(26, current);
    std::sort(result.begin(), result.end(), comparator);

    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; ++i) std::cout << result[i] << " ";
        std::cout << "\n";
    }
}