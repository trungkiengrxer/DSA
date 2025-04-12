/*
Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:

- Xâu rỗng là 1 dãy ngoặc đúng.

- Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.

- Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm một xâu S có độ dài không vượt quá 105 kí tự.

Output: Với mỗi test in ra một số nguyên là độ dài dãy ngoặc đúng dài nhất tìm được.
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

        int result = 0;
        int last_invalid_position = -1;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
                continue;
            }

            if (stack.empty()) {
                last_invalid_position = i;
                continue;
            }

            stack.pop();

            if (stack.empty()) result = std::max(result, i - last_invalid_position);
            else result = std::max(result, i - stack.top());

        }

        std::cout << result << "\n";
    }
}