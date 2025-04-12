/*
Yêu cầu bạn xây dựng một stack với các truy vấn sau đây:

“PUSH x”: Thêm phần tử x vào stack (0 ≤ x ≤ 1000).
“PRINT”: In ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.
“POP”: Xóa phần tử đầu tiên của stack. Nếu stack rỗng, không làm gì cả.

Input:
Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).
Mỗi truy vấn có dạng như trên.

Output:
Với mỗi truy vấn “PRINT”, hãy in ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.
*/

#include <iostream>
#include <stack>
#include <string>

int main() {
    int q;
    std::cin >> q;

    std::stack<int> stack;

    while (q--) {
        std::string s;
        std::cin >> s;
        if (s == "PUSH") {
            int x;
            std::cin >> x;
            stack.push(x);

        } else if (s == "POP") {
            if (stack.empty()) continue;
            stack.pop();
            
        } else {
            if (stack.empty()) {
                std::cout << "NONE\n";
                continue;
            }
            std::cout << stack.top() << "\n";
        }
    }
}