#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::string find(std::string &s) {
    std::string result = "";
    std::stack<int> stack;

    int num = 0;
    for (int i = 0; i <= s.size(); ++i) {
        stack.push(++num);
        if (i == s.size() || s[i] == 'I') {
            while (!stack.empty()) {
                result += std::to_string(stack.top());
                stack.pop();
            }
        }
    }

    return result;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        std::string s;
        std::cin >> s;

        std::cout << "Test " << i << ": " << find(s) << "\n";
    }
}