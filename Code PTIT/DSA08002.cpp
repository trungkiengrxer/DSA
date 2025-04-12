/*
Yêu cầu bạn xây dựng một queue với các truy vấn sau đây:

“PUSH x”: Thêm phần tử x vào cuối của queue (0 ≤ x ≤ 1000).
“PRINTFRONT”: In ra phần tử đầu tiên của queue. Nếu queue rỗng, in ra “NONE”.
“POP”: Xóa phần tử ở đầu của queue. Nếu queue rỗng, không làm gì cả.

Dữ liệu vào:
Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).
Mỗi truy vấn có dạng như trên.

Kết quả:
Với mỗi truy vấn “PRINT”, hãy in ra phần tử đầu tiên của queue. Nếu queue rỗng, in ra “NONE”.
*/

#include <iostream>
#include <queue>
#include <string>

int main() {
    int q;
    std::cin >> q;

    std::queue<int> queue;

    while (q--) {
        std::string s;
        std::cin >> s;

        if (s == "PUSH") {
            int x;
            std::cin >> x;
            queue.push(x);

        } else if (s == "POP") {
            if (queue.empty()) continue;
            queue.pop();
            
        } else {
            if (queue.empty()) {
                std::cout << "NONE\n";
                continue;
            }
            std::cout << queue.front() << "\n";
        }
    }
}