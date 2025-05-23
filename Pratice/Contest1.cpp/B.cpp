#include <iostream>
#include <vector>
#include <stack>

bool is_operator(std::string &s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

long long calculate(long long &a, long long &b, std::string &op) {
    if (op == "+") return a + b;
    else if (op == "-") return a - b;
    else if (op == "*") return a * b;
    else return a / b;
}

void postfix(std::vector<std::string> &num) {
    std::stack<std::string> stack;

    for (std::string &s : num) {
        if (!is_operator(s)) {
            stack.push(s);
            continue;
        }

        long long second = std::stoll(stack.top());
        stack.pop();
        long long first = std::stoll(stack.top());
        stack.pop();

        stack.push(std::to_string(calculate(first, second, s)));
    }

    std::cout << stack.top() << "\n";
}

void prefix(std::vector<std::string> &num) {
    std::stack<std::string> stack;

    for (long long i = num.size() - 1; i >= 0; --i) {
        if (!is_operator(num[i])) {
            stack.push(num[i]);
            continue;
        }

        long long first = std::stoll(stack.top());
        stack.pop();
        long long second = std::stoll(stack.top());
        stack.pop();

        stack.push(std::to_string(calculate(first, second, num[i])));
    }

    std::cout << stack.top() << "\n";
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<std::string> s;

        for (long long i = 0; i < n; ++i) {
            std::string x;
            std::cin >> x;
            s.push_back(x);
        }

        if (is_operator(s[0])) {
            prefix(s);
        } else postfix(s);
    }
}