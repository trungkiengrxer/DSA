#include <iostream>
#include <stack>
#include <string>
#include <vector>

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
        long long n;
        std::cin >> n;

        std::vector<std::string> a(n);
        std::stack<long long> stack;

        for (long long i = 0; i < n; ++i) std::cin >> a[i];

        for (long long i = 0; i < n; ++i) {
            if (a[i] != "+" && a[i] != "-" && a[i] != "*" && a[i] != "/") {
                stack.push(std::stoll(a[i]));
                continue;
            }

            long long second_operand = stack.top();
            stack.pop();
            long long first_operand = stack.top();
            stack.pop();

            stack.push(calculate(a[i], first_operand, second_operand));
        }

        std::cout << stack.top() << "\n";
    }
}