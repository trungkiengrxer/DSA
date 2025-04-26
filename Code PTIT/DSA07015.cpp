#include <iostream>
#include <stack>
#include <string>
#include <vector>

long long priority(char op) {
    if (op == '+' || op == '-')
        return 0;
    else
        return 1;
}

long long calculate(std::string op, long long a, long long b) {
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else
        return a / b;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        std::vector<std::string> postfix;
        std::stack<char> stack;

        for (long long i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                std::string num;
                while (i < s.size() && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '(' && s[i] != ')') {
                    num.push_back(s[i]);
                    ++i;
                }
                if (num != "") postfix.push_back(num);
            }

            if (i >= s.size()) break;
            // std::cout << num;

            if (s[i] == '(') {
                stack.push(s[i]);
            } else if (s[i] == ')') {
                while (true) {
                    if (!stack.empty()) {
                        char c = stack.top();
                        stack.pop();

                        if (c == '(') break;
                        postfix.push_back(std::string(1, c));
                    } else
                        break;
                }

            } else {
                while (!stack.empty() && stack.top() != '(' && ((s[i] != '^' && priority(s[i]) <= priority(stack.top())) || (s[i] == '^' && priority(s[i]) < priority(stack.top())))) {
                    postfix.push_back(std::string(1, stack.top()));
                    stack.pop();
                }
                stack.push(s[i]);
            }
            // std::cout << s[i];
            ++i;
            if (i >= s.size()) break;
        }

        while (!stack.empty()) {
            char c = stack.top();
            stack.pop();
            postfix.push_back(std::string(1, c));
        }

        // for (const auto x : postfix) std::cout << x;
        // std::cout << "\n";

        std::stack<long long> second_stack;

        for (const std::string string : postfix) {
            if (string != "+" && string != "-" && string != "*" && string != "/") {
                second_stack.push(std::stoll(string));
                continue;
            }

            long long second_operand = second_stack.top();
            second_stack.pop();
            long long first_operand = second_stack.top();
            second_stack.pop();

            second_stack.push(calculate(string, first_operand, second_operand));
        }

        std::cout << second_stack.top() << "\n";
    }
}