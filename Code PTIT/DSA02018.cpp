/*
Cho 5 số nguyên dương A, B, C, D, E. Bạn có thể hoán vị các phần tử cho nhau, hãy đặt các dấu biểu thức +, -, * sao cho biểu thức sau đúng:
[[[A o(1) B] o(2) C] o(3) D] o(4) E = 23

Trong đó: o(1) … o(4) là các phép toán +, -, *.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 5 số nguyên dương A, B, C, D, E có giá trị không vượt quá 100.

Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool found;
int a, b, c, d, e;
std::vector<char> ops = {'+', '-', '*'};
std::vector<int> operands(5);

int calculate(char &ops, int num1, int num2) {
    if (ops == '+') return num1 + num2;
    if (ops == '-') return num1 - num2;
    if (ops == '*') return num1 * num2;
}

void backtrack(char op1, char op2, char op3, char op4) {
    if (found) return;
    if (op1 != ' ' && op2 != ' ' && op3 != ' ' && op4 != ' ') {
        a = operands[0], b = operands[1], c = operands[2], d = operands[3], e = operands[4];
        if (calculate(op4, calculate(op3, calculate(op2, calculate(op1, a, b), c), d), e) == 23) {
            found = true;
            return;
        }
        return;
    }

    for (char o1 : ops) {
        for (char o2 : ops) {
            for (char o3 : ops) {
                for (char o4 : ops) {
                    backtrack(o1, o2, o3, o4);
                }
            }
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        found = false;
        std::cin >> operands[0] >> operands[1] >> operands[2] >> operands[3] >> operands[4];

        std::sort(operands.begin(), operands.end());

        do {
            backtrack(' ', ' ', ' ', ' ');
            if (found) {
                std::cout << "YES\n";
                break;
            }
        } while (std::next_permutation(operands.begin(), operands.end()));

        if (found) continue;
        std::cout << "NO\n";
    }
}