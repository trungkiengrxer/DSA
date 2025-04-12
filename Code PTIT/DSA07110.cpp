/*
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’. Một dãy ngoặc đúng được định nghĩa như sau:

- Xâu rỗng là 1 dãy ngoặc đúng.

- Nếu A là 1 dãy ngoặc đúng thì (A), [A], {A} là 1 dãy ngoặc đúng.

- Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

Cho một xâu S. Nhiệm vụ của bạn là xác định xâu S có là dãy ngoặc đúng hay không?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000.

Output:
Với mỗi test, in ra “YES” nếu như S là dãy ngoặc đúng, in ra “NO” trong trường hợp ngược lại.
*/

#include <iostream>
#include <stack>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::stack<char> stack;

        std::cin >> s;

        for (const char &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
                continue;
            }

            if (stack.empty()) continue;
            
            char top = stack.top();
            if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}')) stack.pop();
        }

        if (stack.empty())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}