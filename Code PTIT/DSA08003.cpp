/*
Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:

“PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue (0 ≤ x ≤ 1000).
“PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”.
“POPFRONT”: Xóa phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả.
“PUSHBACK x”: Thêm phần tử x vào cuối của dequeue (0 ≤ x ≤ 1000).
“PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”.
“POPBACK”: Xóa phần tử cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.

Dữ liệu vào:
Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).
Mỗi truy vấn có dạng như trên.

Kết quả:
Với mỗi truy vấn “PRINTFRONT” và “PRINTBACK”, hãy in ra kết quả trên một dòng.
*/

#include <deque>
#include <iostream>
#include <string>

int main() {
    int q;
    std::cin >> q;

    std::deque<int> dequeue;

    while (q--) {
        std::string s;
        std::cin >> s;

        if (s == "PUSHFRONT") {
            int x;
            std::cin >> x;
            dequeue.push_front(x);

        } else if (s == "PRINTFRONT") {
            if (dequeue.empty()) {
                std::cout << "NONE\n";
                continue;
            }
            std::cout << dequeue.front() << "\n";

        } else if (s == "POPFRONT") {
            if (dequeue.empty()) continue;
            dequeue.pop_front();

        } else if (s == "PUSHBACK") {
            int x;
            std::cin >> x;
            dequeue.push_back(x);

        } else if (s == "PRINTBACK") {
            if (dequeue.empty()) {
                std::cout << "NONE\n";
                continue;
            }
            std::cout << dequeue.back() << "\n";

        } else if (s == "POPBACK") {
            if (dequeue.empty()) continue;
            dequeue.pop_back();
        }
    }
}