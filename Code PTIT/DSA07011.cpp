/*
Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng hậu tố về dạng tiền tố.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤10^6.
*/

#include <iostream>
#include <stack>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        std::stack<std::string> stack;

        for (char &c : s) {
            if (isalnum(c)) {
                stack.push(std::string(1, c));
                continue;
            }

            std::string second_operand = stack.top();
            stack.pop();
            std::string first_operand = stack.top();
            stack.pop();

            stack.push(std::string(1, c) + first_operand + second_operand);
        }

        std::cout << stack.top() << "\n";
    }
}