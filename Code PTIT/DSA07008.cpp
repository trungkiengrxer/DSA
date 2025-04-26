/*
Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng trung tố về dạng hậu tố.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Ràng buộc:
T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤10.
Các phép toán bao gồm +, -, *, /, ^. Phép lũy thừa có ưu tiên cao hơn nhân chia và cộng trừ.
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

int priority(char x) {
    if (x == '-' || x == '+')
        return 0;
    else if (x == '*' || x == '/')
        return 1;
    else if (x == '^')
        return 2;
    return -1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        std::vector<char> result;
        std::stack<char> stack;

        for (const char &x : s) {
            if (isalnum(x))
                result.push_back(x);
            else if (x == '(')
                stack.push(x);
            else if (x == ')') {
                while (true) {
                    if (!stack.empty()) {
                        char y = stack.top();
                        stack.pop();

                        if (y == '(') break;
                        result.push_back(y);
                    } else
                        break;
                }
            } else {
                while (!stack.empty() && stack.top() != '(' && ((x != '^' && priority(x) <= priority(stack.top())) || (x == '^' && priority(x) < priority(stack.top())))) {
                    result.push_back(stack.top());
                    stack.pop();
                }
                stack.push(x);
            }
        }

        while (!stack.empty()) {
            char x = stack.top();
            stack.pop();
            result.push_back(x);
        }

        for (const char &x : result) std::cout << x;
        std::cout << "\n";
    }
}