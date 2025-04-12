/*
Cho một ngăn xếp các số nguyên. Các thao tác gồm 3 lệnh: push, pop và show. Trong đó thao tác push kèm theo một giá trị cần thêm (không quá 1000). Hãy viết chương trình ghi ra kết quả của các lệnh show.

Input: Gồm nhiều dòng, mỗi dòng chứa một lệnh push, pop hoặc show. Input đảm bảo số lượng phần tử trong stack khi nhiều nhất cũng không vượt quá 200.

Output: Ghi ra màn hình các phần tử đang có trong stack theo thứ tự lưu trữ mỗi khi gặp lệnh show. Các số viết cách nhau đúng một khoảng trống. Nếu trong stack không còn gì thì in ra dòng “empty”
*/

#include <iostream>
#include <stack>

int main() {
    std::string s;
    std::stack<int> stack;

    while (std::cin >> s) {
        if (s == "push") {
            int x;
            std::cin >> x;
            stack.push(x);
        } else if (s == "pop")
            stack.pop();
        else {
            if (stack.empty()) {
                std::cout << "empty\n";
                continue;
            }
            
            std::stack<int> temp = stack;
            std::stack<int> reverse_stack;

            while (!temp.empty()) {
                reverse_stack.push(temp.top());
                temp.pop();
            }

            while (!reverse_stack.empty()) {
                std::cout << reverse_stack.top() << " ";
                reverse_stack.pop();
            }
            std::cout << "\n";
        }
    }
}