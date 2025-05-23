#include <iostream>
#include <vector>
#include <stack>
#include <string>

bool is_operator(std::string s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

long long calculate(long long a, long long b, std::string op) {
    if (op == "+") return a + b;
    else if (op == "-") return a - b;
    else if (op == "*") return a * b;
    else return a / b;
}

long long calculate_postfix(std::vector<std::string> &a) {
    std::stack<long long> stack;

    for (const std::string &a : a) {
        if (!is_operator(a)) {
            stack.push(std::stoll(a));
            continue;
        }

        long long second_operand = stack.top();
        stack.pop();
        long long first_operand = stack.top();
        stack.pop();

        stack.push(calculate(first_operand, second_operand, a));
    }

    return stack.top();
}

long long calculate_prefix(std::vector<std::string> &a) {
    std::stack<long long> stack;

    for (long long i = a.size() - 1; i >= 0; --i) {
        if (!is_operator(a[i])) {
            stack.push(std::stoll(a[i]));
            continue;
        }

        long long first_operand = stack.top();
        stack.pop();
        long long second_operand = stack.top();
        stack.pop();

        stack.push(calculate(first_operand, second_operand, a[i]));
    }

    return stack.top();
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<std::string> a(n);
        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        if (!is_operator(a[0])) std::cout << calculate_postfix(a) << "\n";
        else std::cout << calculate_prefix(a) << "\n";
    }
}