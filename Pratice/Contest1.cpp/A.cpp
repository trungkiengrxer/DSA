#include <iostream>
#include <string>
#include <vector>

int n, k;
std::vector<std::string> numbers;
std::vector<std::string> result;

void backtrack(std::string &s) {
    if (s.size() == k) {
        numbers.push_back(s);
        return;
    }

    for (char num : {'6', '8'}) {
        s.push_back(num);
        backtrack(s);
        s.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n;
        result.clear();

        for (k = 1; k <= n; ++k) {
            numbers.clear();
            std::string temp = "";
            backtrack(temp);
            
            for (const std::string num : numbers) {
                result.push_back(num);
            }
        }

        std::cout << result.size() << "\n";
        for (const std::string num : result) {
            std::cout << num << " ";
        }

        std::cout << "\n";
    }
}