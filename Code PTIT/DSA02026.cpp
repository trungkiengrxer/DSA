/*
Cho một biểu thức trong phạm vi hai chữ số với các phép toán cộng trừ nhân chia. Các toán hạng và kết quả đảm bảo là số nguyên dương có hai chữ số, nếu có phép chia thì phải thỏa mãn tính chia hết.
Người ta có thể ẩn đi một số chữ số hoặc phép toán bằng cách điền dấu chấm hỏi (?). Nhiệm vụ của bạn là khôi phục các dấu chấm hỏi và in ra phép toán chính xác ban đầu. Nếu không thể có kết quả đúng thì ghi ra WRONG PROBLEM!

Dữ liệu vào
Dòng đầu ghi số bộ test T (1 ≤ T ≤ 100).
T dòng tiếp theo, mỗi dòng là một biểu thức có thể có các dấu ?.
Nếu có thể có nhiều kết quả đúng thì in ra kết quả đầu tiên theo thứ tự từ điển, tức là số nhỏ nhất có thể tính từ trái sang phải.

Kết quả
Với mỗi bộ test, ghi ra biểu thức đúng tìm được. Hoặc WRONG PROBLEM!
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

bool found;

std::vector<int> num1;
std::vector<int> num2;
std::vector<int> num3;

void generate(std::string &operand, std::set<int> &num) {
    if (operand[0] != '?' && operand[1] != '?') {
        num.insert(std::stoi(operand));
        return;
    }
    if (operand[0] == '?') {
        for (int i = 1; i <= 9; ++i) {
            operand[0] = i + '0';
            generate(operand, num);
        }
        operand[0] = '?';
    }
    if (operand[1] == '?') {
        for (int i = 0; i <= 9; ++i) {
            operand[1] = i + '0';
            generate(operand, num);
        }
        operand[1] = '?';
    }
}

void backtrack(int operand1, int operand2, int result, std::string op) {
    if (found) return;

    if (operand1 != -1 && operand2 != -1 && result != -1) {
        if (op == "+") {
            if (operand1 + operand2 == result) {
                found = true;
                std::cout << operand1 << " + " << operand2 << " = " << result << "\n";
            }
            return;
        }
    
        if (op == "-") {
            if (operand1 - operand2 == result) {
                found = true;
                std::cout << operand1 << " - " << operand2 << " = " << result << "\n";
            }
            return;
        }
    
        if (op == "*" || op == "/") return;
    }

    for (int op1 : num1) {
        for (int op2 : num2) {
            for (int res : num3) {
                if (op == "?") {
                    backtrack(op1, op2, res, "+");
                    backtrack(op1, op2, res, "-");
                    continue;
                }
                backtrack(op1, op2, res, op);
            }
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();

    while (t--) {
        found = false;
        std::string s;
        std::getline(std::cin, s);

        std::set<int> set1;
        std::set<int> set2;
        std::set<int> set3;

        num1.clear();
        num2.clear();
        num3.clear();

        std::string operand1, operand2, op1, op2, result;

        std::stringstream ss(s);

        ss >> operand1 >> op1 >> operand2 >> op2 >> result;

        generate(operand1, set1);
        generate(operand2, set2);
        generate(result, set3);

        for (const auto num : set1) num1.push_back(num);
        for (const auto num : set2) num2.push_back(num);
        for (const auto num : set3) num3.push_back(num);

        backtrack(-1, -1, -1, op1);

        if (!found) std::cout << "WRONG PROBLEM!\n";
    }
}