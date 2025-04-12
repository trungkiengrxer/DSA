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

int priority(char c) {
    if (c == '+')
        return 0;
    else if (c == '-')
        return 1;
    else if (c == '*')
        return 2;
    else if (c == '/')
        return 3;
    else
        return 4;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::vector<char> result;
        std::stack<char> stack;

        for (const char &x : s) {
            if (x == '(')
                stack.push(x);
            else if (isalnum(x))
                result.push_back(x);
            else {
                char y = stack.top();
                if (priority(x) >= priority(y))
                    stack.push(x);
                else {
                    stack.pop();
                    result.push_back(y);
                    stack.push(x);
                }
            }
        }
    }
}

// A+(B*C)
/*
A
ABC*+
*/