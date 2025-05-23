#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;
    std::cin.ignore();

    while (t--) {
        std::string s;

        std::getline(std::cin, s);

        std::vector<char> a;
        for (const char &c : s) {
            if (c == '(' || c == ')') a.push_back(c);
        }

        std::stack<int> stack;

        int count_dec = a.size() / 2;
        int count_inc = 1;
        std::vector<int> result(a.size());

        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == '(') {
                stack.push(i);
                result[i] = count_inc;
                ++count_inc;
                continue;
            }

            if (stack.empty()) continue;
            result[i] = result[stack.top()];
            stack.pop();
        }

        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << "\n";
    }
}