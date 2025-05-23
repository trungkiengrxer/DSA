#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool is_operator(std::string &s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

long long calculate(long long &a, long long &b, std::string &op) {
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else
        return a / b;
}

void infix(std::vector<std::string> &a) {
    std::stack<std::string> stack;

    for (long long i = a.size() - 1; i >= 0; --i) {
        if (!is_operator(a[i])) {
            stack.push(a[i]);
            continue;
        }

        long long first = std::stoll(stack.top());
        stack.pop();

        long long second = std::stoll(stack.top());
        stack.pop();

        stack.push(std::to_string(calculate(first, second, a[i])));
    }

    std::cout << stack.top() << "\n";
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<std::string> a(n);

        for (long long i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        infix(a);
    }
}