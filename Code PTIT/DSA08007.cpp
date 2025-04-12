/*
Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 1, 10, 101. Cho số tự nhiên N (N<263). Hãy cho biết có bao nhiêu số BDN nhỏ hơn N. Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.

Input:
Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số tự nhiên N.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <queue>
#include <string>

bool compare(std::string &s, std::string &t) {
    if (s.size() < t.size())
        return true;
    else if (s.size() == t.size()) {
        return s <= t;
    } else
        return false;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        std::string n;
        int count = 0;
        std::cin >> n;

        std::queue<std::string> queue;

        queue.push("1");

        while (true) {
            std::string bdn_num = queue.front();
            if (compare(bdn_num, n)) ++count;
            else break;

            queue.pop();
            queue.push(bdn_num + "0");
            queue.push(bdn_num + "1");
        }

        std::cout << count << "\n";
    }
}