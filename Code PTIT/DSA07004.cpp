/*
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).

Output:
Với mỗi test, in ra đáp án tìm được trên một dòng.
*/

#include <iostream>
#include <stack>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int open = 0, close = 0;
        std::string s;

        std::cin >> s;

        std::stack<char> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                stack.push(s[i]);
            else {
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    stack.push(')');
            }
        }

        while (!stack.empty()) {
            if (stack.top() == '(')
                ++open;
            else
                ++close;
            stack.pop();
        }

        std::cout << (open + 1) / 2 + (close + 1) / 2 << "\n";
    }
}