#include <iostream>
#include <vector>
#include <string>

int n;
std::vector<std::string> result;

void backtrack(std::string s) {
    if (s.size() == n) {
        result.push_back(s);
        return;
    }

    backtrack(s + "A");
    backtrack(s + "B");
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        result.clear();
        std::cin >> n;
        backtrack("");

        for (int i = 0; i < result.size(); ++i) {
            std::cout << result[i];
            if (i < result.size() - 1) std::cout << ",";
        }
        std::cout << "\n";
    }
}