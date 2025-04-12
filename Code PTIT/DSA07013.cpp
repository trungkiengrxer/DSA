/*
Hãy viết chương trình chuyển tính toán giá trị của biểu thức hậu tố.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức hậu tố exp. Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.

Output:
Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.

Ràng buộc:
T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
*/

#include <iostream>
#include <stack>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::stack<int> stack;

        std::cin >> s;

        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                stack.push(s[i] - '0');
                continue;
            }

            int second_operand = stack.top();
            stack.pop();
            int first_operand = stack.top();
            stack.pop();

            if (s[i] == '+') stack.push(first_operand + second_operand);
            else if (s[i] == '-') stack.push(first_operand - second_operand);
            else if (s[i] == '*') stack.push(first_operand * second_operand);
            else stack.push(first_operand / second_operand);
        }

        std::cout << stack.top() << "\n";
    }
}